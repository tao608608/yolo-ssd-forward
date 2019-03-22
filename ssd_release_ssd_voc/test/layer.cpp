#include "layer.h"

//从硬盘读取文件，并存入已分配好的内存(buffer)中
void readFile(string filename, float *buffer, unsigned int size)
{
	fstream inFile;
	inFile.open(filename, ios::binary | ios::in);
	inFile.read((char*)buffer, size);
	inFile.close();
	return;
}
void readFile1(string filename, float *buffer, unsigned int size, vector<int> vec)
{
	fstream inFile;
	int a = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		a = a + vec[i];
	}
	inFile.open(filename, ios::binary | ios::in);
	inFile.seekg(a, ios::cur);

	inFile.read((char*)buffer, size);
	inFile.close();
	return;
}

//判断a是否为0<=a<b
inline bool is_a_ge_zero_and_a_lt_b(int a, int b)
{
	return static_cast<unsigned>(a) < static_cast<unsigned>(b);
}




float im2col_get_pixel(float *im, int height, int width, int channels,
	int row, int col, int channel, int pad)
{
	row -= pad;
	col -= pad;

	if (row < 0 || col < 0 ||
		row >= height || col >= width) return 0;
	return im[col + width*(row + height*channel)];
}


void im2col_cpu(float* data_im,
	int channels, int height, int width,
	int ksize, int stride, int pad, float* data_col)
{
	int c, h, w;
	int height_col = (height + 2 * pad - ksize) / stride + 1;
	int width_col = (width + 2 * pad - ksize) / stride + 1;

	int channels_col = channels * ksize * ksize;
	for (c = 0; c < channels_col; ++c) {
		int w_offset = c % ksize;
		int h_offset = (c / ksize) % ksize;
		int c_im = c / ksize / ksize;
		for (h = 0; h < height_col; ++h) {
			for (w = 0; w < width_col; ++w) {
				int im_row = h_offset + h * stride;
				int im_col = w_offset + w * stride;
				int col_index = (c * height_col + h) * width_col + w;
				data_col[col_index] = im2col_get_pixel(data_im, height, width, channels,
					im_row, im_col, c_im, pad);
			}
		}
	}
}

void gemm_nn(int M, int N, int K, float ALPHA,
	float *A, int lda,
	float *B, int ldb,
	float *C, int ldc)
{
	int i, j, k;
		for (i = 0; i < M; ++i) {
			for (k = 0; k < K; ++k) {
				register float A_PART = ALPHA*A[i*lda + k];
				for (j = 0; j < N; ++j) {
					C[i*ldc + j] += A_PART*B[k*ldb + j];
				}
				// // SSE
				//__m128 a128, b128, c128, result128;	// SSE
				//a128 = _mm_set1_ps(A_PART);
				//for (j = 0; j < N - 4; j += 4) {
				//b128 = _mm_loadu_ps(&B[k*ldb + j]);
				//c128 = _mm_loadu_ps(&C[i*ldc + j]);
				////result128 = _mm_fmadd_ps(a128, b128, c128);
				//result128 = _mm_mul_ps(a128, b128);
				//result128 = _mm_add_ps(result128, c128);
				//_mm_storeu_ps(&C[i*ldc + j], result128);
				//}

				//int prev_end = (N % 4 == 0) ? (N - 4) : (N / 4) * 4;
				//for (j = prev_end; j < N; ++j) {
				//	C[i*ldc + j] += A_PART*B[k*ldb + j];
				//}
		}
	}
}



void gemm1(int TA, int TB, int M, int N, int K, float ALPHA,
	float *A, int lda,
	float *B, int ldb,
	float BETA,
	float *C, int ldc)
{
#pragma omp parallel for
	for (int t = 0; t < M; ++t) {
		gemm_nn(1, N, K, ALPHA, A + t*lda, lda, B, ldb, C + t*ldc, ldc);
	}
}

void gemm(int TA, int TB, int M, int N, int K, float ALPHA,
	float *A, int lda,
	float *B, int ldb,
	float BETA,
	float *C, int ldc)
{
	gemm_nn( M, N, K, ALPHA, A, lda, B, ldb, C, ldc);
}

void add_bias(float *output, float *biases, int batch, int n, int size)
{
	int i, j, b;
	for (b = 0; b < batch; ++b) {
		for (i = 0; i < n; ++i) {
			for (j = 0; j < size; ++j) {
				output[(b*n + i)*size + j] += biases[i];
			}
		}
	}
}

void convforward(convParam *param,float*input_col, const int pad, 
	const int stride,  int withRELU )
{
	int out_h = param->outH;
	int out_w = param->outW;
	int m = param->outC;
	int k = param->knlH* param->knlW* param->inC;
	int n = out_h*out_w;
	float *a = param->coef;
	int num = param->outC*param->inC*param->knlH* param->knlW;
	float *b = input_col;
	float *c = param->output;
	memset(c, 0, param->outC * param->outH * param->outW * sizeof(float));
	im2col_cpu(param->col, param->inC, param->inH, param->inW,
		param->knlH, stride, pad, b);
	gemm(0, 0, m, n, k, 1, a, k, b, n, 1, c, n);
	add_bias(param->output, param->bias, 1, param->outC, out_h*out_w);
	if (withRELU)
	{
		for (int i = 0; i < param->outC * param->outH * param->outW; i++)
		{
			if (param->output[i] <= 0)
			{
				param->output[i] = 0;
			}
		}
	}

}


//行列转置
void Row_column_transpose(float *fc6_coef, float *fc6_new_coef, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			int m = i * col + j;
			int n = j * row + i;
			*(fc6_new_coef + n) = *(fc6_coef + m);
		}
	}
}


//把经过padding以后的feature map(该feature map的值是按行存完一个通道再存下一个通道，可以理解为行优先数组)，按卷积滑动时候需要计算的神经元按顺序排列，变成矩阵的方式。
void im2row(float *input, int channels, int height, int width, int kernel_h, int kernel_w,
	int pad_h, int pad_w, int stride_h, int stride_w, int dilation_h, int dilation_w, float *data_col)
{
	const int output_h = (height + 2 * pad_h - (dilation_h * (kernel_h - 1) + 1)) / stride_h + 1;
	const int output_w = (width + 2 * pad_w - (dilation_w * (kernel_w - 1) + 1)) / stride_w + 1;
	int channel_size = height * width;
	int kernel_row_start = -pad_h;
	for (int output_row = 0; output_row < output_h; output_row++)
	{
		int kernel_col_start = -pad_w;
		for (int output_col = 0; output_col < output_w; output_col++)
		{
			for (int channel = 0; channel < channels; channel++)
			{
				for (int kernel_row = 0; kernel_row < kernel_h; kernel_row++)
				{
					for (int kernel_col = 0; kernel_col < kernel_w; kernel_col++)
					{
						int input_row = kernel_row_start + kernel_row * dilation_h;
						int input_col = kernel_col_start + kernel_col * dilation_w;
						if (!is_a_ge_zero_and_a_lt_b(input_row, height) || !is_a_ge_zero_and_a_lt_b(input_col, width))
						{
							*(data_col++) = 0;
						}
						else
						{
							*(data_col++) = input[channel * channel_size + input_row * width + input_col];
						}
					}
				}
			}
			kernel_col_start += stride_w;
		}
		kernel_row_start += stride_h;
	}
}

//把经过padding以后的feature map(该feature map的值是按列存完一个通道再存下一个通道，可以理解为列优先数组)，按卷积滑动时候需要计算的神经元按顺序排列，变成矩阵的方式。
void im2rowBycol(const float* data_im, const int channels, const int height, const int width,
	const int kernel_h, const int kernel_w, const int pad_h, const int pad_w,
	const int stride_h, const int stride_w, const int dilation_h, const int dilation_w, float* data_col)
{
	const int output_h = (height + 2 * pad_h - (dilation_h * (kernel_h - 1) + 1)) / stride_h + 1;
	const int output_w = (width + 2 * pad_w - (dilation_w * (kernel_w - 1) + 1)) / stride_w + 1;
	int kernel_row_start = -pad_h;
	for (int output_row = 0; output_row < output_h; output_row++)
	{
		int kernel_col_start = -pad_w;
		for (int output_col = 0; output_col < output_w; output_col++)
		{
			for (int channel = 0; channel < channels; channel++)
			{
				for (int kernel_row = 0; kernel_row < kernel_h; kernel_row++)
				{
					for (int kernel_col = 0; kernel_col < kernel_w; kernel_col++)
					{
						int input_row = kernel_row_start + kernel_row * dilation_h;
						int input_col = kernel_col_start + kernel_col * dilation_w;
						if (!is_a_ge_zero_and_a_lt_b(input_row, height) || !is_a_ge_zero_and_a_lt_b(input_col, width))
						{
							*(data_col++) = 0;
						}
						else
						{
							int loc = (input_row * width + input_col) * channels + channel;
							float a= data_im[(input_row * width + input_col) * channels + channel];
							*(data_col++) = data_im[(input_row * width + input_col) * channels + channel];
						}
					}
				}
			}
			kernel_col_start += stride_w;
		}
		kernel_row_start += stride_h;
	}
}

