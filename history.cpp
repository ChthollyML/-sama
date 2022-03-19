#include "history.h"
#include<sstream>
#include <time.h>   
history::history()
{
}

history::history(const std::string& xh, const std::string& phone, const std::string& rq)
	:xh(xh), phone(phone), rq(rq)
{

}
std::string history::formatInfols()
{
	std::stringstream ss;
	ss << xh << "\t" << phone << "\t" << rq << std::endl;
	return ss.str();
}
