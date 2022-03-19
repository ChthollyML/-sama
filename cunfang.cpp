#include "cunfang.h"
#include<sstream>
#include <time.h>   

Students::Students()
{
}

Students::Students(const std::string& name, uint32 cf, const std::string& phone,time_t rq)
//初始化参数列表 
	:name(name),cf(cf),phone(phone),rq(rq)
{
	
}
std::string Students::formatInfo()
{
	
	std::stringstream ss;
	ss << name << "\t"  << cf  <<"\t" <<phone <<"\t"<<rq<< std::endl;
	return ss.str();
}