//经过im2row/im2rowBycol函数转换的feature map和经过行列转置的卷积核参数进行点积运算。
void convLayer(convParam *param, int withRELU = 0)
{
	float *col = param->col;
	float *coef = param->coef;
	float *bias = param->bias;
	float *output = param->output;
	memset(output, 0, param->outC * param->outH * param->outW * sizeof(float));
	int is_0_count = 0;
	int is_not_0_count = 0;
	int output_count = 0;
	for (int i = 0; i < param->outH * param->outW; i++)
	{
		for (int j = 0; j < param->inC * param->knlH * param->knlW; j++)
		{
			float x = *(col + j);
			if (x == 0)
			{
				is_0_count++;
				coef += param->outC;
				continue;
			}
			else
			{
				is_not_0_count++;
				for (int k = 0; k < param->outC; k++)
				{
					output[i * param->outC + k] += *(coef++) * x;
					//output[k * param->outH * param->outW + i] += *(coef++) * x;
				}
			}
		}
		for (int c = 0; c < param->outC; c++)
		{
			output[i * param->outC + c] += bias[c];
		}
		coef = param->coef;
		col += param->inC * param->knlH * param->knlW;
	}
	if (withRELU)
	{
		for (int i = 0; i < param->outC * param->outH * param->outW; i++)
		{
			if (output[i] <= 0)
			{
				output[i] = 0;
			}
			else
			{
				output_count++;
			}
		}
	}
	cout << "is_0_count: " << is_0_count << " is_not_0_count: " << is_not_0_count << " output_count: " << output_count << endl;
}

void batchnorm1(BNParam *net)
{
	for (int j = 0; j < net->col_C; j++)
	{
		float mean = net->bn_mean[j] / net->bn_scales[0];
		float var = sqrtf(net->bn_variance[j] / net->bn_scales[0]+1e-5) ;
		for (int i = 0; i < net->col_H*net->col_W; i++)
		{
			net->output[j*net->col_H*net->col_W + i] = (net->col[j*net->col_H*net->col_W + i] - mean) / var;
		}

	}
}
void batchnorm(BNParam *net)
{//BNParam bn1_input = { bn1_col,bn1_output,bn1_mean,bn1_variance ,bn1_scale,img_channel,img_height,img_width };
	for (int j = 0; j < net->col_W*net->col_H; j++)
	{

		for (int i = 0; i < net->col_C; i++)
		{
			float mean = net->bn_mean[i] / net->bn_scales[0];
			float var = sqrtf(net->bn_variance[i] / net->bn_scales[0] + 1e-5) ;
			net->output[j*net->col_C + i] = (net->col[j*net->col_C + i] - mean) / var;
		}

	}
}
void scales(ScaleParam *data, int withRelu)
{
	for (int i = 0; i < data->col_H*data->col_W; i++)

	{
		for (int j = 0; j < data->col_C; j++)
		{
			data->output[i*data->col_C + j] = data->col[i*data->col_C + j] * data->gamma[j] + data->beta[j];
			if (withRelu&&data->output[i*data->col_C + j] <= 0)
			{
				 data->output[i*data->col_C + j] = 0;
			}

		}
	}
}

void scales1(ScaleParam *data,int withRelu)
{
	for (int j = 0; j < data->col_C; j++)
	{
		for (int i = 0; i < data->col_H*data->col_W; i++)
		{
			data->output[j*data->col_H*data->col_W + i] = data->col[j*data->col_H*data->col_W + i] * data->gamma[j] + data->beta[j];
			if (withRelu&&data->output[j*data->col_H*data->col_W + i] <= 0)
			{
					data->output[j*data->col_H*data->col_W + i] = 0;
			}
		}
	}
}

void maxpool(maxpoolParam*param)
{
	float *col = param->col;
	float *output = param->output;
	int b, i, j, k, m, n;
	int w_offset = -param->pad;
	int h_offset = -param->pad;
	int h = param->outH;
	int w = param->outW;
	int c = param->outC;
	int out_index = 0;
	for (k = 0; k < h; ++k) {
		for (i = 0; i < w; ++i) {
			for (j = 0; j < c; ++j) {
				float max = -FLT_MAX;
				int max_i = -1;
				for (n = 0; n < param->knlH; ++n) {
					for (m = 0; m < param->knlW; ++m) {
						int cur_c = j;
						int cur_h = h_offset + k*param->stride + n;
						int cur_w = w_offset + i*param->stride + m;

						int index = cur_c + param->outC*(cur_w + param->inW*cur_h);
						int valid = (cur_h >= 0 && cur_h < param->inH &&
							cur_w >= 0 && cur_w < param->inW);
						float val = (valid != 0) ? col[index] : -FLT_MAX;
						max_i = (val > max) ? index : max_i;
						max = (val > max) ? val : max;
					}
				}
				output[out_index++] = max;
			}
		}
	}
}
void Eltwise(EltwiseParam *data)
{
	memset(data->output, 0, data->shape[0] * data->shape[1] * data->shape[2] * sizeof(float));
	for (int j = 0; j < data->input.size(); j++)
	{
		for (int i = 0; i < data->shape[0] * data->shape[1] * data->shape[2]; i++)
		{
			data->output[i] += data->input[j][i];
		}
	}
}


void Normalize(normalizeParam *param)
{
	float *norm_input = param->norm_input;
	float *norm_output = param->norm_output;
	float *scale = param->scale;
	int across_spatial_ = param->across_spatial_;
	int channel_shared_ = param->channel_shared_;
	int channel = param->channel;
	int height = param->height;
	int width = param->width;
	if (across_spatial_)
	{
		double sum = 0;
		for (int i = 0; i < channel * height * width; i++)
		{
			sum += pow(*(norm_input + i), 2);
		}
		if (channel_shared_)
		{
			for (int i = 0; i < channel * height * width; i++)
			{
				*(norm_output + i) = *(norm_input + i) * scale[0] / sqrt(sum + 1e-5);
			}
		}
		else
		{
			for (int i = 0; i < channel * height * width; i++)
			{
				*(norm_output + i) = *(norm_input + i) * (*scale) / sqrt(sum + 1e-5);
				if (i % channel == 0)
				{
					++scale;
				}
			}
		}
	}
	else
	{
		for (int hw = 0; hw < height * width; hw++)
		{
			double sum = 0;
			for (int c = 0; c < channel; c++)
			{
				sum += pow(*(norm_input + c * height * width + hw), 2);
			}
			if (channel_shared_)
			{
				for (int c = 0; c < channel; c++)
				{
					*(norm_output + c * height * width + hw) = *(norm_input + c * height * width + hw) * scale[0] / sqrt(sum + 1e-5);
				}
			}
			else
			{
				for (int c = 0; c < channel; c++)
				{
					*(norm_output + c * height * width + hw) = *(norm_input + c * height * width + hw) * (*(scale + c)) / sqrt(sum + 1e-5);
				}
			}
		}
	}
}

