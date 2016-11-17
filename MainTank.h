#ifndef __MAIN_TANK__
#define __MAIN_TANK__

#include "Tank.h"

class MainTank : public Tank
{
public:
	MainTank()
	{
		m_x = 300;
		m_y = 300;
		m_color = WHITE;
		m_dir = Dir::UP;
		m_step = 2;
	}

	~MainTank(){}

	// 设置行驶方向
	void SetDir(Dir dir);
	void Display();
	void Move();

protected:
	// 绘制坦克主体
	void DrawTankBody(int style);
};

#endif