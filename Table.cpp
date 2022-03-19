#include "Table.h"
#include<iostream>
Table::Table(int row, int col)
	:BasicWidget(0,0,0,0)
	,m_cols(col),m_rows(row),m_curPage(0),m_maxPage(0),m_extraData(0)
{

}

void Table::setRow(int row)
{
	m_rows = row;
}

void Table::setCow(int col)
{
	m_cols = col;
}

void Table::setHeader(const std::string& header)
{
	m_header = header;
	m_cols=std::count(m_header.begin(), m_header.end(), '\t')+1;
	//求出文字高度与宽度
	m_tw= ::textwidth("11111111111");
	m_th= ::textheight(m_header.c_str());
	 //格子宽度与高度
	m_gzw = m_tw+10;
	 m_gzh = m_th+10;
	 m_w = m_gzw * m_cols;
	 m_h = m_gzh * m_rows;
}

void Table::insertData(const std::string& data)
{
	m_datas.push_back(data);
	updatePage();
}

void Table::show()
{
	drawHeader();
	drawTableGrid();
	drawTableData();
}

void Table::drawTableGrid()
{	
	//确定表格有多少行，多少列
	//画横线
	setlinestyle(PS_SOLID, 2);
	for (size_t i = 0; i < m_rows + 1; i++) {
		line(m_x, m_y + i * m_gzh, m_x + m_cols * m_gzw, m_y + i * m_gzh);
	}
	//画竖线
	for (size_t i = 0; i < m_cols + 1; i++) {
		line(m_x + i * m_gzw, m_y, m_x + i * m_gzw, m_y + m_rows * m_gzh);
	}
	setlinestyle(PS_SOLID, 1);
}

void Table::drawTableData()//历史记录分页功能还没搞
{
	
	//判断
	for (size_t i = 0; i < m_datas.size(); i++)  //行
	{
		const auto& line_data = split(m_datas[i],'\t');   //列
		for (size_t k = 0; k < line_data.size(); k++) {
			int tx = m_x + k*m_gzw+(m_gzw-::textwidth(line_data[k].c_str())) / 2;
			int ty = m_y + i * m_gzh+5;
			outtextxy(tx,ty, line_data[k].c_str());
		}
	}
}

void Table::drawHeader()
{
	setlinestyle(PS_SOLID, 3);
	::rectangle(m_x, m_y - 30, m_x + m_w, m_y);
	for (size_t i = 0; i < m_cols; i++)
	{
		line(m_x+i*m_gzw, m_y - 30, m_x+i*m_gzw, m_y);
	}
	setlinestyle(PS_SOLID, 1);
	//分割表头数据
	auto headers = split(m_header,'\t');
	for (size_t i = 0;i<headers.size();i++) {
		int spaceH = (m_gzw - ::textwidth(headers[i].c_str()))/2;
		int spaceV = (30 - ::textheight(headers[i].c_str()) )/ 2;
		outtextxy(m_x + i * m_gzw+spaceH, m_y - m_gzh+spaceV, headers[i].c_str());
	}
}

std::vector<std::string> Table::split(std::string str, char separator)
{
	std::vector<std::string> res;
	for (size_t pos = 0;pos!=std::string::npos;) {
		//查找指定分隔符的位置
		pos= str.find(separator);
		//取出前字符串
		res.push_back(str.substr(0,pos));
		//把剩下的字符保存起来,删去前面部分
		str = std::string(str.c_str()+pos+1);
	}
	return res;
}

std::vector<std::string> Table::splituser(std::string str, char separator)//专门copy一下给用户名那边用
{
	std::vector<std::string> res;
	//"1 - 1\t1\t15057573995\t1644375639"
	str += '#';
	for (size_t pos = 0; pos != std::string::npos;) {
		//查找指定分隔符的位置
		pos = str.find(separator);
		//取出前字符串
		res.push_back(str.substr(0, pos));
		//把剩下的字符保存起来,删去前面部分
		str = std::string(str.c_str() + pos + 1);
	}
	return res;
}
void Table::updatePage()//历史记录分页功能还没搞
{	
	//更新最大页数
	if (m_rows >= m_datas.size()) {
		m_maxPage = 0;
		m_extraData = m_datas.size();
	}
	else {
		m_maxPage = m_datas.size() / m_rows;
		m_extraData = m_datas.size() % m_rows;
	}

}