void Concat(concatParam *param)
{
	vector<concatDataParam> dataParam = param->dataParam;
	vector<int> output_shape = param->shape;
	if (dataParam.size() == 1)
	{
		return;
	}
	int concat_axis_;
	if (param->concat_dim != -1)
	{
		concat_axis_ = param->concat_dim;
	}
	else
	{
		concat_axis_ = param->axis;
	}
	int num_concats_ = 1;
	for (int i = 0; i < concat_axis_; i++)
	{
		num_concats_ *= dataParam[i].shape[i];
	}
	int concat_input_size_ = 1;
	for (unsigned int i = concat_axis_ + 1; i < dataParam[0].shape.size(); i++)
	{
		concat_input_size_ *= dataParam[i].shape[i];
	}
	float *output_data = param->output_data;
	const int top_concat_axis = output_shape[concat_axis_];
	int offset_concat_axis = 0;
	for (unsigned int i = 0; i < dataParam.size(); i++)
	{
		float *input_data = dataParam[i].input_data;
		const int bottom_concat_axis = dataParam[i].shape[concat_axis_];
		for (int n = 0; n < num_concats_; n++)
		{
			for (int j = 0; j < bottom_concat_axis * concat_input_size_; j++)
			{
				output_data[(n * top_concat_axis + offset_concat_axis) * concat_input_size_ + j] = input_data[n * bottom_concat_axis * concat_input_size_ + j];
			}
		}
		offset_concat_axis += bottom_concat_axis;
	}
}

void Permute(permuteParam *param)
{
	vector<int> permute_order_ = param->orders;
	vector<int> bottom_shape = param->shape;
	int top_count = 1;
	vector<int> top_shape;
	vector<int> old_steps_(4, 1);
	vector<int> new_steps_(4, 1);
	float *input_data = param->input_data;
	float *output_data = param->output_data;
	int need_permute_ = 0;
	for (int i = 0; i < 4; i++)
	{
		if (permute_order_[i] != i)
		{
			need_permute_ = 1;
			break;
		}
	}
	if (need_permute_)
	{
		for (int i = 0; i < 4; i++)
		{
			if (i == 3)
			{
				old_steps_[i] = 1;
			}
			else
			{
				for (unsigned int j = i + 1; j < bottom_shape.size(); j++)
				{
					old_steps_[i] *= bottom_shape[j];
				}
			}
			top_shape.push_back(bottom_shape[permute_order_[i]]);
		}
		for (int i = 0; i < 4; i++)
		{
			if (i == 3)
			{
				new_steps_[i] = 1;
			}
			else
			{
				for (unsigned int j = i + 1; j < top_shape.size(); j++)
				{
					new_steps_[i] *= top_shape[j];
				}
			}
			top_count *= top_shape[i];
		}
		for (int i = 0; i < top_count; ++i)
		{
			int old_idx = 0;
			int idx = i;
			for (int j = 0; j < 4; j++)
			{
				int order = permute_order_[j];
				old_idx += (idx / new_steps_[j]) * old_steps_[order];
				idx %= new_steps_[j];
			}
			output_data[i] = input_data[old_idx];
		}
	}
}

void Softmax(softmaxParam *param)
{
	float *input_data = param->input_data;
	float *output_data = param->output_data;
	vector<int> shape = param->shape;
	int softmax_axis = param->axis;
	int outer_num = 1;
	int count = 1;
	int inner_num = 1;
	for (unsigned int i = 0; i < shape.size(); i++)
	{
		if ((int)i < softmax_axis)
		{
			outer_num *= shape[i];
		}
		count *= shape[i];
	}
	for (unsigned int i = softmax_axis + 1; i < shape.size(); i++)
	{
		inner_num *= shape[i];
	}
	float *sum_multiplier = new float[1 * shape[softmax_axis]];
	cout << shape[softmax_axis] << endl;
	for (int i = 0; i < shape[2]; i++)
	{
		sum_multiplier[i] = 1.0;
	}
	float *scale_data = new float[inner_num];
	int channel = shape[softmax_axis];
	int dim = count / outer_num;
	for (int i = 0; i < count; i++)
	{
		output_data[i] = input_data[i];
	}
	for (int i = 0; i < outer_num; i++)
	{
		for (int j = 0; j < inner_num; j++)
		{
			scale_data[j] = input_data[i * dim + j];
		}
		for (int j = 0; j < channel; j++)
		{
			for (int k = 0; k < inner_num; k++)
			{
				scale_data[k] = std::max(scale_data[k], input_data[i * dim + j * inner_num + k]);
			}
		}
		for (int a = 0; a < channel; a++)
		{
			for (int b = 0; b < inner_num; b++)
			{
				for (int c = 0; c < 1; c++)
				{
					output_data[a * inner_num + b] = 1.0 * output_data[a * inner_num + b] - 1.0 * sum_multiplier[a * 1 + c] * scale_data[c * inner_num + b];
				}
			}
		}
		for (int j = 0; j < dim; j++)
		{
			output_data[j] = exp(output_data[j]);
		}
		float sum = 0.0;
		for (int j = 0; j < shape[2]; j++)
		{
			sum += output_data[j];
		}
		//cout << "val: " << sum << endl;
		for (int j = 0; j < inner_num; j++)
		{
			//float sum = 0.0;
			//for (int k = 0; k < channel; k++)
			//{
			//	for (int c = 0; c < 1; c++)
			//	{
			//		sum += output_data[j * channel + k] * sum_multiplier[k * 1 + c];
			//	}
			//}
			scale_data[j] = sum;
		}
		//cout << "test: " << scale_data[0] << endl;
		for (int j = 0; j < channel; j++)
		{
			for (int k = 0; k < inner_num; k++)
			{
				output_data[k] = output_data[k] / scale_data[k];
			}
			output_data += inner_num;
		}
	}
	delete[] sum_multiplier;
	sum_multiplier = NULL;
	delete[] scale_data;
	scale_data = NULL;
}

void ReadLabelFromTextFile(const char* filename, map<int, string> *label_to_name, map<int, string> *label_to_display_name)
{
	ifstream input(filename);
	string oneline;
	string name;
	int label;
	string display_name;
	int pos;
	int pos1;
	int pos2;
	while (getline(input, oneline))
	{
		pos1 = oneline.find("name");
		pos2 = oneline.find("display_name");
		if (pos1 != -1 && pos2 == -1)
		{
			pos = oneline.find("\"");
			name = oneline.substr(pos + 1);
			pos = name.find("\"");
			name = name.substr(0, pos);
			getline(input, oneline);
			pos = oneline.find(":");
			label = atoi(oneline.substr(pos + 1).c_str());
			getline(input, oneline);
			pos = oneline.find("\"");
			display_name = oneline.substr(pos + 1);
			pos = display_name.find("\"");
			display_name = display_name.substr(0, pos);
			(*label_to_name)[label] = name;
			(*label_to_display_name)[label] = display_name;
		}
	}
	input.close();
}

#ifdef SSD

