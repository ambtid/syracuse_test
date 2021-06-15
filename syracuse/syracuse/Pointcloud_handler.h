#pragma once
#include "data_maneger.h"
class Pointcloud_handler
{
public:
	data_maneger* dataList;
	Pointcloud_handler(data_maneger* data) :dataList(data) {};

	void slicing(int axis, int startPoint, int endPoint);
	void slicing(int numPoint, char axis);
	void clustering(int numPoint);
	void clustering(int startPoint, int endPoint);
	void inspection(int numPoint, char viewPoint);
	void inspection(char viewPoint, int startPoint, int endPoint);
	void print_vector(std::vector<Lidar_sample*> dataList);
};

