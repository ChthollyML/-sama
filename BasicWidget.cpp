#include "BasicWidget.h"
#include "BasicWidget.h"

BasicWidget::BasicWidget(int x, int y, int w, int h)
    :m_x(x), m_y(y), m_w(w), m_h(h)
{

}

int BasicWidget::width()
{
    return m_w;
}

int BasicWidget::height()
{
    return m_h;
}

void BasicWidget::setFixedSize(int w, int h)
{
    this->m_w= w;
    this->m_h = h;
}

int BasicWidget::x()
{
    return m_x;
}

int BasicWidget::y()
{
    return m_y;
}

void BasicWidget::move(int x, int y)
{
    this->m_x = x;
    this->m_y = y;
}
