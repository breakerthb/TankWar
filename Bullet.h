#pragma once

#include "Object.h"

class Bullet : public Object
{
public:
	Bullet();
	Bullet(Point pos, Dir dir, COLORREF color);
	~Bullet();

	void Display();

	void Move();

	bool IsDisappear()
	{
		return m_bDisappear;
	}

protected:
	void CalculateSphere();
};

