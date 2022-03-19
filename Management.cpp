#include "Management.h"
#include"cunfang.h"
#include"history.h"
#include"Table.h"
#include"Usersname.h"
#include<conio.h>
#include<iostream>
#include<fstream>
#include<algorithm>
#include<sstream>
#include<string>
#include <graphics.h>
#include <time.h>   
#pragma warning(disable:4996)
using namespace std;
Students stu;
history lishi;
Usersname users;
int MessageBox(
	HWND hWnd,          
	LPCTSTR lpText,     
	LPCTSTR lpCaption,  
	UINT uType         
);
Management::Management()
{
	readFile("./xx/������.txt");
	readFilels("./xx/ȡ����ʷ.txt");
	readFileUser("./xx/����Ա.txt");
	::loadimage(&m_bk, "./img/bk1.jpg",window::width(), window::height());
	settextstyle(20, 0, "����");
	setlinecolor(BLACK);
	//�����水ť��ʼ��
	menu_btns.push_back(new Pushbutton("�û�"));
	menu_btns.push_back(new Pushbutton("����Ա"));
	menu_btns.push_back(new Pushbutton("����Ա����"));
	menu_btns.push_back(new Pushbutton("�˳�ϵͳ"));
	for (int i = 0; i < 4; i++)
	{	//��С����
		menu_btns[i]->setFixedSize(250, 50);
		//��ť��λ��
		int bx = (window::width() - menu_btns[i]->width()) / 2;//ˮƽ����
		int bt = (window::height() - menu_btns.size() * menu_btns[i]->height()) / 2+180;//��ֱλ��
		int by =bt+i * menu_btns[i]->height();
		menu_btns[i]->move(bx,by);
	}
	menu_btns.push_back(new Pushbutton("1-1"));
	menu_btns.push_back(new Pushbutton("1-2"));
	menu_btns.push_back(new Pushbutton("1-3"));
	menu_btns.push_back(new Pushbutton("2-1"));
	menu_btns.push_back(new Pushbutton("2-2"));
	menu_btns.push_back(new Pushbutton("2-3"));
	menu_btns.push_back(new Pushbutton("3-1"));
	menu_btns.push_back(new Pushbutton("3-2"));
	menu_btns.push_back(new Pushbutton("3-3"));
	for (int i = 4; i < 13; i++)
	{	//��С����
		menu_btns[i]->setFixedSize(100, 100);
		//��ť��λ��
		int bx = 270+(i-4)%3*150;//ˮƽ����
		int by = 175 + (i-4)/3  * 150;;//��ֱλ��
		menu_btns[i]->move(bx, by);
	}
	menu_btns.push_back(new Pushbutton("ȡ��"));
	menu_btns.push_back(new Pushbutton("��ʷȡ��"));
	menu_btns.push_back(new Pushbutton("���"));
	menu_btns.push_back(new Pushbutton("�޸�����"));
	menu_btns.push_back(new Pushbutton("�չ�"));
	menu_btns.push_back(new Pushbutton("�Ѵ��"));
	menu_btns.push_back(new Pushbutton("�Ѵ�����12hδȡ��"));
	menu_btns.push_back(new Pushbutton("��������"));
	menu_btns.push_back(new Pushbutton("���ڲ����"));
	menu_btns.push_back(new Pushbutton("����������"));
	menu_btns.push_back(new Pushbutton("����"));
	for (int i = 13; i < 16; i++) {
		menu_btns[i]->setFixedSize(250, 50);
		int bx = (window::width() - menu_btns[i]->width()) / 2;//ˮƽ����
		int bt = (window::height() - menu_btns.size() * menu_btns[i]->height()) / 2 + 250+100*(i-12);//��ֱλ��
		menu_btns[i]->move(bx, bt);
	}
	menu_btns[16]->setFixedSize(200, 50);
	menu_btns[16]->move(0, 25);
	for (int i = 17; i < 20; i++) {
		menu_btns[i]->setFixedSize(200, 50);
		int bx = 250 + (i - 17) * 200;//ˮƽ����
		menu_btns[i]->move(bx, 0);
	}
	for (int i = 20; i < 22; i++) {
		menu_btns[i]->setFixedSize(200, 80);
		menu_btns[i]->move(680, 200 + (i - 20) * 150);
	}
	for (int i = 22; i < 24; i++) {
		menu_btns[i]->setFixedSize(150, 50);
		menu_btns[i]->move(750, 500+(i-22)*50);
	}
	//��ʼ�����
	m_showTable = new Table;
	m_showTable->setRow(16);
	m_showTable->setHeader(m_headerls);
	//������
	m_showTable->move((window::width()-m_showTable->width())/2, 100);
	for (auto& val : vec_lishi) {
		m_showTable->insertData(val.formatInfols());
	}
}
void Management::run()
{   //��ȡ�˵��ķ���ֵ
	int op = Menu;
	int tt = 0;
	window::beginDraw();
	while (true) {
		window::clear();
		drawBackground();
		if (window::hasMsg()) {
			m_msg=window::getMsg();
		}
		switch (op)
		{
		case Menu:
				op = menu();
				break;
		case Management::Yonghu:
			op=yonghu();
			break;
		case Management::Waimaiyuan1:
			op=waimaiyuan1();
			break;
		case Management::Userswm1:
			op=guanliyuan2();
			break;
		case Management::Waimaiyuan2:
			op=waimaiyuan2();
			break;
		case Management::Tabletext:
			op=Tabletxt();
			break;
		case Management::Userswm2:
			op=guanliyuan1();
			break;
		default:
			exit(666);
			break;
		}
		window::flushDraw();
	} 
	window::endDraw();
}

