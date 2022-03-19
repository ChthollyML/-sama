#include "Pushbutton.h"

Pushbutton::Pushbutton(const std::string& text, int x, int y, int w, int h)
	:BasicWidget(w, y, w, h), m_text(text)
{

}

void Pushbutton::show()
{	
	setfillcolor(cur_c);
	::fillroundrect(m_x, m_y, m_x + m_w, m_y + m_h, 10, 10);
	//绘制按钮
	settextcolor(BLACK);
	//文字居中
	int tx = m_x + (m_w - textwidth(m_text.c_str())) / 2;
	int ty = m_y + (m_h - textheight(m_text.c_str())) / 2;
	::outtextxy(tx, ty, m_text.c_str());
}

bool Pushbutton::isin()
{
	if (m_msg.x >= m_x && m_msg.x < m_x + m_w && m_msg.y >= m_y && m_msg.y < m_y + m_h)
	{
		return true;
	}
	return false;
}

bool Pushbutton::isclick()
{
	if (isin()) {
		if (m_msg.message == WM_LBUTTONDOWN) {
			return true;
		}
	}
	return false;
}

void Pushbutton::eventloop(const ExMessage& msg)
{
	m_msg = msg;
	//判断当前鼠标在不在按钮上（改色过程）
	if(!isin()){
		cur_c = normal_c;
				}
	else {
		cur_c = cover_c;
		}
}

void Pushbutton::setBackgroundColor(COLORREF C)
{
	cur_c = C;
}

void Pushbutton::setCoverColor(COLORREF C)
{
	cur_c=C;
}
