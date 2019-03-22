#pragma once
#include <vector>
#include <cmath>
#include <omp.h>
#include <string>
#include <string.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <map>
#define FACE
#define SSD
using namespace std;

/*
####结构体
- #####`convParam`
卷积层的参数
- col：经过im2row/im2rowBycol函数转换的feature map

- coef: 经过行列转置的卷积核参数

- bias: 偏移量
- output：卷积层输出
- inC, inH, inW：输入数据的形状
- knlH, knlW：卷积核形状
- outC, outW, outH：输出数据的形状
*/
struct convParam
{
	float *col;
	float *coef;
	float *bias;
	float *output;
	int inC;
	int inH;
	int inW;
	int knlH;
	int knlW;
	int outC;
	int outH;
	int outW;
};



void convforward(convParam *param, float*input_col, const int pad,
	const int stride, int withRELU = 0);


struct normalizeParam
{
	float *norm_input;
	float *norm_output;
	float *scale;
	int across_spatial_;
	int channel_shared_;
	int channel;
	int height;
	int width;
};


struct concatDataParam
{
	float *input_data;
	vector<int> shape;
};

struct concatParam
{
	vector<concatDataParam> dataParam;
	float *output_data;
	vector<int> shape;
	int concat_dim;
	int axis;
};

struct permuteParam
{
	vector<int> orders;
	vector<int> shape;
	float *input_data;
	float *output_data;
};

struct softmaxParam
{
	float *input_data;
	float *output_data;
	vector<int> shape;
	int axis;
};

struct BNParam
{
	float *col;
	float *output;
	float *bn_mean;
	float *bn_variance;
	float *bn_scales;
	int col_C;
	int col_H;
	int col_W;
};

struct ScaleParam
{
	float *col;
	float *output;
	float *gamma;
	float *beta;
	int col_C;
	int col_H;
	int col_W;
};


struct EltwiseParam
{
	vector<float *> input;
	float *output;
	vector<int> shape;//W:shape[0] H:shape[1] C:shape[2]
};

struct maxpoolParam
{
	float *col;
	float *output;
	int inC;
	int inH;
	int inW;
	int pad;
	int knlH;
	int knlW;
	int stride;
	int outC;
	int outH;
	int outW;
};


void readFile1(string filename, float *buffer, unsigned int size, vector<int> vec);

void readFile(string filename, float *buffer, unsigned int size);

void Row_column_transpose(float *fc6_coef, float *fc6_new_coef, int row, int col);

void im2row(float *input, int channels, int height, int width, int kernel_h, int kernel_w,
	int pad_h, int pad_w, int stride_h, int stride_w, int dilation_h, int dilation_w, float *data_col);

void im2rowBycol(const float* data_im, const int channels, const int height, const int width,
	const int kernel_h, const int kernel_w, const int pad_h, const int pad_w,
	const int stride_h, const int stride_w, const int dilation_h, const int dilation_w, float* data_col);

void convLayer(convParam *param, int withRELU);
void ReadLabelFromTextFile(const char* filename, map<int, string> *label_to_name, map<int, string> *label_to_display_name);

void maxpool(maxpoolParam*param);
void batchnorm(BNParam *net);//若卷积层后添加了bn层 则需要将该层的卷积系数与bn层的系数进行整合后作为新的卷积权值进行计算。(将bn层放在卷积计算中一起计算，可减少计算时间，只需要在卷积权值初始化时进行此操作)
void scales(ScaleParam *data,int withRelu);
void Eltwise(EltwiseParam *data);
void batchnorm1(BNParam *net);//若卷积层后添加了bn层 则需要将该层的卷积系数与bn层的系数进行整合后作为新的卷积权值进行计算。(将bn层放在卷积计算中一起计算，可减少计算时间，只需要在卷积权值初始化时进行此操作)
void scales1(ScaleParam *data, int withRelu);


void Normalize(normalizeParam *param);

void Concat(concatParam *param);

void Permute(permuteParam *param);

void Softmax(softmaxParam *param);

#ifdef SSD

struct priorBoxParam
{
	int input_height;
	int input_width;
	int img_height;
	int img_width;
	float step_h;
	float step_w;
	vector<float> min_sizes_;
	vector<float> max_sizes_;
	vector<float> aspect_ratios_;
	int num_priors_;
	int flip_;
	int clip_;
	vector<float> variance_;
	float offset_;
	float *output_data;
};

struct normalizedBBox
{
	float xmin;
	float ymin;
	float xmax;
	float ymax;
	int label;
	int difficult;
	float score;
	float size;
};

enum resize_mode
{
	WARP = 1,
	FIT_SMALL_SIZE = 2,
	FIT_LARGE_SIZE_AND_PAD = 3
};

enum codeType
{
	CORNER = 1,
	CENTER_SIZE = 2,
	CORNER_SIZE = 3
};

struct resizeParameter
{
	int resize_mode;
	float height;
	float width;
	int height_scale;
	int width_scale;
};

struct detectionParam
{
	int num_classes;
	int share_location;
	int background_label_id;
	int code_type;
	int variance_encoded_in_target;
	int keep_top_k;
	float confidence_threshold;
	float nms_threshold;
	float eta;
	int top_k;
	vector<int> mbox_loc_shape;
	vector<int> mbox_conf_flatten_shape;
	vector<int> mbox_priorbox_shape;
	float *loc_data;
	float *conf_data;
	float *prior_data;
};

typedef map<int, vector<normalizedBBox> > LabelBBox;

void PriorBox(priorBoxParam *param);

float* Detection_output(detectionParam *param, int &top_count);

#endif // SSD

#ifdef YOLO

typedef enum {
	LOGISTIC, RELU, RELIE, LINEAR, RAMP, TANH, PLSE, LEAKY, ELU, LOGGY, STAIR, HARDTAN, LHTAN
}ACTIVATION;

struct yoloParam
{
	float *col;
	float *output;
	int C;
	int H;
	int W;
	int classes;
};

struct upsampleParam
{
	float *col;
	float *output;
	int w;
	int h;
	int c;
	int stride;
	float scale;
};

typedef struct {
	float x, y, w, h;
} box;

typedef struct detection {
	box bbox;
	int classes;
	float *prob;
	float *mask;
	float objectness;
	int sort_class;
} detection;

struct detectionDataParam
{
	float *input_data;
	vector<int> shape;//w[0],h[1],c[2]
	vector<int> mask;
	vector<int> anchor;
	int classes;
};

struct detectionParam
{
	vector<detectionDataParam> dataParam;
	vector<int> shape; //w[0], h[1], c[2],layernum[3]
};

void yolo(yoloParam *param);
void upsample(upsampleParam*param);

int entry_index(detectionDataParam l, int batch, int location, int entry);

int yolo_num_detections(detectionDataParam l, float thresh);

int num_detections(detectionParam net, float thresh);

box get_yolo_box(float *x, vector<int> biases, int n, int index, int i, int j, int lw, int lh, int w, int h, int stride);

void correct_yolo_boxes(detection *dets, int n, int w, int h, int netw, int neth, int relative, int letter);

int get_yolo_detections(detectionDataParam l, int w, int h, int netw, int neth, float thresh, int relative, detection *dets, int letter);

detection *make_network_boxes(detectionParam net, float thresh, int *num);

void fill_network_boxes(detectionParam net, int w, int h, float thresh, float hier, int relative, detection *dets, int letter);


detection *get_network_boxes(detectionParam net, int w, int h, float thresh, float hier, int relative, int *num, int letter);

void do_nms_sort(detection *dets, int total, int classes, float thresh);
#endif // YOLO
