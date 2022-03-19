#pragma once
#include "BasicWidget.h"
#include"configure.h"
class Pushbutton :
    public BasicWidget
{
public:
    Pushbutton(const std::string& text = "button", int x = 0, int y = 0, int w = 100, int h = 30);
    void show() override;
    bool isin(); //�ж�����Ƿ��ڵ�ǰ��ť��
    bool isclick();//�ж�����Ƿ���
    void eventloop(const ExMessage& msg);//����¼�ѭ��
    void setBackgroundColor(COLORREF C);//���ð�ť��ɫ����
    void setCoverColor(COLORREF C);//���ð�ť�����ɫ
private:
    std::string m_text;
    ExMessage m_msg;
private:
    COLORREF normal_c= RGB(232, 232, 236);
    COLORREF cover_c=RED;
    COLORREF cur_c= RGB(232, 232, 236);
};