void PriorBox(priorBoxParam *param)
{
	int input_height = param->input_height;
	int input_width = param->input_width;
	int img_height = param->img_height;
	int img_width = param->img_width;
	float step_h = param->step_h;
	float step_w = param->step_w;
	vector<float> min_sizes_ = param->min_sizes_;
	vector<float> max_sizes_user = param->max_sizes_;
	vector<float> max_sizes_;
	vector<float> aspect_ratios_user = param->aspect_ratios_;
	vector<float> aspect_ratios_;
	int num_priors_ = param->num_priors_;
	int flip_ = param->flip_;
	int clip_ = param->clip_;
	vector<float> variance_user = param->variance_;
	vector<float> variance_;
	float offset_ = param->offset_;
	float *output_data = param->output_data;
	for (unsigned int i = 0; i < aspect_ratios_user.size(); i++)
	{
		float ar = aspect_ratios_user[i];
		int already_exist = 0;
		if (fabs(ar - 1.) < 1e-6)
		{
			already_exist = 1;
			break;
		}
		if (!already_exist)
		{
			aspect_ratios_.push_back(ar);
			if (flip_)
			{
				aspect_ratios_.push_back(1. / ar);
			}
		}
	}
	if (max_sizes_user.size() > 0)
	{
		for (unsigned int i = 0; i < max_sizes_user.size(); i++)
		{
			max_sizes_.push_back(max_sizes_user[i]);
			if (max_sizes_[i] == min_sizes_[i])
			{
				cout << "max_size must be greater than min_size." << endl;
			}
		}
	}
	if (variance_user.size() == 4)
	{
		for (unsigned int i = 0; i < variance_user.size(); i++)
		{
			if (variance_user[i] > 0)
			{
				variance_.push_back(variance_user[i]);
			}
		}
	}
	else if (variance_user.size() == 1)
	{
		if (variance_user[0] > 0)
		{
			variance_.push_back(variance_user[0]);
		}
	}
	else
	{
		variance_.push_back(0.1);
	}
	int dim = input_height * input_width * num_priors_ * 4;
	int idx = 0;
	for (int h = 0; h < input_height; h++)
	{
		for (int w = 0; w < input_width; w++)
		{
			float center_x = (w + offset_) * step_w;
			float center_y = (h + offset_) * step_h;
			float box_width, box_height;
			for (unsigned int s = 0; s < min_sizes_.size(); s++)
			{
				int min_size_ = min_sizes_[s];
				box_width = box_height = min_size_;
				// xmin
				output_data[idx++] = (center_x - box_width / 2.) / img_width;
				// ymin
				output_data[idx++] = (center_y - box_height / 2.) / img_height;
				// xmax
				output_data[idx++] = (center_x + box_width / 2.) / img_width;
				// ymax
				output_data[idx++] = (center_y + box_height / 2.) / img_height;
				if (max_sizes_.size() > 0)
				{
					int max_size_ = max_sizes_[s];
					// second prior: aspect_ratio = 1, size = sqrt(min_size * max_size)
					box_width = box_height = sqrt(min_size_ * max_size_);
					// xmin
					output_data[idx++] = (center_x - box_width / 2.) / img_width;
					// ymin
					output_data[idx++] = (center_y - box_height / 2.) / img_height;
					// xmax
					output_data[idx++] = (center_x + box_width / 2.) / img_width;
					// ymax
					output_data[idx++] = (center_y + box_height / 2.) / img_height;
				}
				for (unsigned int r = 0; r < aspect_ratios_.size(); ++r)
				{
					float ar = aspect_ratios_[r];
					box_width = min_size_ * sqrt(ar);
					box_height = min_size_ / sqrt(ar);
					// xmin
					output_data[idx++] = (center_x - box_width / 2.) / img_width;
					// ymin
					output_data[idx++] = (center_y - box_height / 2.) / img_height;
					// xmax
					output_data[idx++] = (center_x + box_width / 2.) / img_width;
					// ymax
					output_data[idx++] = (center_y + box_height / 2.) / img_height;
				}
			}
		}
	}
	if (clip_)
	{
		for (int d = 0; d < dim; ++d)
		{
			output_data[d] = std::min<float>(std::max<float>(output_data[d], 0.), 1.);
		}
	}
	output_data += input_height * input_width * num_priors_ * 4;
	if (variance_.size() == 1)
	{
		memset(output_data, variance_[0], sizeof(float) * dim);
	}
	else
	{
		int count = 0;
		for (int h = 0; h < input_height; ++h)
		{
			for (int w = 0; w < input_width; ++w)
			{
				for (int i = 0; i < num_priors_; ++i)
				{
					for (int j = 0; j < 4; ++j)
					{
						output_data[count] = variance_[j];
						++count;
					}
				}
			}
		}
	}
}


void GetLocPredictions(const float *loc_data, const int num, const int num_preds_per_class,
	const int num_loc_classes, const int share_location, vector<LabelBBox>* loc_preds)
{
	loc_preds->clear();
	loc_preds->resize(num);
	for (int i = 0; i < num; ++i)
	{
		LabelBBox& label_bbox = (*loc_preds)[i];
		for (int p = 0; p < num_preds_per_class; ++p)
		{
			int start_idx = p * num_loc_classes * 4;
			for (int c = 0; c < num_loc_classes; ++c)
			{
				int label = share_location ? -1 : c;
				if (label_bbox.find(label) == label_bbox.end())
				{
					label_bbox[label].resize(num_preds_per_class);
				}
				//size?
				label_bbox[label][p].size = -1;
				label_bbox[label][p].xmin = loc_data[start_idx + c * 4];
				label_bbox[label][p].ymin = loc_data[start_idx + c * 4 + 1];
				label_bbox[label][p].xmax = loc_data[start_idx + c * 4 + 2];
				label_bbox[label][p].ymax = loc_data[start_idx + c * 4 + 3];
			}
		}
		loc_data += num_preds_per_class * num_loc_classes * 4;
	}
}

void GetConfidenceScores(const float* conf_data, const int num,
	const int num_preds_per_class, const int num_classes, vector<map<int, vector<float> > >* conf_preds)
{
	conf_preds->clear();
	conf_preds->resize(num);
	for (int i = 0; i< num; ++i)
	{
		map<int, vector<float> >& label_scores = (*conf_preds)[i];
		for (int p = 0; p < num_preds_per_class; ++p)
		{
			int start_idx = p * num_classes;
			for (int c = 0; c < num_classes; ++c)
			{
				label_scores[c].push_back(conf_data[start_idx + c]);
			}
		}
		conf_data += num_preds_per_class * num_classes;
	}
}

float BBoxSize(const normalizedBBox& bbox, const int normalized = 1)
{
	if (bbox.xmax < bbox.xmin || bbox.ymax < bbox.ymin)
	{
		return 0;
	}
	else
	{
		if (bbox.size != -1)
		{
			return bbox.size;
		}
		else
		{
			float width = bbox.xmax - bbox.xmin;
			float height = bbox.ymax - bbox.ymin;
			if (normalized)
			{
				return width * height;
			}
			else
			{
				return (width + 1) * (height + 1);
			}
		}
	}
}

void GetPriorBBoxes(const float* prior_data, const int num_priors,
	vector<normalizedBBox>* prior_bboxes, vector<vector<float> >* prior_variances)
{
	prior_bboxes->clear();
	prior_variances->clear();
	for (int i = 0; i < num_priors; ++i)
	{
		int start_idx = i * 4;
		normalizedBBox bbox;
		bbox.size = -1;
		bbox.xmin = prior_data[start_idx];
		bbox.ymin = prior_data[start_idx + 1];
		bbox.xmax = prior_data[start_idx + 2];
		bbox.ymax = prior_data[start_idx + 3];
		float bbox_size = BBoxSize(bbox);
		bbox.size = bbox_size;
		prior_bboxes->push_back(bbox);
	}
	for (int i = 0; i < num_priors; ++i)
	{
		int start_idx = (num_priors + i) * 4;
		vector<float> var;
		for (int j = 0; j < 4; ++j)
		{
			var.push_back(prior_data[start_idx + j]);
		}
		prior_variances->push_back(var);
	}
}

void ClipBBox(const normalizedBBox& bbox, normalizedBBox* clip_bbox)
{
	clip_bbox->size = -1;
	clip_bbox->xmin = std::max(std::min(bbox.xmin, 1.f), 0.f);
	clip_bbox->ymin = std::max(std::min(bbox.ymin, 1.f), 0.f);
	clip_bbox->xmax = std::max(std::min(bbox.xmax, 1.f), 0.f);
	clip_bbox->ymax = std::max(std::min(bbox.ymax, 1.f), 0.f);
	clip_bbox->size = BBoxSize(*clip_bbox);
	clip_bbox->difficult = bbox.difficult;
}

void ClipBBox(const normalizedBBox& bbox, const float height, const float width,
	normalizedBBox* clip_bbox)
{
	clip_bbox->size = -1;
	clip_bbox->xmin = std::max(std::min(bbox.xmin, width), 0.f);
	clip_bbox->ymin = std::max(std::min(bbox.ymin, height), 0.f);
	clip_bbox->xmax = std::max(std::min(bbox.xmax, width), 0.f);
	clip_bbox->ymax = std::max(std::min(bbox.ymax, height), 0.f);
	clip_bbox->size = BBoxSize(*clip_bbox);
	clip_bbox->difficult = bbox.difficult;
}