int Management::menu()
{
	cur = 0;//���ù���Ա����ĳ�ʼ����չʾ
	::loadimage(&m_bk, "./img/bk1.jpg", window::width(), window::height());
	for (int i = 0; i < 4; i++)
	{
		menu_btns[i]->show();
		menu_btns[i]->eventloop(m_msg);
		if (menu_btns[i]->isclick())
		{
			if (i == 2) {
				InputBox(USER, 30, _T("�������û��������룬�м���#�Ÿ���"));
				if (strlen(USER) == 0) {
					HWND wnd = GetHWnd();
					MessageBox(wnd, "�û������������", "��ʾ", MB_OK | MB_ICONWARNING);
					return  Menu;
				}
			}
			return i;
		}
	
	}
	return Menu;
}

int  Management::yonghu()
{
	if (YNGAI==TRUE) {
		cout << "�����һ��" << endl;
		auto tttt = vec_lishi.back();
		m_showTable->insertData(tttt.formatInfols());
		YNGAI = FALSE;
	}
	TCHAR s[20];
	::loadimage(&m_bk, "./img/bk2.jpg", window::width(), window::height());
	drawBackground();
	for (int i = 13; i<14; i++)
	 {	menu_btns[i]->show();
		menu_btns[i]->eventloop(m_msg);
		if (menu_btns[i]->isclick())
		{
			int t = 0;
				int p = 0;
				string qcm;
			InputBox(s, 20, _T("���������ȡ����������ĵ绰����"));
			for (int j = strlen(s) - 4; j < strlen(s); j++)  qcm+=s[j];
			for (int i = 0; i < 9; i++) {
				string q="";
				for (int j= waimai[i].phone.length() - 4; j < waimai[i].phone.length(); j++) q += waimai[i].phone[j];
				if ( q== s||waimai[i].phone==s) {
					t++;
					p = i;
				}
			}
			if (t == 0) {
				HWND wnd = GetHWnd();
				MessageBox(wnd, "δ���ҵ�������������ȷ������ȡ����������ȷ", "��ʾ", MB_OK | MB_ICONWARNING);
			}
			else if (strlen(s) == 0) {
				HWND wnd = GetHWnd();
				MessageBox(wnd, "ȡ���벻��Ϊ��", "��ʾ", MB_OK | MB_ICONWARNING);
			}
			else if (t == 1) {
				HWND wnd = GetHWnd();
				char* kk = waimai[p].name.data();
				LPCSTR tt = kk;
				MessageBox(wnd, tt,"���������ڸ��������У������·�ȷ��ȡ��", MB_OK | MB_ICONWARNING);
					if (IDOK) {
						waimai[p].cf = 0;
						waimai[p].phone = "0";
						waimai[p].rq = 0;
						lishi.xh = waimai[p].name;
						lishi.phone = qcm;
						lishi.rq = gettime();
						vec_lishi.push_back(lishi);
						YNGAI = TRUE;
						MessageBox(wnd,"ȡ�ͺ���ر��ڲ����","��ʾ", MB_OK | MB_ICONWARNING);
					}
			}
			else if (t > 1&&strlen(s)!=11) {
				HWND wnd = GetHWnd();
				MessageBox(wnd, "ȡ�����ظ��������������ĵ绰����ȡ������", "��ʾ", MB_OK | MB_ICONWARNING);
			}
			else if (t > 1 && strlen(s) == 11) {
				HWND wnd = GetHWnd();
				char* kk = waimai[p].name.data();
				LPCSTR tt = kk;
				MessageBox(wnd, tt, "���������ڸ��������У������·�ȷ��ȡ��", MB_OK | MB_ICONWARNING);
				if (IDOK) {
					waimai[p].cf = 0;
					waimai[p].phone = "0";
					waimai[p].rq = 0;
					lishi.xh = waimai[p].name;
					lishi.phone = qcm;
					lishi.rq = gettime();
					vec_lishi.push_back(lishi);
					YNGAI = TRUE;
					MessageBox(wnd, "ȡ�ͺ���ر��ڲ����", "��ʾ", MB_OK | MB_ICONWARNING);
					MessageBox(wnd,"�����ж���������������У���������ȡ������", "��ʾ", MB_OK | MB_ICONWARNING);
				}
			}
		}
	}
	for (int i = 14; i <= 14; i++) {
		menu_btns[i]->show();
		menu_btns[i]->eventloop(m_msg);
		if (menu_btns[i]->isclick()) return 68;
	}
	for (int i = 22; i <= 22; i++) {
		menu_btns[i]->show();
		menu_btns[i]->eventloop(m_msg);
		if (menu_btns[i]->isclick()) return Menu;
	}
	saveFilels("./xx/ȡ����ʷ.txt");
	saveFile("./xx/������.txt");
	return 0;
}

