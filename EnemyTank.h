#ifndef __ENEMY_TANK__
#define __ENEMY_TANK__

#include "Tank.h"

#define MAX_STEP 10

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
	// 随机产生坦克方向 type： 1, 新方向必须与之前方向不同 2, 任意一个新方向
	void RandomDir(int type);

	int m_stepCnt;
};

#endif