void DecodeBBox(const normalizedBBox& prior_bbox, const vector<float>& prior_variance,
	const int code_type, const int variance_encoded_in_target, const int clip_bbox,
	const normalizedBBox& bbox, normalizedBBox* decode_bbox)
{
	if (code_type == CORNER)
	{
		if (variance_encoded_in_target)
		{
			decode_bbox->size = -1;
			decode_bbox->xmin = prior_bbox.xmin + bbox.xmin;
			decode_bbox->ymin = prior_bbox.ymin + bbox.ymin;
			decode_bbox->xmax = prior_bbox.xmax + bbox.xmax;
			decode_bbox->ymax = prior_bbox.ymax + bbox.ymax;
		}
		else
		{
			decode_bbox->size = -1;
			decode_bbox->xmin = prior_bbox.xmin + prior_variance[0] * bbox.xmin;
			decode_bbox->ymin = prior_bbox.ymin + prior_variance[1] * bbox.ymin;
			decode_bbox->xmax = prior_bbox.xmax + prior_variance[2] * bbox.xmax;
			decode_bbox->ymax = prior_bbox.ymax + prior_variance[3] * bbox.ymax;
		}
	}
	else if (code_type == CENTER_SIZE)
	{
		float prior_width = prior_bbox.xmax - prior_bbox.xmin;
		float prior_height = prior_bbox.ymax - prior_bbox.ymin;
		float prior_center_x = (prior_bbox.xmin + prior_bbox.xmax) / 2.0;
		float prior_center_y = (prior_bbox.ymin + prior_bbox.ymax) / 2.0;
		float decode_bbox_center_x, decode_bbox_center_y;
		float decode_bbox_width, decode_bbox_height;
		if (variance_encoded_in_target)
		{
			decode_bbox_center_x = bbox.xmin * prior_width + prior_center_x;
			decode_bbox_center_y = bbox.ymin * prior_height + prior_center_y;
			decode_bbox_width = exp(bbox.xmax) * prior_width;
			decode_bbox_height = exp(bbox.ymax) * prior_height;
		}
		else
		{
			decode_bbox_center_x = prior_variance[0] * bbox.xmin * prior_width + prior_center_x;
			decode_bbox_center_y = prior_variance[1] * bbox.ymin * prior_height + prior_center_y;
			decode_bbox_width = exp(prior_variance[2] * bbox.xmax) * prior_width;
			decode_bbox_height = exp(prior_variance[3] * bbox.ymax) * prior_height;
		}
		decode_bbox->size = -1;
		decode_bbox->xmin = decode_bbox_center_x - decode_bbox_width / 2.0;
		decode_bbox->ymin = decode_bbox_center_y - decode_bbox_height / 2.0;
		decode_bbox->xmax = decode_bbox_center_x + decode_bbox_width / 2.0;
		decode_bbox->ymax = decode_bbox_center_y + decode_bbox_height / 2.0;
	}
	else if (code_type == CORNER_SIZE)
	{
		float prior_width = prior_bbox.xmax - prior_bbox.xmin;
		float prior_height = prior_bbox.ymax - prior_bbox.ymin;
		if (variance_encoded_in_target)
		{
			decode_bbox->size = -1;
			decode_bbox->xmin = prior_bbox.xmin + bbox.xmin * prior_width;
			decode_bbox->ymin = prior_bbox.ymin + bbox.ymin * prior_height;
			decode_bbox->xmax = prior_bbox.xmax + bbox.xmax * prior_width;
			decode_bbox->ymax = prior_bbox.ymax + bbox.ymax * prior_height;
		}
		else
		{
			decode_bbox->size = -1;
			decode_bbox->xmin = prior_bbox.xmin + prior_variance[0] * bbox.xmin * prior_width;
			decode_bbox->ymin = prior_bbox.ymin + prior_variance[1] * bbox.ymin * prior_height;
			decode_bbox->xmax = prior_bbox.xmax + prior_variance[2] * bbox.xmax * prior_width;
			decode_bbox->ymax = prior_bbox.ymax + prior_variance[3] * bbox.ymax * prior_width;
		}
	}
	else
	{
		cout << "Unknown LocLossType." << endl;
	}
	float bbox_size = BBoxSize(*decode_bbox);
	decode_bbox->size = bbox_size;
	if (clip_bbox)
	{
		ClipBBox(*decode_bbox, decode_bbox);
	}
}

void DecodeBBoxes(const vector<normalizedBBox>& prior_bboxes, const vector<vector<float> >& prior_variances,
	const int code_type, const int variance_encoded_in_target, const int clip_bbox,
	const vector<normalizedBBox>& bboxes, vector<normalizedBBox>* decode_bboxes)
{
	int num_bboxes = prior_bboxes.size();
	decode_bboxes->clear();
	for (int i = 0; i < num_bboxes; ++i)
	{
		normalizedBBox decode_bbox;
		DecodeBBox(prior_bboxes[i], prior_variances[i], code_type,
			variance_encoded_in_target, clip_bbox, bboxes[i], &decode_bbox);
		decode_bboxes->push_back(decode_bbox);
	}
}

void DecodeBBoxesAll(const vector<LabelBBox>& all_loc_preds, const vector<normalizedBBox>& prior_bboxes,
	const vector<vector<float> >& prior_variances, const int num, const int shared_location,
	const int num_loc_classes, const int background_label_id, const int code_type,
	const int variance_encoded_in_target, const int clip, vector<LabelBBox>* all_decode_bboxes)
{
	all_decode_bboxes->clear();
	all_decode_bboxes->resize(num);
	for (int i = 0; i < num; ++i)
	{
		LabelBBox& decode_bboxes = (*all_decode_bboxes)[i];
		for (int c = 0; c < num_loc_classes; ++c)
		{
			int label = shared_location ? -1 : c;
			if (label == background_label_id)
			{
				continue;
			}
			if (all_loc_preds[i].find(label) == all_loc_preds[i].end())
			{
				cout << "Could not find location prediction for label: " << label << endl;
			}
			const vector<normalizedBBox>& label_loc_preds = all_loc_preds[i].find(label)->second;
			DecodeBBoxes(prior_bboxes, prior_variances, code_type, variance_encoded_in_target,
				clip, label_loc_preds, &(decode_bboxes[label]));
		}
	}
}

template <typename T>
bool SortScorePairDescend(const pair<float, T>& pair1, const pair<float, T>& pair2)
{
	return pair1.first > pair2.first;
}

template bool SortScorePairDescend(const pair<float, int>& pair1,
	const pair<float, int>& pair2);
template bool SortScorePairDescend(const pair<float, pair<int, int> >& pair1,
	const pair<float, pair<int, int> >& pair2);

void GetMaxScoreIndex(const vector<float>& scores, const float threshold,
	const int top_k, vector<pair<float, int> >* score_index_vec)
{
	for (unsigned int i = 0; i < scores.size(); ++i)
	{
		if (scores[i] > threshold)
		{
			score_index_vec->push_back(std::make_pair(scores[i], i));
		}
	}
	std::stable_sort(score_index_vec->begin(), score_index_vec->end(), SortScorePairDescend<int>);
	if (top_k > -1 && top_k < (int)score_index_vec->size())
	{
		score_index_vec->resize(top_k);
	}
}

void IntersectBBox(const normalizedBBox& bbox1, const normalizedBBox& bbox2, normalizedBBox* intersect_bbox)
{
	if (bbox2.xmin > bbox1.xmax || bbox2.xmax < bbox1.xmin ||
		bbox2.ymin > bbox1.ymax || bbox2.ymax < bbox1.ymin)
	{
		// Return [0, 0, 0, 0] if there is no intersection.
		intersect_bbox->size = -1;
		intersect_bbox->xmin = 0;
		intersect_bbox->ymin = 0;
		intersect_bbox->xmax = 0;
		intersect_bbox->ymax = 0;
	}
	else
	{
		intersect_bbox->size = -1;
		intersect_bbox->xmin = std::max(bbox1.xmin, bbox2.xmin);
		intersect_bbox->ymin = std::max(bbox1.ymin, bbox2.ymin);
		intersect_bbox->xmax = std::min(bbox1.xmax, bbox2.xmax);
		intersect_bbox->ymax = std::min(bbox1.ymax, bbox2.ymax);
	}
}

float JaccardOverlap(const normalizedBBox& bbox1, const normalizedBBox& bbox2, const int normalized = 1)
{
	normalizedBBox intersect_bbox;
	IntersectBBox(bbox1, bbox2, &intersect_bbox);
	float intersect_width, intersect_height;
	if (normalized)
	{
		intersect_width = intersect_bbox.xmax - intersect_bbox.xmin;
		intersect_height = intersect_bbox.ymax - intersect_bbox.ymin;
	}
	else
	{
		intersect_width = intersect_bbox.xmax - intersect_bbox.xmin + 1;
		intersect_height = intersect_bbox.ymax - intersect_bbox.ymin + 1;
	}
	if (intersect_width > 0 && intersect_height > 0)
	{
		float intersect_size = intersect_width * intersect_height;
		float bbox1_size = BBoxSize(bbox1);
		float bbox2_size = BBoxSize(bbox2);
		return intersect_size / (bbox1_size + bbox2_size - intersect_size);
	}
	else
	{
		return 0.;
	}
}

