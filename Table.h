#pragma once
#include"configure.h"
#include "BasicWidget.h"
#include<vector>
class Table :
    public BasicWidget
{
public:
    Table(int row = 0, int col = 0);
    void setRow(int row);
    void setCow(int col);
    void setHeader(const std::string& header);
    void insertData(const std::string& data);
    void show();
    void drawTableGrid();
    void drawTableData();
    void drawHeader();
    static std::vector<std::string> split(std::string str, char separator);
    static std::vector<std::string> splituser(std::string str, char separator);
private:
    int m_rows;
    int m_cols;
    //格子的宽高
    int m_gzw;
    int m_gzh;
    //文字的宽高
    int m_tw;
    int m_th;
    std::string m_header;
    std::vector<std::string> m_datas;
    void updatePage();

private:
    int m_curPage;//当前页
    int m_maxPage;//最大页数
    int m_extraData;//最后一页剩余多少数据


};