int Management::waimaiyuan1()
{
	::loadimage(&m_bk, "./img/bk3.jpg", window::width(), window::height());
	drawBackground();
	for (int i = 15; i <= 15; i++)
	{
		menu_btns[i]->show();
		menu_btns[i]->eventloop(m_msg);
		if (menu_btns[i]->isclick()) {
			InputBox(T, 20, _T("������ȡ�ͺ���"));
			if (strlen(T) == 11) {
				return 67;
			}
			else {
				HWND wnd = GetHWnd();
				MessageBox(wnd, "��������ȷ�ĵ绰����", "��ʾ", MB_OK | MB_ICONWARNING);
			}
		}
	}
	for (int i = 22; i <= 22; i++) {
		menu_btns[i]->show();
		menu_btns[i]->eventloop(m_msg);
		if (menu_btns[i]->isclick()) return Menu;
	}
	return 1;
}
	
int Management::waimaiyuan2()
{
	::loadimage(&m_bk, "./img/bk3.jpg", window::width(), window::height());
	drawBackground();
	for (int i = 4; i < 13; i++)
	{
		if (waimai[i - 4].cf == 0) {
			rest++;
			menu_btns[i]->setCoverColor(RGB(232, 232, 236));
			menu_btns[i]->show();
			menu_btns[i]->eventloop(m_msg);
			if (menu_btns[i]->isclick())
			{
				waimai[i - 4].phone = T;
				waimai[i - 4].cf = 1;
				waimai[i - 4].rq = time(NULL);
				HWND wnd = GetHWnd();
				MessageBox(wnd, "�����Ϻ���ر�������", "��ʾ", MB_OK | MB_ICONWARNING);
				saveFile("./xx/������.txt");
				if (IDOK) return 1;
			}
		}
	}
	if (rest == 0) {
		HWND wnd = GetHWnd();
		MessageBox(wnd, "����û�п����������", "��ʾ", MB_OK | MB_ICONWARNING);
		if (IDOK) return 1;
	}
	for (int i = 23; i <= 23; i++) {
		menu_btns[i]->show();
		menu_btns[i]->eventloop(m_msg);
		if (menu_btns[i]->isclick()) return 1;
	}
	return 67;
}

int Management::guanliyuan1()
{
	::loadimage(&m_bk, "./img/bk4.jpg", window::width(), window::height());
	drawBackground();
	for (int i = 20; i <= 20; i++)
	{
		menu_btns[i]->show();
		menu_btns[i]->eventloop(m_msg);
		if (menu_btns[i]->isclick()) {
			HWND wnd = GetHWnd();
			MessageBox(wnd, "�ù����Ѵ�", "��ʾ", MB_OK | MB_ICONWARNING);
			return 2;
		}
	}
	for (int i = 21; i <= 21; i++)
	{
		menu_btns[i]->show();
		menu_btns[i]->eventloop(m_msg);
		if (menu_btns[i]->isclick()) {
			HWND wnd = GetHWnd();
			MessageBox(wnd, "�ù����Ѵ�", "��ʾ", MB_OK | MB_ICONWARNING);
			return 2;
		}
	}
	menu_btns[23]->show();
	menu_btns[23]->eventloop(m_msg);
	if (menu_btns[23]->isclick()) {
		return 2;
	}
	return 69;
}

