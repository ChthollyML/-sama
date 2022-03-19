// hanjiaruanjian.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<graphics.h>
#include"Management.h"
#include"window.h"
#include"table.h"
using namespace std;
int main()
{
    window w(960,640,EW_SHOWCONSOLE);
    w.setWindowTitle("校园外卖柜系统");
    Management m;
    m.run();
    return w.exec();
}

