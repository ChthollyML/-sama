#pragma once
#include"configure.h"
class window
{
public:
		window(int w, int h, int flag);
		void setWindowTitle(const std::string&tilte);
		int exec();
		static int width();
		static int height();
		static void clear();
		static void beginDraw();
		static void flushDraw();
		static void endDraw();
		//按键操作
		//判断消息
		inline static bool hasMsg() { return ::peekmessage(&m_msg, EM_MOUSE | EM_KEY); }
		inline static const ExMessage& getMsg() { return m_msg; }
private:
	HWND m_handle;//窗口句柄
	inline static ExMessage m_msg;//消息
};
//一般中c++17前要定义一下静态