void ApplyNMSFast(const vector<normalizedBBox>& bboxes, const vector<float>& scores, const float score_threshold,
	const float nms_threshold, const float eta, const int top_k, vector<int>* indices)
{
	vector<pair<float, int> > score_index_vec;
	GetMaxScoreIndex(scores, score_threshold, top_k, &score_index_vec);
	float adaptive_threshold = nms_threshold;
	indices->clear();
	while (score_index_vec.size() != 0)
	{
		const int idx = score_index_vec.front().second;
		int keep = 1;
		for (unsigned int k = 0; k < indices->size(); ++k)
		{
			if (keep)
			{
				const int kept_idx = (*indices)[k];
				float overlap = JaccardOverlap(bboxes[idx], bboxes[kept_idx]);
				keep = overlap <= adaptive_threshold;
			}
			else
			{
				break;
			}
		}
		if (keep)
		{
			indices->push_back(idx);
		}
		score_index_vec.erase(score_index_vec.begin());
		if (keep && eta < 1 && adaptive_threshold > 0.5)
		{
			adaptive_threshold *= eta;
		}
	}
}

void ScaleBBox(const normalizedBBox& bbox, const int height, const int width, normalizedBBox* scale_bbox)
{
	scale_bbox->size = -1;
	scale_bbox->xmin = bbox.xmin * width;
	scale_bbox->ymin = bbox.ymin * height;
	scale_bbox->xmax = bbox.xmax * width;
	scale_bbox->ymax = bbox.ymax * height;
	int normalized = !(width > 1 || height > 1);
	scale_bbox->size = BBoxSize(*scale_bbox, normalized);
	scale_bbox->difficult = bbox.difficult;
}

