#pragma once
#include"configure.h"
#include <time.h>   
using uint32 = unsigned int;
class history
{
public:
	history();
	history(const std::string& xh, const std::string& phone, const std::string& rq);
	std::string formatInfols();//��ʽ������
public:
	// 
	std::string  xh;
	std::string phone;
	std::string rq;
};

