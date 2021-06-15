#include "data_maneger.h"

#include "compers.h"


namespace fs = std::filesystem;
data_maneger::data_maneger()
{
	std::vector fileList(fs::directory_iterator("./Dev_Data/PC/"), {});
	fileList.size();
	for (int i = 1; i <= fileList.size(); i++)
	{
		dataList.push_back(new data_combin(i));
	}


}

data_maneger::~data_maneger()
{
	for (size_t i = 0; i < dataList.size(); i++)
	{
		delete dataList.at(i);
	}
}
