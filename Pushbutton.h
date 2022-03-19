#pragma once
#include "BasicWidget.h"
#include"configure.h"
class Pushbutton :
    public BasicWidget
{
public:
    Pushbutton(const std::string& text = "button", int x = 0, int y = 0, int w = 100, int h = 30);
    void show() override;
    bool isin(); //判断鼠标是否在当前按钮上
    bool isclick();//判断鼠标是否点击
    void eventloop(const ExMessage& msg);//鼠标事件循环
    void setBackgroundColor(COLORREF C);//设置按钮颜色函数
    void setCoverColor(COLORREF C);//设置按钮点击颜色
private:
    std::string m_text;
    ExMessage m_msg;
private:
    COLORREF normal_c= RGB(232, 232, 236);
    COLORREF cover_c=RED;
    COLORREF cur_c= RGB(232, 232, 236);
};

