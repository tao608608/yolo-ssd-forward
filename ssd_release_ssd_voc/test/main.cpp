//#include <sys/time.h>
//#include <opencv2/opencv.hpp>
#include "layer.h"
using namespace std;

//如果需要验证代码是否正确，可以把这个设置为1，这样conv8_1层的输出就会保存为一个文本文件



int main1()
{
	vector<int> vec;

//#ifdef SSD
//
//
//		int img_heighteight = 224;
//		int img_widthidth = 224;
//		//struct timeval startfc;
//		//struct timeval endfc;
//		//long startfctt;
//		//long endfctt;
//
//		//start init fc6
//
//		int pool5_output_channel = 512;
//		int pool5_output_height = 7;
//		int pool5_output_width = 7;
//		int fc6_output_channel = 1024;
//		int fc6_kernel_height = 3;
//		int fc6_kernel_width = 3;
//		int fc6_output_height = 7;
//		int fc6_output_width = 7;
//		int fc6_pad_height = 1;
//		int fc6_pad_width = 1;
//		int fc6_stride_height = 1;
//		int fc6_stride_width = 1;
//		int fc6_dilation_height = 1;
//		int fc6_dilation_width = 1;
//		int fc6_withRELU = 1;
//
//
//		//vector<float>pool5_output [512 * 7 * 7];
//		float *pool5_output = new float[pool5_output_channel * pool5_output_height * pool5_output_width];
//		vec.push_back(0);
//		readFile("data/pool5_output", pool5_output, pool5_output_channel * pool5_output_height * pool5_output_width * 4);
//		float *fc6_coef = new float[pool5_output_channel * fc6_output_channel * fc6_kernel_height * fc6_kernel_width];
//		float *fc6_new_coef = new float[pool5_output_channel * fc6_output_channel * fc6_kernel_height * fc6_kernel_width];
//		float *fc6_bias = new float[fc6_output_channel];
//		float *pool5_output_col = new float[pool5_output_channel * fc6_kernel_height * fc6_kernel_width * fc6_output_height * fc6_output_width];
//		float *fc6_output = new float[fc6_output_channel * fc6_output_height * fc6_output_width];
//		readFile1("./data/fc.bin", fc6_coef, pool5_output_channel * fc6_output_channel * fc6_kernel_height * fc6_kernel_width * sizeof(float), vec);
//		vec.push_back(pool5_output_channel * fc6_output_channel * fc6_kernel_height * fc6_kernel_width * sizeof(float));
//		readFile1("./data/fc.bin", fc6_bias, fc6_output_channel * sizeof(float), vec);
//		vec.push_back(fc6_output_channel * sizeof(float));
//		Row_column_transpose(fc6_coef, fc6_new_coef, fc6_output_channel, pool5_output_channel * fc6_kernel_height * fc6_kernel_width);
//		//end init fc6
//
//
//
//
//
//
//		//start init fc7
//		int fc7_output_channel = 1024;
//		int fc7_kernel_height = 1;
//		int fc7_kernel_width = 1;
//		int fc7_output_height = 7;
//		int fc7_output_width = 7;
//		int fc7_pad_height = 0;
//		int fc7_pad_width = 0;
//		int fc7_stride_height = 1;
//		int fc7_stride_width = 1;
//		int fc7_dilation_height = 1;
//		int fc7_dilation_width = 1;
//		int fc7_withRELU = 1;
//
//
//		float *fc7_coef = new float[fc6_output_channel * fc7_output_channel * fc7_kernel_height * fc7_kernel_width];
//		float *fc7_new_coef = new float[fc6_output_channel * fc7_output_channel * fc7_kernel_height * fc7_kernel_width];
//		float *fc7_bias = new float[fc7_output_channel];
//		float *fc6_output_col = new float[fc7_output_height * fc7_output_width * fc6_output_channel * fc7_kernel_height * fc7_kernel_width];
//		float *fc7_output = new float[fc7_output_channel * fc7_output_height * fc7_output_width];
//		float *fc7_output_transpose = new float[fc7_output_channel * fc7_output_height * fc7_output_width];
//		readFile1("./data/fc.bin", fc7_coef, fc6_output_channel * fc7_output_channel * fc7_kernel_height * fc7_kernel_width * sizeof(float), vec);
//		vec.push_back(fc6_output_channel * fc7_output_channel * fc7_kernel_height * fc7_kernel_width * sizeof(float));
//		readFile1("./data/fc.bin", fc7_bias, fc7_output_channel * sizeof(float), vec);
//		vec.push_back(fc7_output_channel * sizeof(float));
//
//		Row_column_transpose(fc7_coef, fc7_new_coef, fc7_output_channel, fc6_output_channel * fc7_kernel_height * fc7_kernel_width);
//		//end init fc7
//
//
//
//		//start init conv6_1
//		int conv6_1_output_channel = 256;
//		int conv6_1_kernel_height = 1;
//		int conv6_1_kernel_width = 1;
//		int conv6_1_output_height = 7;
//		int conv6_1_output_width = 7;
//
//		int conv6_1_pad_height = 0;
//		int conv6_1_pad_width = 0;
//		int conv6_1_stride_height = 1;
//		int conv6_1_stride_width = 1;
//		int conv6_1_dilation_height = 1;
//		int conv6_1_dilation_width = 1;
//		int conv6_1_withRELU = 1;
//
//		float *conv6_1_coef = new float[fc7_output_channel * conv6_1_output_channel * conv6_1_kernel_height * conv6_1_kernel_width];
//		float *conv6_1_new_coef = new float[fc7_output_channel * conv6_1_output_channel * conv6_1_kernel_height * conv6_1_kernel_width];
//		float *conv6_1_bias = new float[conv6_1_output_channel];
//		float *fc7_output_col = new float[fc7_output_channel * conv6_1_kernel_height * conv6_1_kernel_width * conv6_1_output_height * conv6_1_output_width];
//		float *conv6_1_output = new float[conv6_1_output_channel * conv6_1_output_height * conv6_1_output_width];
//		readFile1("./data/fc.bin", conv6_1_coef, fc7_output_channel * conv6_1_output_channel * conv6_1_kernel_height * conv6_1_kernel_width * sizeof(float), vec);
//		vec.push_back(fc7_output_channel * conv6_1_output_channel * conv6_1_kernel_height * conv6_1_kernel_width * sizeof(float));
//		readFile1("./data/fc.bin", conv6_1_bias, conv6_1_output_channel * sizeof(float), vec);
//		vec.push_back(conv6_1_output_channel * sizeof(float));
//		Row_column_transpose(conv6_1_coef, conv6_1_new_coef, conv6_1_output_channel, fc7_output_channel * conv6_1_kernel_height * conv6_1_kernel_width);
//		//end init conv6_1
//
//
//		//start init conv6_2
//		int conv6_2_output_channel = 512;
//		int conv6_2_kernel_height = 3;
//		int conv6_2_kernel_width = 3;
//		int conv6_2_output_height = 4;
//		int conv6_2_output_width = 4;
//		int conv6_2_pad_height = 1;
//		int conv6_2_pad_width = 1;
//		int conv6_2_stride_height = 2;
//		int conv6_2_stride_width = 2;
//		int conv6_2_dilation_height = 1;
//		int conv6_2_dilation_width = 1;
//		int conv6_2_withRELU = 1;
//
//		float *conv6_2_coef = new float[conv6_1_output_channel * conv6_2_output_channel * conv6_2_kernel_height * conv6_2_kernel_width];
//		float *conv6_2_new_coef = new float[conv6_1_output_channel * conv6_2_output_channel * conv6_2_kernel_height * conv6_2_kernel_width];
//		float *conv6_2_bias = new float[conv6_2_output_channel];
//		float *conv6_1_output_col = new float[conv6_1_output_channel * conv6_2_kernel_height * conv6_2_kernel_width * conv6_2_output_height * conv6_2_output_width];
//		float *conv6_2_output = new float[conv6_2_output_channel * conv6_2_output_height * conv6_2_output_width];
//		readFile1("./data/fc.bin", conv6_2_coef, conv6_1_output_channel * conv6_2_output_channel * conv6_2_kernel_height * conv6_2_kernel_width * sizeof(float), vec);
//		vec.push_back(conv6_1_output_channel * conv6_2_output_channel * conv6_2_kernel_height * conv6_2_kernel_width * sizeof(float));
//		readFile1("./data/fc.bin", conv6_2_bias, conv6_2_output_channel * sizeof(float), vec);
//		vec.push_back(conv6_2_output_channel * sizeof(float));
//		Row_column_transpose(conv6_2_coef, conv6_2_new_coef, conv6_2_output_channel, conv6_1_output_channel * conv6_2_kernel_height * conv6_2_kernel_width);
//		//end init conv6_2
//
//
//		//start init conv7_1
//		int conv7_1_output_channel = 128;
//		int conv7_1_kernel_height = 1;
//		int conv7_1_kernel_width = 1;
//		int conv7_1_output_height = 4;
//		int conv7_1_output_width = 4;
//
//		int conv7_1_pad_height = 0;
//		int conv7_1_pad_width = 0;
//		int conv7_1_stride_height = 1;
//		int conv7_1_stride_width = 1;
//		int conv7_1_dilation_height = 1;
//		int conv7_1_dilation_width = 1;
//		int conv7_1_withRELU = 1;
//
//		float *conv7_1_coef = new float[conv6_2_output_channel * conv7_1_output_channel * conv7_1_kernel_height * conv7_1_kernel_width];
//		float *conv7_1_new_coef = new float[conv6_2_output_channel * conv7_1_output_channel * conv7_1_kernel_height * conv7_1_kernel_width];
//		float *conv7_1_bias = new float[conv7_1_output_channel];
//		float *conv6_2_output_col = new float[conv6_2_output_channel * conv7_1_kernel_height * conv7_1_kernel_width * conv7_1_output_height * conv7_1_output_width];
//		float *conv7_1_output = new float[conv7_1_output_channel * conv7_1_output_height * conv7_1_output_width];
//		readFile1("./data/fc.bin", conv7_1_coef, conv6_2_output_channel * conv7_1_output_channel * conv7_1_kernel_height * conv7_1_kernel_width * sizeof(float), vec);
//		vec.push_back(conv6_2_output_channel * conv7_1_output_channel * conv7_1_kernel_height * conv7_1_kernel_width * sizeof(float));
//		readFile1("./data/fc.bin", conv7_1_bias, conv7_1_output_channel * sizeof(float), vec);
//		vec.push_back(conv7_1_output_channel * sizeof(float));
//		Row_column_transpose(conv7_1_coef, conv7_1_new_coef, conv7_1_output_channel, conv6_2_output_channel * conv7_1_kernel_height * conv7_1_kernel_width);
//		//end init conv7_1
//
//
//		//start init conv7_2
//		int conv7_2_output_channel = 256;
//		int conv7_2_kernel_height = 3;
//		int conv7_2_kernel_width = 3;
//		int conv7_2_output_height = 2;
//		int conv7_2_output_width = 2;
//		int conv7_2_pad_height = 1;
//		int conv7_2_pad_width = 1;
//		int conv7_2_stride_height = 2;
//		int conv7_2_stride_width = 2;
//		int conv7_2_dilation_height = 1;
//		int conv7_2_dilation_width = 1;
//		int conv7_2_withRELU = 1;
//
//		float *conv7_2_coef = new float[conv7_1_output_channel * conv7_2_output_channel * conv7_2_kernel_height * conv7_2_kernel_width];
//		float *conv7_2_new_coef = new float[conv7_1_output_channel * conv7_2_output_channel * conv7_2_kernel_height * conv7_2_kernel_width];
//		float *conv7_2_bias = new float[conv7_2_output_channel];
//		float *conv7_1_output_col = new float[conv7_1_output_channel * conv7_2_kernel_height * conv7_2_kernel_width * conv7_2_output_height * conv7_2_output_width];
//		float *conv7_2_output = new float[conv7_2_output_channel * conv7_2_output_height * conv7_2_output_width];
//		readFile1("./data/fc.bin", conv7_2_coef, conv7_1_output_channel * conv7_2_output_channel * conv7_2_kernel_height * conv7_2_kernel_width * sizeof(float), vec);
//		vec.push_back(conv7_1_output_channel * conv7_2_output_channel * conv7_2_kernel_height * conv7_2_kernel_width * sizeof(float));
//		readFile1("./data/fc.bin", conv7_2_bias, conv7_2_output_channel * sizeof(float), vec);
//		vec.push_back(conv7_2_output_channel * sizeof(float));
//		Row_column_transpose(conv7_2_coef, conv7_2_new_coef, conv7_2_output_channel, conv7_1_output_channel * conv7_2_kernel_height * conv7_2_kernel_width);
//		//end init conv7_2
//
//
//		//start init conv8_1
//		int conv8_1_output_channel = 128;
//		int conv8_1_kernel_height = 1;
//		int conv8_1_kernel_width = 1;
//		int conv8_1_output_height = 2;
//		int conv8_1_output_width = 2;
//		int conv8_1_pad_height = 0;
//		int conv8_1_pad_width = 0;
//		int conv8_1_stride_height = 1;
//		int conv8_1_stride_width = 1;
//		int conv8_1_dilation_height = 1;
//		int conv8_1_dilation_width = 1;
//		int conv8_1_withRELU = 1;
//
//		float *conv8_1_coef = new float[conv7_2_output_channel * conv8_1_output_channel * conv8_1_kernel_height * conv8_1_kernel_width];
//		float *conv8_1_new_coef = new float[conv7_2_output_channel * conv8_1_output_channel * conv8_1_kernel_height * conv8_1_kernel_width];
//		float *conv8_1_bias = new float[conv8_1_output_channel];
//		float *conv7_2_output_col = new float[conv7_2_output_channel * conv8_1_kernel_height * conv8_1_kernel_width * conv8_1_output_height * conv8_1_output_width];
//		float *conv8_1_output = new float[conv8_1_output_channel * conv8_1_output_height * conv8_1_output_width];
//		readFile1("./data/fc.bin", conv8_1_coef, conv7_2_output_channel * conv8_1_output_channel * conv8_1_kernel_height * conv8_1_kernel_width * sizeof(float), vec);
//		vec.push_back(conv7_2_output_channel * conv8_1_output_channel * conv8_1_kernel_height * conv8_1_kernel_width * sizeof(float));
//		readFile1("./data/fc.bin", conv8_1_bias, conv8_1_output_channel * sizeof(float), vec);
//		vec.push_back(conv8_1_output_channel * sizeof(float));
//		Row_column_transpose(conv8_1_coef, conv8_1_new_coef, conv8_1_output_channel, conv7_2_output_channel * conv8_1_kernel_height * conv8_1_kernel_width);
//		//end init conv8_1
//
//		//start init conv8_2
//		int conv8_2_output_channel = 256;
//		int conv8_2_kernel_height = 3;
//		int conv8_2_kernel_width = 3;
//		int conv8_2_output_height = 1;
//		int conv8_2_output_width = 1;
//		int conv8_2_pad_height = 1;
//		int conv8_2_pad_width = 1;
//		int conv8_2_stride_height = 2;
//		int conv8_2_stride_width = 2;
//		int conv8_2_dilation_height = 1;
//		int conv8_2_dilation_width = 1;
//		int conv8_2_withRELU = 1;
//
//		float *conv8_2_coef = new float[conv7_1_output_channel * conv8_2_output_channel * conv8_2_kernel_height * conv8_2_kernel_width];
//		float *conv8_2_new_coef = new float[conv7_1_output_channel * conv8_2_output_channel * conv8_2_kernel_height * conv8_2_kernel_width];
//		float *conv8_2_bias = new float[conv8_2_output_channel];
//		float *conv8_1_output_col = new float[conv8_1_output_channel * conv8_2_kernel_height * conv8_2_kernel_width * conv8_2_output_height * conv8_2_output_width];
//		float *conv8_2_output = new float[conv8_2_output_channel * conv8_2_output_height * conv8_2_output_width];
//		readFile1("./data/fc.bin", conv8_2_coef, conv7_1_output_channel * conv8_2_output_channel * conv8_2_kernel_height * conv8_2_kernel_width * sizeof(float), vec);
//		vec.push_back(conv7_1_output_channel * conv8_2_output_channel * conv8_2_kernel_height * conv8_2_kernel_width * sizeof(float));
//		readFile1("./data/fc.bin", conv8_2_bias, conv8_2_output_channel * sizeof(float), vec);
//		vec.push_back(conv8_2_output_channel * sizeof(float));
//		Row_column_transpose(conv8_2_coef, conv8_2_new_coef, conv8_2_output_channel, conv7_1_output_channel * conv8_2_kernel_height * conv8_2_kernel_width);
//		//end init conv8_2
//
//
//		//start init fc7_norm
//		int fc7_norm_output_channel = 1024;
//		int fc7_norm_output_height = 7;
//		int fc7_norm_output_width = 7;
//		//float *fc7_norm_output = new float[fc7_norm_output_channel * fc7_norm_output_height * fc7_norm_output_width];
//		//readFile("data/fc7_norm_output", fc7_norm_output, fc7_norm_output_channel * fc7_norm_output_height * fc7_norm_output_width * 4);
//		float *fc7_norm_output = new float[fc7_norm_output_channel * fc7_norm_output_height * fc7_norm_output_width];
//		//float *fc7_norm_output_transpose = new float[fc7_norm_output_channel * fc7_norm_output_height * fc7_norm_output_width];
//
//		float *scale = new float[fc7_norm_output_channel];
//		int across_spatial = 0;
//		int channel_shared = 0;
//		if (channel_shared)
//		{
//			readFile1("./data/fc.bin", scale, 1 * 4, vec);
//			vec.push_back(1 * 4);
//
//		}
//		else
//		{
//			readFile1("./data/fc.bin", scale, fc7_norm_output_channel * 4, vec);
//			vec.push_back(fc7_norm_output_channel * 4);
//		}
//		//end init fc7_norm    
//
//
//
//		//start init fc7_mbox_loc
//		int fc7_mbox_loc_output_channel = 24;
//		int fc7_mbox_loc_kernel_height = 3;
//		int fc7_mbox_loc_kernel_width = 3;
//		int fc7_mbox_loc_output_height = 7;
//		int fc7_mbox_loc_output_width = 7;
//		int fc7_mbox_loc_pad_height = 1;
//		int fc7_mbox_loc_pad_width = 1;
//		int fc7_mbox_loc_stride_height = 1;
//		int fc7_mbox_loc_stride_width = 1;
//		int fc7_mbox_loc_dilation_height = 1;
//		int fc7_mbox_loc_dilation_width = 1;
//		int fc7_mbox_loc_withRELU = 0;
//		float *fc7_mbox_loc_coef = new float[fc7_output_channel * fc7_mbox_loc_output_channel * fc7_mbox_loc_kernel_height * fc7_mbox_loc_kernel_width];
//		float *fc7_mbox_loc_new_coef = new float[fc7_output_channel * fc7_mbox_loc_output_channel * fc7_mbox_loc_kernel_height * fc7_mbox_loc_kernel_width];
//		float *fc7_mbox_loc_bias = new float[fc7_mbox_loc_output_channel];
//		float *fc7_norm_output_col2 = new float[fc7_mbox_loc_output_height * fc7_mbox_loc_output_width * fc7_output_channel * fc7_mbox_loc_kernel_height * fc7_mbox_loc_kernel_height];
//		float *fc7_mbox_loc_output = new float[fc7_mbox_loc_output_channel * fc7_mbox_loc_output_height * fc7_mbox_loc_output_width];
//		float *fc7_mbox_loc_output_transpose = new float[fc7_mbox_loc_output_channel * fc7_mbox_loc_output_height * fc7_mbox_loc_output_width];
//		readFile1("./data/fc.bin", fc7_mbox_loc_coef, fc7_output_channel * fc7_mbox_loc_output_channel * fc7_mbox_loc_kernel_height * fc7_mbox_loc_kernel_width * sizeof(float), vec);
//		vec.push_back(fc7_output_channel * fc7_mbox_loc_output_channel * fc7_mbox_loc_kernel_height * fc7_mbox_loc_kernel_width * sizeof(float));
//		readFile1("./data/fc.bin", fc7_mbox_loc_bias, fc7_mbox_loc_output_channel * sizeof(float), vec);
//		vec.push_back(fc7_mbox_loc_output_channel * sizeof(float));
//		Row_column_transpose(fc7_mbox_loc_coef, fc7_mbox_loc_new_coef, fc7_mbox_loc_output_channel, fc7_output_channel * fc7_mbox_loc_kernel_height * fc7_mbox_loc_kernel_width);
//		//end init fc7_mbox_loc
//
//		//start init fc7_mbox_loc_perm
//		int fc7_mbox_loc_perm_orders_value[4] = { 0, 2, 3, 1 };
//		vector<int> fc7_mbox_loc_perm_orders(fc7_mbox_loc_perm_orders_value, fc7_mbox_loc_perm_orders_value + 4);
//		vector<int> fc7_mbox_loc_perm_shape(4, 1);
//		fc7_mbox_loc_perm_shape[1] = fc7_mbox_loc_output_channel;
//		fc7_mbox_loc_perm_shape[2] = fc7_mbox_loc_output_height;
//		fc7_mbox_loc_perm_shape[3] = fc7_mbox_loc_output_width;
//		float *fc7_mbox_loc_perm_output = new float[fc7_mbox_loc_output_channel * fc7_mbox_loc_output_height * fc7_mbox_loc_output_width];
//		//end init fc7_mbox_loc_perm
//
//
//		//start init fc7_mbox_conf
//		int fc7_mbox_conf_output_channel = 36;
//		int fc7_mbox_conf_kernel_height = 3;
//		int fc7_mbox_conf_kernel_width = 3;
//		int fc7_mbox_conf_output_height = 7;
//		int fc7_mbox_conf_output_width = 7;
//		int fc7_mbox_conf_pad_height = 1;
//		int fc7_mbox_conf_pad_width = 1;
//		int fc7_mbox_conf_stride_height = 1;
//		int fc7_mbox_conf_stride_width = 1;
//		int fc7_mbox_conf_dilation_height = 1;
//		int fc7_mbox_conf_dilation_width = 1;
//		int fc7_mbox_conf_withRELU = 0;
//		float *fc7_mbox_conf_coef = new float[fc7_output_channel * fc7_mbox_conf_output_channel * fc7_mbox_conf_kernel_height * fc7_mbox_conf_kernel_width];
//		float *fc7_mbox_conf_new_coef = new float[fc7_output_channel * fc7_mbox_conf_output_channel * fc7_mbox_conf_kernel_height * fc7_mbox_conf_kernel_width];
//		float *fc7_mbox_conf_bias = new float[fc7_mbox_conf_output_channel];
//		float *fc7_norm_output_col3 = new float[fc7_mbox_conf_output_height * fc7_mbox_conf_output_width * fc7_output_channel * fc7_mbox_conf_kernel_height * fc7_mbox_conf_kernel_width];
//		float *fc7_mbox_conf_output = new float[fc7_mbox_conf_output_channel * fc7_mbox_conf_output_height * fc7_mbox_conf_output_width];
//		float *fc7_mbox_conf_output_transpose = new float[fc7_mbox_conf_output_channel * fc7_mbox_conf_output_height * fc7_mbox_conf_output_width];
//		readFile1("./data/fc.bin", fc7_mbox_conf_coef, fc7_output_channel * fc7_mbox_conf_output_channel * fc7_mbox_conf_kernel_height * fc7_mbox_conf_kernel_width * sizeof(float), vec);
//		vec.push_back(fc7_output_channel * fc7_mbox_conf_output_channel * fc7_mbox_conf_kernel_height * fc7_mbox_conf_kernel_width * sizeof(float));
//		readFile1("./data/fc.bin", fc7_mbox_conf_bias, fc7_mbox_conf_output_channel * sizeof(float), vec);
//		vec.push_back(fc7_mbox_conf_output_channel * sizeof(float));
//		Row_column_transpose(fc7_mbox_conf_coef, fc7_mbox_conf_new_coef, fc7_mbox_conf_output_channel, fc7_output_channel * fc7_mbox_conf_kernel_height * fc7_mbox_conf_kernel_width);
//		//end init fc7_mbox_conf
//
//		//start init fc7_mbox_conf_perm
//		int fc7_mbox_conf_perm_orders_value[4] = { 0, 2, 3, 1 };
//		vector<int> fc7_mbox_conf_perm_orders(fc7_mbox_conf_perm_orders_value, fc7_mbox_conf_perm_orders_value + 4);
//		vector<int> fc7_mbox_conf_perm_shape(4, 1);
//		fc7_mbox_conf_perm_shape[1] = fc7_mbox_conf_output_channel;
//		fc7_mbox_conf_perm_shape[2] = fc7_mbox_conf_output_height;
//		fc7_mbox_conf_perm_shape[3] = fc7_mbox_conf_output_width;
//		float *fc7_mbox_conf_perm_output = new float[fc7_mbox_conf_output_channel * fc7_mbox_conf_output_height * fc7_mbox_conf_output_width];
//		//end init fc7_mbox_conf_perm
//
//
//
//
//
//
//		//start init conv6_2_mbox_loc
//		int conv6_2_mbox_loc_output_channel = 24;
//		int conv6_2_mbox_loc_kernel_height = 3;
//		int conv6_2_mbox_loc_kernel_width = 3;
//		int conv6_2_mbox_loc_output_height = 4;
//		int conv6_2_mbox_loc_output_width = 4;
//		int conv6_2_mbox_loc_pad_height = 1;
//		int conv6_2_mbox_loc_pad_width = 1;
//		int conv6_2_mbox_loc_stride_height = 1;
//		int conv6_2_mbox_loc_stride_width = 1;
//		int conv6_2_mbox_loc_dilation_height = 1;
//		int conv6_2_mbox_loc_dilation_width = 1;
//		int conv6_2_mbox_loc_withRELU = 0;
//
//		float *conv6_2_mbox_loc_coef = new float[conv6_2_output_channel * conv6_2_mbox_loc_output_channel * conv6_2_mbox_loc_kernel_height * conv6_2_mbox_loc_kernel_width];
//		float *conv6_2_mbox_loc_new_coef = new float[conv6_2_output_channel * conv6_2_mbox_loc_output_channel * conv6_2_mbox_loc_kernel_height * conv6_2_mbox_loc_kernel_width];
//		float *conv6_2_mbox_loc_bias = new float[conv6_2_mbox_loc_output_channel];
//		float *conv6_2_output_col2 = new float[conv6_2_output_channel * conv6_2_mbox_loc_kernel_height * conv6_2_mbox_loc_kernel_width * conv6_2_mbox_loc_output_height * conv6_2_mbox_loc_output_width];
//		float *conv6_2_mbox_loc_output = new float[conv6_2_mbox_loc_output_channel * conv6_2_mbox_loc_output_height * conv6_2_mbox_loc_output_width];
//		float *conv6_2_mbox_loc_output_transpose = new float[conv6_2_mbox_loc_output_channel * conv6_2_mbox_loc_output_height * conv6_2_mbox_loc_output_width];
//		readFile1("./data/fc.bin", conv6_2_mbox_loc_coef, conv6_2_output_channel * conv6_2_mbox_loc_output_channel * conv6_2_mbox_loc_kernel_height * conv6_2_mbox_loc_kernel_width * sizeof(float), vec);
//		vec.push_back(conv6_2_output_channel * conv6_2_mbox_loc_output_channel * conv6_2_mbox_loc_kernel_height * conv6_2_mbox_loc_kernel_width * sizeof(float));
//		readFile1("./data/fc.bin", conv6_2_mbox_loc_bias, conv6_2_mbox_loc_output_channel * sizeof(float), vec);
//		vec.push_back(conv6_2_mbox_loc_output_channel * sizeof(float));
//		Row_column_transpose(conv6_2_mbox_loc_coef, conv6_2_mbox_loc_new_coef, conv6_2_mbox_loc_output_channel, conv6_2_output_channel * conv6_2_mbox_loc_kernel_height * conv6_2_mbox_loc_kernel_width);
//		//end init conv6_2_mbox_loc
//
//
//		//start init conv6_2_mbox_loc_perm
//		int conv6_2_mbox_loc_perm_orders_value[4] = { 0, 2, 3, 1 };
//		vector<int> conv6_2_mbox_loc_perm_orders(conv6_2_mbox_loc_perm_orders_value, conv6_2_mbox_loc_perm_orders_value + 4);
//		vector<int> conv6_2_mbox_loc_perm_shape(4, 1);
//		conv6_2_mbox_loc_perm_shape[1] = conv6_2_mbox_loc_output_channel;
//		conv6_2_mbox_loc_perm_shape[2] = conv6_2_mbox_loc_output_height;
//		conv6_2_mbox_loc_perm_shape[3] = conv6_2_mbox_loc_output_width;
//		float *conv6_2_mbox_loc_perm_output = new float[conv6_2_mbox_loc_output_channel * conv6_2_mbox_loc_output_height * conv6_2_mbox_loc_output_width];
//		//end init conv6_2_mbox_loc_perm
//
//
//
//		//start init conv6_2_mbox_conf
//		int conv6_2_mbox_conf_output_channel = 36;
//		int conv6_2_mbox_conf_kernel_height = 3;
//		int conv6_2_mbox_conf_kernel_width = 3;
//		int conv6_2_mbox_conf_output_height = 4;
//		int conv6_2_mbox_conf_output_width = 4;
//		int conv6_2_mbox_conf_pad_height = 1;
//		int conv6_2_mbox_conf_pad_width = 1;
//		int conv6_2_mbox_conf_stride_height = 1;
//		int conv6_2_mbox_conf_stride_width = 1;
//		int conv6_2_mbox_conf_dilation_height = 1;
//		int conv6_2_mbox_conf_dilation_width = 1;
//		int conv6_2_mbox_conf_withRELU = 0;
//		float *conv6_2_mbox_conf_coef = new float[conv6_2_output_channel * conv6_2_mbox_conf_output_channel * conv6_2_mbox_conf_kernel_height * conv6_2_mbox_conf_kernel_width];
//		float *conv6_2_mbox_conf_new_coef = new float[conv6_2_output_channel * conv6_2_mbox_conf_output_channel * conv6_2_mbox_conf_kernel_height * conv6_2_mbox_conf_kernel_width];
//		float *conv6_2_mbox_conf_bias = new float[conv6_2_mbox_conf_output_channel];
//		float *conv6_2_output_col3 = new float[conv6_2_output_channel * conv6_2_mbox_conf_kernel_height * conv6_2_mbox_conf_kernel_width * conv6_2_mbox_conf_output_height * conv6_2_mbox_conf_output_width];
//		float *conv6_2_mbox_conf_output = new float[conv6_2_mbox_conf_output_channel * conv6_2_mbox_conf_output_height * conv6_2_mbox_conf_output_width];
//		float *conv6_2_mbox_conf_output_transpose = new float[conv6_2_mbox_conf_output_channel * conv6_2_mbox_conf_output_height * conv6_2_mbox_conf_output_width];
//		readFile1("./data/fc.bin", conv6_2_mbox_conf_coef, conv6_2_output_channel * conv6_2_mbox_conf_output_channel * conv6_2_mbox_conf_kernel_height * conv6_2_mbox_conf_kernel_width * sizeof(float), vec);
//		vec.push_back(conv6_2_output_channel * conv6_2_mbox_conf_output_channel * conv6_2_mbox_conf_kernel_height * conv6_2_mbox_conf_kernel_width * sizeof(float));
//		readFile1("./data/fc.bin", conv6_2_mbox_conf_bias, conv6_2_mbox_conf_output_channel * sizeof(float), vec);
//		vec.push_back(conv6_2_mbox_conf_output_channel * sizeof(float));
//		Row_column_transpose(conv6_2_mbox_conf_coef, conv6_2_mbox_conf_new_coef, conv6_2_mbox_conf_output_channel, conv6_2_output_channel * conv6_2_mbox_conf_kernel_height * conv6_2_mbox_conf_kernel_width);
//		//end init conv6_2_mbox_conf
//
//		//start init conv6_2_mbox_conf_perm
//		int conv6_2_mbox_conf_perm_orders_value[4] = { 0, 2, 3, 1 };
//		vector<int> conv6_2_mbox_conf_perm_orders(conv6_2_mbox_conf_perm_orders_value, conv6_2_mbox_conf_perm_orders_value + 4);
//		vector<int> conv6_2_mbox_conf_perm_shape(4, 1);
//		conv6_2_mbox_conf_perm_shape[1] = conv6_2_mbox_conf_output_channel;
//		conv6_2_mbox_conf_perm_shape[2] = conv6_2_mbox_conf_output_height;
//		conv6_2_mbox_conf_perm_shape[3] = conv6_2_mbox_conf_output_width;
//		float *conv6_2_mbox_conf_perm_output = new float[conv6_2_mbox_conf_output_channel * conv6_2_mbox_conf_output_height * conv6_2_mbox_conf_output_width];
//		//end init conv6_2_mbox_conf_perm
//
//
//
//
//
//
//		//start init conv7_2_mbox_loc
//		int conv7_2_mbox_loc_output_channel = 24;
//		int conv7_2_mbox_loc_kernel_height = 3;
//		int conv7_2_mbox_loc_kernel_width = 3;
//		int conv7_2_mbox_loc_output_height = 2;
//		int conv7_2_mbox_loc_output_width = 2;
//		int conv7_2_mbox_loc_pad_height = 1;
//		int conv7_2_mbox_loc_pad_width = 1;
//		int conv7_2_mbox_loc_stride_height = 1;
//		int conv7_2_mbox_loc_stride_width = 1;
//		int conv7_2_mbox_loc_dilation_height = 1;
//		int conv7_2_mbox_loc_dilation_width = 1;
//		int conv7_2_mbox_loc_withRELU = 0;
//
//		float *conv7_2_mbox_loc_coef = new float[conv7_2_output_channel * conv7_2_mbox_loc_output_channel * conv7_2_mbox_loc_kernel_height * conv7_2_mbox_loc_kernel_width];
//		float *conv7_2_mbox_loc_new_coef = new float[conv7_2_output_channel * conv7_2_mbox_loc_output_channel * conv7_2_mbox_loc_kernel_height * conv7_2_mbox_loc_kernel_width];
//		float *conv7_2_mbox_loc_bias = new float[conv7_2_mbox_loc_output_channel];
//		float *conv7_2_output_col2 = new float[conv7_2_output_channel * conv7_2_mbox_loc_kernel_height * conv7_2_mbox_loc_kernel_width * conv7_2_mbox_loc_output_height * conv7_2_mbox_loc_output_width];
//		float *conv7_2_mbox_loc_output = new float[conv7_2_mbox_loc_output_channel * conv7_2_mbox_loc_output_height * conv7_2_mbox_loc_output_width];
//		float *conv7_2_mbox_loc_output_transpose = new float[conv7_2_mbox_loc_output_channel * conv7_2_mbox_loc_output_height * conv7_2_mbox_loc_output_width];
//		readFile1("./data/fc.bin", conv7_2_mbox_loc_coef, conv7_2_output_channel * conv7_2_mbox_loc_output_channel * conv7_2_mbox_loc_kernel_height * conv7_2_mbox_loc_kernel_width * sizeof(float), vec);
//		vec.push_back(conv7_2_output_channel * conv7_2_mbox_loc_output_channel * conv7_2_mbox_loc_kernel_height * conv7_2_mbox_loc_kernel_width * sizeof(float));
//		readFile1("./data/fc.bin", conv7_2_mbox_loc_bias, conv7_2_mbox_loc_output_channel * sizeof(float), vec);
//		vec.push_back(conv7_2_mbox_loc_output_channel * sizeof(float));
//		Row_column_transpose(conv7_2_mbox_loc_coef, conv7_2_mbox_loc_new_coef, conv7_2_mbox_loc_output_channel, conv7_2_output_channel * conv7_2_mbox_loc_kernel_height * conv7_2_mbox_loc_kernel_width);
//		//end init conv7_2_mbox_loc
//
//
//		//start init conv7_2_mbox_loc_perm
//		int conv7_2_mbox_loc_perm_orders_value[4] = { 0, 2, 3, 1 };
//		vector<int> conv7_2_mbox_loc_perm_orders(conv7_2_mbox_loc_perm_orders_value, conv7_2_mbox_loc_perm_orders_value + 4);
//		vector<int> conv7_2_mbox_loc_perm_shape(4, 1);
//		conv7_2_mbox_loc_perm_shape[1] = conv7_2_mbox_loc_output_channel;
//		conv7_2_mbox_loc_perm_shape[2] = conv7_2_mbox_loc_output_height;
//		conv7_2_mbox_loc_perm_shape[3] = conv7_2_mbox_loc_output_width;
//		float *conv7_2_mbox_loc_perm_output = new float[conv7_2_mbox_loc_output_channel * conv7_2_mbox_loc_output_height * conv7_2_mbox_loc_output_width];
//		//end init conv7_2_mbox_loc_perm
//
//
//
//		//start init conv7_2_mbox_conf
//		int conv7_2_mbox_conf_output_channel = 36;
//		int conv7_2_mbox_conf_kernel_height = 3;
//		int conv7_2_mbox_conf_kernel_width = 3;
//		int conv7_2_mbox_conf_output_height = 2;
//		int conv7_2_mbox_conf_output_width = 2;
//		int conv7_2_mbox_conf_pad_height = 1;
//		int conv7_2_mbox_conf_pad_width = 1;
//		int conv7_2_mbox_conf_stride_height = 1;
//		int conv7_2_mbox_conf_stride_width = 1;
//		int conv7_2_mbox_conf_dilation_height = 1;
//		int conv7_2_mbox_conf_dilation_width = 1;
//		int conv7_2_mbox_conf_withRELU = 0;
//		float *conv7_2_mbox_conf_coef = new float[conv7_2_output_channel * conv7_2_mbox_conf_output_channel * conv7_2_mbox_conf_kernel_height * conv7_2_mbox_conf_kernel_width];
//		float *conv7_2_mbox_conf_new_coef = new float[conv7_2_output_channel * conv7_2_mbox_conf_output_channel * conv7_2_mbox_conf_kernel_height * conv7_2_mbox_conf_kernel_width];
//		float *conv7_2_mbox_conf_bias = new float[conv7_2_mbox_conf_output_channel];
//		float *conv7_2_output_col3 = new float[conv7_2_output_channel * conv7_2_mbox_conf_kernel_height * conv7_2_mbox_conf_kernel_width * conv7_2_mbox_conf_output_height * conv7_2_mbox_conf_output_width];
//		float *conv7_2_mbox_conf_output = new float[conv7_2_mbox_conf_output_channel * conv7_2_mbox_conf_output_height * conv7_2_mbox_conf_output_width];
//		float *conv7_2_mbox_conf_output_transpose = new float[conv7_2_mbox_conf_output_channel * conv7_2_mbox_conf_output_height * conv7_2_mbox_conf_output_width];
//		readFile1("./data/fc.bin", conv7_2_mbox_conf_coef, conv7_2_output_channel * conv7_2_mbox_conf_output_channel * conv7_2_mbox_conf_kernel_height * conv7_2_mbox_conf_kernel_width * sizeof(float), vec);
//		vec.push_back(conv7_2_output_channel * conv7_2_mbox_conf_output_channel * conv7_2_mbox_conf_kernel_height * conv7_2_mbox_conf_kernel_width * sizeof(float));
//		readFile1("./data/fc.bin", conv7_2_mbox_conf_bias, conv7_2_mbox_conf_output_channel * sizeof(float), vec);
//		vec.push_back(conv7_2_mbox_conf_output_channel * sizeof(float));
//		Row_column_transpose(conv7_2_mbox_conf_coef, conv7_2_mbox_conf_new_coef, conv7_2_mbox_conf_output_channel, conv7_2_output_channel * conv7_2_mbox_conf_kernel_height * conv7_2_mbox_conf_kernel_width);
//		//end init conv7_2_mbox_conf
//
//		//start init conv7_2_mbox_conf_perm
//		int conv7_2_mbox_conf_perm_orders_value[4] = { 0, 2, 3, 1 };
//		vector<int> conv7_2_mbox_conf_perm_orders(conv7_2_mbox_conf_perm_orders_value, conv7_2_mbox_conf_perm_orders_value + 4);
//		vector<int> conv7_2_mbox_conf_perm_shape(4, 1);
//		conv7_2_mbox_conf_perm_shape[1] = conv7_2_mbox_conf_output_channel;
//		conv7_2_mbox_conf_perm_shape[2] = conv7_2_mbox_conf_output_height;
//		conv7_2_mbox_conf_perm_shape[3] = conv7_2_mbox_conf_output_width;
//		float *conv7_2_mbox_conf_perm_output = new float[conv7_2_mbox_conf_output_channel * conv7_2_mbox_conf_output_height * conv7_2_mbox_conf_output_width];
//		//end init conv7_2_mbox_conf_perm
//
//
//
//
//
//
//
//
//		//start init conv8_2_mbox_loc
//
//		int conv8_2_mbox_loc_output_channel = 24;
//		int conv8_2_mbox_loc_kernel_height = 3;
//		int conv8_2_mbox_loc_kernel_width = 3;
//		int conv8_2_mbox_loc_output_height = 1;
//		int conv8_2_mbox_loc_output_width = 1;
//		int conv8_2_mbox_loc_pad_height = 1;
//		int conv8_2_mbox_loc_pad_width = 1;
//		int conv8_2_mbox_loc_stride_height = 1;
//		int conv8_2_mbox_loc_stride_width = 1;
//		int conv8_2_mbox_loc_dilation_height = 1;
//		int conv8_2_mbox_loc_dilation_width = 1;
//		int conv8_2_mbox_loc_withRELU = 0;
//
//		float *conv8_2_mbox_loc_coef = new float[conv8_2_output_channel * conv8_2_mbox_loc_output_channel * conv8_2_mbox_loc_kernel_height * conv8_2_mbox_loc_kernel_width];
//		float *conv8_2_mbox_loc_new_coef = new float[conv8_2_output_channel * conv8_2_mbox_loc_output_channel * conv8_2_mbox_loc_kernel_height * conv8_2_mbox_loc_kernel_width];
//		float *conv8_2_mbox_loc_bias = new float[conv8_2_mbox_loc_output_channel];
//		float *conv8_2_output_col2 = new float[conv8_2_output_channel * conv8_2_mbox_loc_kernel_height * conv8_2_mbox_loc_kernel_width * conv8_2_mbox_loc_output_height * conv8_2_mbox_loc_output_width];
//		float *conv8_2_mbox_loc_output = new float[conv8_2_mbox_loc_output_channel * conv8_2_mbox_loc_output_height * conv8_2_mbox_loc_output_width];
//		float *conv8_2_mbox_loc_output_transpose = new float[conv8_2_mbox_loc_output_channel * conv8_2_mbox_loc_output_height * conv8_2_mbox_loc_output_width];
//		readFile1("./data/fc.bin", conv8_2_mbox_loc_coef, conv8_2_output_channel * conv8_2_mbox_loc_output_channel * conv8_2_mbox_loc_kernel_height * conv8_2_mbox_loc_kernel_width * sizeof(float), vec);
//		vec.push_back(conv8_2_output_channel * conv8_2_mbox_loc_output_channel * conv8_2_mbox_loc_kernel_height * conv8_2_mbox_loc_kernel_width * sizeof(float));
//		readFile1("./data/fc.bin", conv8_2_mbox_loc_bias, conv8_2_mbox_loc_output_channel * sizeof(float), vec);
//		vec.push_back(conv8_2_mbox_loc_output_channel * sizeof(float));
//		Row_column_transpose(conv8_2_mbox_loc_coef, conv8_2_mbox_loc_new_coef, conv8_2_mbox_loc_output_channel, conv8_2_output_channel * conv8_2_mbox_loc_kernel_height * conv8_2_mbox_loc_kernel_width);
//		//end init conv8_2_mbox_loc
//
//
//		//start init conv8_2_mbox_loc_perm
//		int conv8_2_mbox_loc_perm_orders_value[4] = { 0, 2, 3, 1 };
//		vector<int> conv8_2_mbox_loc_perm_orders(conv8_2_mbox_loc_perm_orders_value, conv8_2_mbox_loc_perm_orders_value + 4);
//		vector<int> conv8_2_mbox_loc_perm_shape(4, 1);
//		conv8_2_mbox_loc_perm_shape[1] = conv8_2_mbox_loc_output_channel;
//		conv8_2_mbox_loc_perm_shape[2] = conv8_2_mbox_loc_output_height;
//		conv8_2_mbox_loc_perm_shape[3] = conv8_2_mbox_loc_output_width;
//		float *conv8_2_mbox_loc_perm_output = new float[conv8_2_mbox_loc_output_channel * conv8_2_mbox_loc_output_height * conv8_2_mbox_loc_output_width];
//		//end init conv8_2_mbox_loc_perm
//
//		//start init conv8_2_mbox_conf
//		int conv8_2_mbox_conf_output_channel = 36;
//		int conv8_2_mbox_conf_kernel_height = 3;
//		int conv8_2_mbox_conf_kernel_width = 3;
//		int conv8_2_mbox_conf_output_height = 1;
//		int conv8_2_mbox_conf_output_width = 1;
//		int conv8_2_mbox_conf_pad_height = 1;
//		int conv8_2_mbox_conf_pad_width = 1;
//		int conv8_2_mbox_conf_stride_height = 1;
//		int conv8_2_mbox_conf_stride_width = 1;
//		int conv8_2_mbox_conf_dilation_height = 1;
//		int conv8_2_mbox_conf_dilation_width = 1;
//		int conv8_2_mbox_conf_withRELU = 0;
//		float *conv8_2_mbox_conf_coef = new float[conv8_2_output_channel * conv8_2_mbox_conf_output_channel * conv8_2_mbox_conf_kernel_height * conv8_2_mbox_conf_kernel_width];
//		float *conv8_2_mbox_conf_new_coef = new float[conv8_2_output_channel * conv8_2_mbox_conf_output_channel * conv8_2_mbox_conf_kernel_height * conv8_2_mbox_conf_kernel_width];
//		float *conv8_2_mbox_conf_bias = new float[conv8_2_mbox_conf_output_channel];
//		float *conv8_2_output_col3 = new float[conv8_2_output_channel * conv8_2_mbox_conf_kernel_height * conv8_2_mbox_conf_kernel_width * conv8_2_mbox_conf_output_height * conv8_2_mbox_conf_output_width];
//		float *conv8_2_mbox_conf_output = new float[conv8_2_mbox_conf_output_channel * conv8_2_mbox_conf_output_height * conv8_2_mbox_conf_output_width];
//		float *conv8_2_mbox_conf_output_transpose = new float[conv8_2_mbox_conf_output_channel * conv8_2_mbox_conf_output_height * conv8_2_mbox_conf_output_width];
//		readFile1("./data/fc.bin", conv8_2_mbox_conf_coef, conv8_2_output_channel * conv8_2_mbox_conf_output_channel * conv8_2_mbox_conf_kernel_height * conv8_2_mbox_conf_kernel_width * sizeof(float), vec);
//		vec.push_back(conv8_2_output_channel * conv8_2_mbox_conf_output_channel * conv8_2_mbox_conf_kernel_height * conv8_2_mbox_conf_kernel_width * sizeof(float));
//		readFile1("./data/fc.bin", conv8_2_mbox_conf_bias, conv8_2_mbox_conf_output_channel * sizeof(float), vec);
//		vec.push_back(conv8_2_mbox_conf_output_channel * sizeof(float));
//		Row_column_transpose(conv8_2_mbox_conf_coef, conv8_2_mbox_conf_new_coef, conv8_2_mbox_conf_output_channel, conv8_2_output_channel * conv8_2_mbox_conf_kernel_height * conv8_2_mbox_conf_kernel_width);
//		//end init conv8_2_mbox_conf
//
//		//start init conv8_2_mbox_conf_perm
//		int conv8_2_mbox_conf_perm_orders_value[4] = { 0, 2, 3, 1 };
//		vector<int> conv8_2_mbox_conf_perm_orders(conv8_2_mbox_conf_perm_orders_value, conv8_2_mbox_conf_perm_orders_value + 4);
//		vector<int> conv8_2_mbox_conf_perm_shape(4, 1);
//		conv8_2_mbox_conf_perm_shape[1] = conv8_2_mbox_conf_output_channel;
//		conv8_2_mbox_conf_perm_shape[2] = conv8_2_mbox_conf_output_height;
//		conv8_2_mbox_conf_perm_shape[3] = conv8_2_mbox_conf_output_width;
//		float *conv8_2_mbox_conf_perm_output = new float[conv8_2_mbox_conf_output_channel * conv8_2_mbox_conf_output_height * conv8_2_mbox_conf_output_width];
//		//end init conv8_2_mbox_conf_perm
//
//
//
//		//start init fc7_mbox_priorbox
//		int fc7_mbox_prior_channel = 2;
//		float fc7_mbox_prior_step_h = 32.0;
//		float fc7_mbox_prior_step_w = 32.0;
//		vector<float> fc7_mbox_prior_min_sizes_;
//		fc7_mbox_prior_min_sizes_.push_back(44.8);
//		vector<float> fc7_mbox_prior_max_sizes_;
//		fc7_mbox_prior_max_sizes_.push_back(89.6);
//		vector<float> fc7_mbox_prior_aspect_ratios_;
//		fc7_mbox_prior_aspect_ratios_.push_back(2.0);
//		fc7_mbox_prior_aspect_ratios_.push_back(3.0);
//		int fc7_mbox_prior_flip_ = 1;
//		int fc7_mbox_prior_clip_ = 0;
//		vector<float> fc7_mbox_prior_variance_;
//		fc7_mbox_prior_variance_.push_back(0.10000000149);
//		fc7_mbox_prior_variance_.push_back(0.10000000149);
//		fc7_mbox_prior_variance_.push_back(0.20000000298);
//		fc7_mbox_prior_variance_.push_back(0.20000000298);
//		float fc7_mbox_prior_offset_ = 0.5;
//		int fc7_mbox_prior_num_priors_;
//		if (fc7_mbox_prior_flip_)
//		{
//			fc7_mbox_prior_num_priors_ = (fc7_mbox_prior_min_sizes_.size() + fc7_mbox_prior_max_sizes_.size()) + (fc7_mbox_prior_aspect_ratios_.size() * 2);
//		}
//		else
//		{
//			fc7_mbox_prior_num_priors_ = (fc7_mbox_prior_min_sizes_.size() + fc7_mbox_prior_max_sizes_.size()) + fc7_mbox_prior_aspect_ratios_.size();
//		}
//		int fc7_mbox_prior_output_size = fc7_mbox_prior_channel * fc7_output_height * fc7_output_width * fc7_mbox_prior_num_priors_ * 4;
//		float *fc7_mbox_prior_output = new float[fc7_mbox_prior_output_size];
//		//end init fc7_mbox_priorbox
//
//		//start init conv6_2_mbox_priorbox
//		int conv6_2_mbox_prior_channel = 2;
//		float conv6_2_mbox_prior_step_h = 56.0;
//		float conv6_2_mbox_prior_step_w = 56.0;
//		vector<float> conv6_2_mbox_prior_min_sizes_;
//		conv6_2_mbox_prior_min_sizes_.push_back(89.6);
//		vector<float> conv6_2_mbox_prior_max_sizes_;
//		conv6_2_mbox_prior_max_sizes_.push_back(145.6);
//		vector<float> conv6_2_mbox_prior_aspect_ratios_;
//		conv6_2_mbox_prior_aspect_ratios_.push_back(2.0);
//		conv6_2_mbox_prior_aspect_ratios_.push_back(3.0);
//		int conv6_2_mbox_prior_flip_ = 1;
//		int conv6_2_mbox_prior_clip_ = 0;
//		vector<float> conv6_2_mbox_prior_variance_;
//		conv6_2_mbox_prior_variance_.push_back(0.10000000149);
//		conv6_2_mbox_prior_variance_.push_back(0.10000000149);
//		conv6_2_mbox_prior_variance_.push_back(0.20000000298);
//		conv6_2_mbox_prior_variance_.push_back(0.20000000298);
//		float conv6_2_mbox_prior_offset_ = 0.5;
//		int conv6_2_mbox_prior_num_priors_;
//		if (conv6_2_mbox_prior_flip_)
//		{
//			conv6_2_mbox_prior_num_priors_ = (conv6_2_mbox_prior_min_sizes_.size() + conv6_2_mbox_prior_max_sizes_.size()) + (conv6_2_mbox_prior_aspect_ratios_.size() * 2);
//		}
//		else
//		{
//			conv6_2_mbox_prior_num_priors_ = (conv6_2_mbox_prior_min_sizes_.size() + conv6_2_mbox_prior_max_sizes_.size()) + conv6_2_mbox_prior_aspect_ratios_.size();
//		}
//		int conv6_2_mbox_prior_output_size = conv6_2_mbox_prior_channel * conv6_2_output_height * conv6_2_output_width * conv6_2_mbox_prior_num_priors_ * 4;
//		float *conv6_2_mbox_prior_output = new float[conv6_2_mbox_prior_output_size];
//		//end init conv6_2_mbox_priorbox
//
//		//start init conv7_2_mbox_priorbox
//		int conv7_2_mbox_prior_channel = 2;
//		float conv7_2_mbox_prior_step_h = 112.0;
//		float conv7_2_mbox_prior_step_w = 112.0;
//		vector<float> conv7_2_mbox_prior_min_sizes_;
//		conv7_2_mbox_prior_min_sizes_.push_back(145.6);
//		vector<float> conv7_2_mbox_prior_max_sizes_;
//		conv7_2_mbox_prior_max_sizes_.push_back(201.6);
//		vector<float> conv7_2_mbox_prior_aspect_ratios_;
//		conv7_2_mbox_prior_aspect_ratios_.push_back(2.0);
//		conv7_2_mbox_prior_aspect_ratios_.push_back(3.0);
//		int conv7_2_mbox_prior_flip_ = 1;
//		int conv7_2_mbox_prior_clip_ = 0;
//		vector<float> conv7_2_mbox_prior_variance_;
//		conv7_2_mbox_prior_variance_.push_back(0.10000000149);
//		conv7_2_mbox_prior_variance_.push_back(0.10000000149);
//		conv7_2_mbox_prior_variance_.push_back(0.20000000298);
//		conv7_2_mbox_prior_variance_.push_back(0.20000000298);
//		float conv7_2_mbox_prior_offset_ = 0.5;
//		int conv7_2_mbox_prior_num_priors_;
//		if (conv7_2_mbox_prior_flip_)
//		{
//			conv7_2_mbox_prior_num_priors_ = (conv7_2_mbox_prior_min_sizes_.size() + conv7_2_mbox_prior_max_sizes_.size()) + (conv7_2_mbox_prior_aspect_ratios_.size() * 2);
//		}
//		else
//		{
//			conv7_2_mbox_prior_num_priors_ = (conv7_2_mbox_prior_min_sizes_.size() + conv7_2_mbox_prior_max_sizes_.size()) + conv7_2_mbox_prior_aspect_ratios_.size();
//		}
//		int conv7_2_mbox_prior_output_size = conv7_2_mbox_prior_channel * conv7_2_output_height * conv7_2_output_width * conv7_2_mbox_prior_num_priors_ * 4;
//		float *conv7_2_mbox_prior_output = new float[conv7_2_mbox_prior_output_size];
//		//end init conv7_2_mbox_priorbox
//
//		//start init conv8_2_mbox_priorbox
//		int conv8_2_mbox_prior_channel = 2;
//		float conv8_2_mbox_prior_step_h = 224.0;
//		float conv8_2_mbox_prior_step_w = 224.0;
//		vector<float> conv8_2_mbox_prior_min_sizes_;
//		conv8_2_mbox_prior_min_sizes_.push_back(201.6);
//		vector<float> conv8_2_mbox_prior_max_sizes_;
//		conv8_2_mbox_prior_max_sizes_.push_back(257.6);
//		vector<float> conv8_2_mbox_prior_aspect_ratios_;
//		conv8_2_mbox_prior_aspect_ratios_.push_back(2.0);
//		int conv8_2_mbox_prior_flip_ = 1;
//		int conv8_2_mbox_prior_clip_ = 0;
//		vector<float> conv8_2_mbox_prior_variance_;
//		conv8_2_mbox_prior_variance_.push_back(0.10000000149);
//		conv8_2_mbox_prior_variance_.push_back(0.10000000149);
//		conv8_2_mbox_prior_variance_.push_back(0.20000000298);
//		conv8_2_mbox_prior_variance_.push_back(0.20000000298);
//		float conv8_2_mbox_prior_offset_ = 0.5;
//		int conv8_2_mbox_prior_num_priors_;
//		if (conv8_2_mbox_prior_flip_)
//		{
//			conv8_2_mbox_prior_num_priors_ = (conv8_2_mbox_prior_min_sizes_.size() + conv8_2_mbox_prior_max_sizes_.size()) + (conv8_2_mbox_prior_aspect_ratios_.size() * 2);
//		}
//		else
//		{
//			conv8_2_mbox_prior_num_priors_ = (conv8_2_mbox_prior_min_sizes_.size() + conv8_2_mbox_prior_max_sizes_.size()) + conv8_2_mbox_prior_aspect_ratios_.size();
//		}
//		int conv8_2_mbox_prior_output_size = conv8_2_mbox_prior_channel * conv8_2_output_height * conv8_2_output_width * conv8_2_mbox_prior_num_priors_ * 4;
//		float *conv8_2_mbox_prior_output = new float[conv8_2_mbox_prior_output_size];
//		//end init conv8_2_mbox_priorbox
//
//
//		//start init mbox_priorbox
//		vector<concatDataParam> DataParams;
//		concatDataParam DataParam;
//		int output_size = 0;
//		int mbox_priorbox_shape_value[3] = { 1, 2, 7 * 7 * 6 * 4 };
//		output_size += 2 * 7 * 7 * 6 * 4;
//		vector<int> shape(mbox_priorbox_shape_value, mbox_priorbox_shape_value + 3);
//		DataParam = { fc7_mbox_prior_output, shape };
//		DataParams.push_back(DataParam);
//		shape[2] = 4 * 4 * 6 * 4;
//		output_size += 2 * 4 * 4 * 6 * 4;
//		DataParam = { conv6_2_mbox_prior_output, shape };
//		DataParams.push_back(DataParam);
//		shape[2] = 2 * 2 * 6 * 4;
//		output_size += 2 * 2 * 2 * 6 * 4;
//		DataParam = { conv7_2_mbox_prior_output, shape };
//		DataParams.push_back(DataParam);
//		shape[2] = 1 * 1 * 4 * 4;
//		output_size += 2 * 1 * 1 * 6 * 4;
//		DataParam = { conv8_2_mbox_prior_output, shape };
//		DataParams.push_back(DataParam);
//		shape[2] = output_size / 2;
//		float *mbox_priorbox_output_Data = new float[output_size];
//		int mbox_priorbox_axis = 2;
//		//end init mbox_priorbox
//
//
//		//start init mbox_conf
//		vector<concatDataParam> DataParams_conf;
//		concatDataParam DataParam_conf;
//		int output_size_conf = 0;
//		output_size_conf += 7 * 7 * 6 * 6;
//		vector<int> shape_conf{ 1, 7 * 7 * 6 * 6 };
//		DataParam_conf = { fc7_mbox_conf_perm_output, shape_conf };
//		DataParams_conf.push_back(DataParam_conf);
//		shape_conf[1] = 4 * 4 * 6 * 6;
//		output_size_conf += 4 * 4 * 6 * 6;
//		DataParam_conf = { conv6_2_mbox_conf_perm_output, shape_conf };
//		DataParams_conf.push_back(DataParam_conf);
//		shape_conf[1] = 2 * 2 * 6 * 6;
//		output_size_conf += 2 * 2 * 6 * 6;
//		DataParam_conf = { conv7_2_mbox_conf_perm_output, shape_conf };
//		DataParams_conf.push_back(DataParam_conf);
//		shape_conf[1] = 1 * 1 * 6 * 6;
//		output_size_conf += 1 * 1 * 6 * 6;
//		DataParam_conf = { conv8_2_mbox_conf_perm_output, shape_conf };
//		DataParams_conf.push_back(DataParam_conf);
//		shape_conf[1] = output_size_conf;
//		float *mbox_conf_output_Data = new float[output_size_conf];
//		int mbox_conf_axis = 1;
//		//end init mbox_conf
//
//
//
//		//start init mbox_loc
//		vector<concatDataParam> DataParams_loc;
//		concatDataParam DataParam_loc;
//		int output_size_loc = 0;
//		output_size_loc += 7 * 7 * 6 * 4;
//		vector<int> shape_loc{ 1, 7 * 7 * 6 * 4 };
//		DataParam_loc = { fc7_mbox_loc_perm_output, shape_loc };
//		DataParams_loc.push_back(DataParam_loc);
//		shape_loc[1] = 4 * 4 * 6 * 4;
//		output_size_loc += 4 * 4 * 6 * 4;
//		DataParam_loc = { conv6_2_mbox_loc_perm_output, shape_loc };
//		DataParams_loc.push_back(DataParam_loc);
//		shape_loc[1] = 2 * 2 * 6 * 4;
//		output_size_loc += 2 * 2 * 6 * 4;
//		DataParam_loc = { conv7_2_mbox_loc_perm_output, shape_loc };
//		DataParams_loc.push_back(DataParam_loc);
//		shape_loc[1] = 1 * 1 * 6 * 4;
//		output_size_loc += 1 * 1 * 6 * 4;
//		DataParam_loc = { conv8_2_mbox_loc_perm_output, shape_loc };
//		DataParams_loc.push_back(DataParam_loc);
//		shape_loc[1] = output_size_loc;
//		float *mbox_loc_output_Data = new float[output_size_loc];
//		int mbox_loc_axis = 1;
//		//end init mbox_loc
//
//
//
//		// =============================================================================================================
//
//		//start run fc6
//		//gettimeofday(&startfc, NULL);
//		im2row(pool5_output, pool5_output_channel, pool5_output_height, pool5_output_width, fc6_kernel_height, fc6_kernel_width,
//			fc6_pad_height, fc6_pad_width, fc6_stride_height, fc6_stride_width, fc6_dilation_height, fc6_dilation_width, pool5_output_col);
//
//		convParam fc6_param = { pool5_output_col, fc6_new_coef, fc6_bias, fc6_output, pool5_output_channel, pool5_output_height, pool5_output_width,fc6_kernel_height, fc6_kernel_width, fc6_output_channel, fc6_output_height, fc6_output_width };
//
//		convLayer(&fc6_param, fc6_withRELU);
//
//
//		float *fc6_output2 = new float[fc6_output_channel * fc6_output_height * fc6_output_width];
//		Row_column_transpose(fc6_output, fc6_output2, fc6_output_height * fc6_output_width, fc6_output_channel);
//		//float *fc6_output1 = new float[fc6_output_channel * fc6_output_height * fc6_output_width];
//		//readFile("data/ip6_output", fc6_output1, fc6_output_channel * fc6_output_height * fc6_output_width * sizeof(float));
//
//		//gettimeofday(&endfc, NULL);
//		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
//		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
//		//cout << "fc6 conv: " << endfctt - startfctt << "ms" << endl;
//		//end run fc6
//
//		//start delete fc6
//		delete[] pool5_output;
//		pool5_output = NULL;
//		delete[] fc6_coef;
//		fc6_coef = NULL;
//		delete[] fc6_new_coef;
//		fc6_new_coef = NULL;
//		delete[] fc6_bias;
//		fc6_bias = NULL;
//		delete[] pool5_output_col;
//		pool5_output_col = NULL;
//		//end delete fc6
//
//		//start run fc7
//		//gettimeofday(&startfc, NULL);
//		im2rowBycol(fc6_output, fc6_output_channel, fc6_output_height, fc6_output_width, fc7_kernel_height, fc7_kernel_width,
//			fc7_pad_height, fc7_pad_width, fc7_stride_height, fc7_stride_width, fc7_dilation_height, fc7_dilation_width, fc6_output_col);
//
//		convParam fc7_param = { fc6_output_col, fc7_new_coef, fc7_bias, fc7_output, fc6_output_channel, fc6_output_height, fc6_output_width,
//			fc7_kernel_height, fc7_kernel_width, fc7_output_channel, fc7_output_height, fc7_output_width };
//		convLayer(&fc7_param, fc7_withRELU);
//		//gettimeofday(&endfc, NULL);
//		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
//		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
//		//cout << "fc7 conv: " << endfctt - startfctt << "ms" << endl;
//		//end run fc7
//
//		//start delete fc7
//		delete[] fc6_output;
//		fc6_output = NULL;
//		delete[] fc7_coef;
//		fc7_coef = NULL;
//		delete[] fc7_new_coef;
//		fc7_new_coef = NULL;
//		delete[] fc7_bias;
//		fc7_bias = NULL;
//		delete[] fc6_output_col;
//		fc6_output_col = NULL;
//		//end delete fc7
//
//
//		//start run conv6_1
//		//gettimeofday(&startfc, NULL);
//		im2rowBycol(fc7_output, fc7_output_channel, fc7_output_height, fc7_output_width, conv6_1_kernel_height, conv6_1_kernel_width,
//			conv6_1_pad_height, conv6_1_pad_width, conv6_1_stride_height, conv6_1_stride_width, conv6_1_dilation_height, conv6_1_dilation_width, fc7_output_col);
//
//		convParam conv6_1_param = { fc7_output_col, conv6_1_new_coef, conv6_1_bias, conv6_1_output, fc7_output_channel, fc7_output_height, fc7_output_width,
//			conv6_1_kernel_height, conv6_1_kernel_width, conv6_1_output_channel, conv6_1_output_height, conv6_1_output_width };
//		convLayer(&conv6_1_param, conv6_1_withRELU);
//		//gettimeofday(&endfc, NULL);
//		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
//		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
//		//cout << "conv6_1 conv: " << endfctt - startfctt << "ms" << endl;  
//		//end run conv6_1
//
//
//		float *conv6_1_output2 = new float[conv6_1_output_channel * conv6_1_output_height * conv6_1_output_width];
//		Row_column_transpose(conv6_1_output, conv6_1_output2, conv6_1_output_height * conv6_1_output_width, conv6_1_output_channel);
//		//float *conv6_1_output1 = new float[conv6_1_output_channel * conv6_1_output_height * conv6_1_output_width];
//		//readFile("data/conv6_1_output", conv6_1_output1, conv6_1_output_height * conv6_1_output_width * conv6_1_output_channel * sizeof(float));
//
//
//
//		//start delete conv6_1
//		delete[] conv6_1_coef;
//		conv6_1_coef = NULL;
//		delete[] conv6_1_new_coef;
//		conv6_1_new_coef = NULL;
//		delete[] conv6_1_bias;
//		conv6_1_bias = NULL;
//		delete[] fc7_output_col;
//		fc7_output_col = NULL;
//		//end delete conv6_1
//
//
//		//start run fc7_norm
//		//gettimeofday(&startfc, NULL);
//		Row_column_transpose(fc7_output, fc7_output_transpose, fc7_output_height * fc7_output_width, fc7_output_channel);
//		normalizeParam fc7_norm_param = { fc7_output_transpose, fc7_norm_output, scale, across_spatial, channel_shared, fc7_output_channel, fc7_output_height, fc7_output_width };
//		Normalize(&fc7_norm_param);
//		//gettimeofday(&endfc, NULL);
//		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
//		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
//		//cout << "fc7 norm: " << endfctt - startfctt << "ms" << endl;
//		//end run fc7_norm
//
//
//		//float *fc7_norm_output1 = new float[fc7_norm_output_channel * fc7_norm_output_height * fc7_norm_output_width];
//		//readFile("data/ip7_norm_output", fc7_norm_output1, fc7_mbox_loc_output_height * fc7_mbox_loc_output_width * fc7_mbox_loc_output_channel * sizeof(float));
//
//
//		//start run fc7_mbox_loc
//		//gettimeofday(&startfc, NULL);
//		//Row_column_transpose(fc7_norm_output, fc7_norm_output_transpose, fc7_output_channel, fc7_output_height * fc7_output_width);
//		im2row(fc7_norm_output, fc7_output_channel, fc7_output_height, fc7_output_width, fc7_mbox_loc_kernel_height, fc7_mbox_loc_kernel_width,
//			fc7_mbox_loc_pad_height, fc7_mbox_loc_pad_width, fc7_mbox_loc_stride_height, fc7_mbox_loc_stride_width, fc7_mbox_loc_dilation_height, fc7_mbox_loc_dilation_width, fc7_norm_output_col2);
//
//		convParam fc7_mbox_loc_param = { fc7_norm_output_col2, fc7_mbox_loc_new_coef, fc7_mbox_loc_bias, fc7_mbox_loc_output, fc7_output_channel, fc7_output_height, fc7_output_width, fc7_mbox_loc_kernel_height, fc7_mbox_loc_kernel_width, fc7_mbox_loc_output_channel, fc7_mbox_loc_output_height, fc7_mbox_loc_output_width };
//		convLayer(&fc7_mbox_loc_param, fc7_mbox_loc_withRELU);
//		Row_column_transpose(fc7_mbox_loc_output, fc7_mbox_loc_output_transpose, fc7_mbox_loc_output_height * fc7_mbox_loc_output_width, fc7_mbox_loc_output_channel);
//		//gettimeofday(&endfc, NULL);
//		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
//		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
//		//cout << "fc7_mbox_loc conv: " << endfctt - startfctt << "ms" << endl;
//		//end run fc7_mbox_loc
//
//		//float *fc7_mbox_loc_output1 = new float[fc7_mbox_loc_output_channel * fc7_mbox_loc_output_height * fc7_mbox_loc_output_width];
//		//readFile("data/ip7_norm_mbox_loc_output", fc7_mbox_loc_output1, fc7_mbox_loc_output_height * fc7_mbox_loc_output_width * fc7_mbox_loc_output_channel * sizeof(float));
//
//		//start delete fc7_mbox_loc
//		delete[] fc7_mbox_loc_output;
//		fc7_mbox_loc_output = NULL;
//		delete[] fc7_mbox_loc_coef;
//		fc7_mbox_loc_coef = NULL;
//		delete[] fc7_mbox_loc_new_coef;
//		fc7_mbox_loc_new_coef = NULL;
//		delete[] fc7_mbox_loc_bias;
//		fc7_mbox_loc_bias = NULL;
//		delete[] fc7_norm_output_col2;
//		fc7_norm_output_col2 = NULL;
//
//		//end delete fc7_mbox_loc
//
//
//		//start run fc7_mbox_loc_perm
//		//gettimeofday(&startfc, NULL);
//		permuteParam fc7_mbox_loc_perm = { fc7_mbox_loc_perm_orders, fc7_mbox_loc_perm_shape, fc7_mbox_loc_output_transpose, fc7_mbox_loc_perm_output };
//		Permute(&fc7_mbox_loc_perm);
//		//gettimeofday(&endfc, NULL);
//		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
//		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
//		//cout << "fc7_mbox_loc_perm: " << endfctt - startfctt << "ms" << endl;
//		//end run fc7_mbox_loc_perm
//
//
//		//start run fc7_mbox_conf
//		//gettimeofday(&startfc, NULL);
//		im2row(fc7_norm_output, fc7_output_channel, fc7_output_height, fc7_output_width, fc7_mbox_conf_kernel_height, fc7_mbox_conf_kernel_width,
//			fc7_mbox_conf_pad_height, fc7_mbox_conf_pad_width, fc7_mbox_conf_stride_height, fc7_mbox_conf_stride_width, fc7_mbox_conf_dilation_height, fc7_mbox_conf_dilation_width, fc7_norm_output_col3);
//
//		convParam fc7_mbox_conf_param = { fc7_norm_output_col3, fc7_mbox_conf_new_coef, fc7_mbox_conf_bias, fc7_mbox_conf_output, fc7_output_channel, fc7_output_height, fc7_output_width, fc7_mbox_conf_kernel_height, fc7_mbox_conf_kernel_width, fc7_mbox_conf_output_channel, fc7_mbox_conf_output_height, fc7_mbox_conf_output_width };
//		convLayer(&fc7_mbox_conf_param, fc7_mbox_conf_withRELU);
//		Row_column_transpose(fc7_mbox_conf_output, fc7_mbox_conf_output_transpose, fc7_mbox_conf_output_height * fc7_mbox_conf_output_width, fc7_mbox_conf_output_channel);
//		//gettimeofday(&endfc, NULL);
//		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
//		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
//		//cout << "fc7_mbox_conf conv: " << endfctt - startfctt << "ms" << endl;
//		//end run fc7_mbox_conf
//
//		//start run fc7_mbox_conf_perm
//		//gettimeofday(&startfc, NULL);
//		permuteParam fc7_mbox_conf_perm = { fc7_mbox_conf_perm_orders, fc7_mbox_conf_perm_shape, fc7_mbox_conf_output_transpose, fc7_mbox_conf_perm_output };
//		Permute(&fc7_mbox_conf_perm);
//		//gettimeofday(&endfc, NULL);
//		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
//		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
//		//cout << "fc7_mbox_conf_perm: " << endfctt - startfctt << "ms" << endl;
//		//end run fc7_mbox_conf_perm
//
//		//start delete fc7_mbox_conf
//		delete[] fc7_norm_output;
//		fc7_norm_output = NULL;
//		delete[] fc7_mbox_conf_output;
//		fc7_mbox_conf_output = NULL;
//		delete[] fc7_mbox_conf_coef;
//		fc7_mbox_conf_coef = NULL;
//		delete[] fc7_mbox_conf_new_coef;
//		fc7_mbox_conf_new_coef = NULL;
//		delete[] fc7_mbox_conf_bias;
//		fc7_mbox_conf_bias = NULL;
//		delete[] fc7_norm_output_col3;
//		fc7_norm_output_col3 = NULL;
//
//		//end delete fc7_mbox_conf
//
//
//
//
//
//		//start run conv6_2
//		//gettimeofday(&startfc, NULL);
//		im2rowBycol(conv6_1_output, conv6_1_output_channel, conv6_1_output_height, conv6_1_output_width, conv6_2_kernel_height, conv6_2_kernel_width,
//			conv6_2_pad_height, conv6_2_pad_width, conv6_2_stride_height, conv6_2_stride_width, conv6_2_dilation_height, conv6_2_dilation_width, conv6_1_output_col);
//		convParam conv6_2_param = { conv6_1_output_col, conv6_2_new_coef, conv6_2_bias, conv6_2_output, conv6_1_output_channel, conv6_1_output_height, conv6_1_output_width,conv6_2_kernel_height, conv6_2_kernel_width, conv6_2_output_channel, conv6_2_output_height, conv6_2_output_width };
//		convLayer(&conv6_2_param, conv6_2_withRELU);
//		//gettimeofday(&endfc, NULL);
//		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
//		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
//		//cout << "conv6_2 conv: " << endfctt - startfctt << "ms" << endl;
//		//end run conv6_2
//
//
//		float *conv6_2_output2 = new float[conv6_2_output_channel * conv6_2_output_height * conv6_2_output_width];
//		Row_column_transpose(conv6_2_output, conv6_2_output2, conv6_2_output_height * conv6_2_output_width, conv6_2_output_channel);
//		//float *conv6_2_output1 = new float[conv6_2_output_channel * conv6_2_output_height * conv6_2_output_width];
//		//readFile("data/conv6_2_output", conv6_2_output1, conv6_2_output_height * conv6_2_output_width * conv6_2_output_channel * sizeof(float));
//
//
//
//
//
//
//
//
//
//		//start run conv6_2_mbox_loc
//		//gettimeofday(&startfc, NULL);
//		im2rowBycol(conv6_2_output, conv6_2_output_channel, conv6_2_output_height, conv6_2_output_width, conv6_2_mbox_loc_kernel_height, conv6_2_mbox_loc_kernel_width,
//			conv6_2_mbox_loc_pad_height, conv6_2_mbox_loc_pad_width, conv6_2_mbox_loc_stride_height, conv6_2_mbox_loc_stride_width, conv6_2_mbox_loc_dilation_height, conv6_2_mbox_loc_dilation_width, conv6_2_output_col2);
//		convParam conv6_2_mbox_loc_param = { conv6_2_output_col2, conv6_2_mbox_loc_new_coef, conv6_2_mbox_loc_bias, conv6_2_mbox_loc_output, conv6_2_output_channel, conv6_2_output_height, conv6_2_output_width,conv6_2_mbox_loc_kernel_height, conv6_2_mbox_loc_kernel_width, conv6_2_mbox_loc_output_channel, conv6_2_mbox_loc_output_height, conv6_2_mbox_loc_output_width };
//		convLayer(&conv6_2_mbox_loc_param, conv6_2_mbox_loc_withRELU);
//		Row_column_transpose(conv6_2_mbox_loc_output, conv6_2_mbox_loc_output_transpose, conv6_2_mbox_loc_output_height * conv6_2_mbox_loc_output_width, conv6_2_mbox_loc_output_channel);
//		//gettimeofday(&endfc, NULL);
//		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
//		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
//		//cout << "conv6_2_mbox_loc conv: " << endfctt - startfctt << "ms" << endl;
//		//end run conv6_2_mbox_loc
//
//
//
//		//start run conv6_2_mbox_loc_perm
//		//gettimeofday(&startfc, NULL);
//		permuteParam conv6_2_mbox_loc_perm = { conv6_2_mbox_loc_perm_orders, conv6_2_mbox_loc_perm_shape, conv6_2_mbox_loc_output_transpose, conv6_2_mbox_loc_perm_output };
//		Permute(&conv6_2_mbox_loc_perm);
//		//gettimeofday(&endfc, NULL);
//		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
//		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
//		//cout << "conv6_2_mbox_loc_perm: " << endfctt - startfctt << "ms" << endl;
//		//end run conv6_2_mbox_loc_perm
//
//
//		//start run conv6_2_mbox_conf
//		//gettimeofday(&startfc, NULL);
//		im2rowBycol(conv6_2_output, conv6_2_output_channel, conv6_2_output_height, conv6_2_output_width, conv6_2_mbox_conf_kernel_height, conv6_2_mbox_conf_kernel_width,
//			conv6_2_mbox_conf_pad_height, conv6_2_mbox_conf_pad_width, conv6_2_mbox_conf_stride_height, conv6_2_mbox_conf_stride_width, conv6_2_mbox_conf_dilation_height, conv6_2_mbox_conf_dilation_width, conv6_2_output_col3);
//
//		convParam conv6_2_mbox_conf_param = { conv6_2_output_col3, conv6_2_mbox_conf_new_coef, conv6_2_mbox_conf_bias, conv6_2_mbox_conf_output, conv6_2_output_channel, conv6_2_output_height, conv6_2_output_width, conv6_2_mbox_conf_kernel_height, conv6_2_mbox_conf_kernel_width, conv6_2_mbox_conf_output_channel, conv6_2_mbox_conf_output_height, conv6_2_mbox_conf_output_width };
//		convLayer(&conv6_2_mbox_conf_param, conv6_2_mbox_conf_withRELU);
//		Row_column_transpose(conv6_2_mbox_conf_output, conv6_2_mbox_conf_output_transpose, conv6_2_mbox_conf_output_height * conv6_2_mbox_conf_output_width, conv6_2_mbox_conf_output_channel);
//		//gettimeofday(&endfc, NULL);
//		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
//		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
//		//cout << "conv6_2_mbox_conf conv: " << endfctt - startfctt << "ms" << endl;
//		//end run conv6_2_mbox_conf
//
//		//start run conv6_2_mbox_conf_perm
//		//gettimeofday(&startfc, NULL);
//		permuteParam conv6_2_mbox_conf_perm = { conv6_2_mbox_conf_perm_orders, conv6_2_mbox_conf_perm_shape, conv6_2_mbox_conf_output_transpose, conv6_2_mbox_conf_perm_output };
//		Permute(&conv6_2_mbox_conf_perm);
//		//gettimeofday(&endfc, NULL);
//		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
//		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
//		//cout << "conv6_2_mbox_conf_perm: " << endfctt - startfctt << "ms" << endl;
//		//end run conv6_2_mbox_conf_perm
//
//
//		//start delete conv6_2
//		delete[] conv6_1_output;
//		conv6_1_output = NULL;
//		delete[] conv6_2_coef;
//		conv6_2_coef = NULL;
//		delete[] conv6_2_new_coef;
//		conv6_2_new_coef = NULL;
//		delete[] conv6_2_bias;
//		conv6_2_bias = NULL;
//		delete[] conv6_1_output_col;
//		conv6_1_output_col = NULL;
//		//end delete conv6_2
//
//		//start delete conv6_2_mbox_loc
//		delete[] conv6_2_mbox_loc_coef;
//		conv6_2_mbox_loc_coef = NULL;
//		delete[] conv6_2_mbox_loc_new_coef;
//		conv6_2_mbox_loc_new_coef = NULL;
//		delete[] conv6_2_mbox_loc_bias;
//		conv6_2_mbox_loc_bias = NULL;
//		delete[] conv6_2_output_col2;
//		conv6_2_output_col2 = NULL;
//		delete[] conv6_2_mbox_loc_output;
//		conv6_2_mbox_loc_output = NULL;
//		//end delete conv6_2_mbox_loc
//
//		//start delete conv6_2_mbox_loc_perm
//		delete[] conv6_2_mbox_loc_output_transpose;
//		conv6_2_mbox_loc_output_transpose = NULL;
//		//end delete conv6_2_mbox_loc_perm
//
//
//		//start delete conv6_2_mbox_conf
//		delete[] conv6_2_mbox_conf_output;
//		conv6_2_mbox_conf_output = NULL;
//		delete[] conv6_2_mbox_conf_coef;
//		conv6_2_mbox_conf_coef = NULL;
//		delete[] conv6_2_mbox_conf_new_coef;
//		conv6_2_mbox_conf_new_coef = NULL;
//		delete[] conv6_2_mbox_conf_bias;
//		conv6_2_mbox_conf_bias = NULL;
//		delete[] conv6_2_output_col3;
//		conv6_2_output_col3 = NULL;
//
//		//end delete conv6_2_mbox_conf
//
//		//start run conv7_1   
//		//gettimeofday(&startfc, NULL);
//		im2rowBycol(conv6_2_output, conv6_2_output_channel, conv6_2_output_height, conv6_2_output_width, conv7_1_kernel_height, conv7_1_kernel_width,
//			conv7_1_pad_height, conv7_1_pad_width, conv7_1_stride_height, conv7_1_stride_width, conv7_1_dilation_height, conv7_1_dilation_width, conv6_2_output_col);
//		convParam conv7_1_param = { conv6_2_output_col, conv7_1_new_coef, conv7_1_bias, conv7_1_output, conv6_2_output_channel, conv6_2_output_height, conv6_2_output_width,
//			conv7_1_kernel_height, conv7_1_kernel_width, conv7_1_output_channel, conv7_1_output_height, conv7_1_output_width };
//		convLayer(&conv7_1_param, conv7_1_withRELU);
//		//gettimeofday(&endfc, NULL);
//		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
//		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
//		//cout << "conv7_1 conv: " << endfctt - startfctt << "ms" << endl;
//		//end run conv7_1
//
//
//		float *conv7_1_output2 = new float[conv7_1_output_channel * conv7_1_output_height * conv7_1_output_width];
//		Row_column_transpose(conv7_1_output, conv7_1_output2, conv7_1_output_height * conv7_1_output_width, conv7_1_output_channel);
//		//float *conv7_1_output1 = new float[conv7_1_output_channel * conv7_1_output_height * conv7_1_output_width];
//		//readFile("data/conv7_1_output", conv7_1_output1, conv7_1_output_height * conv7_1_output_width * conv7_1_output_channel * sizeof(float));
//
//
//
//
//		//start delete conv7_1
//		delete[] conv6_2_output;
//		conv6_2_output = NULL;
//		delete[] conv7_1_coef;
//		conv7_1_coef = NULL;
//		delete[] conv7_1_new_coef;
//		conv7_1_new_coef = NULL;
//		delete[] conv7_1_bias;
//		conv7_1_bias = NULL;
//		delete[] conv6_2_output_col;
//		conv6_2_output_col = NULL;
//		//end delete conv7_1
//
//		//start run conv7_2
//		//gettimeofday(&startfc, NULL);
//		im2rowBycol(conv7_1_output, conv7_1_output_channel, conv7_1_output_height, conv7_1_output_width, conv7_2_kernel_height, conv7_2_kernel_width,
//			conv7_2_pad_height, conv7_2_pad_width, conv7_2_stride_height, conv7_2_stride_width, conv7_2_dilation_height, conv7_2_dilation_width, conv7_1_output_col);
//		convParam conv7_2_param = { conv7_1_output_col, conv7_2_new_coef, conv7_2_bias, conv7_2_output, conv7_1_output_channel, conv7_1_output_height, conv7_1_output_width,conv7_2_kernel_height, conv7_2_kernel_width, conv7_2_output_channel, conv7_2_output_height, conv7_2_output_width };
//		convLayer(&conv7_2_param, conv7_2_withRELU);
//		//gettimeofday(&endfc, NULL);
//		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
//		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
//		//cout << "conv7_2 conv: " << endfctt - startfctt << "ms" << endl;
//		//end run conv7_2
//
//
//		//float *conv7_2_output2 = new float[conv7_2_output_channel * conv7_2_output_height * conv7_2_output_width];
//		//Row_column_transpose(conv7_2_output, conv7_2_output2, conv7_2_output_height * conv7_2_output_width, conv7_2_output_channel);
//		//float *conv7_2_output1 = new float[conv7_2_output_channel * conv7_2_output_height * conv7_2_output_width];
//		//readFile("data/conv7_2_output", conv7_2_output1, conv7_2_output_height * conv7_2_output_width * conv7_2_output_channel * sizeof(float));
//
//
//
//
//
//		//start run conv7_2_mbox_loc
//		//gettimeofday(&startfc, NULL);
//		im2rowBycol(conv7_2_output, conv7_2_output_channel, conv7_2_output_height, conv7_2_output_width, conv7_2_mbox_loc_kernel_height, conv7_2_mbox_loc_kernel_width,
//			conv7_2_mbox_loc_pad_height, conv7_2_mbox_loc_pad_width, conv7_2_mbox_loc_stride_height, conv7_2_mbox_loc_stride_width, conv7_2_mbox_loc_dilation_height, conv7_2_mbox_loc_dilation_width, conv7_2_output_col2);
//		convParam conv7_2_mbox_loc_param = { conv7_2_output_col2, conv7_2_mbox_loc_new_coef, conv7_2_mbox_loc_bias, conv7_2_mbox_loc_output, conv7_2_output_channel, conv7_2_output_height, conv7_2_output_width, conv7_2_mbox_loc_kernel_height, conv7_2_mbox_loc_kernel_width, conv7_2_mbox_loc_output_channel, conv7_2_mbox_loc_output_height, conv7_2_mbox_loc_output_width };
//		convLayer(&conv7_2_mbox_loc_param, conv7_2_mbox_loc_withRELU);
//		Row_column_transpose(conv7_2_mbox_loc_output, conv7_2_mbox_loc_output_transpose, conv7_2_mbox_loc_output_height * conv7_2_mbox_loc_output_width, conv7_2_mbox_loc_output_channel);
//		//gettimeofday(&endfc, NULL);
//		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
//		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
//		//cout << "conv7_2_mbox_loc conv: " << endfctt - startfctt << "ms" << endl;
//		//end run conv7_2_mbox_loc
//
//		//float *conv7_2_mbox_loc_output1 = new float[conv7_2_mbox_loc_output_height * conv7_2_mbox_loc_output_width*conv7_2_mbox_loc_output_channel];
//		//readFile("data/conv7_2_mbox_loc_output", conv7_2_mbox_loc_output1, conv7_2_mbox_loc_output_height * conv7_2_mbox_loc_output_width*conv7_2_mbox_loc_output_channel * sizeof(float));
//
//
//		//start run conv7_2_mbox_loc_perm
//		//gettimeofday(&startfc, NULL);
//		permuteParam conv7_2_mbox_loc_perm = { conv7_2_mbox_loc_perm_orders, conv7_2_mbox_loc_perm_shape, conv7_2_mbox_loc_output_transpose, conv7_2_mbox_loc_perm_output };
//		Permute(&conv7_2_mbox_loc_perm);
//		//gettimeofday(&endfc, NULL);
//		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
//		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
//		//cout << "conv7_2_mbox_loc_perm: " << endfctt - startfctt << "ms" << endl;
//		//end run conv7_2_mbox_loc_perm
//
//
//		//start run conv7_2_mbox_conf
//		//gettimeofday(&startfc, NULL);
//		im2rowBycol(conv7_2_output, conv7_2_output_channel, conv7_2_output_height, conv7_2_output_width, conv7_2_mbox_conf_kernel_height, conv7_2_mbox_conf_kernel_width,
//			conv7_2_mbox_conf_pad_height, conv7_2_mbox_conf_pad_width, conv7_2_mbox_conf_stride_height, conv7_2_mbox_conf_stride_width, conv7_2_mbox_conf_dilation_height, conv7_2_mbox_conf_dilation_width, conv7_2_output_col3);
//
//		convParam conv7_2_mbox_conf_param = { conv7_2_output_col3, conv7_2_mbox_conf_new_coef, conv7_2_mbox_conf_bias, conv7_2_mbox_conf_output, conv7_2_output_channel, conv7_2_output_height, conv7_2_output_width, conv7_2_mbox_conf_kernel_height, conv7_2_mbox_conf_kernel_width, conv7_2_mbox_conf_output_channel, conv7_2_mbox_conf_output_height, conv7_2_mbox_conf_output_width };
//		convLayer(&conv7_2_mbox_conf_param, conv7_2_mbox_conf_withRELU);
//		Row_column_transpose(conv7_2_mbox_conf_output, conv7_2_mbox_conf_output_transpose, conv7_2_mbox_conf_output_height * conv7_2_mbox_conf_output_width, conv7_2_mbox_conf_output_channel);
//		//gettimeofday(&endfc, NULL);
//		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
//		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
//		//cout << "conv7_2_mbox_conf conv: " << endfctt - startfctt << "ms" << endl;
//		//end run conv7_2_mbox_conf
//
//
//		//float *conv7_2_mbox_conf_output1 = new float[conv7_2_mbox_conf_output_height * conv7_2_mbox_conf_output_width*conv7_2_mbox_conf_output_channel];
//		//readFile("data/conv7_2_mbox_conf_output", conv7_2_mbox_conf_output1, conv7_2_mbox_conf_output_height * conv7_2_mbox_conf_output_width*conv7_2_mbox_conf_output_channel * sizeof(float));
//
//
//
//		//start run conv7_2_mbox_conf_perm
//		//gettimeofday(&startfc, NULL);
//		permuteParam conv7_2_mbox_conf_perm = { conv7_2_mbox_conf_perm_orders, conv7_2_mbox_conf_perm_shape, conv7_2_mbox_conf_output_transpose, conv7_2_mbox_conf_perm_output };
//		Permute(&conv7_2_mbox_conf_perm);
//		//gettimeofday(&endfc, NULL);
//		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
//		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
//		//cout << "conv7_2_mbox_conf_perm: " << endfctt - startfctt << "ms" << endl;
//		//end run conv7_2_mbox_conf_perm
//
//		//start delete conv7_2
//		delete[] conv7_1_output;
//		conv7_1_output = NULL;
//		delete[] conv7_2_coef;
//		conv7_2_coef = NULL;
//		delete[] conv7_2_new_coef;
//		conv7_2_new_coef = NULL;
//		delete[] conv7_2_bias;
//		conv7_2_bias = NULL;
//		delete[] conv7_1_output_col;
//		conv7_1_output_col = NULL;
//		//end delete conv7_2
//
//		//start delete conv7_2_mbox_loc
//		delete[] conv7_2_mbox_loc_coef;
//		conv7_2_mbox_loc_coef = NULL;
//		delete[] conv7_2_mbox_loc_new_coef;
//		conv7_2_mbox_loc_new_coef = NULL;
//		delete[] conv7_2_mbox_loc_bias;
//		conv7_2_mbox_loc_bias = NULL;
//		delete[] conv7_2_output_col2;
//		conv7_2_output_col2 = NULL;
//		delete[] conv7_2_mbox_loc_output;
//		conv7_2_mbox_loc_output = NULL;
//		//end delete conv7_2_mbox_loc
//
//		//start delete conv7_2_mbox_loc_perm
//		delete[] conv7_2_mbox_loc_output_transpose;
//		conv7_2_mbox_loc_output_transpose = NULL;
//		//end delete conv7_2_mbox_loc_perm
//
//
//		//start delete conv7_2_mbox_conf
//		delete[] conv7_2_mbox_conf_output;
//		conv7_2_mbox_conf_output = NULL;
//		delete[] conv7_2_mbox_conf_coef;
//		conv7_2_mbox_conf_coef = NULL;
//		delete[] conv7_2_mbox_conf_new_coef;
//		conv7_2_mbox_conf_new_coef = NULL;
//		delete[] conv7_2_mbox_conf_bias;
//		conv7_2_mbox_conf_bias = NULL;
//		delete[] conv7_2_output_col3;
//		conv7_2_output_col3 = NULL;
//
//		//end delete conv7_2_mbox_conf
//
//
//
//
//		//start run conv8_1
//		//gettimeofday(&startfc, NULL);
//		im2rowBycol(conv7_2_output, conv7_2_output_channel, conv7_2_output_height, conv7_2_output_width, conv8_1_kernel_height, conv8_1_kernel_width,
//			conv8_1_pad_height, conv8_1_pad_width, conv8_1_stride_height, conv8_1_stride_width, conv8_1_dilation_height, conv8_1_dilation_width, conv7_2_output_col);
//		convParam conv8_1_param = { conv7_2_output_col, conv8_1_new_coef, conv8_1_bias, conv8_1_output, conv7_2_output_channel, conv7_2_output_height, conv7_2_output_width,conv8_1_kernel_height, conv8_1_kernel_width, conv8_1_output_channel, conv8_1_output_height, conv8_1_output_width };
//		convLayer(&conv8_1_param, conv8_1_withRELU);
//		//gettimeofday(&endfc, NULL);
//		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
//		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
//		//cout << "conv8_1 conv: " << endfctt - startfctt << "ms" << endl;  
//		////end run conv8_1
//
//		//start delete conv8_1
//		delete[] conv7_2_output;
//		conv7_2_output = NULL;
//		delete[] conv8_1_coef;
//		conv8_1_coef = NULL;
//		delete[] conv8_1_new_coef;
//		conv8_1_new_coef = NULL;
//		delete[] conv8_1_bias;
//		conv8_1_bias = NULL;
//		delete[] conv7_2_output_col;
//		conv7_2_output_col = NULL;
//		//end delete conv8_1   
//
//
//		//float *conv8_1_output2 = new float[conv8_1_output_channel * conv8_1_output_height * conv8_1_output_width];
//		//Row_column_transpose(conv8_1_output, conv8_1_output2, conv8_1_output_height * conv8_1_output_width, conv8_1_output_channel);
//		//float *conv8_1_output1 = new float[conv8_1_output_channel * conv8_1_output_height * conv8_1_output_width];
//		//readFile("data/conv8_1_output", conv8_1_output1, conv8_1_output_height * conv8_1_output_width * conv8_1_output_channel * sizeof(float));
//
//
//		//start run conv8_2
//		//gettimeofday(&startfc, NULL);
//		im2rowBycol(conv8_1_output, conv8_1_output_channel, conv8_1_output_height, conv8_1_output_width, conv8_2_kernel_height, conv8_2_kernel_width,
//			conv8_2_pad_height, conv8_2_pad_width, conv8_2_stride_height, conv8_2_stride_width, conv8_2_dilation_height, conv8_2_dilation_width, conv8_1_output_col);
//		convParam conv8_2_param = { conv8_1_output_col, conv8_2_new_coef, conv8_2_bias, conv8_2_output, conv8_1_output_channel, conv8_1_output_height, conv8_1_output_width, conv8_2_kernel_height, conv8_2_kernel_width, conv8_2_output_channel, conv8_2_output_height, conv8_2_output_width };
//		convLayer(&conv8_2_param, conv8_2_withRELU);
//		//gettimeofday(&endfc, NULL);
//		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
//		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
//		//cout << "conv8_2 conv: " << endfctt - startfctt << "ms" << endl;
//		//end run conv8_2
//
//		//float *conv8_2_output1 = new float[conv8_2_output_channel * conv8_2_output_height * conv8_2_output_width];
//		//Row_column_transpose(conv8_2_output, conv8_2_output1, conv8_2_output_height * conv8_2_output_width, conv8_2_output_channel);
//		//float *conv8_2_output2 = new float[conv8_2_output_channel * conv8_2_output_height * conv8_2_output_width];
//		//readFile("data/conv8_2_output", conv8_2_output2, conv8_2_output_height * conv8_2_output_width * conv8_2_output_channel * sizeof(float));
//
//
//
//
//		//start run conv8_2_mbox_loc
//		//gettimeofday(&startfc, NULL);
//		im2rowBycol(conv8_2_output, conv8_2_output_channel, conv8_2_output_height, conv8_2_output_width, conv8_2_mbox_loc_kernel_height, conv8_2_mbox_loc_kernel_width,
//			conv8_2_mbox_loc_pad_height, conv8_2_mbox_loc_pad_width, conv8_2_mbox_loc_stride_height, conv8_2_mbox_loc_stride_width, conv8_2_mbox_loc_dilation_height, conv8_2_mbox_loc_dilation_width, conv8_2_output_col2);
//		convParam conv8_2_mbox_loc_param = { conv8_2_output_col2, conv8_2_mbox_loc_new_coef, conv8_2_mbox_loc_bias, conv8_2_mbox_loc_output, conv8_2_output_channel, conv8_2_output_height, conv8_2_output_width, conv8_2_mbox_loc_kernel_height, conv8_2_mbox_loc_kernel_width, conv8_2_mbox_loc_output_channel, conv8_2_mbox_loc_output_height, conv8_2_mbox_loc_output_width };
//		convLayer(&conv8_2_mbox_loc_param, conv8_2_mbox_loc_withRELU);
//		Row_column_transpose(conv8_2_mbox_loc_output, conv8_2_mbox_loc_output_transpose, conv8_2_mbox_loc_output_height * conv8_2_mbox_loc_output_width, conv8_2_mbox_loc_output_channel);
//		//gettimeofday(&endfc, NULL);
//		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
//		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
//		//cout << "conv8_2_mbox_loc conv: " << endfctt - startfctt << "ms" << endl;
//		//end run conv8_2_mbox_loc
//
//
//
//		//start run conv8_2_mbox_loc_perm
//		//gettimeofday(&startfc, NULL);
//		permuteParam conv8_2_mbox_loc_perm = { conv8_2_mbox_loc_perm_orders, conv8_2_mbox_loc_perm_shape, conv8_2_mbox_loc_output_transpose, conv8_2_mbox_loc_perm_output };
//		Permute(&conv8_2_mbox_loc_perm);
//		//gettimeofday(&endfc, NULL);
//		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
//		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
//		//cout << "conv8_2_mbox_loc_perm: " << endfctt - startfctt << "ms" << endl;
//		//end run conv8_2_mbox_loc_perm
//
//
//		//start run conv8_2_mbox_conf
//		//gettimeofday(&startfc, NULL);
//		im2rowBycol(conv8_2_output, conv8_2_output_channel, conv8_2_output_height, conv8_2_output_width, conv8_2_mbox_conf_kernel_height, conv8_2_mbox_conf_kernel_width,
//			conv8_2_mbox_conf_pad_height, conv8_2_mbox_conf_pad_width, conv8_2_mbox_conf_stride_height, conv8_2_mbox_conf_stride_width, conv8_2_mbox_conf_dilation_height, conv8_2_mbox_conf_dilation_width, conv8_2_output_col3);
//
//		convParam conv8_2_mbox_conf_param = { conv8_2_output_col3, conv8_2_mbox_conf_new_coef, conv8_2_mbox_conf_bias, conv8_2_mbox_conf_output, conv8_2_output_channel, conv8_2_output_height, conv8_2_output_width, conv8_2_mbox_conf_kernel_height, conv8_2_mbox_conf_kernel_width, conv8_2_mbox_conf_output_channel, conv8_2_mbox_conf_output_height, conv8_2_mbox_conf_output_width };
//		convLayer(&conv8_2_mbox_conf_param, conv8_2_mbox_conf_withRELU);
//		Row_column_transpose(conv8_2_mbox_conf_output, conv8_2_mbox_conf_output_transpose, conv8_2_mbox_conf_output_height * conv8_2_mbox_conf_output_width, conv8_2_mbox_conf_output_channel);
//		//gettimeofday(&endfc, NULL);
//		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
//		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
//		//cout << "conv8_2_mbox_conf conv: " << endfctt - startfctt << "ms" << endl;
//		//end run conv8_2_mbox_conf
//
//		//start run conv8_2_mbox_conf_perm
//		//gettimeofday(&startfc, NULL);
//		permuteParam conv8_2_mbox_conf_perm = { conv8_2_mbox_conf_perm_orders, conv8_2_mbox_conf_perm_shape, conv8_2_mbox_conf_output_transpose, conv8_2_mbox_conf_perm_output };
//		Permute(&conv8_2_mbox_conf_perm);
//		//gettimeofday(&endfc, NULL);
//		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
//		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
//		//cout << "conv8_2_mbox_conf_perm: " << endfctt - startfctt << "ms" << endl;
//		//end run conv8_2_mbox_conf_perm
//
//
//		//start delete conv8_2
//		delete[] conv8_1_output;
//		conv8_1_output = NULL;
//		delete[] conv8_2_coef;
//		conv8_2_coef = NULL;
//		delete[] conv8_2_new_coef;
//		conv8_2_new_coef = NULL;
//		delete[] conv8_2_bias;
//		conv8_2_bias = NULL;
//		delete[] conv8_1_output_col;
//		conv8_1_output_col = NULL;
//		//end delete conv8_2
//
//		//start delete conv8_2_mbox_loc
//		delete[] conv8_2_mbox_loc_coef;
//		conv8_2_mbox_loc_coef = NULL;
//		delete[] conv8_2_mbox_loc_new_coef;
//		conv8_2_mbox_loc_new_coef = NULL;
//		delete[] conv8_2_mbox_loc_bias;
//		conv8_2_mbox_loc_bias = NULL;
//		delete[] conv8_2_output_col2;
//		conv8_2_output_col2 = NULL;
//		delete[] conv8_2_mbox_loc_output;
//		conv8_2_mbox_loc_output = NULL;
//		//end delete conv8_2_mbox_loc
//
//		//start delete conv8_2_mbox_loc_perm
//		delete[] conv8_2_mbox_loc_output_transpose;
//		conv8_2_mbox_loc_output_transpose = NULL;
//		//end delete conv8_2_mbox_loc_perm
//
//
//		//start delete conv8_2_mbox_conf
//		delete[] conv8_2_mbox_conf_output;
//		conv8_2_mbox_conf_output = NULL;
//		delete[] conv8_2_mbox_conf_coef;
//		conv8_2_mbox_conf_coef = NULL;
//		delete[] conv8_2_mbox_conf_new_coef;
//		conv8_2_mbox_conf_new_coef = NULL;
//		delete[] conv8_2_mbox_conf_bias;
//		conv8_2_mbox_conf_bias = NULL;
//		delete[] conv8_2_output_col3;
//		conv8_2_output_col3 = NULL;
//
//		//end delete conv8_2_mbox_conf
//
//
//		//start run fc7_mbox_priorbox
//		//gettimeofday(&startfc, NULL);
//		priorBoxParam fc7_mbox_prior_param = { fc7_output_height, fc7_output_width, img_heighteight, img_widthidth, fc7_mbox_prior_step_h, fc7_mbox_prior_step_w, fc7_mbox_prior_min_sizes_, fc7_mbox_prior_max_sizes_, fc7_mbox_prior_aspect_ratios_, fc7_mbox_prior_num_priors_, fc7_mbox_prior_flip_, fc7_mbox_prior_clip_, fc7_mbox_prior_variance_, fc7_mbox_prior_offset_, fc7_mbox_prior_output };
//		PriorBox(&fc7_mbox_prior_param);
//		//gettimeofday(&endfc, NULL);
//		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
//		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
//		//cout << "fc7_mbox_prior: " << endfctt - startfctt << "ms" << endl;
//		//end run fc7_mbox_priorbox
//
//		//start run conv6_2_mbox_priorbox
//		//gettimeofday(&startfc, NULL);
//		priorBoxParam conv6_2_mbox_prior_param = { conv6_2_output_height, conv6_2_output_width, img_heighteight, img_widthidth, conv6_2_mbox_prior_step_h, conv6_2_mbox_prior_step_w, conv6_2_mbox_prior_min_sizes_, conv6_2_mbox_prior_max_sizes_, conv6_2_mbox_prior_aspect_ratios_, conv6_2_mbox_prior_num_priors_, conv6_2_mbox_prior_flip_, conv6_2_mbox_prior_clip_, conv6_2_mbox_prior_variance_, conv6_2_mbox_prior_offset_, conv6_2_mbox_prior_output };
//		PriorBox(&conv6_2_mbox_prior_param);
//		//gettimeofday(&endfc, NULL);
//		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
//		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
//		//cout << "conv6_2_mbox_prior: " << endfctt - startfctt << "ms" << endl;
//		//end run conv6_2_mbox_priorbox
//
//		//start run conv7_2_mbox_priorbox
//		//gettimeofday(&startfc, NULL);
//		priorBoxParam conv7_2_mbox_prior_param = { conv7_2_output_height, conv7_2_output_width, img_heighteight, img_widthidth, conv7_2_mbox_prior_step_h, conv7_2_mbox_prior_step_w, conv7_2_mbox_prior_min_sizes_, conv7_2_mbox_prior_max_sizes_, conv7_2_mbox_prior_aspect_ratios_, conv7_2_mbox_prior_num_priors_, conv7_2_mbox_prior_flip_, conv7_2_mbox_prior_clip_, conv7_2_mbox_prior_variance_, conv7_2_mbox_prior_offset_, conv7_2_mbox_prior_output };
//		PriorBox(&conv7_2_mbox_prior_param);
//		//gettimeofday(&endfc, NULL);
//		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
//		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
//		//cout << "conv7_2_mbox_prior: " << endfctt - startfctt << "ms" << endl;
//		//end run conv7_2_mbox_priorbox
//
//		//start run conv8_2_mbox_priorbox
//		//gettimeofday(&startfc, NULL);
//		priorBoxParam conv8_2_mbox_prior_param = { conv8_2_output_height, conv8_2_output_width, img_heighteight, img_widthidth, conv8_2_mbox_prior_step_h, conv8_2_mbox_prior_step_w, conv8_2_mbox_prior_min_sizes_, conv8_2_mbox_prior_max_sizes_, conv8_2_mbox_prior_aspect_ratios_, conv8_2_mbox_prior_num_priors_, conv8_2_mbox_prior_flip_, conv8_2_mbox_prior_clip_, conv8_2_mbox_prior_variance_, conv8_2_mbox_prior_offset_, conv8_2_mbox_prior_output };
//		PriorBox(&conv8_2_mbox_prior_param);
//		//gettimeofday(&endfc, NULL);
//		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
//		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
//		//cout << "conv8_2_mbox_prior: " << endfctt - startfctt << "ms" << endl;
//		//end run conv8_2_mbox_priorbox
//
//
//		//start run mbox_priorbox
//		//gettimeofday(&startfc, NULL);
//		concatParam mbox_priorbox_param = { DataParams, mbox_priorbox_output_Data, shape, -1, mbox_priorbox_axis };
//		Concat(&mbox_priorbox_param);
//		//gettimeofday(&endfc, NULL);
//		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
//		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
//		//cout << "mbox_priorbox: " << endfctt - startfctt << "ms" << endl;
//		//end run mbox_priorbox
//
//		//start delete fc7_mbox_prior
//		delete[] fc7_mbox_prior_output;
//		fc7_mbox_prior_output = NULL;
//		//end delete fc7_mbox_prior
//
//		//start delete conv6_2_mbox_prior
//		delete[] conv6_2_mbox_prior_output;
//		conv6_2_mbox_prior_output = NULL;
//		//end delete conv6_2_mbox_prior
//
//		//start delete conv7_2_mbox_prior
//		delete[] conv7_2_mbox_prior_output;
//		conv7_2_mbox_prior_output = NULL;
//		//end delete conv7_2_mbox_prior
//
//		//start delete conv8_2_mbox_prior
//		delete[] conv8_2_mbox_prior_output;
//		conv8_2_mbox_prior_output = NULL;
//		//end delete conv8_2_mbox_prior
//
//
//
//		//start run mbox_loc
//		//gettimeofday(&startfc, NULL);
//		concatParam mbox_loc_param = { DataParams_loc, mbox_loc_output_Data, shape_loc, -1, mbox_loc_axis };
//		Concat(&mbox_loc_param);
//		//gettimeofday(&endfc, NULL);
//		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
//		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
//		//cout << "mbox_loc: " << endfctt - startfctt << "ms" << endl;
//		//end run mbox_loc
//
//		//start delete mbox_loc
//		delete[] fc7_mbox_loc_perm_output;
//		fc7_mbox_loc_perm_output = NULL;
//
//		delete[] conv6_2_mbox_loc_perm_output;
//		conv6_2_mbox_loc_perm_output = NULL;
//
//		delete[] conv7_2_mbox_loc_perm_output;
//		conv7_2_mbox_loc_perm_output = NULL;
//
//		delete[] conv8_2_mbox_loc_perm_output;
//		conv8_2_mbox_loc_perm_output = NULL;
//		//end delete mbox_loc
//
//
//
//		//start run mbox_conf
//		//gettimeofday(&startfc, NULL);
//		concatParam mbox_conf_param = { DataParams_conf, mbox_conf_output_Data, shape_conf, -1, mbox_conf_axis };
//		Concat(&mbox_conf_param);
//		//gettimeofday(&endfc, NULL);
//		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
//		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
//		//cout << "mbox_conf: " << endfctt - startfctt << "ms" << endl;
//		//end run mbox_conf
//
//
//		//start delete mbox_conf
//		delete[] fc7_mbox_conf_perm_output;
//		fc7_mbox_conf_perm_output = NULL;
//
//		delete[] conv6_2_mbox_conf_perm_output;
//		conv6_2_mbox_conf_perm_output = NULL;
//
//		delete[] conv7_2_mbox_conf_perm_output;
//		conv7_2_mbox_conf_perm_output = NULL;
//
//		delete[] conv8_2_mbox_conf_perm_output;
//		conv8_2_mbox_conf_perm_output = NULL;
//		//end delete mbox_conf
//
//
//
//
//		//float *input = new float[1 * 420 * 2];
//		//input = mbox_conf_param.output_data;
//		//readFile("data/mbox_conf_reshape_output", input, 1 * 420 * 2 * sizeof(float));
//		int axis = 2;
//		//vector<int> shape;
//		shape.clear();
//		shape.push_back(1);
//		shape.push_back(420);
//		shape.push_back(6);
//		float *conf_soft_output = new float[1 * 420 * 6];
//		softmaxParam mbox_conf_softmax_param = { mbox_conf_param.output_data, conf_soft_output, shape, axis };
//		Softmax(&mbox_conf_softmax_param);
//
//
//
//		int num_classes = 6;
//		int share_location = 1;
//		int background_label_id = 0;
//		int code_type = CENTER_SIZE;
//		int variance_encoded_in_target = 0;
//		int keep_top_k = 200;
//		float confidence_threshold = 0.3;
//		float nms_threshold = 0.449999988079;
//		float eta = 1.0;
//		int top_k = 400;
//		vector<int> mbox_loc_shape(2, 1);
//		mbox_loc_shape[1] = 1680;
//		vector<int> mbox_conf_flatten_shape(2, 1);
//		mbox_conf_flatten_shape[1] = 840 * 3;
//		vector<int> mbox_priorbox_shape(3, 1);
//		mbox_priorbox_shape[1] = 2;
//		mbox_priorbox_shape[2] = 1680;
//		int object_num;
//		detectionParam detection_out_param = { num_classes, share_location, background_label_id, code_type, variance_encoded_in_target, keep_top_k, confidence_threshold, nms_threshold, eta, top_k, mbox_loc_shape, mbox_conf_flatten_shape, mbox_priorbox_shape, mbox_loc_param.output_data, mbox_conf_softmax_param.output_data, mbox_priorbox_param.output_data };
//		float *result = Detection_output(&detection_out_param, object_num);
//
//		vector<vector<float>> objects;
//		vector<float>object(6, 0);//class,conf,xmin,ymin,xmax,ymax
//		for (int i = 0; i < object_num; i++) {
//			object[0] = result[i * 7 + 1];
//			object[1] = result[i * 7 + 2];
//			object[2] = result[i * 7 + 3];
//			object[3] = result[i * 7 + 4];
//			object[4] = result[i * 7 + 5];
//			object[5] = result[i * 7 + 6];
//			objects.push_back(object);
//
//		}
//		map<int, string> *label_to_name = new map<int, string>[num_classes];
//		map<int, string> *label_to_display_name = new map<int, string>[num_classes];
//		ReadLabelFromTextFile("./data/labelmap.prototxt", label_to_name, label_to_display_name);
//		cout << "object+num:" << object_num << endl;
//
//		delete[] mbox_loc_param.output_data;
//		mbox_loc_param.output_data = NULL;
//		delete[] mbox_conf_softmax_param.output_data;
//		mbox_conf_softmax_param.output_data = NULL;
//		delete[] mbox_priorbox_param.output_data;
//		mbox_priorbox_param.output_data = NULL;
//		delete[] result;
//		result = NULL;
//
//		return 0;
//#endif // SSD



#ifdef YOLO

		clock_t  clockBegin, clockEnd;
		vector<int> vec;

		int imgc = 3;
		int imgh = 416;
		int imgw = 416;
		int classes = 80;

		float *img = new float[imgh * imgw * imgc];
		readFile("input_img", img, imgh * imgw * imgc * sizeof(float));


		//ini conv1
		int conv1_c = 16;
		int conv1_kernel_h = 3;
		int conv1_kernel_w = 3;
		int conv1_h = 416;
		int conv1_w = 416;
		int conv1_p_h = 1;
		int conv1_p_w = 1;
		int conv1_s_h = 1;
		int conv1_s_w = 1;
		int conv1_d_h = 1;
		int conv1_d_w = 1;
		int conv1_act = 2;
		float *imgcol = new float[conv1_h * conv1_w * conv1_kernel_h *conv1_kernel_w*imgc];
		float *conv1_b = new float[conv1_c];
		float *conv1_coef = new float[conv1_kernel_h * conv1_kernel_w * imgc * conv1_c];
		float *conv1_coef_t = new float[conv1_kernel_h * conv1_kernel_w * imgc * conv1_c];
		float *conv1_out = new float[conv1_w * conv1_h * conv1_c];
		vec.push_back(0);
		readFile1("conv1_cof", conv1_b, conv1_c * sizeof(float), vec);
		vec.push_back(16 * sizeof(float));
		readFile1("conv1_cof", conv1_coef, conv1_kernel_h * conv1_kernel_w * imgc * conv1_c * sizeof(float), vec);
		vec.push_back(conv1_kernel_h * conv1_kernel_w * imgc * conv1_c * sizeof(float));
		Row_column_transpose(conv1_coef, conv1_coef_t, conv1_c, conv1_kernel_h * conv1_kernel_w * imgc);

		//ini pool1
		int pool1_inC = 16;
		int pool1_inH = 416;
		int pool1_inW = 416;
		int pool1_pad = 0;
		int pool1_knlH = 2;
		int pool1_knlW = 2;
		int pool1_stride = 2;
		int pool1_outC = pool1_inC;
		int pool1_outH = 208;
		int pool1_outW = 208;
		float * pool1_output = new float[pool1_outH * pool1_outW * pool1_outC];

		vec.clear();
		//ini conv2
		int conv2_c = 32;
		int conv2_kernel_h = 3;
		int conv2_kernel_w = 3;
		int conv2_h = 208;
		int conv2_w = 208;
		int conv2_p_h = 1;
		int conv2_p_w = 1;
		int conv2_s_h = 1;
		int conv2_s_w = 1;
		int conv2_d_h = 1;
		int conv2_d_w = 1;
		int conv2_act = 2;
		float *pool1_col = new float[conv2_h * conv2_w * conv2_kernel_h *conv2_kernel_w*pool1_inC];
		float *conv2_b = new float[conv2_c];
		float *conv2_coef = new float[conv2_kernel_h * conv2_kernel_w * pool1_inC * conv2_c];
		float *conv2_coef_t = new float[conv2_kernel_h * conv2_kernel_w * pool1_inC * conv2_c];
		float *conv2_out = new float[conv2_w * conv2_h * conv2_c];
		vec.push_back(0);
		readFile1("conv2_cof", conv2_b, conv2_c * sizeof(float), vec);
		vec.push_back(conv2_c * sizeof(float));
		readFile1("conv2_cof", conv2_coef, conv2_kernel_h * conv2_kernel_w * pool1_inC * conv2_c * sizeof(float), vec);
		vec.push_back(conv2_kernel_h * conv2_kernel_w * pool1_inC * conv2_c * sizeof(float));
		Row_column_transpose(conv2_coef, conv2_coef_t, conv2_c, conv2_kernel_h * conv2_kernel_w * pool1_inC);



		//ini pool2
		int pool2_inC = 32;
		int pool2_inH = 208;
		int pool2_inW = 208;
		int pool2_pad = 0;
		int pool2_knlH = 2;
		int pool2_knlW = 2;
		int pool2_stride = 2;
		int pool2_outC = pool2_inC;
		int pool2_outH = 104;
		int pool2_outW = 104;
		float * pool2_output = new float[pool2_outH * pool2_outW * pool2_outC];


		vec.clear();
		//ini conv3
		int conv3_c = 64;
		int conv3_kernel_h = 3;
		int conv3_kernel_w = 3;
		int conv3_h = 104;
		int conv3_w = 104;
		int conv3_p_h = 1;
		int conv3_p_w = 1;
		int conv3_s_h = 1;
		int conv3_s_w = 1;
		int conv3_d_h = 1;
		int conv3_d_w = 1;
		int conv3_act = 2;
		float *pool2_col = new float[conv3_h * conv3_w * conv3_kernel_h *conv3_kernel_w*pool2_inC];
		float *conv3_b = new float[conv3_c];
		float *conv3_coef = new float[conv3_kernel_h * conv3_kernel_w * pool2_inC * conv3_c];
		float *conv3_coef_t = new float[conv3_kernel_h * conv3_kernel_w * pool2_inC * conv3_c];
		float *conv3_out = new float[conv3_w * conv3_h * conv3_c];
		vec.push_back(0);
		readFile1("conv3_cof", conv3_b, conv3_c * sizeof(float), vec);
		vec.push_back(conv3_c * sizeof(float));
		readFile1("conv3_cof", conv3_coef, conv3_kernel_h * conv3_kernel_w * pool2_inC * conv3_c * sizeof(float), vec);
		vec.push_back(conv3_kernel_h * conv3_kernel_w * pool2_inC * conv3_c * sizeof(float));
		Row_column_transpose(conv3_coef, conv3_coef_t, conv3_c, conv3_kernel_h * conv3_kernel_w * pool2_inC);



		//ini pool3
		int pool3_inC = 64;
		int pool3_inH = 104;
		int pool3_inW = 104;
		int pool3_pad = 0;
		int pool3_knlH = 2;
		int pool3_knlW = 2;
		int pool3_stride = 2;
		int pool3_outC = pool3_inC;
		int pool3_outH = 52;
		int pool3_outW = 52;
		float * pool3_output = new float[pool3_outH * pool3_outW * pool3_outC];


		vec.clear();
		//ini conv4
		int conv4_c = 128;
		int conv4_kernel_h = 3;
		int conv4_kernel_w = 3;
		int conv4_h = 52;
		int conv4_w = 52;
		int conv4_p_h = 1;
		int conv4_p_w = 1;
		int conv4_s_w = 1;
		int conv4_s_h = 1;
		int conv4_d_h = 1;
		int conv4_d_w = 1;
		int conv4_act = 2;
		float *pool3_col = new float[conv4_h * conv4_w * conv4_kernel_h *conv4_kernel_w*pool3_inC];
		float *conv4_b = new float[conv4_c];
		float *conv4_coef = new float[conv4_kernel_h * conv4_kernel_w * pool3_inC * conv4_c];
		float *conv4_coef_t = new float[conv4_kernel_h * conv4_kernel_w * pool3_inC * conv4_c];
		float *conv4_out = new float[conv4_w * conv4_h * conv4_c];
		vec.push_back(0);
		readFile1("conv4_cof", conv4_b, conv4_c * sizeof(float), vec);
		vec.push_back(conv4_c * sizeof(float));
		readFile1("conv4_cof", conv4_coef, conv4_kernel_h * conv4_kernel_w * pool3_inC * conv4_c * sizeof(float), vec);
		vec.push_back(conv4_kernel_h * conv4_kernel_w * pool3_inC * conv4_c * sizeof(float));
		Row_column_transpose(conv4_coef, conv4_coef_t, conv4_c, conv4_kernel_h * conv4_kernel_w * pool3_inC);



		//ini pool4
		int pool4_inC = 128;
		int pool4_inH = 52;
		int pool4_inW = 52;
		int pool4_pad = 0;
		int pool4_knlH = 2;
		int pool4_knlW = 2;
		int pool4_stride = 2;
		int pool4_outC = pool4_inC;
		int pool4_outH = 26;
		int pool4_outW = 26;
		float * pool4_output = new float[pool4_outH * pool4_outW * pool4_outC];


		vec.clear();
		//ini conv5
		int conv5_c = 256;
		int conv5_kernel_h = 3;
		int conv5_kernel_w = 3;
		int conv5_h = 26;
		int conv5_w = 26;
		int conv5_p_h = 1;
		int conv5_p_w = 1;
		int conv5_s_h = 1;
		int conv5_s_w = 1;
		int conv5_d_h = 1;
		int conv5_d_w = 1;
		int conv5_act = 2;
		float *pool4_col = new float[conv5_h * conv5_w * conv5_kernel_h *conv5_kernel_w*pool4_inC];
		float *conv5_b = new float[conv5_c];
		float *conv5_coef = new float[conv5_kernel_h * conv5_kernel_w * pool4_inC * conv5_c];
		float *conv5_coef_t = new float[conv5_kernel_h * conv5_kernel_w * pool4_inC * conv5_c];
		float *conv5_out = new float[conv5_w * conv5_h * conv5_c];
		float *conv_output5 = new float[conv5_c * conv5_w * conv5_h];
		vec.push_back(0);
		readFile1("conv5_cof", conv5_b, conv5_c * sizeof(float), vec);
		vec.push_back(conv5_c * sizeof(float));
		readFile1("conv5_cof", conv5_coef, conv5_kernel_h * conv5_kernel_w * pool4_inC * conv5_c * sizeof(float), vec);
		vec.push_back(conv5_kernel_h * conv5_kernel_w * pool4_inC * conv5_c * sizeof(float));
		Row_column_transpose(conv5_coef, conv5_coef_t, conv5_c, conv5_kernel_h * conv5_kernel_w * pool4_inC);



		//ini pool5
		int pool5_inC = 256;
		int pool5_inH = 26;
		int pool5_inW = 26;
		int pool5_pad = 0;
		int pool5_knlH = 2;
		int pool5_knlW = 2;
		int pool5_stride = 2;
		int pool5_outC = pool5_inC;
		int pool5_outH = 13;
		int pool5_outW = 13;
		float * pool5_output = new float[pool5_outH * pool5_outW * pool5_outC];


		vec.clear();

		//ini conv6
		int conv6_c = 512;
		int conv6_kernel_h = 3;
		int conv6_kernel_w = 3;
		int conv6_h = 13;
		int conv6_w = 13;
		int conv6_p_h = 1;
		int conv6_p_w = 1;
		int conv6_s_h = 1;
		int conv6_s_w = 1;
		int conv6_d_h = 1;
		int conv6_d_w = 1;
		int conv6_act = 2;
		float *pool5_col = new float[conv6_h * conv6_w * conv6_kernel_h *conv6_kernel_w*pool5_inC];
		float *conv6_b = new float[conv6_c];
		float *conv6_coef = new float[conv6_kernel_h * conv6_kernel_w * pool5_inC * conv6_c];
		float *conv6_coef_t = new float[conv6_kernel_h * conv6_kernel_w * pool5_inC * conv6_c];
		float *conv6_out = new float[conv6_w * conv6_h * conv6_c];
		vec.push_back(0);
		readFile1("conv6_cof", conv6_b, conv6_c * sizeof(float), vec);
		vec.push_back(conv6_c * sizeof(float));
		readFile1("conv6_cof", conv6_coef, conv6_kernel_h * conv6_kernel_w * pool5_inC * conv6_c * sizeof(float), vec);
		vec.push_back(conv6_kernel_h * conv6_kernel_w * pool5_inC * conv6_c * sizeof(float));
		Row_column_transpose(conv6_coef, conv6_coef_t, conv6_c, conv6_kernel_h * conv6_kernel_w * pool5_inC);



		//ini pool6
		int pool6_inC = 512;
		int pool6_inH = 13;
		int pool6_inW = 13;
		int pool6_pad = 0;
		int pool6_knlH = 2;
		int pool6_knlW = 2;
		int pool6_stride = 1;
		int pool6_outC = pool6_inC;
		int pool6_outH = 13;
		int pool6_outW = 13;
		float * pool6_output = new float[pool6_outH * pool6_outW * pool6_outC];

		vec.clear();

		//ini conv7
		int conv7_c = 1024;
		int conv7_kernel_h = 3;
		int conv7_kernel_w = 3;
		int conv7_h = 13;
		int conv7_w = 13;
		int conv7_p_h = 1;
		int conv7_p_w = 1;
		int conv7_s_h = 1;
		int conv7_s_w = 1;
		int conv7_d_h = 1;
		int conv7_d_w = 1;
		int conv7_act = 2;
		float *pool6_col = new float[conv7_h * conv7_w * conv7_kernel_h *conv7_kernel_w*pool6_inC];
		float *conv7_b = new float[conv7_c];
		float *conv7_coef = new float[conv7_kernel_h * conv7_kernel_w * pool6_inC * conv7_c];
		float *conv7_coef_t = new float[conv7_kernel_h * conv7_kernel_w * pool6_inC * conv7_c];
		float *conv7_out = new float[conv7_w * conv7_h * conv7_c];
		vec.push_back(0);
		readFile1("conv7_cof", conv7_b, conv7_c * sizeof(float), vec);
		vec.push_back(conv7_c * sizeof(float));
		readFile1("conv7_cof", conv7_coef, conv7_kernel_h * conv7_kernel_w * pool6_inC * conv7_c * sizeof(float), vec);
		vec.push_back(conv7_kernel_h * conv7_kernel_w * pool6_inC * conv7_c * sizeof(float));
		Row_column_transpose(conv7_coef, conv7_coef_t, conv7_c, conv7_kernel_h * conv7_kernel_w * pool6_inC);


		vec.clear();

		//ini conv8
		int conv8_c = 256;
		int conv8_kernel_h = 1;
		int conv8_kernel_w = 1;
		int conv8_h = 13;
		int conv8_w = 13;
		int conv8_p_h = 0;
		int conv8_p_w = 0;
		int conv8_s_h = 1;
		int conv8_s_w = 1;
		int conv8_d_h = 1;
		int conv8_d_w = 1;
		int conv8_act = 2;
		float *conv7_col = new float[conv8_h * conv8_w * conv8_kernel_h *conv8_kernel_w*conv7_c];
		float *conv8_b = new float[conv8_c];
		float *conv8_coef = new float[conv8_kernel_h * conv8_kernel_w * conv7_c * conv8_c];
		float *conv8_coef_t = new float[conv8_kernel_h * conv8_kernel_w * conv7_c * conv8_c];
		float *conv8_out = new float[conv8_w * conv8_h * conv8_c];
		vec.push_back(0);
		readFile1("conv8_cof", conv8_b, conv8_c * sizeof(float), vec);
		vec.push_back(conv8_c * sizeof(float));
		readFile1("conv8_cof", conv8_coef, conv8_kernel_h * conv8_kernel_w * conv7_c * conv8_c * sizeof(float), vec);
		vec.push_back(conv8_kernel_h * conv8_kernel_w * conv7_c * conv8_c * sizeof(float));
		Row_column_transpose(conv8_coef, conv8_coef_t, conv8_c, conv8_kernel_h * conv8_kernel_w * conv7_c);



		vec.clear();

		//ini conv9
		int conv9_c = 512;
		int conv9_kernel_h = 3;
		int conv9_kernel_w = 3;
		int conv9_h = 13;
		int conv9_w = 13;
		int conv9_p_h = 1;
		int conv9_p_w = 1;
		int conv9_s_h = 1;
		int conv9_s_w = 1;
		int conv9_d_h = 1;
		int conv9_d_w = 1;
		int conv9_act = 2;
		float *conv8_col = new float[conv9_h * conv9_w * conv9_kernel_h *conv9_kernel_w*conv8_c];
		float *conv9_b = new float[conv9_c];
		float *conv9_coef = new float[conv9_kernel_h * conv9_kernel_w * conv8_c * conv9_c];
		float *conv9_coef_t = new float[conv9_kernel_h * conv9_kernel_w * conv8_c * conv9_c];
		float *conv9_out = new float[conv9_w * conv9_h * conv9_c];
		vec.push_back(0);
		readFile1("conv9_cof", conv9_b, conv9_c * sizeof(float), vec);
		vec.push_back(conv9_c * sizeof(float));
		readFile1("conv9_cof", conv9_coef, conv9_kernel_h * conv9_kernel_w * conv8_c * conv9_c * sizeof(float), vec);
		vec.push_back(conv9_kernel_h * conv9_kernel_w * conv8_c * conv9_c * sizeof(float));
		Row_column_transpose(conv9_coef, conv9_coef_t, conv9_c, conv9_kernel_h * conv9_kernel_w * conv8_c);

		vec.clear();

		//ini conv10
		int conv10_c = 255;
		int conv10_kernel_h = 1;
		int conv10_kernel_w = 1;
		int conv10_h = 13;
		int conv10_w = 13;
		int conv10_p_h = 0;
		int conv10_p_w = 0;
		int conv10_s_h = 1;
		int conv10_s_w = 1;
		int conv10_d_h = 1;
		int conv10_d_w = 1;
		int conv10_act = 3;//linear
		float *conv9_col = new float[conv10_h * conv10_w * conv10_kernel_h *conv10_kernel_w*conv9_c];
		float *conv10_b = new float[conv10_c];
		float *conv10_coef = new float[conv10_kernel_h * conv10_kernel_w * conv9_c * conv10_c];
		float *conv10_coef_t = new float[conv10_kernel_h * conv10_kernel_w * conv9_c * conv10_c];
		float *conv10_out = new float[conv10_w * conv10_h * conv10_c];
		vec.push_back(0);
		readFile1("conv10_cof", conv10_b, conv10_c * sizeof(float), vec);
		vec.push_back(conv10_c * sizeof(float));
		readFile1("conv10_cof", conv10_coef, conv10_kernel_h * conv10_kernel_w * conv9_c * conv10_c * sizeof(float), vec);
		vec.push_back(conv10_kernel_h * conv10_kernel_w * conv9_c * conv10_c * sizeof(float));
		Row_column_transpose(conv10_coef, conv10_coef_t, conv10_c, conv10_kernel_h * conv10_kernel_w * conv9_c);

		//ini yolo1
		int yolo1_c = conv10_c;
		int yolo1_w = conv10_w;
		int yolo1_h = conv10_h;
		float *yolo1 = new float[yolo1_c * yolo1_w * yolo1_h];

		//ini route1(conv8) 
		vector<concatDataParam> DataParams_route1;
		concatDataParam DataParam_route1;
		int output_size_route1 = 0;
		output_size_route1 += conv8_h * conv8_w * conv8_c;
		vector<int> shape_route1{ 1,  conv8_h * conv8_w * conv8_c };
		DataParam_route1 = { conv8_out, shape_route1 };
		DataParams_route1.push_back(DataParam_route1);
		shape_route1[1] = output_size_route1;
		float *route1_output_Data = new float[output_size_route1];
		int mbox_route1_axis = 1;
		int route1_c = conv8_c;
		int route1_w = conv8_w;
		int route1_h = conv8_h;


		vec.clear();
		//ini conv11
		int conv11_c = 128;
		int conv11_kernel_h = 1;
		int conv11_kernel_w = 1;
		int conv11_h = 13;
		int conv11_w = 13;
		int conv11_p_h = 0;
		int conv11_p_w = 0;
		int conv11_s_h = 1;
		int conv11_s_w = 1;
		int conv11_d_h = 1;
		int conv11_d_w = 1;
		int conv11_act = 2;//leaky
		float *route1_col = new float[conv11_h * conv11_w * conv11_kernel_h *conv11_kernel_w*route1_c];
		float *conv11_b = new float[conv11_c];
		float *conv11_coef = new float[conv11_kernel_h * conv11_kernel_w * route1_c * conv11_c];
		float *conv11_coef_t = new float[conv11_kernel_h * conv11_kernel_w * route1_c * conv11_c];
		float *conv11_out = new float[conv11_w * conv11_h * conv11_c];
		vec.push_back(0);
		readFile1("conv11_cof", conv11_b, conv11_c * sizeof(float), vec);
		vec.push_back(conv11_c * sizeof(float));
		readFile1("conv11_cof", conv11_coef, conv11_kernel_h * conv11_kernel_w * route1_c * conv11_c * sizeof(float), vec);
		vec.push_back(conv11_kernel_h * conv11_kernel_w * route1_c * conv11_c * sizeof(float));
		Row_column_transpose(conv11_coef, conv11_coef_t, conv11_c, conv11_kernel_h * conv11_kernel_w * route1_c);

		//ini upsample
		int upsample_c = 128;
		int upsample_w = 13;
		int upsample_h = 13;
		int upsample_s = 2;
		float upsample_scale = 1.0;
		float *upsample_out = new float[upsample_c*upsample_w*upsample_s*upsample_h*upsample_s];
		float *upsample_out_t = new float[upsample_c*upsample_w*upsample_s*upsample_h*upsample_s];


		//ini route2(upsample+conv5) 
		vector<concatDataParam> DataParams_route2;
		concatDataParam DataParam_route2;


		int output_size_route2 = 0;
		vector<int> shape_route2{ 1, upsample_c * upsample_w * upsample_s * upsample_h * upsample_s };

		output_size_route2 += upsample_c * upsample_w * upsample_s * upsample_h * upsample_s;
		DataParam_route2 = { upsample_out, shape_route2 };
		DataParams_route2.push_back(DataParam_route2);

		output_size_route2 += conv5_h * conv5_w * conv5_c;
		shape_route2[1] = conv5_h * conv5_w * conv5_c;
		DataParam_route2 = { conv_output5, shape_route2 };
		DataParams_route2.push_back(DataParam_route2);

		shape_route2[1] = output_size_route2;
		float *route2_output_Data = new float[output_size_route2];
		int mbox_route2_axis = 1;
		int route2_c = upsample_c + conv5_c;
		int route2_w = conv5_w;//=upsample_w
		int route2_h = conv5_h;//=upsample_h


		vec.clear();
		//ini conv12
		int conv12_c = 256;
		int conv12_kernel_h = 3;
		int conv12_kernel_w = 3;
		int conv12_h = 26;
		int conv12_w = 26;
		int conv12_p_h = 1;
		int conv12_p_w = 1;
		int conv12_s_h = 1;
		int conv12_s_w = 1;
		int conv12_d_h = 1;
		int conv12_d_w = 1;
		int conv12_act = 2;//leaky
		float *route2_col = new float[conv12_h * conv12_w * conv12_kernel_h *conv12_kernel_w*route2_c];
		float *conv12_b = new float[conv12_c];
		float *conv12_coef = new float[conv12_kernel_h * conv12_kernel_w * route2_c * conv12_c];
		float *conv12_coef_t = new float[conv12_kernel_h * conv12_kernel_w * route2_c * conv12_c];
		float *conv12_out = new float[conv12_w * conv12_h * conv12_c];
		vec.push_back(0);
		readFile1("conv12_cof", conv12_b, conv12_c * sizeof(float), vec);
		vec.push_back(conv12_c * sizeof(float));
		readFile1("conv12_cof", conv12_coef, conv12_kernel_h * conv12_kernel_w * route2_c * conv12_c * sizeof(float), vec);
		vec.push_back(conv12_kernel_h * conv12_kernel_w * route2_c * conv12_c * sizeof(float));
		Row_column_transpose(conv12_coef, conv12_coef_t, conv12_c, conv12_kernel_h * conv12_kernel_w * route2_c);

		vec.clear();
		//ini conv13
		int conv13_c = 255;
		int conv13_kernel_h = 1;
		int conv13_kernel_w = 1;
		int conv13_h = 26;
		int conv13_w = 26;
		int conv13_p_h = 0;
		int conv13_p_w = 0;
		int conv13_s_h = 1;
		int conv13_s_w = 1;
		int conv13_d_h = 1;
		int conv13_d_w = 1;
		int conv13_act = 3;//linear
		float *conv12_col = new float[conv13_h * conv13_w * conv13_kernel_h *conv13_kernel_w*conv12_c];
		float *conv13_b = new float[conv13_c];
		float *conv13_coef = new float[conv13_kernel_h * conv13_kernel_w * conv12_c * conv13_c];
		float *conv13_coef_t = new float[conv13_kernel_h * conv13_kernel_w * conv12_c * conv13_c];
		float *conv13_out = new float[conv13_w * conv13_h * conv13_c];
		vec.push_back(0);
		readFile1("conv13_cof", conv13_b, conv13_c * sizeof(float), vec);
		vec.push_back(conv13_c * sizeof(float));
		readFile1("conv13_cof", conv13_coef, conv13_kernel_h * conv13_kernel_w * conv12_c * conv13_c * sizeof(float), vec);
		vec.push_back(conv13_kernel_h * conv13_kernel_w * conv12_c * conv13_c * sizeof(float));
		Row_column_transpose(conv13_coef, conv13_coef_t, conv13_c, conv13_kernel_h * conv13_kernel_w * conv12_c);

		//ini yolo2
		int yolo2_c = conv13_c;
		int yolo2_w = conv13_w;
		int yolo2_h = conv13_h;
		float *yolo2 = new float[yolo2_c * yolo2_w * yolo2_h];

		//ini detection
		int yolo_num = 0;
		vector<detectionDataParam>detection_in;

		vector<int>yolo1_shape{ 13 , 13 , 255 };
		vector<int>yolo1_mask{ 3 , 4 , 5 };
		vector<int>yolo1_anchor{ 10,14,  23,27,  37,58,  81,82,  135,169,  344,319 };
		detectionDataParam yolo_det1 = { yolo1,yolo1_shape ,yolo1_mask,yolo1_anchor,classes };
		yolo_num++;
		detection_in.push_back(yolo_det1);

		vector<int>yolo2_shape{ 26 , 26 , 255 };
		vector<int>yolo2_mask{ 1 , 2 , 3 };
		vector<int>yolo2_anchor{ 10,14,  23,27,  37,58,  81,82,  135,169,  344,319 };
		detectionDataParam yolo_det2 = { yolo2,yolo2_shape ,yolo2_mask,yolo2_anchor,classes };
		yolo_num++;
		detection_in.push_back(yolo_det2);

		vector<int> det_shape{ imgw,imgh,imgc,yolo_num };
		detectionParam detections = { detection_in ,det_shape };


		//clockBegin = clock();
		//run conv1
		im2row(img, imgc, imgw, imgh, conv1_kernel_h, conv1_kernel_h,
			conv1_p_h, conv1_p_w, conv1_s_h, conv1_s_w, conv1_d_h, conv1_d_w, imgcol);
		convParam conv1_param = { imgcol, conv1_coef_t, conv1_b, conv1_out, imgc, imgw, imgh,conv1_kernel_w, conv1_kernel_h, conv1_c, conv1_w, conv1_h };
		convLayer(&conv1_param, conv1_act);
		//clockEnd = clock();
		//printf("%d\n", clockEnd - clockBegin);
		//float *conv_output1 = new float[conv1_c * conv1_w * conv1_h];
		//Row_column_transpose(conv1_out, conv_output1, conv1_w * conv1_h, conv1_c);
		maxpoolParam maxpool1{ conv1_out ,pool1_output ,pool1_inC,pool1_inH,pool1_inW,pool1_pad,pool1_knlH,pool1_knlW,pool1_stride,pool1_outC,pool1_outW,pool1_outH };
		maxpool(&maxpool1);

		//run conv2
		im2rowBycol(pool1_output, pool1_outC, pool1_outW, pool1_outH, conv2_kernel_h, conv2_kernel_h,
			conv2_p_h, conv2_p_w, conv2_s_h, conv2_s_w, conv2_d_h, conv2_d_w, pool1_col);
		convParam conv2_param = { pool1_col, conv2_coef_t, conv2_b, conv2_out, pool1_outC, pool1_outW, pool1_outH,conv2_kernel_w, conv2_kernel_h, conv2_c, conv2_w, conv2_h };
		convLayer(&conv2_param, conv2_act);
		maxpoolParam maxpool2{ conv2_out ,pool2_output ,pool2_inC,pool2_inH,pool2_inW,pool2_pad,pool2_knlH,pool2_knlW,pool2_stride,pool2_outC,pool2_outW,pool2_outH };
		maxpool(&maxpool2);
		//float *conv_output2 = new float[conv2_c * conv2_w * conv2_h];
		//Row_column_transpose(conv2_out, conv_output2, conv2_w * conv2_h, conv2_c);


		//run conv3
		im2rowBycol(pool2_output, pool2_outC, pool2_outW, pool2_outH, conv3_kernel_h, conv3_kernel_h,
			conv3_p_h, conv3_p_w, conv3_s_h, conv3_s_w, conv3_d_h, conv3_d_w, pool2_col);
		convParam conv3_param = { pool2_col, conv3_coef_t, conv3_b, conv3_out, pool2_outC, pool2_outW, pool2_outH,conv3_kernel_w, conv3_kernel_h, conv3_c, conv3_w, conv3_h };
		convLayer(&conv3_param, conv3_act);
		maxpoolParam maxpool3{ conv3_out ,pool3_output ,pool3_inC,pool3_inH,pool3_inW,pool3_pad,pool3_knlH,pool3_knlW,pool3_stride,pool3_outC,pool3_outW,pool3_outH };
		maxpool(&maxpool3);
		//float *conv_output3 = new float[conv3_c * conv3_w * conv3_h];
		//Row_column_transpose(conv3_out, conv_output3, conv3_w * conv3_h, conv3_c);



		//run conv4
		im2rowBycol(pool3_output, pool3_outC, pool3_outW, pool3_outH, conv4_kernel_h, conv4_kernel_h,
			conv4_p_h, conv4_p_w, conv4_s_h, conv4_s_w, conv4_d_h, conv4_d_w, pool3_col);
		convParam conv4_param = { pool3_col, conv4_coef_t, conv4_b, conv4_out, pool3_outC, pool3_outW, pool3_outH,conv4_kernel_w, conv4_kernel_h, conv4_c, conv4_w, conv4_h };
		convLayer(&conv4_param, conv4_act);
		maxpoolParam maxpool4{ conv4_out ,pool4_output ,pool4_inC,pool4_inH,pool4_inW,pool4_pad,pool4_knlH,pool4_knlW,pool4_stride,pool4_outC,pool4_outW,pool4_outH };
		maxpool(&maxpool4);
		//float *conv_output4 = new float[conv4_c * conv4_w * conv4_h];
		//Row_column_transpose(conv4_out, conv_output4, conv4_w * conv4_h, conv4_c);

		//run conv5
		im2rowBycol(pool4_output, pool4_outC, pool4_outW, pool4_outH, conv5_kernel_h, conv5_kernel_h,
			conv5_p_h, conv5_p_w, conv5_s_h, conv5_s_w, conv5_d_h, conv5_d_w, pool4_col);
		convParam conv5_param = { pool4_col, conv5_coef_t, conv5_b, conv5_out, pool4_outC, pool4_outW, pool4_outH,conv5_kernel_w, conv5_kernel_h, conv5_c, conv5_w, conv5_h };
		convLayer(&conv5_param, conv5_act);
		maxpoolParam maxpool5{ conv5_out ,pool5_output ,pool5_inC,pool5_inH,pool5_inW,pool5_pad,pool5_knlH,pool5_knlW,pool5_stride,pool5_outC,pool5_outW,pool5_outH };
		maxpool(&maxpool5);
		//float *conv_output5 = new float[conv5_c * conv5_w * conv5_h];
		Row_column_transpose(conv5_out, conv_output5, conv5_w * conv5_h, conv5_c);

		//run conv6
		im2rowBycol(pool5_output, pool5_outC, pool5_outW, pool5_outH, conv6_kernel_h, conv6_kernel_h,
			conv6_p_h, conv6_p_w, conv6_s_h, conv6_s_w, conv6_d_h, conv6_d_w, pool5_col);
		convParam conv6_param = { pool5_col, conv6_coef_t, conv6_b, conv6_out, pool5_outC, pool5_outW, pool5_outH,conv6_kernel_w, conv6_kernel_h, conv6_c, conv6_w, conv6_h };
		convLayer(&conv6_param, conv6_act);
		maxpoolParam maxpool6{ conv6_out ,pool6_output ,pool6_inC,pool6_inH,pool6_inW,pool6_pad,pool6_knlH,pool6_knlW,pool6_stride,pool6_outC,pool6_outW,pool6_outH };
		maxpool(&maxpool6);
		//float *conv_output6 = new float[pool6_outC * pool6_outW * pool6_outH];
		//Row_column_transpose(pool6_output, conv_output6, pool6_outW * pool6_outH, pool6_outC);

		//run conv7
		im2rowBycol(pool6_output, pool6_outC, pool6_outW, pool6_outH, conv7_kernel_h, conv7_kernel_h,
			conv7_p_h, conv7_p_w, conv7_s_h, conv7_s_w, conv7_d_h, conv7_d_w, pool6_col);
		convParam conv7_param = { pool6_col, conv7_coef_t, conv7_b, conv7_out, pool6_outC, pool6_outW, pool6_outH,conv7_kernel_w, conv7_kernel_h, conv7_c, conv7_w, conv7_h };
		convLayer(&conv7_param, conv7_act);
		//float *conv_output7 = new float[conv7_c * conv7_w * conv7_h];
		//Row_column_transpose(conv7_out, conv_output7, conv7_w * conv7_h, conv7_c);

		//run conv8
		im2rowBycol(conv7_out, conv7_c, conv7_w, conv7_h, conv8_kernel_h, conv8_kernel_h,
			conv8_p_h, conv8_p_w, conv8_s_h, conv8_s_w, conv8_d_h, conv8_d_w, conv7_col);
		convParam conv8_param = { conv7_col, conv8_coef_t, conv8_b, conv8_out, conv7_c, conv7_w, conv7_h, conv8_kernel_h, conv8_kernel_h, conv8_c, conv8_w, conv8_h };
		convLayer(&conv8_param, conv8_act);
		//float *conv_output8 = new float[conv8_c * conv8_w * conv8_h];
		//Row_column_transpose(conv8_out, conv_output8, conv8_w * conv8_h, conv8_c);

		//run conv9
		im2rowBycol(conv8_out, conv8_c, conv8_w, conv8_h, conv9_kernel_h, conv9_kernel_h,
			conv9_p_h, conv9_p_w, conv9_s_h, conv9_s_w, conv9_d_h, conv9_d_w, conv8_col);
		convParam conv9_param = { conv8_col, conv9_coef_t, conv9_b, conv9_out, conv8_c, conv8_w, conv8_h, conv9_kernel_h, conv9_kernel_h, conv9_c, conv9_w, conv9_h };
		convLayer(&conv9_param, conv9_act);
		//float *conv_output9 = new float[route1_c * route1_w * route1_h];
		//Row_column_transpose(route1_out, conv_output9, route1_w * route1_h, route1_c);

		//run conv10
		im2rowBycol(conv9_out, conv9_c, conv9_w, conv9_h, conv10_kernel_h, conv10_kernel_h,
			conv10_p_h, conv10_p_w, conv10_s_h, conv10_s_w, conv10_d_h, conv10_d_w, conv9_col);
		convParam conv10_param = { conv9_col, conv10_coef_t, conv10_b, conv10_out, conv9_c, conv9_w, conv9_h, conv10_kernel_h, conv10_kernel_h, conv10_c, conv10_w, conv10_h };
		convLayer(&conv10_param, conv10_act);
		float *conv_output10 = new float[conv10_c * conv10_w * conv10_h];
		Row_column_transpose(conv10_out, conv_output10, conv10_w * conv10_h, conv10_c);

		//run yolo1
		yoloParam yolo1_param = { conv_output10 ,yolo1,conv10_c ,conv10_h ,conv10_w ,classes };
		yolo(&yolo1_param);

		concatParam route1_param = { DataParams_route1, route1_output_Data, shape_route1, -1, mbox_route1_axis };
		Concat(&route1_param);

		//run conv11
		im2rowBycol(route1_output_Data, route1_c, route1_w, route1_h, conv11_kernel_h, conv11_kernel_h,
			conv11_p_h, conv11_p_w, conv11_s_h, conv11_s_w, conv11_d_h, conv11_d_w, route1_col);
		convParam conv11_param = { route1_col, conv11_coef_t, conv11_b, conv11_out, route1_c, route1_w, route1_h, conv11_kernel_h, conv11_kernel_h, conv11_c, conv11_w, conv11_h };
		convLayer(&conv11_param, conv11_act);
		float *conv_output11 = new float[conv11_c * conv11_w * conv11_h];
		Row_column_transpose(conv11_out, conv_output11, conv11_w * conv11_h, conv11_c);

		upsampleParam upsample_Param = { conv_output11 ,upsample_out,upsample_w,upsample_h ,upsample_c ,upsample_s,upsample_scale };
		upsample(&upsample_Param);
		//Row_column_transpose(upsample_out, upsample_out_t, upsample_w*upsample_s*upsample_s * upsample_h, upsample_c);

		concatParam route2_param = { DataParams_route2, route2_output_Data, shape_route2, -1, mbox_route2_axis };
		Concat(&route2_param);

		//run conv12
		im2row(route2_output_Data, route2_c, route2_w, route2_h, conv12_kernel_h, conv12_kernel_h,
			conv12_p_h, conv12_p_w, conv12_s_h, conv12_s_w, conv12_d_h, conv12_d_w, route2_col);
		convParam conv12_param = { route2_col, conv12_coef_t, conv12_b, conv12_out, route2_c, route2_w, route2_h, conv12_kernel_h, conv12_kernel_h, conv12_c, conv12_w, conv12_h };
		convLayer(&conv12_param, conv12_act);
		//float *conv_output12 = new float[conv12_c * conv12_w * conv12_h];
		//Row_column_transpose(conv12_out, conv_output12, conv12_w * conv12_h, conv12_c);


		//run conv13
		im2rowBycol(conv12_out, conv12_c, conv12_w, conv12_h, conv13_kernel_h, conv13_kernel_h,
			conv13_p_h, conv13_p_w, conv13_s_h, conv13_s_w, conv13_d_h, conv13_d_w, conv12_col);
		convParam conv13_param = { conv12_col, conv13_coef_t, conv13_b, conv13_out, conv12_c, conv12_w, conv12_h, conv13_kernel_h, conv13_kernel_h, conv13_c, conv13_w, conv13_h };
		convLayer(&conv13_param, conv13_act);
		float *conv_output13 = new float[conv13_c * conv13_w * conv13_h];
		Row_column_transpose(conv13_out, conv_output13, conv13_w * conv13_h, conv13_c);

		//run yolo2
		yoloParam yolo2_param = { conv_output13 ,yolo2,yolo2_c ,yolo2_h ,yolo2_w ,classes };
		yolo(&yolo2_param);

		//run detection
		int nboxes = 0;
		int letterbox = 0;
		detection * out = get_network_boxes(detections, 640, 424, 0.25, 0.5, 1, &nboxes, letterbox);
		do_nms_sort(out, nboxes, classes, 1);

		return 0;


#endif // YOLO


#ifdef FACE
		int img_height = 300;
		int img_width = 300;
		int img_channel = 3;

		float *img_data = new float[img_height*img_width*img_channel];
		readFile("./data_face/img.dat", img_data, img_height*img_width*img_channel * sizeof(float));


		//ini bn1
		int bn1_channel = img_channel;
		int bn1_height = img_height;
		int bn1_width = img_width;
		float *bn1_mean = new float[img_channel];
		float *bn1_variance = new float[img_channel];
		float *bn1_scale = new float[1];

		readFile1("./data_face/face.bin", bn1_mean, img_channel * sizeof(float), vec);
		vec.push_back(img_channel * sizeof(float));
		readFile1("./data_face/face.bin", bn1_variance, img_channel * sizeof(float), vec);
		vec.push_back(img_channel * sizeof(float));
		readFile1("./data_face/face.bin", bn1_scale, sizeof(float), vec);
		vec.push_back(1 * sizeof(float));

		float *bn1_output = new float[img_height*img_width*img_channel];

		//end ini bn1

		//ini scales1
		int scales1_channel = img_channel;
		int scales1_width = img_height;
		int scales1_height = img_width;
		int scales1_Relu =0;
		float *scales1_gamma = new float[scales1_channel];
		float *scales1_beta = new float[scales1_channel];
		float *scales1_output = new float[scales1_channel*scales1_width*scales1_height];
		readFile1("./data_face/face.bin", scales1_gamma, scales1_channel * sizeof(float), vec);
		vec.push_back(scales1_channel * sizeof(float));
		readFile1("./data_face/face.bin", scales1_beta, scales1_channel * sizeof(float), vec);
		vec.push_back(scales1_channel * sizeof(float));
		//end ini sclaes





		//ini conv1
		int conv1_output_channel = 32;
		int conv1_kernel_height = 7;
		int conv1_kernel_width = 7;
		int conv1_height = 300;
		int conv1_width = 300;
		int conv1_output_height = 150;
		int conv1_output_width = 150;
		int conv1_pad_height = 3;
		int conv1_pad_width = 3;
		int conv1_stride_height = 2;
		int conv1_stride_width = 2;
		int conv1_dilation_height = 1;
		int conv1_dilation_width = 1;
		int conv1_withRELU = 1;
		float *conv1_bias = new float[conv1_output_channel];
		float *conv1_coef = new float[conv1_kernel_height*conv1_kernel_width*img_channel*conv1_output_channel];
		float *conv1_coef_t = new float[conv1_kernel_height*conv1_kernel_width*img_channel*conv1_output_channel];
		float *conv1_output = new float[conv1_output_width*conv1_output_height*conv1_output_channel];
		float *scales1_output_col = new float[img_channel*conv1_kernel_height*conv1_kernel_width*conv1_output_channel*conv1_output_height*conv1_output_width];
		readFile1("./data_face/face.bin", conv1_coef, conv1_kernel_height*conv1_kernel_width*img_channel*conv1_output_channel * sizeof(float), vec);
		vec.push_back(conv1_kernel_height*conv1_kernel_width*img_channel*conv1_output_channel * sizeof(float));
		readFile1("./data_face/face.bin", conv1_bias, conv1_output_channel * sizeof(float), vec);
		vec.push_back(conv1_output_channel * sizeof(float));
		Row_column_transpose(conv1_coef, conv1_coef_t, conv1_output_channel, conv1_kernel_height*conv1_kernel_width*img_channel);
		//end ini conv1

		//ini pool
		int pool_output_channel = 32;
		int pool_output_height = 75;
		int pool_output_width = 75;
		int pool_pad = 0;
		int pool_kernel_height = 3;
		int pool_kernel_width = 3;
		int pool_stride = 2;
		float *pool_output = new float[pool_output_width*pool_output_height*pool_output_channel];

		//end pool

		//ini conv2
		int conv2_output_channel = 32;
		int conv2_kernel_height = 3;
		int conv2_kernel_width = 3;
		int conv2_output_height = 75;
		int conv2_output_width = 75;
		int conv2_pad_height = 1;
		int conv2_pad_width = 1;
		int conv2_stride_height = 1;
		int conv2_stride_width = 1;
		int conv2_dilation_height = 1;
		int conv2_dilation_width = 1;
		int conv2_withRELU = 1;
		float *conv2_bias = new float[conv2_output_channel];
		float *conv2_coef = new float[conv2_kernel_height*conv2_kernel_width*pool_output_channel*conv2_output_channel];
		float *conv2_new_coef = new float[conv2_kernel_height*conv2_kernel_width*pool_output_channel*conv2_output_channel];
		float *conv2_output = new float[conv2_output_height*conv2_output_width*conv2_output_channel];
		float *pool_output_col = new float[pool_output_channel*conv1_kernel_height*conv1_kernel_width*conv1_output_channel*conv2_output_height*conv2_output_width];
		readFile1("./data_face/face.bin", conv2_coef, conv2_kernel_height*conv2_kernel_width*pool_output_channel*conv2_output_channel * sizeof(float), vec);
		vec.push_back(conv2_kernel_height*conv2_kernel_width*pool_output_channel*conv2_output_channel * sizeof(float));
		readFile1("./data_face/face.bin", conv2_bias, conv2_output_channel * sizeof(float), vec);
		vec.push_back(conv2_output_channel * sizeof(float));
		Row_column_transpose(conv2_coef, conv2_new_coef, conv2_output_channel, conv2_kernel_height*conv2_kernel_width*pool_output_channel);
		//end ini conv2


		//ini conv3
		int conv3_output_channel = 32;
		int conv3_kernel_height = 3;
		int conv3_kernel_width = 3;
		int conv3_pad_height = 1;
		int conv3_pad_width = 1;
		int conv3_stride_height = 1;
		int conv3_stride_width = 1;
		int conv3_dilation_height = 1;
		int conv3_dilation_width = 1;
		int conv3_output_height = 75;
		int conv3_output_width = 75;
		int conv3_withRELU =0;
		float *conv3_output = new float[conv3_output_width*conv3_output_height*conv3_output_channel];
		float *conv2_output_col = new float[conv2_output_channel*conv3_kernel_height*conv3_kernel_width*conv3_output_channel*conv3_output_width*conv3_output_height];
		float *conv3_bias = new float[conv3_output_channel];
		float *conv3_coef = new float[conv3_kernel_height*conv3_kernel_width*conv3_output_channel*conv2_output_channel];
		float *conv3_new_coef = new float[conv3_kernel_height*conv3_kernel_width*conv3_output_channel*conv2_output_channel];
		readFile1("./data_face/face.bin", conv3_coef, conv3_kernel_height*conv3_kernel_width*conv2_output_channel*conv3_output_channel * sizeof(float), vec);
		vec.push_back(conv3_kernel_height*conv3_kernel_width*conv2_output_channel*conv3_output_channel * sizeof(float));
		readFile1("./data_face/face.bin", conv3_bias, conv3_output_channel * sizeof(float), vec);
		vec.push_back(conv3_output_channel * sizeof(float));
		Row_column_transpose(conv3_coef, conv3_new_coef, conv3_output_channel, conv3_kernel_height*conv3_kernel_width*conv2_output_channel);
		//end ini conv3


		//ini eltwsie1
		int eltwise1_channel = 32;
		int eltwise1_output_width = 75;
		int eltwise1_output_height = 75;
		float * eltwise1_output = new float[eltwise1_channel*eltwise1_output_width*eltwise1_output_height];
		vector<float*>eltwise1_input{ pool_output,conv3_output };
		vector<int>eltwise1_shape{ eltwise1_channel,eltwise1_output_width,eltwise1_output_height };
		//end ini eltwise1

		//ini bn2
		int bn2_channel = eltwise1_channel;
		int bn2_width = eltwise1_output_width;
		int bn2_height = eltwise1_output_height;
		float *bn2_col = new float[bn2_height*bn2_width*bn2_channel];
		float *bn2_scale = new float[sizeof(1)];
		float *bn2_mean = new float[bn2_channel];
		float *bn2_variance = new float[bn2_channel];
		readFile1("./data_face/face.bin", bn2_mean, bn2_channel * sizeof(float), vec);
		vec.push_back(eltwise1_channel * sizeof(float));
		readFile1("./data_face/face.bin", bn2_variance, bn2_channel * sizeof(float), vec);
		vec.push_back(eltwise1_channel * sizeof(float));
		readFile1("./data_face/face.bin", bn2_scale, sizeof(float), vec);
		vec.push_back(sizeof(float));

		float *bn2_output = new float[eltwise1_output_height*eltwise1_output_width*eltwise1_channel];
		BNParam bn2 = { bn2_col,bn2_output,bn2_scale,bn2_mean,bn2_variance ,eltwise1_channel,eltwise1_output_height,eltwise1_output_width };
		//end ini bn2

		//ini scales2
		int scales2_channel = eltwise1_channel;
		int scales2_width = eltwise1_output_width;
		int scales2_height = eltwise1_output_height;
		int scales2_Relu = 1;
		float *scales2_gamma = new float[scales2_channel];
		float *scales2_beta = new float[scales2_channel];
		float *scales2_output = new float[scales2_channel*scales2_width*scales2_height];
		readFile1("./data_face/face.bin", scales2_gamma, scales2_channel * sizeof(float), vec);
		vec.push_back(scales2_channel * sizeof(float));
		readFile1("./data_face/face.bin", scales2_beta, scales2_channel * sizeof(float), vec);
		vec.push_back(scales2_channel * sizeof(float));
		//end ini sclaes




		//ini conv4
		int conv4_output_channel = 128;
		int conv4_kernel_height = 3;
		int conv4_kernel_width = 3;
		int conv4_pad_height = 1;
		int conv4_pad_width = 1;
		int conv4_stride_height = 2;
		int conv4_stride_width = 2;
		int conv4_dilation_height = 1;
		int conv4_dilation_width = 1;
		int conv4_output_height = 38;
		int conv4_output_width = 38;
		int conv4_withRELU = 1;
		float *conv4_output = new float[conv4_output_width*conv4_output_height*conv4_output_channel];
		float *conv4_bias = new float[conv4_output_channel];
		float *conv4_coef = new float[conv4_kernel_height*conv4_kernel_width*conv4_output_channel*eltwise1_channel];
		float *conv4_new_coef = new float[conv4_kernel_height*conv4_kernel_width*conv4_output_channel*eltwise1_channel];
		readFile1("./data_face/face.bin", conv4_coef, conv4_kernel_height*conv4_kernel_width*eltwise1_channel*conv4_output_channel * sizeof(float), vec);
		vec.push_back(conv4_kernel_height*conv4_kernel_width*eltwise1_channel*conv4_output_channel * sizeof(float));
		readFile1("./data_face/face.bin", conv4_bias, conv4_output_channel * sizeof(float), vec);
		vec.push_back(conv4_output_channel * sizeof(float));
		Row_column_transpose(conv4_coef, conv4_new_coef, conv4_output_channel, conv4_kernel_height*conv4_kernel_width*eltwise1_channel);
		//end ini conv4


		//ini conv5
		int conv5_output_channel = 128;
		int conv5_kernel_height = 3;
		int conv5_kernel_width = 3;
		int conv5_pad_height = 1;
		int conv5_pad_width = 1;
		int conv5_stride_height = 1;
		int conv5_stride_width = 1;
		int conv5_dilation_height = 1;
		int conv5_dilation_width = 1;
		int conv5_output_height = 38;
		int conv5_output_width = 38;
		int conv5_withRELU = 0;
		float *conv5_output = new float[conv5_output_width*conv5_output_height*conv5_output_channel];
		float *conv4_output_col = new float[conv5_output_width*conv5_output_height*conv4_output_channel*conv5_kernel_height*conv5_kernel_width*conv5_output_channel];
		float *conv5_bias = new float[conv5_output_channel];
		float *conv5_coef = new float[conv5_kernel_height*conv5_kernel_width*conv5_output_channel*conv4_output_channel];
		float *conv5_new_coef = new float[conv5_kernel_height*conv5_kernel_width*conv5_output_channel*conv4_output_channel];
		readFile1("./data_face/face.bin", conv5_coef, conv5_kernel_height*conv5_kernel_width*conv4_output_channel*conv5_output_channel * sizeof(float), vec);
		vec.push_back(conv5_kernel_height*conv5_kernel_width*conv4_output_channel*conv5_output_channel * sizeof(float));
		readFile1("./data_face/face.bin", conv5_bias, conv5_output_channel * sizeof(float), vec);
		vec.push_back(conv5_output_channel * sizeof(float));
		Row_column_transpose(conv5_coef, conv5_new_coef, conv5_output_channel, conv5_kernel_height*conv5_kernel_width*conv5_output_channel);
		//end ini conv5

		//ini conv4_expand
		int conv4_expand_output_channel = 128;
		int conv4_expand_kernel_height = 1;
		int conv4_expand_kernel_width = 1;
		int conv4_expand_pad_height = 0;
		int conv4_expand_pad_width = 0;
		int conv4_expand_stride_height = 2;
		int conv4_expand_stride_width = 2;
		int conv4_expand_dilation_height = 1;
		int conv4_expand_dilation_width = 1;
		int conv4_expand_output_height = 38;
		int conv4_expand_output_width = 38;
		int conv4_expand_withRELU = 0;
		float *conv4_expand_output = new float[conv4_expand_output_width*conv4_expand_output_height*conv4_expand_output_channel];
		float *scales2_output_col = new float[scales2_channel*conv4_expand_kernel_height*conv4_expand_kernel_width*conv4_expand_output_channel*conv4_expand_output_width*conv4_expand_output_height];
		float *conv4_expand_bias = new float[conv4_expand_output_channel];
		float *conv4_expand_coef = new float[conv4_expand_kernel_height*conv4_expand_kernel_width*conv4_expand_output_channel*eltwise1_channel];
		float *conv4_expand_new_coef = new float[conv4_expand_kernel_height*conv4_expand_kernel_width*conv4_expand_output_channel*eltwise1_channel];
		readFile1("./data_face/face.bin", conv4_expand_coef, conv4_expand_kernel_height*conv4_expand_kernel_width*eltwise1_channel*conv4_expand_output_channel * sizeof(float), vec);
		vec.push_back(conv4_expand_kernel_height*conv4_expand_kernel_width*scales2_channel*conv4_expand_output_channel * sizeof(float));
		readFile1("./data_face/face.bin", conv4_expand_bias, conv4_expand_output_channel * sizeof(float), vec);
		vec.push_back(conv4_expand_output_channel * sizeof(float));
		Row_column_transpose(conv4_expand_coef, conv4_expand_new_coef, conv4_expand_output_channel, conv4_expand_kernel_height*conv4_expand_kernel_width*scales2_channel);
		//end ini conv4_expand

		//ini eltwise2
		int eltwise2_channel = 128;
		int eltwise2_output_width = 38;
		int eltwise2_output_height = 38;
		float * eltwise2_output = new float[eltwise2_channel*eltwise2_output_width*eltwise2_output_height];
		vector<int>eltwise2_shape{ eltwise2_channel,eltwise2_output_width,eltwise2_output_height };
		//end ini eltwise2


		//ini bn3
		int bn3_channel = eltwise2_channel;
		int bn3_width = eltwise2_output_width;
		int bn3_height = eltwise2_output_height;
		float *bn3_output_col = new float[bn3_width*bn3_height*bn3_channel];
		float *bn3_scale = new float[sizeof(1)];
		float *bn3_mean = new float[bn3_channel];
		float *bn3_variance = new float[bn3_channel];
		readFile1("./data_face/face.bin", bn3_mean, bn3_channel * sizeof(float), vec);
		vec.push_back(eltwise2_channel * sizeof(float));
		readFile1("./data_face/face.bin", bn3_variance, bn3_channel * sizeof(float), vec);
		vec.push_back(eltwise2_channel * sizeof(float));
		readFile1("./data_face/face.bin", bn3_scale, sizeof(float), vec);
		vec.push_back(sizeof(float));
		float *bn3_output = new float[bn3_width*bn3_height*bn3_channel];
		//end bn3

		//ini scales3
		int scales3_channel = eltwise2_channel;
		int scales3_width = eltwise2_output_width;
		int scales3_height = eltwise2_output_height;
		int scales3_Relu = 1;
		float *scales3_gamma = new float[scales3_channel];
		float *scales3_beta = new float[scales3_channel];
		float *scales3_output = new float[scales3_channel*scales3_width*scales3_height];
		float *scales3_output_transpose = new float[scales3_channel*scales3_width*scales3_height];

		readFile1("./data_face/face.bin", scales3_gamma, scales3_channel * sizeof(float), vec);
		vec.push_back(scales3_channel * sizeof(float));
		readFile1("./data_face/face.bin", scales3_beta, scales3_channel * sizeof(float), vec);
		vec.push_back(scales3_channel * sizeof(float));
		//end scales3


		//ini conv6
		int conv6_output_channel = 256;
		int conv6_kernel_height = 3;
		int conv6_kernel_width = 3;
		int conv6_pad_height = 1;
		int conv6_pad_width = 1;
		int conv6_stride_height = 2;
		int conv6_stride_width = 2;
		int conv6_dilation_height = 1;
		int conv6_dilation_width = 1;
		int conv6_output_height = 19;
		int conv6_output_width = 19;
		int conv6_withRelu = 1;
		float *conv6_output = new float[conv6_output_width*conv6_output_height*conv6_output_channel];
		float *conv6_bias = new float[conv6_output_channel];
		float *conv6_coef = new float[conv6_kernel_height*conv6_kernel_width*conv6_output_channel*eltwise2_channel];
		float *conv6_new_coef = new float[conv6_kernel_height*conv6_kernel_width*conv6_output_channel*eltwise2_channel];
		readFile1("./data_face/face.bin", conv6_coef, conv6_kernel_height*conv6_kernel_width*eltwise2_channel*conv6_output_channel * sizeof(float), vec);
		vec.push_back(conv6_kernel_height*conv6_kernel_width*eltwise2_channel*conv6_output_channel * sizeof(float));
		readFile1("./data_face/face.bin", conv6_bias, conv6_output_channel * sizeof(float), vec);
		vec.push_back(conv6_output_channel * sizeof(float));
		Row_column_transpose(conv6_coef, conv6_new_coef, conv6_output_channel, conv6_kernel_height*conv6_kernel_width*eltwise2_channel);
		
		//start init conv7
		int conv7_output_channel = 256;
		int conv7_kernel_height = 3;
		int conv7_kernel_width = 3;
		int conv7_output_height = 19;
		int conv7_output_width = 19;

		int conv7_pad_height = 1;
		int conv7_pad_width = 1;
		int conv7_stride_height = 1;
		int conv7_stride_width = 1;
		int conv7_dilation_height = 1;
		int conv7_dilation_width = 1;
		int conv7_withRelu = 0;

		float *conv7_coef = new float[conv6_output_channel * conv7_output_channel * conv7_kernel_height * conv7_kernel_width];
		float *conv7_new_coef = new float[conv6_output_channel * conv7_output_channel * conv7_kernel_height * conv7_kernel_width];
		float *conv7_bias = new float[conv7_output_channel];
		float *conv6_output_col = new float[conv6_output_channel * conv7_kernel_height * conv7_kernel_width * conv7_output_height * conv7_output_width];
		float *conv7_output = new float[conv7_output_channel * conv7_output_height * conv7_output_width];
		readFile1("./data_face/face.bin", conv7_coef, conv6_output_channel * conv7_output_channel * conv7_kernel_height * conv7_kernel_width * sizeof(float), vec);
		vec.push_back(conv6_output_channel * conv7_output_channel * conv7_kernel_height * conv7_kernel_width * sizeof(float));
		readFile1("./data_face/face.bin", conv7_bias, conv7_output_channel * sizeof(float), vec);
		vec.push_back(conv7_output_channel * sizeof(float));
		Row_column_transpose(conv7_coef, conv7_new_coef, conv7_output_channel, conv6_output_channel * conv7_kernel_height * conv7_kernel_width);
		//end init conv7

		//ini conv6_expand
		int conv6_expand_output_channel = 256;
		int conv6_expand_kernel_height = 1;
		int conv6_expand_kernel_width = 1;
		int conv6_expand_pad_height = 0;
		int conv6_expand_pad_width = 0;
		int conv6_expand_stride_height = 2;
		int conv6_expand_stride_width = 2;
		int conv6_expand_dilation_height = 1;
		int conv6_expand_dilation_width = 1;
		int conv6_expand_output_height = 19;
		int conv6_expand_output_width = 19;
		int conv6_expand_withRELU = 0;
		float *conv6_expand_output = new float[conv6_expand_output_width*conv6_expand_output_height*conv6_expand_output_channel];
		float *scales3_output_col = new float[conv6_expand_output_width*conv6_expand_output_height*scales3_channel*conv6_expand_kernel_height*conv6_expand_kernel_width*conv6_expand_output_channel];
		float *conv6_expand_bias = new float[conv6_expand_output_channel];
		float *conv6_expand_coef = new float[conv6_expand_kernel_height*conv6_expand_kernel_width*conv6_expand_output_channel*eltwise2_channel];
		float *conv6_expand_new_coef = new float[conv6_expand_kernel_height*conv6_expand_kernel_width*conv6_expand_output_channel*eltwise2_channel];
		readFile1("./data_face/face.bin", conv6_expand_coef, conv6_expand_kernel_height*conv6_expand_kernel_width*eltwise2_channel*conv6_expand_output_channel * sizeof(float), vec);
		vec.push_back(conv6_expand_kernel_height*conv6_expand_kernel_width*eltwise2_channel*conv6_expand_output_channel * sizeof(float));
		readFile1("./data_face/face.bin", conv6_expand_bias, conv6_expand_output_channel * sizeof(float), vec);
		vec.push_back(conv6_expand_output_channel * sizeof(float));
		Row_column_transpose(conv6_expand_coef, conv6_expand_new_coef, conv6_expand_output_channel, conv6_expand_kernel_height*conv6_expand_kernel_width*eltwise2_channel);
		//end ini conv6_expand

		//ini eltwsie3
		int eltwise3_channel = 256;
		int eltwise3_width = 19;
		int eltwise3_height = 19;
		float * eltwise3_output = new float[eltwise3_channel*eltwise3_width*eltwise3_height];
		vector<float*>eltwise3_input{ conv7_output,conv6_expand_output };
		vector<int>eltwise3_shape{ eltwise3_channel,eltwise3_width,eltwise3_height };
		//end ini eltwise3


		//ini bn4
		int bn4_channel = 256;
		int bn4_width = 19;
		int bn4_height = 19;
		float *bn4_mean = new float[bn4_channel];
		float *bn4_variance = new float[bn4_channel];
		float *bn4_scale = new float[1];
		float *eltwise3_output_t = new float[eltwise3_channel*eltwise3_width*eltwise3_height];
		float *bn4_output = new float[bn4_channel * bn4_height * bn4_width];

		readFile1("./data_face/face.bin", bn4_mean, bn4_channel * sizeof(float), vec);
		vec.push_back(bn4_channel * sizeof(float));
		readFile1("./data_face/face.bin", bn4_variance, bn4_channel * sizeof(float), vec);
		vec.push_back(bn4_channel * sizeof(float));
		readFile1("./data_face/face.bin", bn4_scale, 1 * sizeof(float), vec);
		vec.push_back(1 * sizeof(float));
		//end ini bn4

		//ini scales4
		int scales4_channel = 256;
		int scales4_width = 19;
		int scales4_height = 19;
		int scales4_Relu = 1;

		float *scales4_gamma = new float[scales4_channel];
		float *scales4_beta = new float[scales4_channel];
		float *scales4_output = new float[scales4_channel*scales4_width*scales4_height];
		readFile1("./data_face/face.bin", scales4_gamma, scales4_channel * sizeof(float), vec);
		vec.push_back(scales4_channel * sizeof(float));
		readFile1("./data_face/face.bin", scales4_beta, scales4_channel * sizeof(float), vec);
		vec.push_back(scales4_channel * sizeof(float));
		//end ini sclaes4



		//start init conv8
		int conv8_output_channel = 128;
		int conv8_kernel_height = 3;
		int conv8_kernel_width = 3;
		int conv8_output_height = 19;
		int conv8_output_width = 19;

		int conv8_pad_height = 1;
		int conv8_pad_width = 1;
		int conv8_stride_height = 1;
		int conv8_stride_width = 1;
		int conv8_dilation_height = 1;
		int conv8_dilation_width = 1;
		int conv8_withRELU = 1;

		float *conv8_coef = new float[bn4_channel * conv8_output_channel * conv8_kernel_height * conv8_kernel_width];
		float *conv8_new_coef = new float[bn4_channel * conv8_output_channel * conv8_kernel_height * conv8_kernel_width];
		float *conv8_bias = new float[conv8_output_channel];
		float *scales4_output_col = new float[bn4_channel * conv8_kernel_height * conv8_kernel_width * conv8_output_height * conv8_output_width];
		float *conv8_output = new float[conv8_output_channel * conv8_output_height * conv8_output_width];
		readFile1("./data_face/face.bin", conv8_coef, bn4_channel * conv8_output_channel * conv8_kernel_height * conv8_kernel_width * sizeof(float), vec);
		vec.push_back(bn4_channel * conv8_output_channel * conv8_kernel_height * conv8_kernel_width * sizeof(float));
		readFile1("./data_face/face.bin", conv8_bias, conv8_output_channel * sizeof(float), vec);
		vec.push_back(conv8_output_channel * sizeof(float));
		Row_column_transpose(conv8_coef, conv8_new_coef, conv8_output_channel, bn4_channel * conv8_kernel_height * conv8_kernel_width);
		//end init conv8

		//start init conv9
		int conv9_output_channel = 256;
		int conv9_kernel_height = 3;
		int conv9_kernel_width = 3;
		int conv9_output_height = 19;
		int conv9_output_width = 19;

		int conv9_pad_height = 2;
		int conv9_pad_width = 2;
		int conv9_stride_height = 1;
		int conv9_stride_width = 1;
		int conv9_dilation_height = 2;
		int conv9_dilation_width = 2;
		int conv9_withRELU = 0;

		float *conv9_coef = new float[conv8_output_channel * conv9_output_channel * conv9_kernel_height * conv9_kernel_width];
		float *conv9_new_coef = new float[conv8_output_channel * conv9_output_channel * conv9_kernel_height * conv9_kernel_width];
		float *conv9_bias = new float[conv9_output_channel];
		float *conv8_output_col = new float[conv8_output_channel * conv9_kernel_height * conv9_kernel_width * conv9_output_height * conv9_output_width];
		float *conv9_output = new float[conv9_output_channel * conv9_output_height * conv9_output_width];
		readFile1("./data_face/face.bin", conv9_coef, conv8_output_channel * conv9_output_channel * conv9_kernel_height * conv9_kernel_width * sizeof(float), vec);
		vec.push_back(conv8_output_channel * conv9_output_channel * conv9_kernel_height * conv9_kernel_width * sizeof(float));
		readFile1("./data_face/face.bin", conv9_bias, conv9_output_channel * sizeof(float), vec);
		vec.push_back(conv9_output_channel * sizeof(float));
		Row_column_transpose(conv9_coef, conv9_new_coef, conv9_output_channel, conv8_output_channel * conv9_kernel_height * conv9_kernel_width);
		//end init conv9

		//start init conv8_expand
		int conv8_expand_output_channel = 256;
		int conv8_expand_kernel_height = 1;
		int conv8_expand_kernel_width = 1;
		int conv8_expand_output_height = 19;
		int conv8_expand_output_width = 19;

		int conv8_expand_pad_height = 0;
		int conv8_expand_pad_width = 0;
		int conv8_expand_stride_height = 1;
		int conv8_expand_stride_width = 1;
		int conv8_expand_dilation_height = 1;
		int conv8_expand_dilation_width = 1;
		int conv8_expand_withRELU = 0;

		float *conv8_expand_coef = new float[bn4_channel * conv8_expand_output_channel * conv8_expand_kernel_height * conv8_expand_kernel_width];
		float *conv8_expand_new_coef = new float[bn4_channel * conv8_expand_output_channel * conv8_expand_kernel_height * conv8_expand_kernel_width];
		float *conv8_expand_bias = new float[conv8_expand_output_channel];
		float *conv8_expand_output = new float[conv8_expand_output_channel * conv8_expand_output_height * conv8_expand_output_width];
		readFile1("./data_face/face.bin", conv8_expand_coef, bn4_channel * conv8_expand_output_channel * conv8_expand_kernel_height * conv8_expand_kernel_width * sizeof(float), vec);
		vec.push_back(bn4_channel * conv8_expand_output_channel * conv8_expand_kernel_height * conv8_expand_kernel_width * sizeof(float));
		readFile1("./data_face/face.bin", conv8_expand_bias, conv8_expand_output_channel * sizeof(float), vec);
		vec.push_back(conv8_expand_output_channel * sizeof(float));
		Row_column_transpose(conv8_expand_coef, conv8_expand_new_coef, conv8_expand_output_channel, bn4_channel * conv8_expand_kernel_height * conv8_expand_kernel_width);
		//end init conv8_expand

		//ini eltwsie4
		int eltwise4_channel = 256;
		int eltwise4_width = 19;
		int eltwise4_height = 19;
		float * eltwise4_output = new float[eltwise4_channel*eltwise4_width*eltwise4_height];
		vector<int>eltwise4_shape{ eltwise4_channel,eltwise4_width,eltwise4_height };
		//end ini eltwise4


		//ini bn5
		int bn5_channel = 256;
		int bn5_width = 19;
		int bn5_height = 19;
		float *bn5_mean = new float[bn5_channel];
		float *bn5_variance = new float[bn5_channel];
		float *bn5_scale = new float[1];
		float *eltwise4_output_t = new float[eltwise4_channel*eltwise4_width*eltwise4_height];
		float *bn5_output = new float[bn5_channel * bn5_height * bn5_width];

		readFile1("./data_face/face.bin", bn5_mean, bn5_channel * sizeof(float), vec);
		vec.push_back(bn5_channel * sizeof(float));
		readFile1("./data_face/face.bin", bn5_variance, bn5_channel * sizeof(float), vec);
		vec.push_back(bn5_channel * sizeof(float));
		readFile1("./data_face/face.bin", bn5_scale, 1 * sizeof(float), vec);
		vec.push_back(1*sizeof(float));
		//end ini bn5

		//ini scales5
		int scales5_channel = 256;
		int scales5_width = 19;
		int scales5_height = 19;
		int scales5_Relu = 1;
		float *scales5_gamma = new float[scales5_channel];
		float *scales5_beta = new float[scales5_channel];
		float *scales5_output = new float[scales5_channel*scales5_width*scales5_height];
		readFile1("./data_face/face.bin", scales5_gamma, scales5_channel * sizeof(float), vec);
		vec.push_back(scales5_channel * sizeof(float));
		readFile1("./data_face/face.bin", scales5_beta, scales5_channel * sizeof(float), vec);
		vec.push_back(scales5_channel * sizeof(float));
		//end ini sclaes5

		//start init conv10
		int conv10_output_channel = 128;
		int conv10_kernel_height = 1;
		int conv10_kernel_width = 1;
		int conv10_output_height = 19;
		int conv10_output_width = 19;

		int conv10_pad_height = 0;
		int conv10_pad_width = 0;
		int conv10_stride_height = 1;
		int conv10_stride_width = 1;
		int conv10_dilation_height = 1;
		int conv10_dilation_width = 1;
		int conv10_withRELU = 1;

		float *conv10_coef = new float[scales5_channel * conv10_output_channel * conv10_kernel_height * conv10_kernel_width];
		float *conv10_new_coef = new float[scales5_channel * conv10_output_channel * conv10_kernel_height * conv10_kernel_width];
		float *conv10_bias = new float[conv10_output_channel];
		float *scales5_output_col = new float[scales5_channel * conv10_kernel_height * conv10_kernel_width * conv10_output_height * conv10_output_width];
		float *conv10_output = new float[conv10_output_channel * conv10_output_height * conv10_output_width];
		readFile1("./data_face/face.bin", conv10_coef, scales5_channel * conv10_output_channel * conv10_kernel_height * conv10_kernel_width * sizeof(float), vec);
		vec.push_back(scales5_channel * conv10_output_channel * conv10_kernel_height * conv10_kernel_width * sizeof(float));
		readFile1("./data_face/face.bin", conv10_bias, conv10_output_channel * sizeof(float), vec);
		vec.push_back(conv10_output_channel * sizeof(float));
		Row_column_transpose(conv10_coef, conv10_new_coef, conv10_output_channel, scales5_channel * conv10_kernel_height * conv10_kernel_width);
		//end init conv10


		//start init conv11
		int conv11_output_channel = 256;
		int conv11_kernel_height = 3;
		int conv11_kernel_width = 3;
		int conv11_output_height = 10;
		int conv11_output_width = 10;
		int conv11_pad_height = 1;
		int conv11_pad_width = 1;
		int conv11_stride_height = 2;
		int conv11_stride_width = 2;
		int conv11_dilation_height = 1;
		int conv11_dilation_width = 1;
		int conv11_withRELU = 1;

		float *conv11_coef = new float[conv10_output_channel * conv11_output_channel * conv11_kernel_height * conv11_kernel_width];
		float *conv11_new_coef = new float[conv10_output_channel * conv11_output_channel * conv11_kernel_height * conv11_kernel_width];
		float *conv11_bias = new float[conv11_output_channel];
		float *conv10_output_col = new float[conv10_output_channel * conv11_kernel_height * conv11_kernel_width * conv11_output_height * conv11_output_width];
		float *conv11_output = new float[conv11_output_channel * conv11_output_height * conv11_output_width];
		readFile1("./data_face/face.bin", conv11_coef, conv10_output_channel * conv11_output_channel * conv11_kernel_height * conv11_kernel_width * sizeof(float), vec);
		vec.push_back(conv10_output_channel * conv11_output_channel * conv11_kernel_height * conv11_kernel_width * sizeof(float));
		readFile1("./data_face/face.bin", conv11_bias, conv11_output_channel * sizeof(float), vec);
		vec.push_back(conv11_output_channel * sizeof(float));
		Row_column_transpose(conv11_coef, conv11_new_coef, conv11_output_channel, conv10_output_channel * conv11_kernel_height * conv11_kernel_width);
		//end init conv11


		//start init conv12
		int conv12_output_channel = 64;
		int conv12_kernel_height = 1;
		int conv12_kernel_width = 1;
		int conv12_output_height = 10;
		int conv12_output_width = 10;

		int conv12_pad_height = 0;
		int conv12_pad_width = 0;
		int conv12_stride_height = 1;
		int conv12_stride_width = 1;
		int conv12_dilation_height = 1;
		int conv12_dilation_width = 1;
		int conv12_withRELU = 1;

		float *conv12_coef = new float[conv11_output_channel * conv12_output_channel * conv12_kernel_height * conv12_kernel_width];
		float *conv12_new_coef = new float[conv11_output_channel * conv12_output_channel * conv12_kernel_height * conv12_kernel_width];
		float *conv12_bias = new float[conv12_output_channel];
		float *conv11_output_col = new float[conv11_output_channel * conv12_kernel_height * conv12_kernel_width * conv12_output_height * conv12_output_width];
		float *conv12_output = new float[conv12_output_channel * conv12_output_height * conv12_output_width];
		readFile1("./data_face/face.bin", conv12_coef, conv11_output_channel * conv12_output_channel * conv12_kernel_height * conv12_kernel_width * sizeof(float), vec);
		vec.push_back(conv11_output_channel * conv12_output_channel * conv12_kernel_height * conv12_kernel_width * sizeof(float));
		readFile1("./data_face/face.bin", conv12_bias, conv12_output_channel * sizeof(float), vec);
		vec.push_back(conv12_output_channel * sizeof(float));
		Row_column_transpose(conv12_coef, conv12_new_coef, conv12_output_channel, conv11_output_channel * conv12_kernel_height * conv12_kernel_width);
		//end init conv12


		//start init conv13
		int conv13_output_channel = 128;
		int conv13_kernel_height = 3;
		int conv13_kernel_width = 3;
		int conv13_output_height = 5;
		int conv13_output_width = 5;
		int conv13_pad_height = 1;
		int conv13_pad_width = 1;
		int conv13_stride_height = 2;
		int conv13_stride_width = 2;
		int conv13_dilation_height = 1;
		int conv13_dilation_width = 1;
		int conv13_withRELU = 1;

		float *conv13_coef = new float[conv12_output_channel * conv13_output_channel * conv13_kernel_height * conv13_kernel_width];
		float *conv13_new_coef = new float[conv12_output_channel * conv13_output_channel * conv13_kernel_height * conv13_kernel_width];
		float *conv13_bias = new float[conv13_output_channel];
		float *conv12_output_col = new float[conv12_output_channel * conv13_kernel_height * conv13_kernel_width * conv13_output_height * conv13_output_width];
		float *conv13_output = new float[conv13_output_channel * conv13_output_height * conv13_output_width];
		readFile1("./data_face/face.bin", conv13_coef, conv12_output_channel * conv13_output_channel * conv13_kernel_height * conv13_kernel_width * sizeof(float), vec);
		vec.push_back(conv12_output_channel * conv13_output_channel * conv13_kernel_height * conv13_kernel_width * sizeof(float));
		readFile1("./data_face/face.bin", conv13_bias, conv13_output_channel * sizeof(float), vec);
		vec.push_back(conv13_output_channel * sizeof(float));
		Row_column_transpose(conv13_coef, conv13_new_coef, conv13_output_channel, conv12_output_channel * conv13_kernel_height * conv13_kernel_width);
		//end init conv13


		//start init conv14
		int conv14_output_channel = 64;
		int conv14_kernel_height = 1;
		int conv14_kernel_width = 1;
		int conv14_output_height = 5;
		int conv14_output_width = 5;
		int conv14_pad_height = 0;
		int conv14_pad_width = 0;
		int conv14_stride_height = 1;
		int conv14_stride_width = 1;
		int conv14_dilation_height = 1;
		int conv14_dilation_width = 1;
		int conv14_withRELU = 1;

		float *conv14_coef = new float[conv13_output_channel * conv14_output_channel * conv14_kernel_height * conv14_kernel_width];
		float *conv14_new_coef = new float[conv13_output_channel * conv14_output_channel * conv14_kernel_height * conv14_kernel_width];
		float *conv14_bias = new float[conv14_output_channel];
		float *conv13_output_col = new float[conv13_output_channel * conv14_kernel_height * conv14_kernel_width * conv14_output_height * conv14_output_width];
		float *conv14_output = new float[conv14_output_channel * conv14_output_height * conv14_output_width];
		readFile1("./data_face/face.bin", conv14_coef, conv13_output_channel * conv14_output_channel * conv14_kernel_height * conv14_kernel_width * sizeof(float), vec);
		vec.push_back(conv13_output_channel * conv14_output_channel * conv14_kernel_height * conv14_kernel_width * sizeof(float));
		readFile1("./data_face/face.bin", conv14_bias, conv14_output_channel * sizeof(float), vec);
		vec.push_back(conv14_output_channel * sizeof(float));
		Row_column_transpose(conv14_coef, conv14_new_coef, conv14_output_channel, conv13_output_channel * conv14_kernel_height * conv14_kernel_width);
		//end init conv14

		//start init conv15
		int conv15_output_channel = 128;
		int conv15_kernel_height = 3;
		int conv15_kernel_width = 3;
		int conv15_output_height = 5;
		int conv15_output_width = 5;
		int conv15_pad_height = 1;
		int conv15_pad_width = 1;
		int conv15_stride_height = 1;
		int conv15_stride_width = 1;
		int conv15_dilation_height = 1;
		int conv15_dilation_width = 1;
		int conv15_withRELU = 1;

		float *conv15_coef = new float[conv12_output_channel * conv15_output_channel * conv15_kernel_height * conv15_kernel_width];
		float *conv15_new_coef = new float[conv12_output_channel * conv15_output_channel * conv15_kernel_height * conv15_kernel_width];
		float *conv15_bias = new float[conv15_output_channel];
		float *conv14_output_col = new float[conv14_output_channel * conv15_kernel_height * conv15_kernel_width * conv15_output_height * conv15_output_width];
		float *conv15_output = new float[conv15_output_channel * conv15_output_height * conv15_output_width];
		readFile1("./data_face/face.bin", conv15_coef, conv12_output_channel * conv15_output_channel * conv15_kernel_height * conv15_kernel_width * sizeof(float), vec);
		vec.push_back(conv12_output_channel * conv15_output_channel * conv15_kernel_height * conv15_kernel_width * sizeof(float));
		readFile1("./data_face/face.bin", conv15_bias, conv15_output_channel * sizeof(float), vec);
		vec.push_back(conv15_output_channel * sizeof(float));
		Row_column_transpose(conv15_coef, conv15_new_coef, conv15_output_channel, conv12_output_channel * conv15_kernel_height * conv15_kernel_width);
		//end init conv15

		//start init conv16
		int conv16_output_channel = 64;
		int conv16_kernel_height = 1;
		int conv16_kernel_width = 1;
		int conv16_output_height = 5;
		int conv16_output_width = 5;
		int conv16_pad_height = 0;
		int conv16_pad_width = 0;
		int conv16_stride_height = 1;
		int conv16_stride_width = 1;
		int conv16_dilation_height = 1;
		int conv16_dilation_width = 1;
		int conv16_withRELU = 1;

		float *conv16_coef = new float[conv15_output_channel * conv16_output_channel * conv16_kernel_height * conv16_kernel_width];
		float *conv16_new_coef = new float[conv15_output_channel * conv16_output_channel * conv16_kernel_height * conv16_kernel_width];
		float *conv16_bias = new float[conv16_output_channel];
		float *conv15_output_col = new float[conv15_output_channel * conv16_kernel_height * conv16_kernel_width * conv16_output_height * conv16_output_width];
		float *conv16_output = new float[conv16_output_channel * conv16_output_height * conv16_output_width];
		readFile1("./data_face/face.bin", conv16_coef, conv15_output_channel * conv16_output_channel * conv16_kernel_height * conv16_kernel_width * sizeof(float), vec);
		vec.push_back(conv15_output_channel * conv16_output_channel * conv16_kernel_height * conv16_kernel_width * sizeof(float));
		readFile1("./data_face/face.bin", conv16_bias, conv16_output_channel * sizeof(float), vec);
		vec.push_back(conv16_output_channel * sizeof(float));
		Row_column_transpose(conv16_coef, conv16_new_coef, conv16_output_channel, conv15_output_channel * conv16_kernel_height * conv16_kernel_width);
		//end init conv16

		//start init conv17
		int conv17_output_channel = 128;
		int conv17_kernel_height = 3;
		int conv17_kernel_width = 3;
		int conv17_output_height = 5;
		int conv17_output_width = 5;
		int conv17_pad_height = 1;
		int conv17_pad_width = 1;
		int conv17_stride_height = 1;
		int conv17_stride_width = 1;
		int conv17_dilation_height = 1;
		int conv17_dilation_width = 1;
		int conv17_withRELU = 1;

		float *conv17_coef = new float[conv12_output_channel * conv17_output_channel * conv17_kernel_height * conv17_kernel_width];
		float *conv17_new_coef = new float[conv12_output_channel * conv17_output_channel * conv17_kernel_height * conv17_kernel_width];
		float *conv17_bias = new float[conv17_output_channel];
		float *conv16_output_col = new float[conv16_output_channel * conv17_kernel_height * conv17_kernel_width * conv17_output_height * conv17_output_width];
		float *conv17_output = new float[conv17_output_channel * conv17_output_height * conv17_output_width];
		readFile1("./data_face/face.bin", conv17_coef, conv12_output_channel * conv17_output_channel * conv17_kernel_height * conv17_kernel_width * sizeof(float), vec);
		vec.push_back(conv12_output_channel * conv17_output_channel * conv17_kernel_height * conv17_kernel_width * sizeof(float));
		readFile1("./data_face/face.bin", conv17_bias, conv17_output_channel * sizeof(float), vec);
		vec.push_back(conv17_output_channel * sizeof(float));
		Row_column_transpose(conv17_coef, conv17_new_coef, conv17_output_channel, conv12_output_channel * conv17_kernel_height * conv17_kernel_width);
		//end init conv17


		//start init scales3_norm
		int scales3_norm_output_channel = 128;
		int scales3_norm_output_height = 38;
		int scales3_norm_output_width = 38;
		//float *scales3_norm_output = new float[scales3_norm_output_channel * scales3_norm_output_height * scales3_norm_output_width];
		//readFile("data/scales3_norm_output", scales3_norm_output, scales3_norm_output_channel * scales3_norm_output_height * scales3_norm_output_width * 4);
		float *scales3_norm_output = new float[scales3_norm_output_channel * scales3_norm_output_height * scales3_norm_output_width];
		//float *scales3_norm_output_transpose = new float[scales3_norm_output_channel * scales3_norm_output_height * scales3_norm_output_width];

		float *scale3 = new float[scales3_norm_output_channel];
		int across_spatial = 0;
		int channel_shared = 0;
		if (channel_shared)
		{
			readFile1("./data_face/face.bin", scale3, 1 * sizeof(float), vec);
			vec.push_back(1 * sizeof(float) );

		}
		else
		{
			readFile1("./data_face/face.bin", scale3, scales3_norm_output_channel * sizeof(float), vec);
			vec.push_back(scales3_norm_output_channel * sizeof(float));
		}
		//end init scales3_norm    



		//start init scales3_mbox_loc
		int scales3_mbox_loc_output_channel = 16;
		int scales3_mbox_loc_kernel_height = 3;
		int scales3_mbox_loc_kernel_width = 3;
		int scales3_mbox_loc_output_height = 38;
		int scales3_mbox_loc_output_width = 38;
		int scales3_mbox_loc_pad_height = 1;
		int scales3_mbox_loc_pad_width = 1;
		int scales3_mbox_loc_stride_height = 1;
		int scales3_mbox_loc_stride_width = 1;
		int scales3_mbox_loc_dilation_height = 1;
		int scales3_mbox_loc_dilation_width = 1;
		int scales3_mbox_loc_withRELU = 0;
		float *scales3_mbox_loc_coef = new float[scales3_channel * scales3_mbox_loc_output_channel * scales3_mbox_loc_kernel_height * scales3_mbox_loc_kernel_width];
		float *scales3_mbox_loc_new_coef = new float[scales3_channel * scales3_mbox_loc_output_channel * scales3_mbox_loc_kernel_height * scales3_mbox_loc_kernel_width];
		float *scales3_mbox_loc_bias = new float[scales3_mbox_loc_output_channel];
		float *scales3_norm_output_col2 = new float[scales3_mbox_loc_output_height * scales3_mbox_loc_output_width * scales3_channel * scales3_mbox_loc_kernel_height * scales3_mbox_loc_kernel_height];
		float *scales3_mbox_loc_output = new float[scales3_mbox_loc_output_channel * scales3_mbox_loc_output_height * scales3_mbox_loc_output_width];
		float *scales3_mbox_loc_output_transpose = new float[scales3_mbox_loc_output_channel * scales3_mbox_loc_output_height * scales3_mbox_loc_output_width];
		readFile1("./data_face/face.bin", scales3_mbox_loc_coef, scales3_channel * scales3_mbox_loc_output_channel * scales3_mbox_loc_kernel_height * scales3_mbox_loc_kernel_width * sizeof(float), vec);
		vec.push_back(scales3_channel * scales3_mbox_loc_output_channel * scales3_mbox_loc_kernel_height * scales3_mbox_loc_kernel_width * sizeof(float));
		readFile1("./data_face/face.bin", scales3_mbox_loc_bias, scales3_mbox_loc_output_channel * sizeof(float), vec);
		vec.push_back(scales3_mbox_loc_output_channel * sizeof(float));
		Row_column_transpose(scales3_mbox_loc_coef, scales3_mbox_loc_new_coef, scales3_mbox_loc_output_channel, scales3_channel * scales3_mbox_loc_kernel_height * scales3_mbox_loc_kernel_width);
		//end init scales3_mbox_loc

		//start init scales3_mbox_loc_perm
		int scales3_mbox_loc_perm_orders_value[4] = { 0, 2, 3, 1 };
		vector<int> scales3_mbox_loc_perm_orders(scales3_mbox_loc_perm_orders_value, scales3_mbox_loc_perm_orders_value + 4);
		vector<int> scales3_mbox_loc_perm_shape(4, 1);
		scales3_mbox_loc_perm_shape[1] = scales3_mbox_loc_output_channel;
		scales3_mbox_loc_perm_shape[2] = scales3_mbox_loc_output_height;
		scales3_mbox_loc_perm_shape[3] = scales3_mbox_loc_output_width;
		float *scales3_mbox_loc_perm_output = new float[scales3_mbox_loc_output_channel * scales3_mbox_loc_output_height * scales3_mbox_loc_output_width];
		//end init scales3_mbox_loc_perm


		//start init scales3_mbox_conf
		int scales3_mbox_conf_output_channel = 8;
		int scales3_mbox_conf_kernel_height = 3;
		int scales3_mbox_conf_kernel_width = 3;
		int scales3_mbox_conf_output_height = 38;
		int scales3_mbox_conf_output_width = 38;
		int scales3_mbox_conf_pad_height = 1;
		int scales3_mbox_conf_pad_width = 1;
		int scales3_mbox_conf_stride_height = 1;
		int scales3_mbox_conf_stride_width = 1;
		int scales3_mbox_conf_dilation_height = 1;
		int scales3_mbox_conf_dilation_width = 1;
		int scales3_mbox_conf_withRELU = 0;
		float *scales3_mbox_conf_coef = new float[scales3_channel * scales3_mbox_conf_output_channel * scales3_mbox_conf_kernel_height * scales3_mbox_conf_kernel_width];
		float *scales3_mbox_conf_new_coef = new float[scales3_channel * scales3_mbox_conf_output_channel * scales3_mbox_conf_kernel_height * scales3_mbox_conf_kernel_width];
		float *scales3_mbox_conf_bias = new float[scales3_mbox_conf_output_channel];
		float *scales3_norm_output_col3 = new float[scales3_mbox_conf_output_height * scales3_mbox_conf_output_width * scales3_channel * scales3_mbox_conf_kernel_height * scales3_mbox_conf_kernel_width];
		float *scales3_mbox_conf_output = new float[scales3_mbox_conf_output_channel * scales3_mbox_conf_output_height * scales3_mbox_conf_output_width];
		float *scales3_mbox_conf_output_transpose = new float[scales3_mbox_conf_output_channel * scales3_mbox_conf_output_height * scales3_mbox_conf_output_width];
		readFile1("./data_face/face.bin", scales3_mbox_conf_coef, scales3_channel * scales3_mbox_conf_output_channel * scales3_mbox_conf_kernel_height * scales3_mbox_conf_kernel_width * sizeof(float), vec);
		vec.push_back(scales3_channel * scales3_mbox_conf_output_channel * scales3_mbox_conf_kernel_height * scales3_mbox_conf_kernel_width * sizeof(float));
		readFile1("./data_face/face.bin", scales3_mbox_conf_bias, scales3_mbox_conf_output_channel * sizeof(float), vec);
		vec.push_back(scales3_mbox_conf_output_channel * sizeof(float));
		Row_column_transpose(scales3_mbox_conf_coef, scales3_mbox_conf_new_coef, scales3_mbox_conf_output_channel, scales3_channel * scales3_mbox_conf_kernel_height * scales3_mbox_conf_kernel_width);
		//end init scales3_mbox_conf

		//start init scales3_mbox_conf_perm
		int scales3_mbox_conf_perm_orders_value[4] = { 0, 2, 3, 1 };
		vector<int> scales3_mbox_conf_perm_orders(scales3_mbox_conf_perm_orders_value, scales3_mbox_conf_perm_orders_value + 4);
		vector<int> scales3_mbox_conf_perm_shape(4, 1);
		scales3_mbox_conf_perm_shape[1] = scales3_mbox_conf_output_channel;
		scales3_mbox_conf_perm_shape[2] = scales3_mbox_conf_output_height;
		scales3_mbox_conf_perm_shape[3] = scales3_mbox_conf_output_width;
		float *scales3_mbox_conf_perm_output = new float[scales3_mbox_conf_output_channel * scales3_mbox_conf_output_height * scales3_mbox_conf_output_width];
		//end init scales3_mbox_conf_perm


		//start init scales5_mbox_loc
		int scales5_mbox_loc_output_channel = 24;
		int scales5_mbox_loc_kernel_height = 3;
		int scales5_mbox_loc_kernel_width = 3;
		int scales5_mbox_loc_output_height = 19;
		int scales5_mbox_loc_output_width = 19;
		int scales5_mbox_loc_pad_height = 1;
		int scales5_mbox_loc_pad_width = 1;
		int scales5_mbox_loc_stride_height = 1;
		int scales5_mbox_loc_stride_width = 1;
		int scales5_mbox_loc_dilation_height = 1;
		int scales5_mbox_loc_dilation_width = 1;
		int scales5_mbox_loc_withRELU = 0;

		float *scales5_mbox_loc_coef = new float[scales5_channel * scales5_mbox_loc_output_channel * scales5_mbox_loc_kernel_height * scales5_mbox_loc_kernel_width];
		float *scales5_mbox_loc_new_coef = new float[scales5_channel * scales5_mbox_loc_output_channel * scales5_mbox_loc_kernel_height * scales5_mbox_loc_kernel_width];
		float *scales5_mbox_loc_bias = new float[scales5_mbox_loc_output_channel];
		float *scales5_output_col2 = new float[scales5_channel * scales5_mbox_loc_kernel_height * scales5_mbox_loc_kernel_width * scales5_mbox_loc_output_height * scales5_mbox_loc_output_width];
		float *scales5_mbox_loc_output = new float[scales5_mbox_loc_output_channel * scales5_mbox_loc_output_height * scales5_mbox_loc_output_width];
		float *scales5_mbox_loc_output_transpose = new float[scales5_mbox_loc_output_channel * scales5_mbox_loc_output_height * scales5_mbox_loc_output_width];
		readFile1("./data_face/face.bin", scales5_mbox_loc_coef, scales5_channel * scales5_mbox_loc_output_channel * scales5_mbox_loc_kernel_height * scales5_mbox_loc_kernel_width * sizeof(float), vec);
		vec.push_back(scales5_channel * scales5_mbox_loc_output_channel * scales5_mbox_loc_kernel_height * scales5_mbox_loc_kernel_width * sizeof(float));
		readFile1("./data_face/face.bin", scales5_mbox_loc_bias, scales5_mbox_loc_output_channel * sizeof(float), vec);
		vec.push_back(scales5_mbox_loc_output_channel * sizeof(float));
		Row_column_transpose(scales5_mbox_loc_coef, scales5_mbox_loc_new_coef, scales5_mbox_loc_output_channel, scales5_channel * scales5_mbox_loc_kernel_height * scales5_mbox_loc_kernel_width);
		//end init scales5_mbox_loc


		//start init scales5_mbox_loc_perm
		int scales5_mbox_loc_perm_orders_value[4] = { 0, 2, 3, 1 };
		vector<int> scales5_mbox_loc_perm_orders(scales5_mbox_loc_perm_orders_value, scales5_mbox_loc_perm_orders_value + 4);
		vector<int> scales5_mbox_loc_perm_shape(4, 1);
		scales5_mbox_loc_perm_shape[1] = scales5_mbox_loc_output_channel;
		scales5_mbox_loc_perm_shape[2] = scales5_mbox_loc_output_height;
		scales5_mbox_loc_perm_shape[3] = scales5_mbox_loc_output_width;
		float *scales5_mbox_loc_perm_output = new float[scales5_mbox_loc_output_channel * scales5_mbox_loc_output_height * scales5_mbox_loc_output_width];
		//end init scales5_mbox_loc_perm



		//start init scales5_mbox_conf
		int scales5_mbox_conf_output_channel = 12;
		int scales5_mbox_conf_kernel_height = 3;
		int scales5_mbox_conf_kernel_width = 3;
		int scales5_mbox_conf_output_height = 19;
		int scales5_mbox_conf_output_width = 19;
		int scales5_mbox_conf_pad_height = 1;
		int scales5_mbox_conf_pad_width = 1;
		int scales5_mbox_conf_stride_height = 1;
		int scales5_mbox_conf_stride_width = 1;
		int scales5_mbox_conf_dilation_height = 1;
		int scales5_mbox_conf_dilation_width = 1;
		int scales5_mbox_conf_withRELU = 0;
		float *scales5_mbox_conf_coef = new float[scales5_channel * scales5_mbox_conf_output_channel * scales5_mbox_conf_kernel_height * scales5_mbox_conf_kernel_width];
		float *scales5_mbox_conf_new_coef = new float[scales5_channel * scales5_mbox_conf_output_channel * scales5_mbox_conf_kernel_height * scales5_mbox_conf_kernel_width];
		float *scales5_mbox_conf_bias = new float[scales5_mbox_conf_output_channel];
		float *scales5_output_col3 = new float[scales5_channel * scales5_mbox_conf_kernel_height * scales5_mbox_conf_kernel_width * scales5_mbox_conf_output_height * scales5_mbox_conf_output_width];
		float *scales5_mbox_conf_output = new float[scales5_mbox_conf_output_channel * scales5_mbox_conf_output_height * scales5_mbox_conf_output_width];
		float *scales5_mbox_conf_output_transpose = new float[scales5_mbox_conf_output_channel * scales5_mbox_conf_output_height * scales5_mbox_conf_output_width];
		readFile1("./data_face/face.bin", scales5_mbox_conf_coef, scales5_channel * scales5_mbox_conf_output_channel * scales5_mbox_conf_kernel_height * scales5_mbox_conf_kernel_width * sizeof(float), vec);
		vec.push_back(scales5_channel * scales5_mbox_conf_output_channel * scales5_mbox_conf_kernel_height * scales5_mbox_conf_kernel_width * sizeof(float));
		readFile1("./data_face/face.bin", scales5_mbox_conf_bias, scales5_mbox_conf_output_channel * sizeof(float), vec);
		vec.push_back(scales5_mbox_conf_output_channel * sizeof(float));
		Row_column_transpose(scales5_mbox_conf_coef, scales5_mbox_conf_new_coef, scales5_mbox_conf_output_channel, scales5_channel * scales5_mbox_conf_kernel_height * scales5_mbox_conf_kernel_width);
		//end init scales5_mbox_conf

		//start init scales5_mbox_conf_perm
		int scales5_mbox_conf_perm_orders_value[4] = { 0, 2, 3, 1 };
		vector<int> scales5_mbox_conf_perm_orders(scales5_mbox_conf_perm_orders_value, scales5_mbox_conf_perm_orders_value + 4);
		vector<int> scales5_mbox_conf_perm_shape(4, 1);
		scales5_mbox_conf_perm_shape[1] = scales5_mbox_conf_output_channel;
		scales5_mbox_conf_perm_shape[2] = scales5_mbox_conf_output_height;
		scales5_mbox_conf_perm_shape[3] = scales5_mbox_conf_output_width;
		float *scales5_mbox_conf_perm_output = new float[scales5_mbox_conf_output_channel * scales5_mbox_conf_output_height * scales5_mbox_conf_output_width];
		//end init scales5_mbox_conf_perm


		//start init conv11_mbox_loc
		int conv11_mbox_loc_output_channel = 24;
		int conv11_mbox_loc_kernel_height = 3;
		int conv11_mbox_loc_kernel_width = 3;
		int conv11_mbox_loc_output_height = 10;
		int conv11_mbox_loc_output_width = 10;
		int conv11_mbox_loc_pad_height = 1;
		int conv11_mbox_loc_pad_width = 1;
		int conv11_mbox_loc_stride_height = 1;
		int conv11_mbox_loc_stride_width = 1;
		int conv11_mbox_loc_dilation_height = 1;
		int conv11_mbox_loc_dilation_width = 1;
		int conv11_mbox_loc_withRELU = 0;

		float *conv11_mbox_loc_coef = new float[conv11_output_channel * conv11_mbox_loc_output_channel * conv11_mbox_loc_kernel_height * conv11_mbox_loc_kernel_width];
		float *conv11_mbox_loc_new_coef = new float[conv11_output_channel * conv11_mbox_loc_output_channel * conv11_mbox_loc_kernel_height * conv11_mbox_loc_kernel_width];
		float *conv11_mbox_loc_bias = new float[conv11_mbox_loc_output_channel];
		float *conv11_output_col2 = new float[conv11_output_channel * conv11_mbox_loc_kernel_height * conv11_mbox_loc_kernel_width * conv11_mbox_loc_output_height * conv11_mbox_loc_output_width];
		float *conv11_mbox_loc_output = new float[conv11_mbox_loc_output_channel * conv11_mbox_loc_output_height * conv11_mbox_loc_output_width];
		float *conv11_mbox_loc_output_transpose = new float[conv11_mbox_loc_output_channel * conv11_mbox_loc_output_height * conv11_mbox_loc_output_width];
		readFile1("./data_face/face.bin", conv11_mbox_loc_coef, conv11_output_channel * conv11_mbox_loc_output_channel * conv11_mbox_loc_kernel_height * conv11_mbox_loc_kernel_width * sizeof(float), vec);
		vec.push_back(conv11_output_channel * conv11_mbox_loc_output_channel * conv11_mbox_loc_kernel_height * conv11_mbox_loc_kernel_width * sizeof(float));
		readFile1("./data_face/face.bin", conv11_mbox_loc_bias, conv11_mbox_loc_output_channel * sizeof(float), vec);
		vec.push_back(conv11_mbox_loc_output_channel * sizeof(float));
		Row_column_transpose(conv11_mbox_loc_coef, conv11_mbox_loc_new_coef, conv11_mbox_loc_output_channel, conv11_output_channel * conv11_mbox_loc_kernel_height * conv11_mbox_loc_kernel_width);
		//end init conv11_mbox_loc


		//start init conv11_mbox_loc_perm
		int conv11_mbox_loc_perm_orders_value[4] = { 0, 2, 3, 1 };
		vector<int> conv11_mbox_loc_perm_orders(conv11_mbox_loc_perm_orders_value, conv11_mbox_loc_perm_orders_value + 4);
		vector<int> conv11_mbox_loc_perm_shape(4, 1);
		conv11_mbox_loc_perm_shape[1] = conv11_mbox_loc_output_channel;
		conv11_mbox_loc_perm_shape[2] = conv11_mbox_loc_output_height;
		conv11_mbox_loc_perm_shape[3] = conv11_mbox_loc_output_width;
		float *conv11_mbox_loc_perm_output = new float[conv11_mbox_loc_output_channel * conv11_mbox_loc_output_height * conv11_mbox_loc_output_width];
		//end init conv11_mbox_loc_perm



		//start init conv11_mbox_conf
		int conv11_mbox_conf_output_channel = 12;
		int conv11_mbox_conf_kernel_height = 3;
		int conv11_mbox_conf_kernel_width = 3;
		int conv11_mbox_conf_output_height = 10;
		int conv11_mbox_conf_output_width = 10;
		int conv11_mbox_conf_pad_height = 1;
		int conv11_mbox_conf_pad_width = 1;
		int conv11_mbox_conf_stride_height = 1;
		int conv11_mbox_conf_stride_width = 1;
		int conv11_mbox_conf_dilation_height = 1;
		int conv11_mbox_conf_dilation_width = 1;
		int conv11_mbox_conf_withRELU = 0;
		float *conv11_mbox_conf_coef = new float[conv11_output_channel * conv11_mbox_conf_output_channel * conv11_mbox_conf_kernel_height * conv11_mbox_conf_kernel_width];
		float *conv11_mbox_conf_new_coef = new float[conv11_output_channel * conv11_mbox_conf_output_channel * conv11_mbox_conf_kernel_height * conv11_mbox_conf_kernel_width];
		float *conv11_mbox_conf_bias = new float[conv11_mbox_conf_output_channel];
		float *conv11_output_col3 = new float[conv11_output_channel * conv11_mbox_conf_kernel_height * conv11_mbox_conf_kernel_width * conv11_mbox_conf_output_height * conv11_mbox_conf_output_width];
		float *conv11_mbox_conf_output = new float[conv11_mbox_conf_output_channel * conv11_mbox_conf_output_height * conv11_mbox_conf_output_width];
		float *conv11_mbox_conf_output_transpose = new float[conv11_mbox_conf_output_channel * conv11_mbox_conf_output_height * conv11_mbox_conf_output_width];
		readFile1("./data_face/face.bin", conv11_mbox_conf_coef, conv11_output_channel * conv11_mbox_conf_output_channel * conv11_mbox_conf_kernel_height * conv11_mbox_conf_kernel_width * sizeof(float), vec);
		vec.push_back(conv11_output_channel * conv11_mbox_conf_output_channel * conv11_mbox_conf_kernel_height * conv11_mbox_conf_kernel_width * sizeof(float));
		readFile1("./data_face/face.bin", conv11_mbox_conf_bias, conv11_mbox_conf_output_channel * sizeof(float), vec);
		vec.push_back(conv11_mbox_conf_output_channel * sizeof(float));
		Row_column_transpose(conv11_mbox_conf_coef, conv11_mbox_conf_new_coef, conv11_mbox_conf_output_channel, conv11_output_channel * conv11_mbox_conf_kernel_height * conv11_mbox_conf_kernel_width);
		//end init conv11_mbox_conf

		//start init conv11_mbox_conf_perm
		int conv11_mbox_conf_perm_orders_value[4] = { 0, 2, 3, 1 };
		vector<int> conv11_mbox_conf_perm_orders(conv11_mbox_conf_perm_orders_value, conv11_mbox_conf_perm_orders_value + 4);
		vector<int> conv11_mbox_conf_perm_shape(4, 1);
		conv11_mbox_conf_perm_shape[1] = conv11_mbox_conf_output_channel;
		conv11_mbox_conf_perm_shape[2] = conv11_mbox_conf_output_height;
		conv11_mbox_conf_perm_shape[3] = conv11_mbox_conf_output_width;
		float *conv11_mbox_conf_perm_output = new float[conv11_mbox_conf_output_channel * conv11_mbox_conf_output_height * conv11_mbox_conf_output_width];
		//end init conv11_mbox_conf_perm

		//start init conv13_mbox_loc

		int conv13_mbox_loc_output_channel = 24;
		int conv13_mbox_loc_kernel_height = 3;
		int conv13_mbox_loc_kernel_width = 3;
		int conv13_mbox_loc_output_height = 5;
		int conv13_mbox_loc_output_width = 5;
		int conv13_mbox_loc_pad_height = 1;
		int conv13_mbox_loc_pad_width = 1;
		int conv13_mbox_loc_stride_height = 1;
		int conv13_mbox_loc_stride_width = 1;
		int conv13_mbox_loc_dilation_height = 1;
		int conv13_mbox_loc_dilation_width = 1;
		int conv13_mbox_loc_withRELU = 0;

		float *conv13_mbox_loc_coef = new float[conv13_output_channel * conv13_mbox_loc_output_channel * conv13_mbox_loc_kernel_height * conv13_mbox_loc_kernel_width];
		float *conv13_mbox_loc_new_coef = new float[conv13_output_channel * conv13_mbox_loc_output_channel * conv13_mbox_loc_kernel_height * conv13_mbox_loc_kernel_width];
		float *conv13_mbox_loc_bias = new float[conv13_mbox_loc_output_channel];
		float *conv13_output_col2 = new float[conv13_output_channel * conv13_mbox_loc_kernel_height * conv13_mbox_loc_kernel_width * conv13_mbox_loc_output_height * conv13_mbox_loc_output_width];
		float *conv13_mbox_loc_output = new float[conv13_mbox_loc_output_channel * conv13_mbox_loc_output_height * conv13_mbox_loc_output_width];
		float *conv13_mbox_loc_output_transpose = new float[conv13_mbox_loc_output_channel * conv13_mbox_loc_output_height * conv13_mbox_loc_output_width];
		readFile1("./data_face/face.bin", conv13_mbox_loc_coef, conv13_output_channel * conv13_mbox_loc_output_channel * conv13_mbox_loc_kernel_height * conv13_mbox_loc_kernel_width * sizeof(float), vec);
		vec.push_back(conv13_output_channel * conv13_mbox_loc_output_channel * conv13_mbox_loc_kernel_height * conv13_mbox_loc_kernel_width * sizeof(float));
		readFile1("./data_face/face.bin", conv13_mbox_loc_bias, conv13_mbox_loc_output_channel * sizeof(float), vec);
		vec.push_back(conv13_mbox_loc_output_channel * sizeof(float));
		Row_column_transpose(conv13_mbox_loc_coef, conv13_mbox_loc_new_coef, conv13_mbox_loc_output_channel, conv13_output_channel * conv13_mbox_loc_kernel_height * conv13_mbox_loc_kernel_width);
		//end init conv13_mbox_loc


		//start init conv13_mbox_loc_perm
		int conv13_mbox_loc_perm_orders_value[4] = { 0, 2, 3, 1 };
		vector<int> conv13_mbox_loc_perm_orders(conv13_mbox_loc_perm_orders_value, conv13_mbox_loc_perm_orders_value + 4);
		vector<int> conv13_mbox_loc_perm_shape(4, 1);
		conv13_mbox_loc_perm_shape[1] = conv13_mbox_loc_output_channel;
		conv13_mbox_loc_perm_shape[2] = conv13_mbox_loc_output_height;
		conv13_mbox_loc_perm_shape[3] = conv13_mbox_loc_output_width;
		float *conv13_mbox_loc_perm_output = new float[conv13_mbox_loc_output_channel * conv13_mbox_loc_output_height * conv13_mbox_loc_output_width];
		//end init conv13_mbox_loc_perm

		//start init conv13_mbox_conf
		int conv13_mbox_conf_output_channel = 12;
		int conv13_mbox_conf_kernel_height = 3;
		int conv13_mbox_conf_kernel_width = 3;
		int conv13_mbox_conf_output_height = 5;
		int conv13_mbox_conf_output_width = 5;
		int conv13_mbox_conf_pad_height = 1;
		int conv13_mbox_conf_pad_width = 1;
		int conv13_mbox_conf_stride_height = 1;
		int conv13_mbox_conf_stride_width = 1;
		int conv13_mbox_conf_dilation_height = 1;
		int conv13_mbox_conf_dilation_width = 1;
		int conv13_mbox_conf_withRELU = 0;
		float *conv13_mbox_conf_coef = new float[conv13_output_channel * conv13_mbox_conf_output_channel * conv13_mbox_conf_kernel_height * conv13_mbox_conf_kernel_width];
		float *conv13_mbox_conf_new_coef = new float[conv13_output_channel * conv13_mbox_conf_output_channel * conv13_mbox_conf_kernel_height * conv13_mbox_conf_kernel_width];
		float *conv13_mbox_conf_bias = new float[conv13_mbox_conf_output_channel];
		float *conv13_output_col3 = new float[conv13_output_channel * conv13_mbox_conf_kernel_height * conv13_mbox_conf_kernel_width * conv13_mbox_conf_output_height * conv13_mbox_conf_output_width];
		float *conv13_mbox_conf_output = new float[conv13_mbox_conf_output_channel * conv13_mbox_conf_output_height * conv13_mbox_conf_output_width];
		float *conv13_mbox_conf_output_transpose = new float[conv13_mbox_conf_output_channel * conv13_mbox_conf_output_height * conv13_mbox_conf_output_width];
		readFile1("./data_face/face.bin", conv13_mbox_conf_coef, conv13_output_channel * conv13_mbox_conf_output_channel * conv13_mbox_conf_kernel_height * conv13_mbox_conf_kernel_width * sizeof(float), vec);
		vec.push_back(conv13_output_channel * conv13_mbox_conf_output_channel * conv13_mbox_conf_kernel_height * conv13_mbox_conf_kernel_width * sizeof(float));
		readFile1("./data_face/face.bin", conv13_mbox_conf_bias, conv13_mbox_conf_output_channel * sizeof(float), vec);
		vec.push_back(conv13_mbox_conf_output_channel * sizeof(float));
		Row_column_transpose(conv13_mbox_conf_coef, conv13_mbox_conf_new_coef, conv13_mbox_conf_output_channel, conv13_output_channel * conv13_mbox_conf_kernel_height * conv13_mbox_conf_kernel_width);
		//end init conv13_mbox_conf

		//start init conv13_mbox_conf_perm
		int conv13_mbox_conf_perm_orders_value[4] = { 0, 2, 3, 1 };
		vector<int> conv13_mbox_conf_perm_orders(conv13_mbox_conf_perm_orders_value, conv13_mbox_conf_perm_orders_value + 4);
		vector<int> conv13_mbox_conf_perm_shape(4, 1);
		conv13_mbox_conf_perm_shape[1] = conv13_mbox_conf_output_channel;
		conv13_mbox_conf_perm_shape[2] = conv13_mbox_conf_output_height;
		conv13_mbox_conf_perm_shape[3] = conv13_mbox_conf_output_width;
		float *conv13_mbox_conf_perm_output = new float[conv13_mbox_conf_output_channel * conv13_mbox_conf_output_height * conv13_mbox_conf_output_width];
		//end init conv13_mbox_conf_perm


		//start init conv15_mbox_loc

		int conv15_mbox_loc_output_channel = 16;
		int conv15_mbox_loc_kernel_height = 3;
		int conv15_mbox_loc_kernel_width = 3;
		int conv15_mbox_loc_output_height = 5;
		int conv15_mbox_loc_output_width = 5;
		int conv15_mbox_loc_pad_height = 1;
		int conv15_mbox_loc_pad_width = 1;
		int conv15_mbox_loc_stride_height = 1;
		int conv15_mbox_loc_stride_width = 1;
		int conv15_mbox_loc_dilation_height = 1;
		int conv15_mbox_loc_dilation_width = 1;
		int conv15_mbox_loc_withRELU = 0;

		float *conv15_mbox_loc_coef = new float[conv15_output_channel * conv15_mbox_loc_output_channel * conv15_mbox_loc_kernel_height * conv15_mbox_loc_kernel_width];
		float *conv15_mbox_loc_new_coef = new float[conv15_output_channel * conv15_mbox_loc_output_channel * conv15_mbox_loc_kernel_height * conv15_mbox_loc_kernel_width];
		float *conv15_mbox_loc_bias = new float[conv15_mbox_loc_output_channel];
		float *conv15_output_col2 = new float[conv15_output_channel * conv15_mbox_loc_kernel_height * conv15_mbox_loc_kernel_width * conv15_mbox_loc_output_height * conv15_mbox_loc_output_width];
		float *conv15_mbox_loc_output = new float[conv15_mbox_loc_output_channel * conv15_mbox_loc_output_height * conv15_mbox_loc_output_width];
		float *conv15_mbox_loc_output_transpose = new float[conv15_mbox_loc_output_channel * conv15_mbox_loc_output_height * conv15_mbox_loc_output_width];
		readFile1("./data_face/face.bin", conv15_mbox_loc_coef, conv15_output_channel * conv15_mbox_loc_output_channel * conv15_mbox_loc_kernel_height * conv15_mbox_loc_kernel_width * sizeof(float), vec);
		vec.push_back(conv15_output_channel * conv15_mbox_loc_output_channel * conv15_mbox_loc_kernel_height * conv15_mbox_loc_kernel_width * sizeof(float));
		readFile1("./data_face/face.bin", conv15_mbox_loc_bias, conv15_mbox_loc_output_channel * sizeof(float), vec);
		vec.push_back(conv15_mbox_loc_output_channel * sizeof(float));
		Row_column_transpose(conv15_mbox_loc_coef, conv15_mbox_loc_new_coef, conv15_mbox_loc_output_channel, conv15_output_channel * conv15_mbox_loc_kernel_height * conv15_mbox_loc_kernel_width);
		//end init conv15_mbox_loc


		//start init conv15_mbox_loc_perm
		int conv15_mbox_loc_perm_orders_value[4] = { 0, 2, 3, 1 };
		vector<int> conv15_mbox_loc_perm_orders(conv15_mbox_loc_perm_orders_value, conv15_mbox_loc_perm_orders_value + 4);
		vector<int> conv15_mbox_loc_perm_shape(4, 1);
		conv15_mbox_loc_perm_shape[1] = conv15_mbox_loc_output_channel;
		conv15_mbox_loc_perm_shape[2] = conv15_mbox_loc_output_height;
		conv15_mbox_loc_perm_shape[3] = conv15_mbox_loc_output_width;
		float *conv15_mbox_loc_perm_output = new float[conv15_mbox_loc_output_channel * conv15_mbox_loc_output_height * conv15_mbox_loc_output_width];
		//end init conv15_mbox_loc_perm

		//start init conv15_mbox_conf
		int conv15_mbox_conf_output_channel = 8;
		int conv15_mbox_conf_kernel_height = 3;
		int conv15_mbox_conf_kernel_width = 3;
		int conv15_mbox_conf_output_height = 5;
		int conv15_mbox_conf_output_width = 5;
		int conv15_mbox_conf_pad_height = 1;
		int conv15_mbox_conf_pad_width = 1;
		int conv15_mbox_conf_stride_height = 1;
		int conv15_mbox_conf_stride_width = 1;
		int conv15_mbox_conf_dilation_height = 1;
		int conv15_mbox_conf_dilation_width = 1;
		int conv15_mbox_conf_withRELU = 0;
		float *conv15_mbox_conf_coef = new float[conv15_output_channel * conv15_mbox_conf_output_channel * conv15_mbox_conf_kernel_height * conv15_mbox_conf_kernel_width];
		float *conv15_mbox_conf_new_coef = new float[conv15_output_channel * conv15_mbox_conf_output_channel * conv15_mbox_conf_kernel_height * conv15_mbox_conf_kernel_width];
		float *conv15_mbox_conf_bias = new float[conv15_mbox_conf_output_channel];
		float *conv15_output_col3 = new float[conv15_output_channel * conv15_mbox_conf_kernel_height * conv15_mbox_conf_kernel_width * conv15_mbox_conf_output_height * conv15_mbox_conf_output_width];
		float *conv15_mbox_conf_output = new float[conv15_mbox_conf_output_channel * conv15_mbox_conf_output_height * conv15_mbox_conf_output_width];
		float *conv15_mbox_conf_output_transpose = new float[conv15_mbox_conf_output_channel * conv15_mbox_conf_output_height * conv15_mbox_conf_output_width];
		readFile1("./data_face/face.bin", conv15_mbox_conf_coef, conv15_output_channel * conv15_mbox_conf_output_channel * conv15_mbox_conf_kernel_height * conv15_mbox_conf_kernel_width * sizeof(float), vec);
		vec.push_back(conv15_output_channel * conv15_mbox_conf_output_channel * conv15_mbox_conf_kernel_height * conv15_mbox_conf_kernel_width * sizeof(float));
		readFile1("./data_face/face.bin", conv15_mbox_conf_bias, conv15_mbox_conf_output_channel * sizeof(float), vec);
		vec.push_back(conv15_mbox_conf_output_channel * sizeof(float));
		Row_column_transpose(conv15_mbox_conf_coef, conv15_mbox_conf_new_coef, conv15_mbox_conf_output_channel, conv15_output_channel * conv15_mbox_conf_kernel_height * conv15_mbox_conf_kernel_width);
		//end init conv15_mbox_conf

		//start init conv15_mbox_conf_perm
		int conv15_mbox_conf_perm_orders_value[4] = { 0, 2, 3, 1 };
		vector<int> conv15_mbox_conf_perm_orders(conv15_mbox_conf_perm_orders_value, conv15_mbox_conf_perm_orders_value + 4);
		vector<int> conv15_mbox_conf_perm_shape(4, 1);
		conv15_mbox_conf_perm_shape[1] = conv15_mbox_conf_output_channel;
		conv15_mbox_conf_perm_shape[2] = conv15_mbox_conf_output_height;
		conv15_mbox_conf_perm_shape[3] = conv15_mbox_conf_output_width;
		float *conv15_mbox_conf_perm_output = new float[conv15_mbox_conf_output_channel * conv15_mbox_conf_output_height * conv15_mbox_conf_output_width];
		//end init conv15_mbox_conf_perm



		//start init conv17_mbox_loc

		int conv17_mbox_loc_output_channel = 16;
		int conv17_mbox_loc_kernel_height = 3;
		int conv17_mbox_loc_kernel_width = 3;
		int conv17_mbox_loc_output_height = 5;
		int conv17_mbox_loc_output_width = 5;
		int conv17_mbox_loc_pad_height = 1;
		int conv17_mbox_loc_pad_width = 1;
		int conv17_mbox_loc_stride_height = 1;
		int conv17_mbox_loc_stride_width = 1;
		int conv17_mbox_loc_dilation_height = 1;
		int conv17_mbox_loc_dilation_width = 1;
		int conv17_mbox_loc_withRELU = 0;

		float *conv17_mbox_loc_coef = new float[conv17_output_channel * conv17_mbox_loc_output_channel * conv17_mbox_loc_kernel_height * conv17_mbox_loc_kernel_width];
		float *conv17_mbox_loc_new_coef = new float[conv17_output_channel * conv17_mbox_loc_output_channel * conv17_mbox_loc_kernel_height * conv17_mbox_loc_kernel_width];
		float *conv17_mbox_loc_bias = new float[conv17_mbox_loc_output_channel];
		float *conv17_output_col2 = new float[conv17_output_channel * conv17_mbox_loc_kernel_height * conv17_mbox_loc_kernel_width * conv17_mbox_loc_output_height * conv17_mbox_loc_output_width];
		float *conv17_mbox_loc_output = new float[conv17_mbox_loc_output_channel * conv17_mbox_loc_output_height * conv17_mbox_loc_output_width];
		float *conv17_mbox_loc_output_transpose = new float[conv17_mbox_loc_output_channel * conv17_mbox_loc_output_height * conv17_mbox_loc_output_width];
		readFile1("./data_face/face.bin", conv17_mbox_loc_coef, conv17_output_channel * conv17_mbox_loc_output_channel * conv17_mbox_loc_kernel_height * conv17_mbox_loc_kernel_width * sizeof(float), vec);
		vec.push_back(conv17_output_channel * conv17_mbox_loc_output_channel * conv17_mbox_loc_kernel_height * conv17_mbox_loc_kernel_width * sizeof(float));
		readFile1("./data_face/face.bin", conv17_mbox_loc_bias, conv17_mbox_loc_output_channel * sizeof(float), vec);
		vec.push_back(conv17_mbox_loc_output_channel * sizeof(float));
		Row_column_transpose(conv17_mbox_loc_coef, conv17_mbox_loc_new_coef, conv17_mbox_loc_output_channel, conv17_output_channel * conv17_mbox_loc_kernel_height * conv17_mbox_loc_kernel_width);
		//end init conv17_mbox_loc


		//start init conv17_mbox_loc_perm
		int conv17_mbox_loc_perm_orders_value[4] = { 0, 2, 3, 1 };
		vector<int> conv17_mbox_loc_perm_orders(conv17_mbox_loc_perm_orders_value, conv17_mbox_loc_perm_orders_value + 4);
		vector<int> conv17_mbox_loc_perm_shape(4, 1);
		conv17_mbox_loc_perm_shape[1] = conv17_mbox_loc_output_channel;
		conv17_mbox_loc_perm_shape[2] = conv17_mbox_loc_output_height;
		conv17_mbox_loc_perm_shape[3] = conv17_mbox_loc_output_width;
		float *conv17_mbox_loc_perm_output = new float[conv17_mbox_loc_output_channel * conv17_mbox_loc_output_height * conv17_mbox_loc_output_width];
		//end init conv17_mbox_loc_perm

		//start init conv17_mbox_conf
		int conv17_mbox_conf_output_channel = 8;
		int conv17_mbox_conf_kernel_height = 3;
		int conv17_mbox_conf_kernel_width = 3;
		int conv17_mbox_conf_output_height = 5;
		int conv17_mbox_conf_output_width = 5;
		int conv17_mbox_conf_pad_height = 1;
		int conv17_mbox_conf_pad_width = 1;
		int conv17_mbox_conf_stride_height = 1;
		int conv17_mbox_conf_stride_width = 1;
		int conv17_mbox_conf_dilation_height = 1;
		int conv17_mbox_conf_dilation_width = 1;
		int conv17_mbox_conf_withRELU = 0;
		float *conv17_mbox_conf_coef = new float[conv17_output_channel * conv17_mbox_conf_output_channel * conv17_mbox_conf_kernel_height * conv17_mbox_conf_kernel_width];
		float *conv17_mbox_conf_new_coef = new float[conv17_output_channel * conv17_mbox_conf_output_channel * conv17_mbox_conf_kernel_height * conv17_mbox_conf_kernel_width];
		float *conv17_mbox_conf_bias = new float[conv17_mbox_conf_output_channel];
		float *conv17_output_col3 = new float[conv17_output_channel * conv17_mbox_conf_kernel_height * conv17_mbox_conf_kernel_width * conv17_mbox_conf_output_height * conv17_mbox_conf_output_width];
		float *conv17_mbox_conf_output = new float[conv17_mbox_conf_output_channel * conv17_mbox_conf_output_height * conv17_mbox_conf_output_width];
		float *conv17_mbox_conf_output_transpose = new float[conv17_mbox_conf_output_channel * conv17_mbox_conf_output_height * conv17_mbox_conf_output_width];
		readFile1("./data_face/face.bin", conv17_mbox_conf_coef, conv17_output_channel * conv17_mbox_conf_output_channel * conv17_mbox_conf_kernel_height * conv17_mbox_conf_kernel_width * sizeof(float), vec);
		vec.push_back(conv17_output_channel * conv17_mbox_conf_output_channel * conv17_mbox_conf_kernel_height * conv17_mbox_conf_kernel_width * sizeof(float));
		readFile1("./data_face/face.bin", conv17_mbox_conf_bias, conv17_mbox_conf_output_channel * sizeof(float), vec);
		vec.push_back(conv17_mbox_conf_output_channel * sizeof(float));
		Row_column_transpose(conv17_mbox_conf_coef, conv17_mbox_conf_new_coef, conv17_mbox_conf_output_channel, conv17_output_channel * conv17_mbox_conf_kernel_height * conv17_mbox_conf_kernel_width);
		//end init conv17_mbox_conf

		//start init conv17_mbox_conf_perm
		int conv17_mbox_conf_perm_orders_value[4] = { 0, 2, 3, 1 };
		vector<int> conv17_mbox_conf_perm_orders(conv17_mbox_conf_perm_orders_value, conv17_mbox_conf_perm_orders_value + 4);
		vector<int> conv17_mbox_conf_perm_shape(4, 1);
		conv17_mbox_conf_perm_shape[1] = conv17_mbox_conf_output_channel;
		conv17_mbox_conf_perm_shape[2] = conv17_mbox_conf_output_height;
		conv17_mbox_conf_perm_shape[3] = conv17_mbox_conf_output_width;
		float *conv17_mbox_conf_perm_output = new float[conv17_mbox_conf_output_channel * conv17_mbox_conf_output_height * conv17_mbox_conf_output_width];
		//end init conv17_mbox_conf_perm



		//start init scales3_mbox_priorbox
		int scales3_mbox_prior_channel = 2;
		float scales3_mbox_prior_step_h = 8.0;
		float scales3_mbox_prior_step_w = 8.0;
		vector<float> scales3_mbox_prior_min_sizes_;
		scales3_mbox_prior_min_sizes_.push_back(30.0);
		vector<float> scales3_mbox_prior_max_sizes_;
		scales3_mbox_prior_max_sizes_.push_back(60.0);
		vector<float> scales3_mbox_prior_aspect_ratios_;
		scales3_mbox_prior_aspect_ratios_.push_back(2.0);
		int scales3_mbox_prior_flip_ = 1;
		int scales3_mbox_prior_clip_ = 0;
		vector<float> scales3_mbox_prior_variance_;
		scales3_mbox_prior_variance_.push_back(0.10000000149);
		scales3_mbox_prior_variance_.push_back(0.10000000149);
		scales3_mbox_prior_variance_.push_back(0.20000000298);
		scales3_mbox_prior_variance_.push_back(0.20000000298);
		float scales3_mbox_prior_offset_ = 0.5;
		int scales3_mbox_prior_num_priors_;
		if (scales3_mbox_prior_flip_)
		{
			scales3_mbox_prior_num_priors_ = (scales3_mbox_prior_min_sizes_.size() + scales3_mbox_prior_max_sizes_.size()) + (scales3_mbox_prior_aspect_ratios_.size() * 2);
		}
		else
		{
			scales3_mbox_prior_num_priors_ = (scales3_mbox_prior_min_sizes_.size() + scales3_mbox_prior_max_sizes_.size()) + scales3_mbox_prior_aspect_ratios_.size();
		}
		int scales3_mbox_prior_output_size = scales3_mbox_prior_channel * scales3_height * scales3_width * scales3_mbox_prior_num_priors_ * 4;
		float *scales3_mbox_prior_output = new float[scales3_mbox_prior_output_size];
		//end init scales3_mbox_priorbox

		//start init scales5_mbox_priorbox
		int scales5_mbox_prior_channel = 2;
		float scales5_mbox_prior_step_h = 16.0;
		float scales5_mbox_prior_step_w = 16.0;
		vector<float> scales5_mbox_prior_min_sizes_;
		scales5_mbox_prior_min_sizes_.push_back(60.0);
		vector<float> scales5_mbox_prior_max_sizes_;
		scales5_mbox_prior_max_sizes_.push_back(111.0);
		vector<float> scales5_mbox_prior_aspect_ratios_;
		scales5_mbox_prior_aspect_ratios_.push_back(2.0);
		scales5_mbox_prior_aspect_ratios_.push_back(3.0);
		int scales5_mbox_prior_flip_ = 1;
		int scales5_mbox_prior_clip_ = 0;
		vector<float> scales5_mbox_prior_variance_;
		scales5_mbox_prior_variance_.push_back(0.10000000149);
		scales5_mbox_prior_variance_.push_back(0.10000000149);
		scales5_mbox_prior_variance_.push_back(0.20000000298);
		scales5_mbox_prior_variance_.push_back(0.20000000298);
		float scales5_mbox_prior_offset_ = 0.5;
		int scales5_mbox_prior_num_priors_;
		if (scales5_mbox_prior_flip_)
		{
			scales5_mbox_prior_num_priors_ = (scales5_mbox_prior_min_sizes_.size() + scales5_mbox_prior_max_sizes_.size()) + (scales5_mbox_prior_aspect_ratios_.size() * 2);
		}
		else
		{
			scales5_mbox_prior_num_priors_ = (scales5_mbox_prior_min_sizes_.size() + scales5_mbox_prior_max_sizes_.size()) + scales5_mbox_prior_aspect_ratios_.size();
		}
		int scales5_mbox_prior_output_size = scales5_mbox_prior_channel * scales5_height * scales5_width * scales5_mbox_prior_num_priors_ * 4;
		float *scales5_mbox_prior_output = new float[scales5_mbox_prior_output_size];
		//end init scales5_mbox_priorbox

		//start init conv11_mbox_priorbox
		int conv11_mbox_prior_channel = 2;
		float conv11_mbox_prior_step_h = 32.0;
		float conv11_mbox_prior_step_w = 32.0;
		vector<float> conv11_mbox_prior_min_sizes_;
		conv11_mbox_prior_min_sizes_.push_back(111.0);
		vector<float> conv11_mbox_prior_max_sizes_;
		conv11_mbox_prior_max_sizes_.push_back(162.0);
		vector<float> conv11_mbox_prior_aspect_ratios_;
		conv11_mbox_prior_aspect_ratios_.push_back(2.0);
		conv11_mbox_prior_aspect_ratios_.push_back(3.0);
		int conv11_mbox_prior_flip_ = 1;
		int conv11_mbox_prior_clip_ = 0;
		vector<float> conv11_mbox_prior_variance_;
		conv11_mbox_prior_variance_.push_back(0.10000000149);
		conv11_mbox_prior_variance_.push_back(0.10000000149);
		conv11_mbox_prior_variance_.push_back(0.20000000298);
		conv11_mbox_prior_variance_.push_back(0.20000000298);
		float conv11_mbox_prior_offset_ = 0.5;
		int conv11_mbox_prior_num_priors_;
		if (conv11_mbox_prior_flip_)
		{
			conv11_mbox_prior_num_priors_ = (conv11_mbox_prior_min_sizes_.size() + conv11_mbox_prior_max_sizes_.size()) + (conv11_mbox_prior_aspect_ratios_.size() * 2);
		}
		else
		{
			conv11_mbox_prior_num_priors_ = (conv11_mbox_prior_min_sizes_.size() + conv11_mbox_prior_max_sizes_.size()) + conv11_mbox_prior_aspect_ratios_.size();
		}
		int conv11_mbox_prior_output_size = conv11_mbox_prior_channel * conv11_output_height * conv11_output_width * conv11_mbox_prior_num_priors_ * 4;
		float *conv11_mbox_prior_output = new float[conv11_mbox_prior_output_size];
		//end init conv11_mbox_priorbox

		//start init conv13_mbox_priorbox
		int conv13_mbox_prior_channel = 2;
		float conv13_mbox_prior_step_h = 64.0;
		float conv13_mbox_prior_step_w = 64.0;
		vector<float> conv13_mbox_prior_min_sizes_;
		conv13_mbox_prior_min_sizes_.push_back(162.0);
		vector<float> conv13_mbox_prior_max_sizes_;
		conv13_mbox_prior_max_sizes_.push_back(213.0);
		vector<float> conv13_mbox_prior_aspect_ratios_;
		conv13_mbox_prior_aspect_ratios_.push_back(2.0);
		conv13_mbox_prior_aspect_ratios_.push_back(3.0);
		int conv13_mbox_prior_flip_ = 1;
		int conv13_mbox_prior_clip_ = 0;
		vector<float> conv13_mbox_prior_variance_;
		conv13_mbox_prior_variance_.push_back(0.10000000149);
		conv13_mbox_prior_variance_.push_back(0.10000000149);
		conv13_mbox_prior_variance_.push_back(0.20000000298);
		conv13_mbox_prior_variance_.push_back(0.20000000298);
		float conv13_mbox_prior_offset_ = 0.5;
		int conv13_mbox_prior_num_priors_;
		if (conv13_mbox_prior_flip_)
		{
			conv13_mbox_prior_num_priors_ = (conv13_mbox_prior_min_sizes_.size() + conv13_mbox_prior_max_sizes_.size()) + (conv13_mbox_prior_aspect_ratios_.size() * 2);
		}
		else
		{
			conv13_mbox_prior_num_priors_ = (conv13_mbox_prior_min_sizes_.size() + conv13_mbox_prior_max_sizes_.size()) + conv13_mbox_prior_aspect_ratios_.size();
		}
		int conv13_mbox_prior_output_size = conv13_mbox_prior_channel * conv13_output_height * conv13_output_width * conv13_mbox_prior_num_priors_ * 4;
		float *conv13_mbox_prior_output = new float[conv13_mbox_prior_output_size];
		//end init conv13_mbox_priorbox

		//start init conv15_mbox_priorbox
		int conv15_mbox_prior_channel = 2;
		float conv15_mbox_prior_step_h = 100.0;
		float conv15_mbox_prior_step_w = 100.0;
		vector<float> conv15_mbox_prior_min_sizes_;
		conv15_mbox_prior_min_sizes_.push_back(213.0);
		vector<float> conv15_mbox_prior_max_sizes_;
		conv15_mbox_prior_max_sizes_.push_back(264.0);
		vector<float> conv15_mbox_prior_aspect_ratios_;
		conv15_mbox_prior_aspect_ratios_.push_back(2.0);
		int conv15_mbox_prior_flip_ = 1;
		int conv15_mbox_prior_clip_ = 0;
		vector<float> conv15_mbox_prior_variance_;
		conv15_mbox_prior_variance_.push_back(0.10000000149);
		conv15_mbox_prior_variance_.push_back(0.10000000149);
		conv15_mbox_prior_variance_.push_back(0.20000000298);
		conv15_mbox_prior_variance_.push_back(0.20000000298);
		float conv15_mbox_prior_offset_ = 0.5;
		int conv15_mbox_prior_num_priors_;
		if (conv15_mbox_prior_flip_)
		{
			conv15_mbox_prior_num_priors_ = (conv15_mbox_prior_min_sizes_.size() + conv15_mbox_prior_max_sizes_.size()) + (conv15_mbox_prior_aspect_ratios_.size() * 2);
		}
		else
		{
			conv15_mbox_prior_num_priors_ = (conv15_mbox_prior_min_sizes_.size() + conv15_mbox_prior_max_sizes_.size()) + conv15_mbox_prior_aspect_ratios_.size();
		}
		int conv15_mbox_prior_output_size = conv15_mbox_prior_channel * conv15_output_height * conv15_output_width * conv15_mbox_prior_num_priors_ * 4;
		float *conv15_mbox_prior_output = new float[conv15_mbox_prior_output_size];
		//end init conv15_mbox_priorbox

		//start init conv17_mbox_priorbox
		int conv17_mbox_prior_channel = 2;
		float conv17_mbox_prior_step_h = 300.0;
		float conv17_mbox_prior_step_w = 300.0;
		vector<float> conv17_mbox_prior_min_sizes_;
		conv17_mbox_prior_min_sizes_.push_back(264.0);
		vector<float> conv17_mbox_prior_max_sizes_;
		conv17_mbox_prior_max_sizes_.push_back(315.0);
		vector<float> conv17_mbox_prior_aspect_ratios_;
		conv17_mbox_prior_aspect_ratios_.push_back(2.0);
		int conv17_mbox_prior_flip_ = 1;
		int conv17_mbox_prior_clip_ = 0;
		vector<float> conv17_mbox_prior_variance_;
		conv17_mbox_prior_variance_.push_back(0.10000000149);
		conv17_mbox_prior_variance_.push_back(0.10000000149);
		conv17_mbox_prior_variance_.push_back(0.20000000298);
		conv17_mbox_prior_variance_.push_back(0.20000000298);
		float conv17_mbox_prior_offset_ = 0.5;
		int conv17_mbox_prior_num_priors_;
		if (conv17_mbox_prior_flip_)
		{
			conv17_mbox_prior_num_priors_ = (conv17_mbox_prior_min_sizes_.size() + conv17_mbox_prior_max_sizes_.size()) + (conv17_mbox_prior_aspect_ratios_.size() * 2);
		}
		else
		{
			conv17_mbox_prior_num_priors_ = (conv17_mbox_prior_min_sizes_.size() + conv17_mbox_prior_max_sizes_.size()) + conv17_mbox_prior_aspect_ratios_.size();
		}
		int conv17_mbox_prior_output_size = conv17_mbox_prior_channel * conv17_output_height * conv17_output_width * conv17_mbox_prior_num_priors_ * 4;
		float *conv17_mbox_prior_output = new float[conv17_mbox_prior_output_size];
		//end init conv17_mbox_priorbox



		//start init mbox_priorbox
		vector<concatDataParam> DataParams;
		concatDataParam DataParam;
		int output_size = 0;
		int mbox_priorbox_shape_value[3] = { 1, 2, 38 * 38 * 4 * 4 };
		output_size += 2 * 38 * 38 * 4 * 4;
		vector<int> shape(mbox_priorbox_shape_value, mbox_priorbox_shape_value + 3);
		DataParam = { scales3_mbox_prior_output, shape };
		DataParams.push_back(DataParam);
		shape[2] = 19 * 19 * 6 * 4;
		output_size += 2 * 19 * 19 * 6 * 4;
		DataParam = { scales5_mbox_prior_output, shape };
		DataParams.push_back(DataParam);
		shape[2] = 10 * 10 * 6 * 4;
		output_size += 2 * 10 * 10 * 6 * 4;
		DataParam = { conv11_mbox_prior_output, shape };
		DataParams.push_back(DataParam);
		shape[2] = 5 * 5 * 6 * 4;
		output_size += 2 * 5 * 5 * 6 * 4;
		DataParam = { conv13_mbox_prior_output, shape };
		DataParams.push_back(DataParam);
		shape[2] = 5 * 5 * 4 * 4;
		output_size += 2 * 5 * 5 * 4 * 4;
		DataParam = { conv15_mbox_prior_output, shape };
		DataParams.push_back(DataParam);
		shape[2] = 5 * 5 * 4 * 4;
		output_size += 2 * 5 * 5 * 4 * 4;
		DataParam = { conv17_mbox_prior_output, shape };
		DataParams.push_back(DataParam);

		shape[2] = output_size / 2;
		float *mbox_priorbox_output_Data = new float[output_size];
		int mbox_priorbox_axis = 2;
		//end init mbox_priorbox


		//start init mbox_conf
		vector<concatDataParam> DataParams_conf;
		concatDataParam DataParam_conf;
		int output_size_conf = 0;
		output_size_conf += 38 * 38 * 4 * 2;
		vector<int> shape_conf{ 1, 38 * 38 * 4 * 2 };
		DataParam_conf = { scales3_mbox_conf_perm_output, shape_conf };
		DataParams_conf.push_back(DataParam_conf);
		shape_conf[1] = 19 * 19 * 6 * 2;
		output_size_conf += 19 * 19 * 6 * 2;
		DataParam_conf = { scales5_mbox_conf_perm_output, shape_conf };
		DataParams_conf.push_back(DataParam_conf);
		shape_conf[1] = 10 * 10 * 6 * 2;
		output_size_conf += 10 * 10 * 6 * 2;
		DataParam_conf = { conv11_mbox_conf_perm_output, shape_conf };
		DataParams_conf.push_back(DataParam_conf);
		shape_conf[1] = 5 * 5 * 6 * 2;
		output_size_conf += 5 * 5 * 6 * 2;
		DataParam_conf = { conv13_mbox_conf_perm_output, shape_conf };
		DataParams_conf.push_back(DataParam_conf);
		shape_conf[1] = 5 * 5 * 4 * 2;
		output_size_conf +=  5 * 5 * 4 * 2;
		DataParam = { conv15_mbox_conf_perm_output, shape_conf };
		DataParams_conf.push_back(DataParam);
		shape_conf[1] = 5 * 5 * 4 * 2;
		output_size_conf +=  5 * 5 * 4 * 2;
		DataParam = { conv17_mbox_conf_perm_output, shape_conf };
		DataParams_conf.push_back(DataParam);
		shape_conf[1] = output_size_conf;
		float *mbox_conf_output_Data = new float[output_size_conf];
		int mbox_conf_axis = 1;
		//end init mbox_conf



		//start init mbox_loc
		vector<concatDataParam> DataParams_loc;
		concatDataParam DataParam_loc;
		int output_size_loc = 0;
		output_size_loc += 38 * 38 * 4 * 4;
		vector<int> shape_loc{ 1, 38 * 38 * 4 * 4 };
		DataParam_loc = { scales3_mbox_loc_perm_output, shape_loc };
		DataParams_loc.push_back(DataParam_loc);
		shape_loc[1] = 19 * 19 * 6 * 4;
		output_size_loc += 19 * 19 * 6 * 4;
		DataParam_loc = { scales5_mbox_loc_perm_output, shape_loc };
		DataParams_loc.push_back(DataParam_loc);
		shape_loc[1] = 10 * 10 * 6 * 4;
		output_size_loc += 10 * 10 * 6 * 4;
		DataParam_loc = { conv11_mbox_loc_perm_output, shape_loc };
		DataParams_loc.push_back(DataParam_loc);
		shape_loc[1] = 5 * 5 * 6 * 4;
		output_size_loc += 5 * 5 * 6 * 4;
		DataParam_loc = { conv13_mbox_loc_perm_output, shape_loc };
		DataParams_loc.push_back(DataParam_loc);
		shape_loc[1] = 5 * 5 * 4 * 4;
		output_size_loc += 5 * 5 * 4 * 4;
		DataParam = { conv15_mbox_loc_perm_output, shape_loc };
		DataParams_loc.push_back(DataParam);
		shape_loc[1] = 5 * 5 * 4 * 4;
		output_size_loc += 5 * 5 * 4 * 4;
		DataParam = { conv17_mbox_loc_perm_output, shape_loc };
		DataParams_loc.push_back(DataParam);
		shape_loc[1] = output_size_loc;
		float *mbox_loc_output_Data = new float[output_size_loc];
		int mbox_loc_axis = 1;
		//end init mbox_loc

///////////////////////////////////////////////////////////

		//start run bn1
		BNParam bn1_input = { img_data ,bn1_output,bn1_mean,bn1_variance,bn1_scale,bn1_channel,bn1_height,bn1_width };
		batchnorm1(&bn1_input);
		//end run bn1

		//start run scales1
		ScaleParam scales1_input = { bn1_output ,scales1_output,scales1_gamma,scales1_beta,scales1_channel,scales1_width,scales1_height };
		scales1(&scales1_input,scales1_Relu);

		//start run conv1
		im2row(scales1_output, scales1_channel, scales1_height, scales1_width, conv1_kernel_height, conv1_kernel_width, conv1_pad_height, conv1_pad_width, conv1_stride_width, conv1_stride_height, conv1_dilation_width, conv1_dilation_height, scales1_output_col);
		convParam conv1_param = { scales1_output_col,conv1_coef_t,conv1_bias,conv1_output,scales1_channel,scales1_height,scales1_width,conv1_kernel_height,conv1_kernel_width,conv1_output_channel,conv1_output_height,conv1_output_width };
		convLayer(&conv1_param, conv1_withRELU);

		float *conv1_output2 = new float[conv1_output_channel*conv1_output_height*conv1_output_width];
		Row_column_transpose(conv1_output, conv1_output2, conv1_output_height*conv1_output_width, conv1_output_channel);
		//end run conv1


		//start run pool
		maxpoolParam pool_data{ conv1_output ,pool_output,conv1_output_channel,conv1_output_height,conv1_output_width, pool_pad ,pool_kernel_height,pool_kernel_width ,pool_stride ,pool_output_channel ,pool_output_height ,pool_output_width };
		maxpool(&pool_data);

		//start run conv2
		im2rowBycol(pool_output, pool_output_channel, pool_output_height, pool_output_width, conv2_kernel_height, conv2_kernel_width, conv2_pad_height, conv2_pad_width, conv2_stride_width, conv2_stride_height, conv2_dilation_width, conv2_dilation_height, pool_output_col);
		convParam conv2_param = { pool_output_col,conv2_new_coef,conv2_bias,conv2_output,pool_output_channel,pool_output_height,pool_output_width,conv2_kernel_height,conv2_kernel_width,conv2_output_channel,conv2_output_height,conv2_output_width };
		convLayer(&conv2_param, conv2_withRELU);

		float *conv2_output2 = new float[conv1_output_channel*conv1_output_height*conv1_output_width];
		Row_column_transpose(conv2_output, conv2_output2, conv2_output_height*conv2_output_width, conv2_output_channel);
		//end run conv2

		//start run conv3
		im2rowBycol(conv2_output, conv2_output_channel, conv2_output_height, conv2_output_width, conv3_kernel_height, conv3_kernel_width, conv3_pad_height, conv3_pad_width, conv3_stride_width, conv3_stride_height, conv3_dilation_width, conv3_dilation_height, conv2_output_col);
		convParam conv3_param = { conv2_output_col,conv3_new_coef,conv3_bias,conv3_output,conv2_output_channel,conv2_output_height,conv2_output_width,conv3_kernel_height,conv3_kernel_width,conv3_output_channel,conv3_output_height,conv3_output_width };
		convLayer(&conv3_param, conv3_withRELU);

		float *conv3_output2 = new float[conv3_output_channel*conv3_output_height*conv3_output_width];
		Row_column_transpose(conv3_output, conv3_output2, conv3_output_height*conv3_output_width, conv3_output_channel);
		//end run conv3

		//start run eltwise1
		EltwiseParam eltwise1_data{ eltwise1_input,eltwise1_output,eltwise1_shape };
		Eltwise(&eltwise1_data);
		//end run eltwise1


		float *eltwise1_output2 = new float[eltwise1_channel*eltwise1_output_height*eltwise1_output_width];
		Row_column_transpose(eltwise1_output, eltwise1_output2, eltwise1_output_height*eltwise1_output_width, eltwise1_channel);


		//start run bn2
		BNParam bn2_input = { eltwise1_output ,bn2_output,bn2_mean,bn2_variance,bn2_scale,bn2_channel,bn2_height,bn2_width };
		batchnorm(&bn2_input);
		//end run bn2

		//start run scales2
		ScaleParam scales2_input = { bn2_output ,scales2_output,scales2_gamma,scales2_beta,scales2_channel,scales2_width,scales2_height };
		scales(&scales2_input, scales2_Relu);




		//run conv4_expand
		im2rowBycol(scales2_output, scales2_channel, scales2_height, scales2_width, conv4_expand_kernel_height, conv4_expand_kernel_width, conv4_expand_pad_height, conv4_expand_pad_width, conv4_expand_stride_width, conv4_expand_stride_height, conv4_expand_dilation_width, conv4_expand_dilation_height, scales2_output_col);
		convParam conv4_expand_param = { scales2_output_col,conv4_expand_new_coef,conv4_expand_bias,conv4_expand_output,scales2_channel,scales2_height,scales2_width,conv4_expand_kernel_height,conv4_expand_kernel_width,conv4_expand_output_channel,conv4_expand_output_height,conv4_expand_output_width };
		convLayer(&conv4_expand_param, conv4_expand_withRELU);

		float *conv4_expand_output2 = new float[conv4_expand_output_channel*conv4_expand_output_height*conv4_expand_output_width];
		Row_column_transpose(conv4_expand_output, conv4_expand_output2, conv4_expand_output_height*conv4_expand_output_width, conv4_expand_output_channel);
		//end run conv4_expand 


		//run conv4
		im2rowBycol(scales2_output, scales2_channel, scales2_height, scales2_width, conv4_kernel_height, conv4_kernel_width, conv4_pad_height, conv4_pad_width, conv4_stride_width, conv4_stride_height, conv4_dilation_width, conv4_dilation_height, scales2_output_col);
		convParam conv4_param = { scales2_output_col,conv4_new_coef,conv4_bias,conv4_output,scales2_channel,scales2_height,scales2_width,conv4_kernel_height,conv4_kernel_width,conv4_output_channel,conv4_output_height,conv4_output_width };
		convLayer(&conv4_param, conv4_withRELU);

		float *conv4_output2 = new float[conv4_output_channel*conv4_output_height*conv4_output_width];
		Row_column_transpose(conv4_output, conv4_output2, conv4_output_height*conv4_output_width, conv4_output_channel);
		//end run conv4


		//start run conv5
		im2rowBycol(conv4_output, conv4_output_channel, conv4_output_height, conv4_output_width, conv5_kernel_height, conv5_kernel_width, conv5_pad_height, conv5_pad_width, conv5_stride_width, conv5_stride_height, conv5_dilation_width, conv5_dilation_height, conv4_output_col);
		convParam conv5_param = { conv4_output_col,conv5_new_coef,conv5_bias,conv5_output,conv4_output_channel,conv4_output_height,conv4_output_width,conv5_kernel_height,conv5_kernel_width,conv5_output_channel,conv5_output_height,conv5_output_width };
		convLayer(&conv5_param, conv5_withRELU);

		float *conv5_output2 = new float[conv5_output_channel*conv5_output_height*conv5_output_width];
		Row_column_transpose(conv5_output, conv5_output2, conv5_output_height*conv5_output_width, conv5_output_channel);
		//end run conv5

			
		//start run eltwise2
		vector<float*>eltwise2_input{ conv4_expand_output,conv5_output };
		EltwiseParam eltwise2_data{ eltwise2_input,eltwise2_output,eltwise2_shape };
		Eltwise(&eltwise2_data);

		float *eltwise2_output2 = new float[eltwise2_channel*eltwise2_output_height*eltwise2_output_width];
		Row_column_transpose(eltwise2_output, eltwise2_output2, eltwise2_output_height*eltwise2_output_width, eltwise2_channel);

		//start run  bn3
		BNParam bn3_input = { eltwise2_output ,bn3_output,bn3_mean,bn3_variance,bn3_scale,bn3_channel,bn3_height,bn3_width };
		batchnorm(&bn3_input);

		//start run scales3
		ScaleParam scales3_input = { bn3_output ,scales3_output,scales3_gamma,scales3_beta,scales3_channel,scales3_width,scales3_height };
		scales(&scales3_input, scales3_Relu);



		//start run conv6_expand
		//gettimeofday(&startfc, NULL);
		im2rowBycol(scales3_output, scales3_channel, scales3_height, scales3_width, conv6_expand_kernel_height, conv6_expand_kernel_width,
			conv6_expand_pad_height, conv6_expand_pad_width, conv6_expand_stride_height, conv6_expand_stride_width, conv6_expand_dilation_height, conv6_expand_dilation_width, scales3_output_col);
		convParam conv6_expand_param = { scales3_output_col, conv6_expand_new_coef, conv6_expand_bias, conv6_expand_output, scales3_channel, scales3_height, scales3_width,
			conv6_expand_kernel_height, conv6_expand_kernel_width, conv6_expand_output_channel, conv6_expand_output_height, conv6_expand_output_width };
		convLayer(&conv6_expand_param, conv6_expand_withRELU);
		//gettimeofday(&endfc, NULL);
		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
		//cout << "conv6_expand conv: " << endfctt - startfctt << "ms" << endl;  
		//end run conv6_expand
		float *conv6_expand_output2 = new float[conv6_expand_output_channel * conv6_expand_output_height * conv6_expand_output_width];
		Row_column_transpose(conv6_expand_output, conv6_expand_output2, conv6_expand_output_height * conv6_expand_output_width, conv6_expand_output_channel);
		//float *conv6_expand_output1 = new float[conv6_expand_output_channel * conv6_expand_output_height * conv6_expand_output_width];
		//readFile("data/conv6_expand_output", conv6_expand_output1, conv6_expand_output_height * conv6_expand_output_width * conv6_expand_output_channel * sizeof(float));



		//start run conv6
		//gettimeofday(&startfc, NULL);
		im2rowBycol(scales3_output, scales3_channel, scales3_height, scales3_width, conv6_kernel_height, conv6_kernel_width,
			conv6_pad_height, conv6_pad_width, conv6_stride_height, conv6_stride_width, conv6_dilation_height, conv6_dilation_width, scales3_output_col);
		convParam conv6_param = { scales3_output_col, conv6_new_coef, conv6_bias, conv6_output, scales3_channel, scales3_height, scales3_width,
			conv6_kernel_height, conv6_kernel_width, conv6_output_channel, conv6_output_height, conv6_output_width };
		convLayer(&conv6_param, conv6_withRelu);
		//gettimeofday(&endfc, NULL);
		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
		//cout << "conv6 conv: " << endfctt - startfctt << "ms" << endl;  
		//end run conv6
		float *conv6_output2 = new float[conv6_output_channel * conv6_output_height * conv6_output_width];
		Row_column_transpose(conv6_output, conv6_output2, conv6_output_height * conv6_output_width, conv6_output_channel);
		//float *conv6_output1 = new float[conv6_output_channel * conv6_output_height * conv6_output_width];
		//readFile("data/conv6_output", conv6_output1, conv6_output_height * conv6_output_width * conv6_output_channel * sizeof(float));


		//start run conv7
		//gettimeofday(&startfc, NULL);
		im2rowBycol(conv6_output, conv6_output_channel, conv6_output_height, conv6_output_width, conv7_kernel_height, conv7_kernel_width,
			conv7_pad_height, conv7_pad_width, conv7_stride_height, conv7_stride_width, conv7_dilation_height, conv7_dilation_width, conv6_output_col);
		convParam conv7_param = { conv6_output_col, conv7_new_coef, conv7_bias, conv7_output, conv6_output_channel, conv6_output_height, conv6_output_width,
			conv7_kernel_height, conv7_kernel_width, conv7_output_channel, conv7_output_height, conv7_output_width };
		convLayer(&conv7_param, conv7_withRelu);
		//gettimeofday(&endfc, NULL);
		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
		//cout << "conv7 conv: " << endfctt - startfctt << "ms" << endl;  
		//end run conv7
		float *conv7_output2 = new float[conv7_output_channel * conv7_output_height * conv7_output_width];
		Row_column_transpose(conv7_output, conv7_output2, conv7_output_height * conv7_output_width, conv7_output_channel);
		//float *conv7_output1 = new float[conv7_output_channel * conv7_output_height * conv7_output_width];
		//readFile("data/conv7_output", conv7_output1, conv7_output_height * conv7_output_width * conv7_output_channel * sizeof(float));


		//start run eltwise3
		EltwiseParam eltwise3_data{ eltwise3_input,eltwise3_output,eltwise3_shape };
		Eltwise(&eltwise3_data);

		float *eltwise3_output2 = new float[eltwise3_channel*eltwise3_height*eltwise3_width];
		Row_column_transpose(eltwise3_output, eltwise3_output2, eltwise3_height*eltwise3_width, eltwise3_channel);



		//start run  bn4
		BNParam bn4_input = { eltwise3_output ,bn4_output,bn4_mean,bn4_variance,bn4_scale,bn4_channel,bn4_height,bn4_width };
		batchnorm(&bn4_input);

		//start run scales4
		ScaleParam scales4_input = { bn4_output ,scales4_output,scales4_gamma,scales4_beta,scales4_channel,scales4_width,scales4_height };
		scales(&scales4_input, scales4_Relu);







		//start run conv8_expand
		//gettimeofday(&startfc, NULL);
		im2rowBycol(scales4_output, scales4_channel, scales4_height, scales4_width, conv8_expand_kernel_height, conv8_expand_kernel_width,
			conv8_expand_pad_height, conv8_expand_pad_width, conv8_expand_stride_height, conv8_expand_stride_width, conv8_expand_dilation_height, conv8_expand_dilation_width, scales4_output_col);
		convParam conv8_expand_param = { scales4_output_col, conv8_expand_new_coef, conv8_expand_bias, conv8_expand_output, scales4_channel, scales4_height, scales4_width,
			conv8_expand_kernel_height, conv8_expand_kernel_width, conv8_expand_output_channel, conv8_expand_output_height, conv8_expand_output_width };
		convLayer(&conv8_expand_param, conv8_expand_withRELU);
		//gettimeofday(&endfc, NULL);
		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
		//cout << "conv8_expand conv: " << endfctt - startfctt << "ms" << endl;  
		//end run conv8_expand
		float *conv8_expand_output2 = new float[conv8_expand_output_channel * conv8_expand_output_height * conv8_expand_output_width];
		Row_column_transpose(conv8_expand_output, conv8_expand_output2, conv8_expand_output_height * conv8_expand_output_width, conv8_expand_output_channel);
		//float *conv8_expand_output1 = new float[conv8_expand_output_channel * conv8_expand_output_height * conv8_expand_output_width];
		//readFile("data/conv8_expand_output", conv8_expand_output1, conv8_expand_output_height * conv8_expand_output_width * conv8_expand_output_channel * sizeof(float));



		//start run conv8
		//gettimeofday(&startfc, NULL);
		im2rowBycol(scales4_output, scales4_channel, scales4_height, scales4_width, conv8_kernel_height, conv8_kernel_width,
			conv8_pad_height, conv8_pad_width, conv8_stride_height, conv8_stride_width, conv8_dilation_height, conv8_dilation_width, scales4_output_col);
		convParam conv8_param = { scales4_output_col, conv8_new_coef, conv8_bias, conv8_output, scales4_channel, scales4_height, scales4_width,
			conv8_kernel_height, conv8_kernel_width, conv8_output_channel, conv8_output_height, conv8_output_width };
		convLayer(&conv8_param, conv8_withRELU);
		//gettimeofday(&endfc, NULL);
		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
		//cout << "conv8 conv: " << endfctt - startfctt << "ms" << endl;  
		//end run conv8
		float *conv8_output2 = new float[conv8_output_channel * conv8_output_height * conv8_output_width];
		Row_column_transpose(conv8_output, conv8_output2, conv8_output_height * conv8_output_width, conv8_output_channel);
		//float *conv8_output1 = new float[conv8_output_channel * conv8_output_height * conv8_output_width];
		//readFile("data/conv8_output", conv8_output1, conv8_output_height * conv8_output_width * conv8_output_channel * sizeof(float));


		//start run conv9
		//gettimeofday(&startfc, NULL);
		im2rowBycol(conv8_output, conv8_output_channel, conv8_output_height, conv8_output_width, conv9_kernel_height, conv9_kernel_width,
			conv9_pad_height, conv9_pad_width, conv9_stride_height, conv9_stride_width, conv9_dilation_height, conv9_dilation_width, conv8_output_col);
		convParam conv9_param = { conv8_output_col, conv9_new_coef, conv9_bias, conv9_output, conv8_output_channel, conv8_output_height, conv8_output_width,
			conv9_kernel_height, conv9_kernel_width, conv9_output_channel, conv9_output_height, conv9_output_width };
		convLayer(&conv9_param, conv9_withRELU);
		//gettimeofday(&endfc, NULL);
		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
		//cout << "conv9 conv: " << endfctt - startfctt << "ms" << endl;  
		//end run conv9
		float *conv9_output2 = new float[conv9_output_channel * conv9_output_height * conv9_output_width];
		Row_column_transpose(conv9_output, conv9_output2, conv9_output_height * conv9_output_width, conv9_output_channel);
		//float *conv9_output1 = new float[conv9_output_channel * conv9_output_height * conv9_output_width];
		//readFile("data/conv9_output", conv9_output1, conv9_output_height * conv9_output_width * conv9_output_channel * sizeof(float));


		//start run eltwise4
		vector<float*>eltwise4_input{ conv9_output,conv8_expand_output };
		EltwiseParam eltwise4_data{ eltwise4_input,eltwise4_output,eltwise4_shape };
		Eltwise( &eltwise4_data);

		float *eltwise4_output2 = new float[eltwise4_channel*eltwise4_height*eltwise4_width];
		Row_column_transpose(eltwise4_output, eltwise4_output2, eltwise4_height*eltwise4_width, eltwise4_channel);


		//start run  bn5
		BNParam bn5_input = { eltwise4_output ,bn5_output,bn5_mean,bn5_variance,bn5_scale,bn5_channel,bn5_height,bn5_width };
		batchnorm(&bn5_input);

		//start run scales5
		ScaleParam scales5_input = { bn5_output ,scales5_output,scales5_gamma,scales5_beta,scales5_channel,scales5_width,scales5_height };
		scales(&scales5_input, scales5_Relu);

		//start run conv10
		//gettimeofday(&startfc, NULL);
		im2rowBycol(scales5_output, scales5_channel, scales5_height, scales5_width, conv10_kernel_height, conv10_kernel_width,
			conv10_pad_height, conv10_pad_width, conv10_stride_height, conv10_stride_width, conv10_dilation_height, conv10_dilation_width, scales5_output_col);
		convParam conv10_param = { scales5_output_col, conv10_new_coef, conv10_bias, conv10_output, scales5_channel, scales5_height, scales5_width,
			conv10_kernel_height, conv10_kernel_width, conv10_output_channel, conv10_output_height, conv10_output_width };
		convLayer(&conv10_param, conv10_withRELU);
		//gettimeofday(&endfc, NULL);
		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
		//cout << "conv10 conv: " << endfctt - startfctt << "ms" << endl;  
		//end run conv10
		float *conv10_output2 = new float[conv10_output_channel * conv10_output_height * conv10_output_width];
		Row_column_transpose(conv10_output, conv10_output2, conv10_output_height * conv10_output_width, conv10_output_channel);
		//float *conv10_output1 = new float[conv10_output_channel * conv10_output_height * conv10_output_width];
		//readFile("data/conv10_output", conv10_output1, conv10_output_height * conv10_output_width * conv10_output_channel * sizeof(float));

		//start run conv11
		//gettimeofday(&startfc, NULL);
		im2rowBycol(conv10_output, conv10_output_channel, conv10_output_height, conv10_output_width, conv11_kernel_height, conv11_kernel_width,
			conv11_pad_height, conv11_pad_width, conv11_stride_height, conv11_stride_width, conv11_dilation_height, conv11_dilation_width, conv10_output_col);
		convParam conv11_param = { conv10_output_col, conv11_new_coef, conv11_bias, conv11_output, conv10_output_channel, conv10_output_height, conv10_output_width,
			conv11_kernel_height, conv11_kernel_width, conv11_output_channel, conv11_output_height, conv11_output_width };
		convLayer(&conv11_param, conv11_withRELU);
		//gettimeofday(&endfc, NULL);
		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
		//cout << "conv11 conv: " << endfctt - startfctt << "ms" << endl;  
		//end run conv11
		float *conv11_output2 = new float[conv11_output_channel * conv11_output_height * conv11_output_width];
		Row_column_transpose(conv11_output, conv11_output2, conv11_output_height * conv11_output_width, conv11_output_channel);
		//float *conv11_output1 = new float[conv11_output_channel * conv11_output_height * conv11_output_width];
		//readFile("data/conv11_output", conv11_output1, conv11_output_height * conv11_output_width * conv11_output_channel * sizeof(float));

		//start run conv12
		//gettimeofday(&startfc, NULL);
		im2rowBycol(conv11_output, conv11_output_channel, conv11_output_height, conv11_output_width, conv12_kernel_height, conv12_kernel_width,
			conv12_pad_height, conv12_pad_width, conv12_stride_height, conv12_stride_width, conv12_dilation_height, conv12_dilation_width, conv11_output_col);
		convParam conv12_param = { conv11_output_col, conv12_new_coef, conv12_bias, conv12_output, conv11_output_channel, conv11_output_height, conv11_output_width,
			conv12_kernel_height, conv12_kernel_width, conv12_output_channel, conv12_output_height, conv12_output_width };
		convLayer(&conv12_param, conv12_withRELU);
		//gettimeofday(&endfc, NULL);
		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
		//cout << "conv12 conv: " << endfctt - startfctt << "ms" << endl;  
		//end run conv12
		float *conv12_output2 = new float[conv12_output_channel * conv12_output_height * conv12_output_width];
		Row_column_transpose(conv12_output, conv12_output2, conv12_output_height * conv12_output_width, conv12_output_channel);
		//float *conv12_output1 = new float[conv12_output_channel * conv12_output_height * conv12_output_width];
		//readFile("data/conv12_output", conv12_output1, conv12_output_height * conv12_output_width * conv12_output_channel * sizeof(float));

		//start run conv13
		//gettimeofday(&startfc, NULL);
		im2rowBycol(conv12_output, conv12_output_channel, conv12_output_height, conv12_output_width, conv13_kernel_height, conv13_kernel_width,
			conv13_pad_height, conv13_pad_width, conv13_stride_height, conv13_stride_width, conv13_dilation_height, conv13_dilation_width, conv12_output_col);
		convParam conv13_param = { conv12_output_col, conv13_new_coef, conv13_bias, conv13_output, conv12_output_channel, conv12_output_height, conv12_output_width,
			conv13_kernel_height, conv13_kernel_width, conv13_output_channel, conv13_output_height, conv13_output_width };
		convLayer(&conv13_param, conv13_withRELU);
		//gettimeofday(&endfc, NULL);
		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
		//cout << "conv13 conv: " << endfctt - startfctt << "ms" << endl;  
		//end run conv13
		float *conv13_output2 = new float[conv13_output_channel * conv13_output_height * conv13_output_width];
		Row_column_transpose(conv13_output, conv13_output2, conv13_output_height * conv13_output_width, conv13_output_channel);
		//float *conv13_output1 = new float[conv13_output_channel * conv13_output_height * conv13_output_width];
		//readFile("data/conv13_output", conv13_output1, conv13_output_height * conv13_output_width * conv13_output_channel * sizeof(float));

		//start run conv14
		//gettimeofday(&startfc, NULL);
		im2rowBycol(conv13_output, conv13_output_channel, conv13_output_height, conv13_output_width, conv14_kernel_height, conv14_kernel_width,
			conv14_pad_height, conv14_pad_width, conv14_stride_height, conv14_stride_width, conv14_dilation_height, conv14_dilation_width, conv13_output_col);
		convParam conv14_param = { conv13_output_col, conv14_new_coef, conv14_bias, conv14_output, conv13_output_channel, conv13_output_height, conv13_output_width,
			conv14_kernel_height, conv14_kernel_width, conv14_output_channel, conv14_output_height, conv14_output_width };
		convLayer(&conv14_param, conv14_withRELU);
		//gettimeofday(&endfc, NULL);
		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
		//cout << "conv14 conv: " << endfctt - startfctt << "ms" << endl;  
		//end run conv14
		float *conv14_output2 = new float[conv14_output_channel * conv14_output_height * conv14_output_width];
		Row_column_transpose(conv14_output, conv14_output2, conv14_output_height * conv14_output_width, conv14_output_channel);
		//float *conv14_output1 = new float[conv14_output_channel * conv14_output_height * conv14_output_width];
		//readFile("data/conv14_output", conv14_output1, conv14_output_height * conv14_output_width * conv14_output_channel * sizeof(float));


		//start run conv15
		//gettimeofday(&startfc, NULL);
		im2rowBycol(conv14_output, conv14_output_channel, conv14_output_height, conv14_output_width, conv15_kernel_height, conv15_kernel_width,
			conv15_pad_height, conv15_pad_width, conv15_stride_height, conv15_stride_width, conv15_dilation_height, conv15_dilation_width, conv14_output_col);
		convParam conv15_param = { conv14_output_col, conv15_new_coef, conv15_bias, conv15_output, conv14_output_channel, conv14_output_height, conv14_output_width,
			conv15_kernel_height, conv15_kernel_width, conv15_output_channel, conv15_output_height, conv15_output_width };
		convLayer(&conv15_param, conv15_withRELU);
		//gettimeofday(&endfc, NULL);
		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
		//cout << "conv15 conv: " << endfctt - startfctt << "ms" << endl;  
		//end run conv15
		float *conv15_output2 = new float[conv15_output_channel * conv15_output_height * conv15_output_width];
		Row_column_transpose(conv15_output, conv15_output2, conv15_output_height * conv15_output_width, conv15_output_channel);
		//float *conv15_output1 = new float[conv15_output_channel * conv15_output_height * conv15_output_width];
		//readFile("data/conv15_output", conv15_output1, conv15_output_height * conv15_output_width * conv15_output_channel * sizeof(float));

		//start run conv16
		//gettimeofday(&startfc, NULL);
		im2rowBycol(conv15_output, conv15_output_channel, conv15_output_height, conv15_output_width, conv16_kernel_height, conv16_kernel_width,
			conv16_pad_height, conv16_pad_width, conv16_stride_height, conv16_stride_width, conv16_dilation_height, conv16_dilation_width, conv15_output_col);
		convParam conv16_param = { conv15_output_col, conv16_new_coef, conv16_bias, conv16_output, conv15_output_channel, conv15_output_height, conv15_output_width,
			conv16_kernel_height, conv16_kernel_width, conv16_output_channel, conv16_output_height, conv16_output_width };
		convLayer(&conv16_param, conv16_withRELU);
		//gettimeofday(&endfc, NULL);
		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
		//cout << "conv16 conv: " << endfctt - startfctt << "ms" << endl;  
		//end run conv16
		float *conv16_output2 = new float[conv16_output_channel * conv16_output_height * conv16_output_width];
		Row_column_transpose(conv16_output, conv16_output2, conv16_output_height * conv16_output_width, conv16_output_channel);
		//float *conv16_output1 = new float[conv16_output_channel * conv16_output_height * conv16_output_width];
		//readFile("data/conv16_output", conv16_output1, conv16_output_height * conv16_output_width * conv16_output_channel * sizeof(float));

		//start run conv17
		//gettimeofday(&startfc, NULL);
		im2rowBycol(conv16_output, conv16_output_channel, conv16_output_height, conv16_output_width, conv17_kernel_height, conv17_kernel_width,
			conv17_pad_height, conv17_pad_width, conv17_stride_height, conv17_stride_width, conv17_dilation_height, conv17_dilation_width, conv16_output_col);
		convParam conv17_param = { conv16_output_col, conv17_new_coef, conv17_bias, conv17_output, conv16_output_channel, conv16_output_height, conv16_output_width,
			conv17_kernel_height, conv17_kernel_width, conv17_output_channel, conv17_output_height, conv17_output_width };
		convLayer(&conv17_param, conv17_withRELU);
		//gettimeofday(&endfc, NULL);
		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
		//cout << "conv17 conv: " << endfctt - startfctt << "ms" << endl;  
		//end run conv17
		float *conv17_output2 = new float[conv17_output_channel * conv17_output_height * conv17_output_width];
		Row_column_transpose(conv17_output, conv17_output2, conv17_output_height * conv17_output_width, conv17_output_channel);
		//float *conv17_output1 = new float[conv17_output_channel * conv17_output_height * conv17_output_width];
		//readFile("data/conv17_output", conv17_output1, conv17_output_height * conv17_output_width * conv17_output_channel * sizeof(float));



		//start run scales3_norm
		//gettimeofday(&startfc, NULL);
		Row_column_transpose(scales3_output, scales3_output_transpose, scales3_height*scales3_width, scales3_channel);
		normalizeParam scales3_norm_param = { scales3_output_transpose, scales3_norm_output, scale3, across_spatial, channel_shared, scales3_channel, scales3_height, scales3_width };
		Normalize(&scales3_norm_param);
		//gettimeofday(&endfc, NULL);
		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
		//cout << "scales3 norm: " << endfctt - startfctt << "ms" << endl;
		//end run scales3_norm

		//float *scales3_norm_output1 = new float[scales3_norm_output_channel * scales3_norm_output_height * scales3_norm_output_width];
		//readFile("data/ip7_norm_output", scales3_norm_output1, scales3_mbox_loc_output_height * scales3_mbox_loc_output_width * scales3_mbox_loc_output_channel * sizeof(float));

		//start run scales3_mbox_loc
		//gettimeofday(&startfc, NULL);
		//Row_column_transpose(scales3_norm_output, scales3_norm_output_transpose, scales3_output_channel, scales3_output_height * scales3_output_width);
		im2row(scales3_norm_output, scales3_channel, scales3_height, scales3_width, scales3_mbox_loc_kernel_height, scales3_mbox_loc_kernel_width,
			scales3_mbox_loc_pad_height, scales3_mbox_loc_pad_width, scales3_mbox_loc_stride_height, scales3_mbox_loc_stride_width, scales3_mbox_loc_dilation_height, scales3_mbox_loc_dilation_width, scales3_norm_output_col2);
		convParam scales3_mbox_loc_param = { scales3_norm_output_col2, scales3_mbox_loc_new_coef, scales3_mbox_loc_bias, scales3_mbox_loc_output, scales3_channel, scales3_height, scales3_width, scales3_mbox_loc_kernel_height, scales3_mbox_loc_kernel_width, scales3_mbox_loc_output_channel, scales3_mbox_loc_output_height, scales3_mbox_loc_output_width };
		convLayer(&scales3_mbox_loc_param, scales3_mbox_loc_withRELU);
		Row_column_transpose(scales3_mbox_loc_output, scales3_mbox_loc_output_transpose, scales3_mbox_loc_output_height * scales3_mbox_loc_output_width, scales3_mbox_loc_output_channel);
		//gettimeofday(&endfc, NULL);
		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
		//cout << "scales3_mbox_loc conv: " << endfctt - startfctt << "ms" << endl;
		//end run scales3_mbox_loc

		//float *scales3_mbox_loc_output1 = new float[scales3_mbox_loc_output_channel * scales3_mbox_loc_output_height * scales3_mbox_loc_output_width];
		//readFile("data/ip7_norm_mbox_loc_output", scales3_mbox_loc_output1, scales3_mbox_loc_output_height * scales3_mbox_loc_output_width * scales3_mbox_loc_output_channel * sizeof(float));


		//start run scales3_mbox_loc_perm
		//gettimeofday(&startfc, NULL);
		permuteParam scales3_mbox_loc_perm = { scales3_mbox_loc_perm_orders, scales3_mbox_loc_perm_shape, scales3_mbox_loc_output_transpose, scales3_mbox_loc_perm_output };
		Permute(&scales3_mbox_loc_perm);
		//gettimeofday(&endfc, NULL);
		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
		//cout << "scales3_mbox_loc_perm: " << endfctt - startfctt << "ms" << endl;
		//end run scales3_mbox_loc_perm


		//start run scales3_mbox_conf
		//gettimeofday(&startfc, NULL);
		im2row(scales3_norm_output, scales3_channel, scales3_height, scales3_width, scales3_mbox_conf_kernel_height, scales3_mbox_conf_kernel_width,
			scales3_mbox_conf_pad_height, scales3_mbox_conf_pad_width, scales3_mbox_conf_stride_height, scales3_mbox_conf_stride_width, scales3_mbox_conf_dilation_height, scales3_mbox_conf_dilation_width, scales3_norm_output_col3);
		convParam scales3_mbox_conf_param = { scales3_norm_output_col3, scales3_mbox_conf_new_coef, scales3_mbox_conf_bias, scales3_mbox_conf_output, scales3_channel, scales3_height, scales3_width, scales3_mbox_conf_kernel_height, scales3_mbox_conf_kernel_width, scales3_mbox_conf_output_channel, scales3_mbox_conf_output_height, scales3_mbox_conf_output_width };
		convLayer(&scales3_mbox_conf_param, scales3_mbox_conf_withRELU);
		Row_column_transpose(scales3_mbox_conf_output, scales3_mbox_conf_output_transpose, scales3_mbox_conf_output_height * scales3_mbox_conf_output_width, scales3_mbox_conf_output_channel);
		//gettimeofday(&endfc, NULL);
		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
		//cout << "scales3_mbox_conf conv: " << endfctt - startfctt << "ms" << endl;
		//end run scales3_mbox_conf

		//start run scales3_mbox_conf_perm
		//gettimeofday(&startfc, NULL);
		permuteParam scales3_mbox_conf_perm = { scales3_mbox_conf_perm_orders, scales3_mbox_conf_perm_shape, scales3_mbox_conf_output_transpose, scales3_mbox_conf_perm_output };
		Permute(&scales3_mbox_conf_perm);
		//gettimeofday(&endfc, NULL);
		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
		//cout << "scales3_mbox_conf_perm: " << endfctt - startfctt << "ms" << endl;
		//end run scales3_mbox_conf_perm



		//start run scales5_mbox_loc
		//gettimeofday(&startfc, NULL);
		im2rowBycol(scales5_output, scales5_channel, scales5_height, scales5_width, scales5_mbox_loc_kernel_height, scales5_mbox_loc_kernel_width,
			scales5_mbox_loc_pad_height, scales5_mbox_loc_pad_width, scales5_mbox_loc_stride_height, scales5_mbox_loc_stride_width, scales5_mbox_loc_dilation_height, scales5_mbox_loc_dilation_width, scales5_output_col2);
		convParam scales5_mbox_loc_param = { scales5_output_col2, scales5_mbox_loc_new_coef, scales5_mbox_loc_bias, scales5_mbox_loc_output, scales5_channel, scales5_height, scales5_width,scales5_mbox_loc_kernel_height, scales5_mbox_loc_kernel_width, scales5_mbox_loc_output_channel, scales5_mbox_loc_output_height, scales5_mbox_loc_output_width };
		convLayer(&scales5_mbox_loc_param, scales5_mbox_loc_withRELU);
		Row_column_transpose(scales5_mbox_loc_output, scales5_mbox_loc_output_transpose, scales5_mbox_loc_output_height * scales5_mbox_loc_output_width, scales5_mbox_loc_output_channel);
		//gettimeofday(&endfc, NULL);
		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
		//cout << "scales5_mbox_loc conv: " << endfctt - startfctt << "ms" << endl;
		//end run scales5_mbox_loc



		//start run scales5_mbox_loc_perm
		//gettimeofday(&startfc, NULL);
		permuteParam scales5_mbox_loc_perm = { scales5_mbox_loc_perm_orders, scales5_mbox_loc_perm_shape, scales5_mbox_loc_output_transpose, scales5_mbox_loc_perm_output };
		Permute(&scales5_mbox_loc_perm);
		//gettimeofday(&endfc, NULL);
		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
		//cout << "scales5_mbox_loc_perm: " << endfctt - startfctt << "ms" << endl;
		//end run scales5_mbox_loc_perm


		//start run scales5_mbox_conf
		//gettimeofday(&startfc, NULL);
		im2rowBycol(scales5_output, scales5_channel, scales5_height, scales5_width, scales5_mbox_conf_kernel_height, scales5_mbox_conf_kernel_width,
			scales5_mbox_conf_pad_height, scales5_mbox_conf_pad_width, scales5_mbox_conf_stride_height, scales5_mbox_conf_stride_width, scales5_mbox_conf_dilation_height, scales5_mbox_conf_dilation_width, scales5_output_col3);

		convParam scales5_mbox_conf_param = { scales5_output_col3, scales5_mbox_conf_new_coef, scales5_mbox_conf_bias, scales5_mbox_conf_output, scales5_channel, scales5_height, scales5_width, scales5_mbox_conf_kernel_height, scales5_mbox_conf_kernel_width, scales5_mbox_conf_output_channel, scales5_mbox_conf_output_height, scales5_mbox_conf_output_width };
		convLayer(&scales5_mbox_conf_param, scales5_mbox_conf_withRELU);
		Row_column_transpose(scales5_mbox_conf_output, scales5_mbox_conf_output_transpose, scales5_mbox_conf_output_height * scales5_mbox_conf_output_width, scales5_mbox_conf_output_channel);
		//gettimeofday(&endfc, NULL);
		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
		//cout << "scales5_mbox_conf conv: " << endfctt - startfctt << "ms" << endl;
		//end run scales5_mbox_conf

		//start run scales5_mbox_conf_perm
		//gettimeofday(&startfc, NULL);
		permuteParam scales5_mbox_conf_perm = { scales5_mbox_conf_perm_orders, scales5_mbox_conf_perm_shape, scales5_mbox_conf_output_transpose, scales5_mbox_conf_perm_output };
		Permute(&scales5_mbox_conf_perm);
		//gettimeofday(&endfc, NULL);
		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
		//cout << "scales5_mbox_conf_perm: " << endfctt - startfctt << "ms" << endl;
		//end run scales5_mbox_conf_perm


		//start run conv11_mbox_loc
		//gettimeofday(&startfc, NULL);
		im2rowBycol(conv11_output, conv11_output_channel, conv11_output_height, conv11_output_width, conv11_mbox_loc_kernel_height, conv11_mbox_loc_kernel_width,
			conv11_mbox_loc_pad_height, conv11_mbox_loc_pad_width, conv11_mbox_loc_stride_height, conv11_mbox_loc_stride_width, conv11_mbox_loc_dilation_height, conv11_mbox_loc_dilation_width, conv11_output_col2);
		convParam conv11_mbox_loc_param = { conv11_output_col2, conv11_mbox_loc_new_coef, conv11_mbox_loc_bias, conv11_mbox_loc_output, conv11_output_channel, conv11_output_height, conv11_output_width,conv11_mbox_loc_kernel_height, conv11_mbox_loc_kernel_width, conv11_mbox_loc_output_channel, conv11_mbox_loc_output_height, conv11_mbox_loc_output_width };
		convLayer(&conv11_mbox_loc_param, conv11_mbox_loc_withRELU);
		Row_column_transpose(conv11_mbox_loc_output, conv11_mbox_loc_output_transpose, conv11_mbox_loc_output_height * conv11_mbox_loc_output_width, conv11_mbox_loc_output_channel);
		//gettimeofday(&endfc, NULL);
		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
		//cout << "conv11_mbox_loc conv: " << endfctt - startfctt << "ms" << endl;
		//end run conv11_mbox_loc



		//start run conv11_mbox_loc_perm
		//gettimeofday(&startfc, NULL);
		permuteParam conv11_mbox_loc_perm = { conv11_mbox_loc_perm_orders, conv11_mbox_loc_perm_shape, conv11_mbox_loc_output_transpose, conv11_mbox_loc_perm_output };
		Permute(&conv11_mbox_loc_perm);
		//gettimeofday(&endfc, NULL);
		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
		//cout << "conv11_mbox_loc_perm: " << endfctt - startfctt << "ms" << endl;
		//end run conv11_mbox_loc_perm


		//start run conv11_mbox_conf
		//gettimeofday(&startfc, NULL);
		im2rowBycol(conv11_output, conv11_output_channel, conv11_output_height, conv11_output_width, conv11_mbox_conf_kernel_height, conv11_mbox_conf_kernel_width,
			conv11_mbox_conf_pad_height, conv11_mbox_conf_pad_width, conv11_mbox_conf_stride_height, conv11_mbox_conf_stride_width, conv11_mbox_conf_dilation_height, conv11_mbox_conf_dilation_width, conv11_output_col3);

		convParam conv11_mbox_conf_param = { conv11_output_col3, conv11_mbox_conf_new_coef, conv11_mbox_conf_bias, conv11_mbox_conf_output, conv11_output_channel, conv11_output_height, conv11_output_width, conv11_mbox_conf_kernel_height, conv11_mbox_conf_kernel_width, conv11_mbox_conf_output_channel, conv11_mbox_conf_output_height, conv11_mbox_conf_output_width };
		convLayer(&conv11_mbox_conf_param, conv11_mbox_conf_withRELU);
		Row_column_transpose(conv11_mbox_conf_output, conv11_mbox_conf_output_transpose, conv11_mbox_conf_output_height * conv11_mbox_conf_output_width, conv11_mbox_conf_output_channel);
		//gettimeofday(&endfc, NULL);
		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
		//cout << "conv11_mbox_conf conv: " << endfctt - startfctt << "ms" << endl;
		//end run conv11_mbox_conf

		//start run conv11_mbox_conf_perm
		//gettimeofday(&startfc, NULL);
		permuteParam conv11_mbox_conf_perm = { conv11_mbox_conf_perm_orders, conv11_mbox_conf_perm_shape, conv11_mbox_conf_output_transpose, conv11_mbox_conf_perm_output };
		Permute(&conv11_mbox_conf_perm);
		//gettimeofday(&endfc, NULL);
		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
		//cout << "conv11_mbox_conf_perm: " << endfctt - startfctt << "ms" << endl;
		//end run conv11_mbox_conf_perm



















		//start run conv13_mbox_loc
		//gettimeofday(&startfc, NULL);
		im2rowBycol(conv13_output, conv13_output_channel, conv13_output_height, conv13_output_width, conv13_mbox_loc_kernel_height, conv13_mbox_loc_kernel_width,
			conv13_mbox_loc_pad_height, conv13_mbox_loc_pad_width, conv13_mbox_loc_stride_height, conv13_mbox_loc_stride_width, conv13_mbox_loc_dilation_height, conv13_mbox_loc_dilation_width, conv13_output_col2);
		convParam conv13_mbox_loc_param = { conv13_output_col2, conv13_mbox_loc_new_coef, conv13_mbox_loc_bias, conv13_mbox_loc_output, conv13_output_channel, conv13_output_height, conv13_output_width,conv13_mbox_loc_kernel_height, conv13_mbox_loc_kernel_width, conv13_mbox_loc_output_channel, conv13_mbox_loc_output_height, conv13_mbox_loc_output_width };
		convLayer(&conv13_mbox_loc_param, conv13_mbox_loc_withRELU);
		Row_column_transpose(conv13_mbox_loc_output, conv13_mbox_loc_output_transpose, conv13_mbox_loc_output_height * conv13_mbox_loc_output_width, conv13_mbox_loc_output_channel);
		//gettimeofday(&endfc, NULL);
		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
		//cout << "conv13_mbox_loc conv: " << endfctt - startfctt << "ms" << endl;
		//end run conv13_mbox_loc



		//start run conv13_mbox_loc_perm
		//gettimeofday(&startfc, NULL);
		permuteParam conv13_mbox_loc_perm = { conv13_mbox_loc_perm_orders, conv13_mbox_loc_perm_shape, conv13_mbox_loc_output_transpose, conv13_mbox_loc_perm_output };
		Permute(&conv13_mbox_loc_perm);
		//gettimeofday(&endfc, NULL);
		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
		//cout << "conv13_mbox_loc_perm: " << endfctt - startfctt << "ms" << endl;
		//end run conv13_mbox_loc_perm


		//start run conv13_mbox_conf
		//gettimeofday(&startfc, NULL);
		im2rowBycol(conv13_output, conv13_output_channel, conv13_output_height, conv13_output_width, conv13_mbox_conf_kernel_height, conv13_mbox_conf_kernel_width,
			conv13_mbox_conf_pad_height, conv13_mbox_conf_pad_width, conv13_mbox_conf_stride_height, conv13_mbox_conf_stride_width, conv13_mbox_conf_dilation_height, conv13_mbox_conf_dilation_width, conv13_output_col3);

		convParam conv13_mbox_conf_param = { conv13_output_col3, conv13_mbox_conf_new_coef, conv13_mbox_conf_bias, conv13_mbox_conf_output, conv13_output_channel, conv13_output_height, conv13_output_width, conv13_mbox_conf_kernel_height, conv13_mbox_conf_kernel_width, conv13_mbox_conf_output_channel, conv13_mbox_conf_output_height, conv13_mbox_conf_output_width };
		convLayer(&conv13_mbox_conf_param, conv13_mbox_conf_withRELU);
		Row_column_transpose(conv13_mbox_conf_output, conv13_mbox_conf_output_transpose, conv13_mbox_conf_output_height * conv13_mbox_conf_output_width, conv13_mbox_conf_output_channel);
		//gettimeofday(&endfc, NULL);
		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
		//cout << "conv13_mbox_conf conv: " << endfctt - startfctt << "ms" << endl;
		//end run conv13_mbox_conf

		//start run conv13_mbox_conf_perm
		//gettimeofday(&startfc, NULL);
		permuteParam conv13_mbox_conf_perm = { conv13_mbox_conf_perm_orders, conv13_mbox_conf_perm_shape, conv13_mbox_conf_output_transpose, conv13_mbox_conf_perm_output };
		Permute(&conv13_mbox_conf_perm);
		//gettimeofday(&endfc, NULL);
		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
		//cout << "conv13_mbox_conf_perm: " << endfctt - startfctt << "ms" << endl;
		//end run conv13_mbox_conf_perm


		//start run conv15_mbox_loc
		//gettimeofday(&startfc, NULL);
		im2rowBycol(conv15_output, conv15_output_channel, conv15_output_height, conv15_output_width, conv15_mbox_loc_kernel_height, conv15_mbox_loc_kernel_width,
			conv15_mbox_loc_pad_height, conv15_mbox_loc_pad_width, conv15_mbox_loc_stride_height, conv15_mbox_loc_stride_width, conv15_mbox_loc_dilation_height, conv15_mbox_loc_dilation_width, conv15_output_col2);
		convParam conv15_mbox_loc_param = { conv15_output_col2, conv15_mbox_loc_new_coef, conv15_mbox_loc_bias, conv15_mbox_loc_output, conv15_output_channel, conv15_output_height, conv15_output_width,conv15_mbox_loc_kernel_height, conv15_mbox_loc_kernel_width, conv15_mbox_loc_output_channel, conv15_mbox_loc_output_height, conv15_mbox_loc_output_width };
		convLayer(&conv15_mbox_loc_param, conv15_mbox_loc_withRELU);
		Row_column_transpose(conv15_mbox_loc_output, conv15_mbox_loc_output_transpose, conv15_mbox_loc_output_height * conv15_mbox_loc_output_width, conv15_mbox_loc_output_channel);
		//gettimeofday(&endfc, NULL);
		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
		//cout << "conv15_mbox_loc conv: " << endfctt - startfctt << "ms" << endl;
		//end run conv15_mbox_loc



		//start run conv15_mbox_loc_perm
		//gettimeofday(&startfc, NULL);
		permuteParam conv15_mbox_loc_perm = { conv15_mbox_loc_perm_orders, conv15_mbox_loc_perm_shape, conv15_mbox_loc_output_transpose, conv15_mbox_loc_perm_output };
		Permute(&conv15_mbox_loc_perm);
		//gettimeofday(&endfc, NULL);
		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
		//cout << "conv15_mbox_loc_perm: " << endfctt - startfctt << "ms" << endl;
		//end run conv15_mbox_loc_perm


		//start run conv15_mbox_conf
		//gettimeofday(&startfc, NULL);
		im2rowBycol(conv15_output, conv15_output_channel, conv15_output_height, conv15_output_width, conv15_mbox_conf_kernel_height, conv15_mbox_conf_kernel_width,
			conv15_mbox_conf_pad_height, conv15_mbox_conf_pad_width, conv15_mbox_conf_stride_height, conv15_mbox_conf_stride_width, conv15_mbox_conf_dilation_height, conv15_mbox_conf_dilation_width, conv15_output_col3);

		convParam conv15_mbox_conf_param = { conv15_output_col3, conv15_mbox_conf_new_coef, conv15_mbox_conf_bias, conv15_mbox_conf_output, conv15_output_channel, conv15_output_height, conv15_output_width, conv15_mbox_conf_kernel_height, conv15_mbox_conf_kernel_width, conv15_mbox_conf_output_channel, conv15_mbox_conf_output_height, conv15_mbox_conf_output_width };
		convLayer(&conv15_mbox_conf_param, conv15_mbox_conf_withRELU);
		Row_column_transpose(conv15_mbox_conf_output, conv15_mbox_conf_output_transpose, conv15_mbox_conf_output_height * conv15_mbox_conf_output_width, conv15_mbox_conf_output_channel);
		//gettimeofday(&endfc, NULL);
		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
		//cout << "conv15_mbox_conf conv: " << endfctt - startfctt << "ms" << endl;
		//end run conv15_mbox_conf

		//start run conv15_mbox_conf_perm
		//gettimeofday(&startfc, NULL);
		permuteParam conv15_mbox_conf_perm = { conv15_mbox_conf_perm_orders, conv15_mbox_conf_perm_shape, conv15_mbox_conf_output_transpose, conv15_mbox_conf_perm_output };
		Permute(&conv15_mbox_conf_perm);
		//gettimeofday(&endfc, NULL);
		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
		//cout << "conv15_mbox_conf_perm: " << endfctt - startfctt << "ms" << endl;
		//end run conv15_mbox_conf_perm



		//start run conv17_mbox_loc
		//gettimeofday(&startfc, NULL);
		im2rowBycol(conv17_output, conv17_output_channel, conv17_output_height, conv17_output_width, conv17_mbox_loc_kernel_height, conv17_mbox_loc_kernel_width,
			conv17_mbox_loc_pad_height, conv17_mbox_loc_pad_width, conv17_mbox_loc_stride_height, conv17_mbox_loc_stride_width, conv17_mbox_loc_dilation_height, conv17_mbox_loc_dilation_width, conv17_output_col2);
		convParam conv17_mbox_loc_param = { conv17_output_col2, conv17_mbox_loc_new_coef, conv17_mbox_loc_bias, conv17_mbox_loc_output, conv17_output_channel, conv17_output_height, conv17_output_width,conv17_mbox_loc_kernel_height, conv17_mbox_loc_kernel_width, conv17_mbox_loc_output_channel, conv17_mbox_loc_output_height, conv17_mbox_loc_output_width };
		convLayer(&conv17_mbox_loc_param, conv17_mbox_loc_withRELU);
		Row_column_transpose(conv17_mbox_loc_output, conv17_mbox_loc_output_transpose, conv17_mbox_loc_output_height * conv17_mbox_loc_output_width, conv17_mbox_loc_output_channel);
		//gettimeofday(&endfc, NULL);
		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
		//cout << "conv17_mbox_loc conv: " << endfctt - startfctt << "ms" << endl;
		//end run conv17_mbox_loc



		//start run conv17_mbox_loc_perm
		//gettimeofday(&startfc, NULL);
		permuteParam conv17_mbox_loc_perm = { conv17_mbox_loc_perm_orders, conv17_mbox_loc_perm_shape, conv17_mbox_loc_output_transpose, conv17_mbox_loc_perm_output };
		Permute(&conv17_mbox_loc_perm);
		//gettimeofday(&endfc, NULL);
		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
		//cout << "conv17_mbox_loc_perm: " << endfctt - startfctt << "ms" << endl;
		//end run conv17_mbox_loc_perm


		//start run conv17_mbox_conf
		//gettimeofday(&startfc, NULL);
		im2rowBycol(conv17_output, conv17_output_channel, conv17_output_height, conv17_output_width, conv17_mbox_conf_kernel_height, conv17_mbox_conf_kernel_width,
			conv17_mbox_conf_pad_height, conv17_mbox_conf_pad_width, conv17_mbox_conf_stride_height, conv17_mbox_conf_stride_width, conv17_mbox_conf_dilation_height, conv17_mbox_conf_dilation_width, conv17_output_col3);

		convParam conv17_mbox_conf_param = { conv17_output_col3, conv17_mbox_conf_new_coef, conv17_mbox_conf_bias, conv17_mbox_conf_output, conv17_output_channel, conv17_output_height, conv17_output_width, conv17_mbox_conf_kernel_height, conv17_mbox_conf_kernel_width, conv17_mbox_conf_output_channel, conv17_mbox_conf_output_height, conv17_mbox_conf_output_width };
		convLayer(&conv17_mbox_conf_param, conv17_mbox_conf_withRELU);
		Row_column_transpose(conv17_mbox_conf_output, conv17_mbox_conf_output_transpose, conv17_mbox_conf_output_height * conv17_mbox_conf_output_width, conv17_mbox_conf_output_channel);
		//gettimeofday(&endfc, NULL);
		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
		//cout << "conv17_mbox_conf conv: " << endfctt - startfctt << "ms" << endl;
		//end run conv17_mbox_conf

		//start run conv17_mbox_conf_perm
		//gettimeofday(&startfc, NULL);
		permuteParam conv17_mbox_conf_perm = { conv17_mbox_conf_perm_orders, conv17_mbox_conf_perm_shape, conv17_mbox_conf_output_transpose, conv17_mbox_conf_perm_output };
		Permute(&conv17_mbox_conf_perm);
		//gettimeofday(&endfc, NULL);
		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
		//cout << "conv17_mbox_conf_perm: " << endfctt - startfctt << "ms" << endl;
		//end run conv17_mbox_conf_perm


		//start run scales3_mbox_priorbox
		//gettimeofday(&startfc, NULL);
		priorBoxParam scales3_mbox_prior_param = { scales3_height, scales3_width, img_height, img_width, scales3_mbox_prior_step_h, scales3_mbox_prior_step_w, scales3_mbox_prior_min_sizes_, scales3_mbox_prior_max_sizes_, scales3_mbox_prior_aspect_ratios_, scales3_mbox_prior_num_priors_, scales3_mbox_prior_flip_, scales3_mbox_prior_clip_, scales3_mbox_prior_variance_, scales3_mbox_prior_offset_, scales3_mbox_prior_output };
		PriorBox(&scales3_mbox_prior_param);
		//gettimeofday(&endfc, NULL);
		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
		//cout << "scales3_mbox_prior: " << endfctt - startfctt << "ms" << endl;
		//end run scales3_mbox_priorbox


		//start run scales5_mbox_priorbox
		//gettimeofday(&startfc, NULL);
		priorBoxParam scales5_mbox_prior_param = { scales5_height, scales5_width, img_height, img_width, scales5_mbox_prior_step_h, scales5_mbox_prior_step_w, scales5_mbox_prior_min_sizes_, scales5_mbox_prior_max_sizes_, scales5_mbox_prior_aspect_ratios_, scales5_mbox_prior_num_priors_, scales5_mbox_prior_flip_, scales5_mbox_prior_clip_, scales5_mbox_prior_variance_, scales5_mbox_prior_offset_, scales5_mbox_prior_output };
		PriorBox(&scales5_mbox_prior_param);
		//gettimeofday(&endfc, NULL);
		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
		//cout << "scales5_mbox_prior: " << endfctt - startfctt << "ms" << endl;
		//end run scales5_mbox_priorbox

		//start run conv11_mbox_priorbox
		//gettimeofday(&startfc, NULL);
		priorBoxParam conv11_mbox_prior_param = { conv11_output_height, conv11_output_width, img_height, img_width, conv11_mbox_prior_step_h, conv11_mbox_prior_step_w, conv11_mbox_prior_min_sizes_, conv11_mbox_prior_max_sizes_, conv11_mbox_prior_aspect_ratios_, conv11_mbox_prior_num_priors_, conv11_mbox_prior_flip_, conv11_mbox_prior_clip_, conv11_mbox_prior_variance_, conv11_mbox_prior_offset_, conv11_mbox_prior_output };
		PriorBox(&conv11_mbox_prior_param);
		//gettimeofday(&endfc, NULL);
		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
		//cout << "conv11_mbox_prior: " << endfctt - startfctt << "ms" << endl;
		//end run conv11_mbox_priorbox


		//start run conv13_mbox_priorbox
		//gettimeofday(&startfc, NULL);
		priorBoxParam conv13_mbox_prior_param = { conv13_output_height, conv13_output_width, img_height, img_width, conv13_mbox_prior_step_h, conv13_mbox_prior_step_w, conv13_mbox_prior_min_sizes_, conv13_mbox_prior_max_sizes_, conv13_mbox_prior_aspect_ratios_, conv13_mbox_prior_num_priors_, conv13_mbox_prior_flip_, conv13_mbox_prior_clip_, conv13_mbox_prior_variance_, conv13_mbox_prior_offset_, conv13_mbox_prior_output };
		PriorBox(&conv13_mbox_prior_param);
		//gettimeofday(&endfc, NULL);
		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
		//cout << "conv13_mbox_prior: " << endfctt - startfctt << "ms" << endl;
		//end run conv13_mbox_priorbox

		//start run conv15_mbox_priorbox
		//gettimeofday(&startfc, NULL);
		priorBoxParam conv15_mbox_prior_param = { conv15_output_height, conv15_output_width, img_height, img_width, conv15_mbox_prior_step_h, conv15_mbox_prior_step_w, conv15_mbox_prior_min_sizes_, conv15_mbox_prior_max_sizes_, conv15_mbox_prior_aspect_ratios_, conv15_mbox_prior_num_priors_, conv15_mbox_prior_flip_, conv15_mbox_prior_clip_, conv15_mbox_prior_variance_, conv15_mbox_prior_offset_, conv15_mbox_prior_output };
		PriorBox(&conv15_mbox_prior_param);
		//gettimeofday(&endfc, NULL);
		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
		//cout << "conv15_mbox_prior: " << endfctt - startfctt << "ms" << endl;
		//end run conv15_mbox_priorbox

		//start run conv17_mbox_priorbox
		//gettimeofday(&startfc, NULL);
		priorBoxParam conv17_mbox_prior_param = { conv17_output_height, conv17_output_width, img_height, img_width, conv17_mbox_prior_step_h, conv17_mbox_prior_step_w, conv17_mbox_prior_min_sizes_, conv17_mbox_prior_max_sizes_, conv17_mbox_prior_aspect_ratios_, conv17_mbox_prior_num_priors_, conv17_mbox_prior_flip_, conv17_mbox_prior_clip_, conv17_mbox_prior_variance_, conv17_mbox_prior_offset_, conv17_mbox_prior_output };
		PriorBox(&conv17_mbox_prior_param);
		//gettimeofday(&endfc, NULL);
		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
		//cout << "conv17_mbox_prior: " << endfctt - startfctt << "ms" << endl;
		//end run conv17_mbox_priorbox


		//start run mbox_priorbox
		//gettimeofday(&startfc, NULL);
		concatParam mbox_priorbox_param = { DataParams, mbox_priorbox_output_Data, shape, -1, mbox_priorbox_axis };
		Concat(&mbox_priorbox_param);
		//gettimeofday(&endfc, NULL);
		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
		//cout << "mbox_priorbox: " << endfctt - startfctt << "ms" << endl;
		//end run mbox_priorbox

		//start run mbox_loc
		//gettimeofday(&startfc, NULL);
		concatParam mbox_loc_param = { DataParams_loc, mbox_loc_output_Data, shape_loc, -1, mbox_loc_axis };
		Concat(&mbox_loc_param);
		//gettimeofday(&endfc, NULL);
		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
		//cout << "mbox_loc: " << endfctt - startfctt << "ms" << endl;
		//end run mbox_loc


		//start run mbox_conf
		//gettimeofday(&startfc, NULL);
		concatParam mbox_conf_param = { DataParams_conf, mbox_conf_output_Data, shape_conf, -1, mbox_conf_axis };
		Concat(&mbox_conf_param);
		//gettimeofday(&endfc, NULL);
		//startfctt = ((long)startfc.tv_sec) * 1000 + (long)startfc.tv_usec / 1000;
		//endfctt = ((long)endfc.tv_sec) * 1000 + (long)endfc.tv_usec / 1000;
		//cout << "mbox_conf: " << endfctt - startfctt << "ms" << endl;
		//end run mbox_conf


		//float *input = new float[1 * 420 * 2];
		//input = mbox_conf_param.output_data;
		//readFile("data/mbox_conf_reshape_output", input, 1 * 420 * 2 * sizeof(float));
		int axis = 2;
		//vector<int> shape;
		shape.clear();
		shape.push_back(1);
		shape.push_back(38 * 38 * 4 + 19 * 19 * 6 + 10 * 10 * 6 + 5 * 5 * 6 + 5 * 5 * 4 + 5 * 5 * 4);
		shape.push_back(2);
		float *conf_soft_output = new float[1 * (38 * 38 * 4 + 19 * 19 * 6 + 10 * 10 * 6 + 5 * 5 * 6 + 5 * 5 * 4 + 5 * 5 * 4) * 2];
		softmaxParam mbox_conf_softmax_param = { mbox_conf_param.output_data, conf_soft_output, shape, axis };
		Softmax(&mbox_conf_softmax_param);



		int num_classes = 2;
		int share_location = 1;
		int background_label_id = 0;
		int code_type = CENTER_SIZE;
		int variance_encoded_in_target = 0;
		int keep_top_k = 200;
		float confidence_threshold = 0.3;
		float nms_threshold = 0.449999988079;
		float eta = 1.0;
		int top_k = 400;
		vector<int> mbox_loc_shape(2, 1);
		mbox_loc_shape[1] = 4 * (38 * 38 * 4 + 19 * 19 * 6 + 10 * 10 * 6 + 5 * 5 * 6 + 5 * 5 * 4 + 5 * 5 * 4);
		vector<int> mbox_conf_flatten_shape(2, 1);
		mbox_conf_flatten_shape[1] = (38 * 38 * 4 + 19 * 19 * 6 + 10 * 10 * 6 + 5 * 5 * 6 + 5 * 5 * 4 + 5 * 5 * 4) * num_classes;
		vector<int> mbox_priorbox_shape(3, 1);
		mbox_priorbox_shape[1] = 2;
		mbox_priorbox_shape[2] = (38 * 38 * 4 + 19 * 19 * 6 + 10 * 10 * 6 + 5 * 5 * 6 + 5 * 5 * 4 + 5 * 5 * 4) *4;
		int object_num;
		detectionParam detection_out_param = { num_classes, share_location, background_label_id, code_type, variance_encoded_in_target, keep_top_k, confidence_threshold, nms_threshold, eta, top_k, mbox_loc_shape, mbox_conf_flatten_shape, mbox_priorbox_shape, mbox_loc_param.output_data, mbox_conf_softmax_param.output_data, mbox_priorbox_param.output_data };
		float *result = Detection_output(&detection_out_param, object_num);

		vector<vector<float>> objects;
		vector<float>object(6, 0);//class,conf,xmin,ymin,xmax,ymax
		for (int i = 0; i < object_num; i++) {
			object[0] = result[i * 7 + 1];
			object[1] = result[i * 7 + 2];
			object[2] = result[i * 7 + 3]*600;
			object[3] = result[i * 7 + 4]*400;
			object[4] = result[i * 7 + 5]*600;
			object[5] = result[i * 7 + 6]*400;
			objects.push_back(object);

		}
		map<int, string> *label_to_name = new map<int, string>[num_classes];
		map<int, string> *label_to_display_name = new map<int, string>[num_classes];
		ReadLabelFromTextFile("./data/labelmap.prototxt", label_to_name, label_to_display_name);
		cout << "object+num:" << object_num << endl;

		delete[] mbox_loc_param.output_data;
		mbox_loc_param.output_data = NULL;
		delete[] mbox_conf_softmax_param.output_data;
		mbox_conf_softmax_param.output_data = NULL;
		delete[] mbox_priorbox_param.output_data;
		mbox_priorbox_param.output_data = NULL;
		delete[] result;
		result = NULL;

		return 0;



#endif // FACE


}
