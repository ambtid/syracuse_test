#pragma once
#include "data_maneger.h"
class motion_manager
{
public:
	data_maneger* data;
	
	std::vector<State>* stateMoves = nullptr;


	motion_manager(data_maneger* data) :data(data) { run_Motion_detection(); };
	void run_Motion_detection();


	void motion_velocity(double bounder, bool alarm = false, bool delete_file = false);


};

