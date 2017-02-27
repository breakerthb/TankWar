#ifndef __MAIN_TANK__
#define __MAIN_TANK__

#include "Tank.h"

class MainTank : public Tank
{
public:
	MainTank() : Tank()
	{
		m_pos.Set(300, 300);

		this->CalculateSphere();

		m_color = YELLOW;
		m_dir = Dir::UP;
		m_step = 4;
	}

	~MainTank(){}

	void SetDir(Dir dir);
	Dir GetDir()
	{
		return m_dir;
	}
	void Display();
	void Move();
	void Shoot(list<Object*>& lstBullets);
	void Boom(list<Object*>& lstBombs);

protected:
	void CalculateSphere();

	// 绘制坦克主体
	void DrawTankBody();
};

#endif