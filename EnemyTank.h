#ifndef __ENEMY_TANK__
#define __ENEMY_TANK__

#include "Tank.h"

class EnemyTank : public Tank
{
public:
	EnemyTank()
	{
		RandomTank();
	}

	~EnemyTank(){}

	void Display();
	void Move();

protected:
	void CalculateSphere();
	void RandomTank();
};

#endif