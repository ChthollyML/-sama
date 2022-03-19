#pragma once
#include"configure.h"
#include <time.h>   
using uint32 = unsigned int;
class Students
{
public:
	Students();
	Students(const std::string& name,uint32 cf, const std::string & phone,time_t rq);
	std::string formatInfo();//格式化数据
public:
	// 
	std::string name;
	uint32 cf; 
	uint32 xh;
    std::string phone;
	time_t rq;
};