int Management::guanliyuan2()
{
	bool flag=TRUE;
	bool flag1= TRUE;
	string name;
	int t = 0;
	fstream read("./xx/����Ա.txt", ios::in);
	while (!read.eof()) {
		TCHAR data[1024];
		read.getline(data, 1024);
		stringstream ss(data);	
		ss >> data;
		 flag = TRUE;
		const auto shurudata = Table::splituser(USER, '#');
		const auto namedata = Table::splituser(data, '#');
		for (size_t k = 0; k < min(namedata.size(),shurudata.size()); k++) {
			if(strcmp(shurudata[k].c_str(),namedata[k].c_str())!=0) {
				 flag = FALSE;
					break;
																	}
																			}
		if (flag == TRUE) { name = namedata[0].c_str(); break; }
		t++;
						}
	if (flag == FALSE||strlen(USER)==1) {
		HWND wnd = GetHWnd();
		MessageBox(wnd, "�û������������", "��ʾ", MB_OK | MB_ICONWARNING);
		return  Menu; }
	read.close();
	::loadimage(&m_bk, "./img/bk4.jpg", window::width(), window::height());
	drawBackground();
	TCHAR s[20];
	time_t now = time(NULL);
	for (int i = 17; i <= 17; i++) {
		menu_btns[i]->show();
		menu_btns[i]->eventloop(m_msg);
		if (menu_btns[i]->isclick()) {
			cur = 1;
		}
	}
	for (int i = 18; i <= 18; i++) {
		menu_btns[i]->show();
		menu_btns[i]->eventloop(m_msg);
		if (menu_btns[i]->isclick()) {
			cur = 2;
		}
	}
	for (int i = 19; i <= 19; i++) {
		menu_btns[i]->show();
		menu_btns[i]->eventloop(m_msg);
		if (menu_btns[i]->isclick()) {
			cur = 3;
		}
	}
	for (int j = 4; j < 13; j++) {
		if (waimai[j - 4].cf == 0) menu_btns[j]->setCoverColor(RGB(232, 232, 236));
		if (waimai[j - 4].cf == 1 && (difftime(now, waimai[j - 4].rq) < 43200)) menu_btns[j]->setCoverColor(BLUE);
		else if(waimai[j - 4].cf == 1 && (difftime(now, waimai[j - 4].rq) >=43200))menu_btns[j]->setCoverColor(RED);
	}
	for (int j = 4; j < 13; j++)
	{
		if (cur == 0) {
			menu_btns[j]->show();
			menu_btns[j]->eventloop(m_msg);
			if (menu_btns[j]->isclick()) {
				return 69;
			}
		}
		if (waimai[j - 4].cf == 0&&cur==1) {
			menu_btns[j]->show();
			menu_btns[j]->eventloop(m_msg);
			if (menu_btns[j]->isclick()) {
				return 69;
			}
		}
		if (waimai[j - 4].cf == 1 && (difftime(now, waimai[j - 4].rq)<43200)&&cur==2 ) {
				menu_btns[j]->show();
				menu_btns[j]->eventloop(m_msg);
				if (menu_btns[j]->isclick()) {
					return 69;
				}
			}
		if (waimai[j - 4].cf == 1 && (difftime(now, waimai[j - 4].rq) > 43200)&&cur==3) {
			menu_btns[j]->show();
			menu_btns[j]->eventloop(m_msg);
			if (menu_btns[j]->isclick()) {
				return 69;
			}
		}
	}
	for (int i = 16; i <= 16; i++) {
		menu_btns[i]->show();
		menu_btns[i]->eventloop(m_msg);
		if (menu_btns[i]->isclick()) {
			InputBox(PWD, 20, _T("��������ĺ������"));
			//find(vec_users.begin(), vec_users.end(),name.c_str())��֪���в���̫����;
			if (strlen(PWD) != 0) {
				for (int i = 0; i < vec_users.size(); i++) {
					if (vec_users[i].username == name.c_str())  vec_users[i].passwords = PWD;
				}
				saveFileUser("./xx/����Ա.txt");
				HWND wnd = GetHWnd();
				MessageBox(wnd, "�����޸ĳɹ��������µ�¼", "��ʾ", MB_OK | MB_ICONWARNING);
				return  Menu;
			}
			else {
				HWND wnd = GetHWnd();
				MessageBox(wnd, "�����벻��Ϊ��", "��ʾ", MB_OK | MB_ICONWARNING);
			}
		}
	}
	for (int i = 22; i <= 22; i++) {
		menu_btns[i]->show();
		menu_btns[i]->eventloop(m_msg);
		if (menu_btns[i]->isclick()) return Menu;
	}
	outtextxy(0, 0, "��ǰ�û���Ϊ��");
	int x = ::textwidth("��ǰ�û���Ϊ��");
	outtextxy(x, 0, name.c_str());
	return 2;
}
int Management::Tabletxt()
{
	::loadimage(&m_bk, "./img/bk5.jpg", window::width(), window::height());
	drawBackground();
	m_showTable->show();
	menu_btns[23]->show();
	menu_btns[23]->eventloop(m_msg);
	if (menu_btns[23]->isclick()) { 
			return 0; 
		}
	return 68;
}

