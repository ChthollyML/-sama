#pragma once
#include"configure.h"
class Usersname
{
public:
	Usersname();
	Usersname(const std::string& username, const std::string& passwords);
	std::string formatInfols();//格式化数据
public:
	std::string username;
	std::string passwords;
};

