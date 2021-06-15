#include "Pointcloud_handler.h"

#include "compers.h"


namespace fs = std::filesystem;

void Pointcloud_handler::slicing(int axis, int startPoint, int endPoint)
{
	vector<Lidar_sample*> above;
	vector<Lidar_sample*> below;

	for (size_t i = startPoint; i <= endPoint; i++)
	{
		dataList->dataList.at(i)->slicing(axis, &above, &below);
	}
	cout << "above" << endl;
	print_vector(above);
	cout << "below" << endl;
	print_vector(below);

}

void Pointcloud_handler::slicing(int numPoint, char axis)
{
	vector<Lidar_sample*> above;
	vector<Lidar_sample*> below;
	dataList->dataList.at(numPoint)->slicing(axis, &above, &below);
	cout << "above" << endl;
	print_vector(above);
	cout << "below" << endl;
	print_vector(below);


}

void Pointcloud_handler::clustering(int numPoint)
{

	vector<Lidar_sample*> sortVector;
	dataList->dataList.at(numPoint)->clustering(&sortVector);


	cout << "sortVector" << endl;
	print_vector(sortVector);


}

void Pointcloud_handler::clustering(int startPoint, int endPoint)
{

	vector<Lidar_sample*> sortVector;

	for (size_t i = startPoint; i < endPoint; i++)
	{
		dataList->dataList.at(i)->clustering(&sortVector);

	}
	sort(sortVector.begin(), sortVector.end(), comper_lidar_clustering);

	cout << "sortVector" << endl;
	print_vector(sortVector);
}

void Pointcloud_handler::inspection(int numPoint, char viewPoint)
{
	vector<Lidar_sample*> sortVector;
	dataList->dataList.at(numPoint)->inspection(viewPoint, &sortVector);

	cout << "sortVector" << endl;
	print_vector(sortVector);
}


void Pointcloud_handler::inspection(char viewPoint, int startPoint, int endPoint)
{

	vector<Lidar_sample*> sortVector;

	for (size_t i = startPoint; i < endPoint; i++)
	{
		dataList->dataList.at(i)->inspection(viewPoint, &sortVector);

	}


	switch (viewPoint)
	{
	case 'X':
		sort(sortVector.begin(), sortVector.end(), comper_lidar_byX);
		break;
	case 'Y':
		sort(sortVector.begin(), sortVector.end(), comper_lidar_byY);
		break;
	case 'Z':
		sort(sortVector.begin(), sortVector.end(), comper_lidar_byZ);
		break;
	}

	cout << "sortVector" << endl;
	print_vector(sortVector);
}

void Pointcloud_handler::print_vector(std::vector<Lidar_sample*> dataList)
{
	for (size_t i = 0; i < dataList.size(); i++)
	{
		cout << dataList.at(i)->X << "  " << dataList.at(i)->Y << "  " << dataList.at(i)->Z << endl;
	}
}