void Management::drawBackground()
{
	::putimage(0, 0, &m_bk);
}

void Management::readFilels(const std::string& fileName)
{
	fstream read(fileName, ios::in);
	if (!read.is_open()) {
		return;
	}
	//��ȡ��ͷ
	char buf[1024] = { 0 };
	read.getline(buf, 1024);
	m_headerls = buf;
	//��ȡ����
	while (!read.eof()) {
		char datals[1024] = { 0 };
		read.getline(datals, 1024);
		//��������,��ʽ����ȡ
		if (strlen(datals) == 0) break;
		//����ÿ������(txt���ļ�������ˣ�û�������ˣ�
		stringstream ss(datals);
			ss >> lishi.xh >> lishi.phone >> lishi.rq;
			vec_lishi.push_back(lishi);
	}
	read.close();
}

void Management::readFile(const std::string& fileName)
{
	fstream read(fileName, ios::in);
	if (!read.is_open()) {

		return;
	}
	//��ȡ��ͷ
	char buf[1024] = { 0 };
	read.getline(buf, 1024);
	m_header = buf;
	//��ȡ����
	int i = 0;
	while (!read.eof()) {
		char data[1024] = { 0 };
		read.getline(data, 1024);
		//��������,��ʽ����ȡ
		if (strlen(data) == 0) break;
		//����ÿ������(txt���ļ�������ˣ�û�������ˣ�
		stringstream ss(data);
		ss >> stu.name >> stu.cf >> stu.phone>>stu.rq;
		waimai[i].name = stu.name;
		waimai[i].cf = stu.cf;
		waimai[i].phone = stu.phone;
		waimai[i].rq = stu.rq;
		i++;
		vec_stu.push_back(stu);
	}
	read.close();
}
void Management::saveFilels(const std::string& fileName)
{
	fstream write(fileName, ios::out | ios::trunc);
	if (!write.is_open()) {
		cerr << fileName << "file open failed" << endl;
		return;
	}
	string KT = m_headerls + "\n";
	write.write(KT.c_str(), KT.size());
	//д����
	for (auto& val : vec_lishi) {
		std::string info = val.formatInfols() ;
		write.write(info.c_str(), info.size());
	}
	write.close();
}

void Management::saveFile(const std::string& fileName)
{
	fstream write(fileName, ios::out | ios::trunc);
	if (!write.is_open()) {
		cerr << fileName << "file open failed" << endl;
		return;
	}
	string KT = m_header + "\n";
	write.write(KT.c_str(),KT.size());
	//д����
	for (int i = 0; i < 9;i++) {
		std::string info = waimai[i].name + '\t' + to_string(waimai[i].cf) + '\t' + waimai[i].phone + '\t'+to_string(waimai[i].rq)+'\n';
		write.write(info.c_str(),info.size());
	}
	write.close();
}

void Management::readFileUser(const std::string& fileName)
{
	fstream read("./xx/����Ա.txt", ios::in);
	while (!read.eof()) {
		TCHAR data[1024];
		read.getline(data, 1024);
		if (strlen(data) == 1) break;
		stringstream ss(data);
		ss >> data;
		const auto namedata = Table::splituser(data,'#');
		users.username = namedata[0].c_str();
		users.passwords = namedata[1].c_str();
		vec_users.push_back(users);
	}
	read.close();
}

void Management::saveFileUser(const std::string& fileName)
{
	fstream write(fileName, ios::out | ios::trunc);
	if (!write.is_open()) {
		cerr << fileName << "file open failed" << endl;
		return;
	}
	//д����
	for (auto& val : vec_users) {
		std::string info = val.formatInfols();
		write.write(info.c_str(), info.size());
	}
	write.close();
}

std::string Management::gettime()
{
	string str;
	time_t tval;
	struct tm* now;
	tval = time(NULL);
	now = localtime(&tval);
	str =to_string(now->tm_mon + 1) + "��" + to_string(now->tm_mday) + "��"+ to_string(now->tm_hour)+"ʱ";
	return str.c_str();
}
  

