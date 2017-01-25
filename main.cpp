#pragma warning(disable:4996)

#include <iostream>
#include <conio.h>
#include <time.h>

#include <list>

#include "Graphic.h"
#include "MainTank.h"
#include "EnemyTank.h"
#include "Utils/Shape.h"

using namespace std;

#define MAX_TANKS 10

// Bullet list
list<Object*> lstMainTankBullets;

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

void main()
{
	srand((unsigned)time(NULL));

	Graphic::Create();

	MainTank mainTank;

	lstMainTankBullets.clear();
	lstBombs.clear();
	lstTanks.clear();

	for (int i = 0; i < MAX_TANKS; i++)
	{
		EnemyTank* p = new EnemyTank();
		lstTanks.push_back(p);
	}

	bool loop = true;
	bool skip = false;
	while (loop)
	{
		if (kbhit())
		{
			int key = getch();
			 
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
			cleardevice();

			CheckCrash();

			Graphic::DrawBattleGround();

			mainTank.Move();
			mainTank.Display();

			// Draw Tanks
			for (list<Tank*>::iterator it = lstTanks.begin(); it != lstTanks.end();)
			{
				(*it)->Move();

				if ((*it)->IsDisappear())
				{
					// Add a bomb
					(*it)->Boom(lstBombs);

					// Delete the tank
					delete *it;
					it = lstTanks.erase(it);
					continue;
				}

				(*it)->Display();

				it++;
			}

			// Draw Bullets
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

			// Draw Bombs
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

		Sleep(200);
	}
	
	// Destroy
	for (list<Tank*>::iterator it = lstTanks.begin(); it != lstTanks.end(); it++)
	{
		delete *it;
	}
	lstTanks.clear();

	for (list<Object*>::iterator it = lstMainTankBullets.begin(); it != lstMainTankBullets.end(); it++)
	{
		delete *it;
	}


	for (list<Object*>::iterator it = lstBombs.begin(); it != lstBombs.end(); it++)
	{
		delete *it;
	}
	lstBombs.clear();

	Graphic::Destroy();
}