#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "Graphic.h"

enum Dir { UP, DOWN, LEFT, RIGHT };

class Object
{
public:
	// 绘图
	virtual void Display() = 0;

	// 移动
	virtual void Move() = 0;

	// 判断是否消失
	virtual bool IsDisappear() = 0;

protected:
	// 计算势力范围
	virtual void CalculateSphere() = 0;

	// 位置
	Point m_pos;
	// 势力范围
	Rect m_rectSphere; 
	// 颜色
	COLORREF m_color;
	// 方向
	Dir m_dir;
	// 存在状态
	bool m_bDisappear;
	// 单次前进步长
	int m_step;
};

#endif