#pragma warning(disable:4996)

#include <iostream>
#include <conio.h>
#include <time.h>

#include <list>

#include "Graphic.h"
#include "MainTank.h"
#include "EnemyTank.h"
#include "Utils/Shape.h"
#include "Setting.h"

using namespace std;

MainTank mainTank;

// Bullet list
list<Object*> lstMainTankBullets;
list<Object*> lstBullets;

// Bomb List
list<Object*> lstBombs;

// Tank list
list<Tank*> lstTanks;

void CheckCrash()
{
	for (list<Object*>::iterator it = lstMainTankBullets.begin(); it != lstMainTankBullets.end(); it++)
	{
		for (list<Tank*>::iterator itt = lstTanks.begin(); itt != lstTanks.end(); itt++)
		{
			if (Shape::CheckIntersect((*it)->GetSphere(), (*itt)->GetSphere()))
			{
				(*itt)->SetDisappear();
				(*it)->SetDisappear();
			}
		}
	}
}

void Init()
{
	srand((unsigned)time(NULL));

	Graphic::Create();
	
	lstMainTankBullets.clear();
	lstBullets.clear();
	lstBombs.clear();
	lstTanks.clear();
}

void Dispose()
{
	for (list<Tank*>::iterator it = lstTanks.begin(); it != lstTanks.end(); it++)
	{
		delete *it;
	}
	lstTanks.clear();

	for (list<Object*>::iterator it = lstMainTankBullets.begin(); it != lstMainTankBullets.end(); it++)
	{
		delete *it;
	}

	for (list<Object*>::iterator it = lstBullets.begin(); it != lstBullets.end(); it++)
	{
		delete *it;
	}
	lstBullets.clear();

	for (list<Object*>::iterator it = lstBombs.begin(); it != lstBombs.end(); it++)
	{
		delete *it;
	}
	lstBombs.clear();

	Graphic::Destroy();
}

void main()
{
	Init();

	bool loop = true;
	bool skip = false;
	while (loop)
	{
		if (kbhit())
		{
 			int key = getch();
			if (skip && key != 13)
			{
				continue;
			}

			switch (key)
			{
			// Up
			case 72:
				mainTank.SetDir(Dir::UP);
				break;
			// Down
			case 80: 
				mainTank.SetDir(Dir::DOWN);
				break;
			// Left
			case 75: 
				mainTank.SetDir(Dir::LEFT);
				break;
			// Right
			case 77: 
				mainTank.SetDir(Dir::RIGHT);
				break;
			case 224: // 方向键高8位
				break;
			// Esc
			case 27:
				loop = false;
				break;
			// Space
			case 32:
				mainTank.Shoot(lstMainTankBullets);
				break;
			// Enter
			case 13:
				if (skip)
					skip = false;
				else
					skip = true;
				break;
			default: 
				break;
			}
		}
		
		if (!skip)
		{
			// Draw Background
			cleardevice();
			Graphic::DrawBattleGround();
			Graphic::ShowScore();

			// New Game Level
			if (Setting::m_bNewLevel)
			{
				Setting::m_bNewLevel = false;

				Setting::NewGameLevel();

				Graphic::ShowGameLevel(Setting::GetGameLevel());

				for (int i = 0; i < Setting::GetTankNum(); i++)
				{
					EnemyTank* p = new EnemyTank();
					lstTanks.push_back(p);
				}

				// 设置暂停，按Enter开始
				skip = true;
				continue;
			}
			
			CheckCrash();
			
			mainTank.Move();
			mainTank.Display();

			/* Draw Tanks */
			for (list<Tank*>::iterator it = lstTanks.begin(); it != lstTanks.end();)
			{
				(*it)->Move();

				if ((*it)->IsDisappear())
				{
					Setting::TankDamaged();

					// Add a bomb
					(*it)->Boom(lstBombs);

					// Delete the tank
					delete *it;
					it = lstTanks.erase(it);
					continue;
				}

				(*it)->Display();

				if ((*it)->NeedShoot())
				{
					EnemyTank* p = (EnemyTank*)*it;
					p->Shoot(lstBullets);
				}
				it++;
			}

			/* Draw Bullets */
			for (list<Object*>::iterator it = lstMainTankBullets.begin(); it != lstMainTankBullets.end();)
			{
				(*it)->Move();

				if ((*it)->IsDisappear())
				{
					// Add a bomb
					(*it)->Boom(lstBombs);

					// Delete the bullet
					delete *it;
					it = lstMainTankBullets.erase(it);
					continue;
				}

				(*it)->Display();
				it++;
			}

			for (list<Object*>::iterator it = lstBullets.begin(); it != lstBullets.end();)
			{
				(*it)->Move();
			
				if ((*it)->IsDisappear())
				{
					// Add a bomb
					(*it)->Boom(lstBombs);

					// Delete the bullet
					delete *it;
					it = lstBullets.erase(it);
					continue;
				}

				(*it)->Display();
				it++;
			}

			/* Draw Bombs */
			for (list<Object*>::iterator it = lstBombs.begin(); it != lstBombs.end();)
			{
				(*it)->Move();

				if ((*it)->IsDisappear())
				{
					delete *it;
					it = lstBombs.erase(it);
					continue;
				}
				
				(*it)->Display();
				it++;
			}
		}

		Sleep(100);
	}
	
	// Destroy
	Dispose();
}