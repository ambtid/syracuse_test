#include "motion_manager.h"

void motion_manager::run_Motion_detection()
{
	stateMoves = new vector<State>{ data->dataList.size() };
	for (size_t i = 0; i < data->dataList.size() - 1; i++)
	{
		double R = abs(data->dataList[i]->state->R - data->dataList[i + 1]->state->R) * 5;
		double H = abs(data->dataList[i]->state->H - data->dataList[i + 1]->state->H) * 5;
		double slew = abs(data->dataList[i]->state->slew - data->dataList[i + 1]->state->slew) * 5;
		stateMoves->push_back(State(R, H, slew));

	}



}

void motion_manager::motion_velocity(double bounder, bool alarm , bool delete_file )
{
	for (size_t i = 0; i < stateMoves->size(); i++)
	{

		if (stateMoves->at(i).R > bounder || stateMoves->at(i).H > bounder || stateMoves->at(i).slew > bounder)
		{
			std::cout << "moving at frame: " << i << "at speed " << stateMoves->at(i).R << " " << stateMoves->at(i).H << " " << stateMoves->at(i).slew << std::endl;
			if (alarm) {

				cout << "warning the speeed is out of range delete ";
				if (delete_file)
					data->dataList.erase(data->dataList.begin() + i);
			}
		}
	}

}