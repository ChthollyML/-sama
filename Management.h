#pragma once
#include "window.h"
#include<vector>
#include<string>
#include"Pushbutton.h"
#include"cunfang.h"
#include"history.h"
#include"Usersname.h"
#include <time.h>  
#include"Table.h"
class Management
{	
	enum Operator
	{
		Yonghu,
		Waimaiyuan1,
		Userswm1,
		Menu = 66,
		Waimaiyuan2,
		Tabletext,
		Userswm2,
	};
public:
	Management();
	void run();
	int menu();
	// 显示所有学生
	int  yonghu();
	// 添加
	int waimaiyuan1();
	// 删除
	int waimaiyuan2();
	//查找
	int guanliyuan1();
	int guanliyuan2();
	int Tabletxt();
	void drawBackground();
	void readFilels(const std::string& fileName);
	void saveFilels(const std::string& fileName);
	void readFile(const std::string& fileName);
	void saveFile(const std::string& fileName);
	void readFileUser(const std::string& fileName);
	void saveFileUser(const std::string& fileName);
	std::string gettime();
private:
	IMAGE m_bk;
	ExMessage m_msg;
	std::vector<Pushbutton*> menu_btns;
private://读取文件 保存消息
	std::string m_header;
	std::string m_headerls;
	std::vector<Students> vec_stu;
	std::vector<history> vec_lishi;
	std::vector<Usersname> vec_users;
private:
	bool YNGAI = FALSE;
	TCHAR T[20];
	TCHAR USER[30];
	TCHAR PWD[20];
	int cur = 0;
	int rest = 0;
	struct Ms
	{
		std::string name;
		uint32 cf = NULL;
		std::string phone;
		time_t rq = NULL;
	}; Ms waimai[10];
private:   //查看表格
	Table* m_showTable;
};
