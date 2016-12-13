#ifndef __TANK_H__
#define __TANK_H__

#include "Object.h"

#include <list>

using namespace std;

class Tank : public Object
{
public:
	Tank()
	{
		m_pos.Set(300, 300);

		this->CalculateSphere();

		m_color = YELLOW;
		m_dir = Dir::UP;
		m_step = 4;

		m_bDisappear = false;
	}

	~Tank(){}

	void Display()
	{
		// Display
	}
	
	void Move()
	{
		// Move
	}

	// 射击
	void Shoot(list<Object*>& lstBullets)
	{
		// Shoot
	}

	bool IsDisappear()
	{
		return m_bDisappear;
	}
	
protected:
	void CalculateSphere()
	{
		// Calculate Sphere
	}
};

#endif