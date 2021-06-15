#pragma once
#include "State.h"
#include "Frame.h"
#include <algorithm>
using namespace std;
class data_combin
{
public:
	Frame* frame;
	State* state;
	~data_combin() { delete frame; delete state; }
	data_combin(int fileNum);
	void slicing(char axis, vector<Lidar_sample*>* above, vector<Lidar_sample*>* below);
	void clustering(vector<Lidar_sample*>* pointC);
	void inspection(char viewPoint, vector<Lidar_sample*>* sortVector);

};