int ProjectBBox(const normalizedBBox& src_bbox, const normalizedBBox& bbox, normalizedBBox* proj_bbox)
{
	if (bbox.xmin >= src_bbox.xmax || bbox.xmax <= src_bbox.xmin ||
		bbox.ymin >= src_bbox.ymax || bbox.ymax <= src_bbox.ymin)
	{
		return 0;
	}
	float src_width = src_bbox.xmax - src_bbox.xmin;
	float src_height = src_bbox.ymax - src_bbox.ymin;
	proj_bbox->size = -1;
	proj_bbox->xmin = (bbox.xmin - src_bbox.xmin) / src_width;
	proj_bbox->ymin = (bbox.ymin - src_bbox.ymin) / src_height;
	proj_bbox->xmax = (bbox.xmax - src_bbox.xmin) / src_width;
	proj_bbox->ymax = (bbox.ymax - src_bbox.ymin) / src_height;
	proj_bbox->difficult = bbox.difficult;
	ClipBBox(*proj_bbox, proj_bbox);
	if (BBoxSize(*proj_bbox) > 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void OutputBBox(const normalizedBBox& bbox, const pair<int, int>& img_size,
	const int has_resize, const resizeParameter& resize_param, normalizedBBox* out_bbox)
{
	const int height = img_size.first;
	const int width = img_size.second;
	normalizedBBox temp_bbox = bbox;
	int resize_mode = resize_param.resize_mode;
	if (resize_mode == -1)
	{
		resize_mode = WARP;
	}
	if (has_resize && resize_mode)
	{
		float resize_height = resize_param.height;
		if (resize_height == -1)
		{
			resize_height = 0.0;
		}
		float resize_width = resize_param.width;
		if (resize_width == -1)
		{
			resize_width = 0.0;
		}
		float resize_aspect = resize_width / resize_height;
		int height_scale = resize_param.height_scale;
		if (height_scale == -1)
		{
			height_scale = 0.0;
		}
		int width_scale = resize_param.width_scale;
		if (width_scale == -1)
		{
			width_scale = 0.0;
		}
		float aspect = static_cast<float>(width) / height;
		float padding;
		normalizedBBox source_bbox;
		switch (resize_mode)
		{
		case WARP:
			ClipBBox(temp_bbox, &temp_bbox);
			ScaleBBox(temp_bbox, height, width, out_bbox);
			break;
		case FIT_LARGE_SIZE_AND_PAD:
			if (aspect > resize_aspect)
			{
				padding = (resize_height - resize_width / aspect) / 2;
				source_bbox.xmin = 0.0;
				source_bbox.ymin = padding / resize_height;
				source_bbox.xmax = 1.0;
				source_bbox.ymax = 1.0 - padding / resize_height;
			}
			else
			{
				padding = (resize_width - resize_height * aspect) / 2;
				source_bbox.xmin = padding / resize_width;
				source_bbox.ymin = 0.0;
				source_bbox.xmax = 1.0 - padding / resize_width;
				source_bbox.ymax = 1.0;
			}
			ProjectBBox(source_bbox, bbox, &temp_bbox);
			ClipBBox(temp_bbox, &temp_bbox);
			ScaleBBox(temp_bbox, height, width, out_bbox);
			break;
		case FIT_SMALL_SIZE:
			if (height_scale == 0 || width_scale == 0)
			{
				ClipBBox(temp_bbox, &temp_bbox);
				ScaleBBox(temp_bbox, height, width, out_bbox);
				break;
			}
			else
			{
				ScaleBBox(temp_bbox, height_scale, width_scale, out_bbox);
				ClipBBox(*out_bbox, height, width, out_bbox);
			}
			break;
		default:
			cout << "Unknown resize mode. " << endl;
		}
	}
	else
	{
		ClipBBox(temp_bbox, &temp_bbox);
		ScaleBBox(temp_bbox, height, width, out_bbox);
	}
}

float* Detection_output(detectionParam *param, int &object_num)
{
	int num_classes = param->num_classes;
	int share_location = param->share_location;
	if (share_location == -1)
	{
		share_location = 1;
	}
	int num_loc_classes = share_location ? 1 : num_classes;
	int background_label_id = param->background_label_id;
	if (background_label_id == -1)
	{
		background_label_id = 0;
	}
	int code_type = param->code_type;
	if (code_type == -1)
	{
		code_type = CORNER;
	}
	int variance_encoded_in_target = param->variance_encoded_in_target;
	if (variance_encoded_in_target == -1)
	{
		variance_encoded_in_target = 0;
	}
	int keep_top_k = param->keep_top_k;
	float confidence_threshold = param->confidence_threshold;
	float nms_threshold = param->nms_threshold;
	if (nms_threshold == -1)
	{
		nms_threshold = 0.3;
	}
	float eta = param->eta;
	if (eta == -1)
	{
		eta = 1.0;
	}
	int top_k = param->top_k;
	vector<int> mbox_loc_shape = param->mbox_loc_shape;
	vector<int> mbox_conf_flatten_shape = param->mbox_conf_flatten_shape;
	vector<int> mbox_priorbox_shape = param->mbox_priorbox_shape;
	int num_priors = mbox_priorbox_shape[2] / 4;
	float *loc_data = param->loc_data;
	float *conf_data = param->conf_data;
	float *prior_data = param->prior_data;
	const int num = mbox_loc_shape[0];
	vector<LabelBBox> all_loc_preds;
	GetLocPredictions(loc_data, num, num_priors, num_loc_classes, share_location, &all_loc_preds);
	vector<map<int, vector<float> > > all_conf_scores;
	GetConfidenceScores(conf_data, num, num_priors, num_classes, &all_conf_scores);
	vector<normalizedBBox> prior_bboxes;
	vector<vector<float> > prior_variances;
	GetPriorBBoxes(prior_data, num_priors, &prior_bboxes, &prior_variances);
	vector<LabelBBox> all_decode_bboxes;
	const int clip_bbox = 0;
	DecodeBBoxesAll(all_loc_preds, prior_bboxes, prior_variances, num, share_location, num_loc_classes,
		background_label_id, code_type, variance_encoded_in_target, clip_bbox, &all_decode_bboxes);
	int num_kept = 0;
	vector<map<int, vector<int> > > all_indices;
	for (int i = 0; i < num; ++i)
	{
		const LabelBBox& decode_bboxes = all_decode_bboxes[i];
		const map<int, vector<float> >& conf_scores = all_conf_scores[i];
		map<int, vector<int> > indices;
		int num_det = 0;
		for (int c = 0; c < num_classes; ++c)
		{
			if (c == background_label_id)
			{
				continue;
			}
			if (conf_scores.find(c) == conf_scores.end())
			{
				cout << "Could not find confidence predictions for label " << c;
			}
			const vector<float>& scores = conf_scores.find(c)->second;
			int label = share_location ? -1 : c;
			if (decode_bboxes.find(label) == decode_bboxes.end())
			{
				cout << "Could not find location predictions for " << label;
				continue;
			}
			const vector<normalizedBBox>& bboxes = decode_bboxes.find(label)->second;
			ApplyNMSFast(bboxes, scores, confidence_threshold, nms_threshold, eta, top_k, &(indices[c]));
			num_det += indices[c].size();
		}
		if (keep_top_k > -1 && num_det > keep_top_k)
		{
			vector<pair<float, pair<int, int> > > score_index_pairs;
			for (map<int, vector<int> >::iterator it = indices.begin(); it != indices.end(); ++it)
			{
				int label = it->first;
				const vector<int>& label_indices = it->second;
				if (conf_scores.find(label) == conf_scores.end())
				{
					cout << "Could not find location predictions for " << label << endl;
					continue;
				}
				const vector<float>& scores = conf_scores.find(label)->second;
				for (unsigned int j = 0; j < label_indices.size(); ++j)
				{
					int idx = label_indices[j];
					score_index_pairs.push_back(std::make_pair(scores[idx], std::make_pair(label, idx)));
				}
			}
			std::sort(score_index_pairs.begin(), score_index_pairs.end(), SortScorePairDescend<pair<int, int> >);
			score_index_pairs.resize(keep_top_k);
			map<int, vector<int> > new_indices;
			for (unsigned int j = 0; j < score_index_pairs.size(); ++j)
			{
				int label = score_index_pairs[j].second.first;
				int idx = score_index_pairs[j].second.second;
				new_indices[label].push_back(idx);
			}
			all_indices.push_back(new_indices);
			num_kept += keep_top_k;
		}
		else
		{
			all_indices.push_back(indices);
			num_kept += num_det;
		}
	}
	object_num = num_kept;
	float *top_data;
	if (num_kept == 0)
	{
		cout << "Could not find any detections" << endl;
		top_data = new float[1 * 1 * num * 7];
		int top_count = 1 * 1 * num * 7;
		memset(top_data, -1, top_count);
		for (int i = 0; i < num; ++i)
		{
			top_data[0] = i;
			top_data += 7;
		}
	}
	else
	{
		top_data = new float[1 * 1 * num_kept * 7];
	}
	int count = 0;
	for (int i = 0; i < num; ++i)
	{
		const map<int, vector<float> >& conf_scores = all_conf_scores[i];
		const LabelBBox& decode_bboxes = all_decode_bboxes[i];
		for (map<int, vector<int> >::iterator it = all_indices[i].begin(); it != all_indices[i].end(); ++it)
		{
			int label = it->first;
			if (conf_scores.find(label) == conf_scores.end())
			{
				cout << "Could not find confidence predictions for " << label << endl;
				continue;
			}
			const vector<float>& scores = conf_scores.find(label)->second;
			int loc_label = share_location ? -1 : label;
			if (decode_bboxes.find(loc_label) == decode_bboxes.end())
			{
				cout << "Could not find location predictions for " << loc_label << endl;
				continue;
			}
			const vector<normalizedBBox>& bboxes = decode_bboxes.find(loc_label)->second;
			vector<int>& indices = it->second;
			for (unsigned int j = 0; j < indices.size(); ++j)
			{
				int idx = indices[j];
				top_data[count * 7] = i;
				top_data[count * 7 + 1] = label;
				top_data[count * 7 + 2] = scores[idx];
				const normalizedBBox& bbox = bboxes[idx];
				top_data[count * 7 + 3] = bbox.xmin;
				top_data[count * 7 + 4] = bbox.ymin;
				top_data[count * 7 + 5] = bbox.xmax;
				top_data[count * 7 + 6] = bbox.ymax;
				++count;
			}
		}
	}
	return top_data;
}


#endif // SSD

#ifdef YOLO



static inline float stair_activate(float x)
{
	int n = floor(x);
	if (n % 2 == 0) return floor(x / 2.);
	else return (x - n) + floor(x / 2.);
}
static inline float hardtan_activate(float x)
{
	if (x < -1) return -1;
	if (x > 1) return 1;
	return x;
}
static inline float linear_activate(float x) { return x; }
static inline float logistic_activate(float x) { return 1. / (1. + exp(-x)); }
static inline float loggy_activate(float x) { return 2. / (1. + exp(-x)) - 1; }
static inline float relu_activate(float x) { return x*(x>0); }
static inline float elu_activate(float x) { return (x >= 0)*x + (x < 0)*(exp(x) - 1); }
static inline float relie_activate(float x) { return (x>0) ? x : .01*x; }
static inline float ramp_activate(float x) { return x*(x>0) + .1*x; }
static inline float leaky_activate(float x) { return (x>0) ? x : .1*x; }
static inline float tanh_activate(float x) { return (exp(2 * x) - 1) / (exp(2 * x) + 1); }
static inline float plse_activate(float x)
{
	if (x < -4) return .01 * (x + 4);
	if (x > 4)  return .01 * (x - 4) + 1;
	return .125*x + .5;
}
static inline float lhtan_activate(float x)
{
	if (x < 0) return .001*x;
	if (x > 1) return .001*(x - 1) + 1;
	return x;
}
static inline float lhtan_gradient(float x)
{
	if (x > 0 && x < 1) return 1;
	return .001;
}
static inline float hardtan_gradient(float x)
{
	if (x > -1 && x < 1) return 1;
	return 0;
}
static inline float linear_gradient(float x) { return 1; }
static inline float logistic_gradient(float x) { return (1 - x)*x; }
static inline float loggy_gradient(float x)
{
	float y = (x + 1.) / 2.;
	return 2 * (1 - y)*y;
}
static inline float stair_gradient(float x)
{
	if (floor(x) == x) return 0;
	return 1;
}
static inline float relu_gradient(float x) { return (x>0); }
static inline float elu_gradient(float x) { return (x >= 0) + (x < 0)*(x + 1); }
static inline float relie_gradient(float x) { return (x>0) ? 1 : .01; }
static inline float ramp_gradient(float x) { return (x>0) + .1; }
static inline float leaky_gradient(float x) { return (x>0) ? 1 : .1; }
static inline float tanh_gradient(float x) { return 1 - x*x; }
static inline float plse_gradient(float x) { return (x < 0 || x > 1) ? .01 : .125; }

float activate(float x, ACTIVATION a)
{
	switch (a) {
	case LINEAR:
		return linear_activate(x);
	case LOGISTIC:
		return logistic_activate(x);
	case LOGGY:
		return loggy_activate(x);
	case RELU:
		return relu_activate(x);
	case ELU:
		return elu_activate(x);
	case RELIE:
		return relie_activate(x);
	case RAMP:
		return ramp_activate(x);
	case LEAKY:
		return leaky_activate(x);
	case TANH:
		return tanh_activate(x);
	case PLSE:
		return plse_activate(x);
	case STAIR:
		return stair_activate(x);
	case HARDTAN:
		return hardtan_activate(x);
	case LHTAN:
		return lhtan_activate(x);
	}
	return 0;
}

void activate_array(float *x, const int n, const ACTIVATION a)
{
	int i;
	for (i = 0; i < n; ++i) {
		x[i] = activate(x[i], a);
	}
}

void yolo(yoloParam*param)
{
	float *col = param->col;
	float *output = param->output;
	memcpy(output, col, param->C * param->H * param->W * sizeof(float));

	for (int n = 0; n < 3; ++n) //3为每个感受野上的box个数
	{
		int index = n* (param->classes + 4 + 1) * param->H * param->W;
		activate_array(output + index, 2 * param->H * param->W, LOGISTIC);
		index = n* (param->classes + 4 + 1) * param->H * param->W + param->H * param->W * 4;
		activate_array(output + index, (1 + param->classes)*param->H * param->W, LOGISTIC);
	}
}

void upsample(upsampleParam*param)
{
	float *col = param->col;
	float *output = param->output;
	int i, j, k;
	int out_index = 0;
	for (k = 0; k < param->c; ++k) {
		for (j = 0; j < param->h*param->stride; ++j) {
			for (i = 0; i < param->w*param->stride; ++i) {
				int in_index = k*param->w*param->h + (j / param->stride)*param->w + i / param->stride;
				int out_index = k*param->w*param->h*param->stride*param->stride + j*param->w*param->stride + i;
				output[out_index] = param->scale*col[in_index];
			}
		}
	}

}

int entry_index(detectionDataParam l, int batch, int location, int entry)
{
	int n = location / (l.shape[0] * l.shape[1]);
	int loc = location % (l.shape[0] * l.shape[1]);
	return batch*l.shape[0] * l.shape[1] * l.shape[2] + n*l.shape[0] * l.shape[1] * (4 + l.classes + 1) + entry*l.shape[0] * l.shape[1] + loc;

}

int yolo_num_detections(detectionDataParam l, float thresh)
{
	int i, n;
	int count = 0;
	for (i = 0; i < l.shape[0] * l.shape[1]; ++i) {
		for (n = 0; n < 3; ++n) {
			int obj_index = entry_index(l, 0, n*l.shape[0] * l.shape[1] + i, 4);
			if (l.input_data[obj_index] > thresh) {
				++count;
			}
		}
	}
	return count;

}

int num_detections(detectionParam  net, float thresh)
{
	int i;
	int s = 0;
	for (i = 0; i < net.shape[3]; i++)
	{
		detectionDataParam l = net.dataParam[i];
		s += yolo_num_detections(l, thresh);

	}
	return s;

}

detection * make_network_boxes(detectionParam net, float thresh, int * num)
{
	detectionDataParam l = net.dataParam[0];
	int i;
	int nboxes = num_detections(net, thresh);
	if (num) *num = nboxes;
	detection *dets = new detection[nboxes];// memset(nboxes, sizeof(detection));
	for (i = 0; i < nboxes; ++i) {
		dets[i].prob = new float[l.classes];
	}
	return dets;
}

box get_yolo_box(float * x, vector<int> biases, int n, int index, int i, int j, int lw, int lh, int w, int h, int stride)
{
	box b;
	b.x = (i + x[index + 0 * stride]) / lw;
	b.y = (j + x[index + 1 * stride]) / lh;
	b.w = exp(x[index + 2 * stride]) * biases[2 * n] / w;
	b.h = exp(x[index + 3 * stride]) * biases[2 * n + 1] / h;
	return b;

}

void correct_yolo_boxes(detection *dets, int n, int w, int h, int netw, int neth, int relative, int letter)
{
	int i;
	int new_w = 0;
	int new_h = 0;
	if (letter) {
		if (((float)netw / w) < ((float)neth / h)) {
			new_w = netw;
			new_h = (h * netw) / w;
		}
		else {
			new_h = neth;
			new_w = (w * neth) / h;
		}
	}
	else {
		new_w = netw;
		new_h = neth;
	}
	for (i = 0; i < n; ++i) {
		box b = dets[i].bbox;
		b.x = (b.x - (netw - new_w) / 2. / netw) / ((float)new_w / netw);
		b.y = (b.y - (neth - new_h) / 2. / neth) / ((float)new_h / neth);
		b.w *= (float)netw / new_w;
		b.h *= (float)neth / new_h;
		if (!relative) {
			b.x *= w;
			b.w *= w;
			b.y *= h;
			b.h *= h;
		}
		dets[i].bbox = b;
	}
}

int get_yolo_detections(detectionDataParam l, int w, int h, int netw, int neth, float thresh, int relative, detection *dets, int letter)
{
	int i, j, n;
	float *predictions = l.input_data;
	int count = 0;
	for (i = 0; i < l.shape[0] * l.shape[1]; ++i) {
		int row = i / l.shape[0];
		int col = i % l.shape[0];
		for (n = 0; n < 3; ++n) {
			int obj_index = entry_index(l, 0, n*l.shape[0] * l.shape[1] + i, 4);
			float objectness = predictions[obj_index];
			if (objectness <= thresh) continue;
			int box_index = entry_index(l, 0, n*l.shape[0] * l.shape[1] + i, 0);
			dets[count].bbox = get_yolo_box(predictions, l.anchor, l.mask[n], box_index, col, row, l.shape[0], l.shape[1], netw, neth, l.shape[0] * l.shape[1]);
			dets[count].objectness = objectness;
			dets[count].classes = l.classes;
			for (j = 0; j < l.classes; ++j) {
				int class_index = entry_index(l, 0, n*l.shape[0] * l.shape[1] + i, 4 + 1 + j);
				float prob = objectness*predictions[class_index];
				dets[count].prob[j] = (prob > thresh) ? prob : 0;
			}
			++count;
		}
	}
	correct_yolo_boxes(dets, count, w, h, netw, neth, relative, letter);
	return count;
}

void fill_network_boxes(detectionParam net, int w, int h, float thresh, float hier, int relative, detection *dets, int letter)
{
	int prev_classes = -1;
	int j;
	for (j = 0; j < net.shape[3]; ++j) {
		detectionDataParam l = net.dataParam[j];
		int count = get_yolo_detections(l, w, h, net.shape[0], net.shape[1], thresh, relative, dets, letter);
		dets += count;
		if (prev_classes < 0) prev_classes = l.classes;
		else if (prev_classes != l.classes) {
			printf(" Error: Different [yolo] layers have different number of classes = %d and %d - check your cfg-file! \n",
				prev_classes, l.classes);
		}
	}
}

detection *get_network_boxes(detectionParam net, int w, int h, float thresh, float hier, int relative, int *num, int letter)
{
	detection *dets = make_network_boxes(net, thresh, num);
	fill_network_boxes(net, w, h, thresh, hier, relative, dets, letter);
	return dets;
}

int nms_comparator_v3(const void *pa, const void *pb)
{
	detection a = *(detection *)pa;
	detection b = *(detection *)pb;
	float diff = 0;
	if (b.sort_class >= 0) {
		diff = a.prob[b.sort_class] - b.prob[b.sort_class];
	}
	else {
		diff = a.objectness - b.objectness;
	}
	if (diff < 0) return 1;
	else if (diff > 0) return -1;
	return 0;
}
float overlap(float x1, float w1, float x2, float w2)
{
	float l1 = x1 - w1 / 2;
	float l2 = x2 - w2 / 2;
	float left = l1 > l2 ? l1 : l2;
	float r1 = x1 + w1 / 2;
	float r2 = x2 + w2 / 2;
	float right = r1 < r2 ? r1 : r2;
	return right - left;
}
float box_intersection(box a, box b)
{
	float w = overlap(a.x, a.w, b.x, b.w);
	float h = overlap(a.y, a.h, b.y, b.h);
	if (w < 0 || h < 0) return 0;
	float area = w*h;
	return area;
}
float box_union(box a, box b)
{
	float i = box_intersection(a, b);
	float u = a.w*a.h + b.w*b.h - i;
	return u;
}

float box_iou(box a, box b)
{
	return box_intersection(a, b) / box_union(a, b);
}

void do_nms_sort(detection *dets, int total, int classes, float thresh)
{
	int i, j, k;
	k = total - 1;
	for (i = 0; i <= k; ++i) {
		if (dets[i].objectness == 0) {
			detection swap = dets[i];
			dets[i] = dets[k];
			dets[k] = swap;
			--k;
			--i;
		}
	}
	total = k + 1;

	for (k = 0; k < classes; ++k) {
		for (i = 0; i < total; ++i) {
			dets[i].sort_class = k;
		}
		qsort(dets, total, sizeof(detection), nms_comparator_v3);
		for (i = 0; i < total; ++i) {
			//printf("  k = %d, \t i = %d \n", k, i);
			if (dets[i].prob[k] == 0) continue;
			box a = dets[i].bbox;
			for (j = i + 1; j < total; ++j) {
				box b = dets[j].bbox;
				if (box_iou(a, b) > thresh) {
					dets[j].prob[k] = 0;
				}
			}
		}
	}
}

#endif // YOLO