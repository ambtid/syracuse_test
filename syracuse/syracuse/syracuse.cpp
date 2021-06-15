// syracuse.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "data_maneger.h"
#include "data_combin.h"
#include "motion_manager.h"
#include "Pointcloud_handler.h"

data_maneger* dataMan;
void manege_one_point();

void manege_N_points();

void pointclud_handler();
void state_handler();


void main() {
Start:
	dataMan = new data_maneger();

	cout << "Wlecome to data maneger" << endl;
	cout << "to pointclud handler press 1" << endl << "for state handler press 2" << endl;
	int x;
	cin >> x;
	switch (x)
	{
	case 1:
		pointclud_handler();
		break;
	case 2:
		state_handler();
		break;
	default:
		break;
	}
	cout << "to do again press 1 for exit press 0" << endl;
	cin >> x;
	if (x == 1) goto Start;

	delete dataMan;
}



void manege_one_point()
{
	Pointcloud_handler p = Pointcloud_handler(dataMan);

	cout << "choose number of the point " << endl;
	int x;
	cin >> x;
	cout << "for Slicing press 1" << endl << "for Inspection press 2" << endl << "for  clustering press 3" << endl;
	int y;
	cin >> y;
	switch (x)
	{
	case 1:

		cout << "to slicing the data by axis X press X" << endl << "to slicing the data by axis Y press Y" << endl << "to slicing the data by axis Z press Z" << endl;
		char axis;
		cin >> axis;
		p.slicing(x, axis);
		break;
	case 2:
		cout << "to inspection the data from pointView X press X" << endl << "to inspection the data from pointView Y press Y" << endl << "to inspection the data from pointView Z press Z" << endl;

		cin >> axis;
		p.inspection(x, axis);
		break;

	case 3:
		p.clustering(x);
		break;
	default:
		break;
	}

}

void manege_N_points()
{
	Pointcloud_handler p = Pointcloud_handler(dataMan);

	cout << "choose start point " << endl;
	int start;
	cin >> start;
	cout << "choose end point " << endl;
	int end;
	cin >> end;
	cout << "for Slicing press 1" << endl << "for Inspection press 2" << endl << "for  clustering press 3" << endl;
	int x;
	cin >> x;
	switch (x)
	{
	case 1:

		cout << "to slicing the data by axis X press X" << endl << "to slicing the data by axis Y press Y" << endl << "to slicing the data by axis Z press Z" << endl;
		char axis;
		cin >> axis;
		p.slicing(axis, start, end);
		break;
	case 2:
		cout << "to inspection the data from pointView X press X" << endl << "to inspection the data from pointView Y press Y" << endl << "to inspection the data from pointView Z press Z" << endl;

		cin >> axis;
		p.inspection(axis, start, end);
		break;

	case 3:
		p.clustering(start, end);
		break;
	default:
		break;
	}

}

void pointclud_handler()
{


	cout << "to manage one point clude press 1 for N points press 2" << endl;
	int x;
	cin >> x;
	switch (x)
	{
	case 1:
		manege_one_point();
		break;
	case 2:
		manege_N_points();
		break;
	default:
		break;
	}
}

void state_handler()
{
	motion_manager moManeg = motion_manager(dataMan);
	moManeg.run_Motion_detection();
	cout << "to all the movment press 1" << endl << "to print all the movment above sum number press 2" << endl;
	int x;
	cin >> x;
	switch (x)
	{
	case 1:
		moManeg.motion_velocity(0);
		break;
	case 2:
		cout << "from which num do you want to see the movment?" << endl;
		int y;
		cin >> y;
		cout << "do you want alert when the movment is above this?  1 for yes 2 for NO" << endl;
		int z;
		cin >> z;
		cout << "do you want do delete the file if is across the limit 1 for yes 2 for NO" << endl;
		int m;
		cin >> m;
		moManeg.motion_velocity(y, (z == 1), (m == 1));
		break;
	default:
		break;
	}


}









