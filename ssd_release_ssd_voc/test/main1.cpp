#include "layer.h"
#include<iostream>
#include<windows.h>
using namespace std;

int main()
{
	vector<int> vec;
	int img_height = 576;
	int img_width = 768;
	int img_channel = 3;

	float *img_data = new float[img_height*img_width*img_channel];
	readFile("img", img_data, img_height*img_width*img_channel * sizeof(float));

	float *con1_w = new float[3 * 3 * 3 * 16];
	float *conv1_b = new float[16];
	float *oup = new float[16 * 416 * 416];
	float*input_col = new float[img_height*img_width*img_channel * 3 * 3 * 3];
	readFile1("0", conv1_b, 16 * sizeof(float), vec);
	vec.push_back(16 * sizeof(float));

	readFile1("0", con1_w, 3 * 3 * 3 * 16 * sizeof(float), vec);
	float *con1_w_1 = new float[3 * 3 * 3 * 16];
	Row_column_transpose(con1_w, con1_w_1, 16, 3 * 3 * 3);

	convParam param = { img_data ,con1_w,conv1_b,oup ,3,416,416,3,3,16,416,416 };
	DWORD k = ::GetTickCount();
	convforward(&param, input_col, 1, 1, 0);
	cout << ::GetTickCount() - k << endl;

	float *img_data_col = new float[3 * 3 * 3 * 16 * 416 * 416];
	DWORD k1 = ::GetTickCount();

	im2row(img_data, 3, 416, 416, 3, 3, 1, 1, 1, 1, 1, 1, img_data_col);
	convParam co_param = { img_data_col,con1_w_1,conv1_b,oup,3,416,416,3,3,16,416,416 };
	convLayer(&co_param, 0);
	cout << ::GetTickCount() - k1 << endl;
	return 0;
}