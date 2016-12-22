#ifndef __BOMB_H__
#define __BOMB_H__

#include "Object.h"

enum BombType
{
	LARGE,
	SMALL
};

class Bomb : public Object
{
public:
	Bomb();
	Bomb(Point pos, BombType type);
	~Bomb(){}

	void Display();

	void Move();

	void Boom(list<Object*>& lstBombs);
	
	bool IsDisappear();

protected:
	void CalculateSphere();
	
	BombType m_type;
	int m_timer;
};

#endif