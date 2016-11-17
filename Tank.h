#ifndef __TANK_H__
#define __TANK_H__

#include "Graphic.h"

enum Dir { UP, DOWN, LEFT, RIGHT };

class Tank
{
public:
	// 绘图
	virtual void Display() = 0;
	
	// 移动
	virtual void Move() = 0;
	
protected:
	int m_x;
	int m_y;
	COLORREF m_color;

	Dir m_dir;
	int m_step;
};



#endif