#pragma warning(disable:4996)

#include <iostream>
#include <conio.h>
#include <time.h>

#include <list>

#include "Graphic.h"
#include "MainTank.h"
#include "EnemyTank.h"

using namespace std;

#define MAX_TANKS 10

void main()
{
	srand((unsigned)time(NULL));

	Graphic::Create();

	MainTank mainTank;

	list<Tank*> lstTanks;
	lstTanks.clear();

	for (int i = 0; i < MAX_TANKS; i++)
	{
		lstTanks.push_back(new EnemyTank());
	}

	list<Object*> lstBullets;
	lstBullets.clear();

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
  				mainTank.Shoot(lstBullets);
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

			Graphic::DrawBattleGround();

			mainTank.Move();
			mainTank.Display();

			for (list<Tank*>::iterator it = lstTanks.begin(); it != lstTanks.end(); it++)
			{
				(*it)->Move();
				(*it)->Display();
			}

			for (list<Object*>::iterator it = lstBullets.begin(); it != lstBullets.end();)
			{
				(*it)->Move();
			
				if ((*it)->IsDisappear())
				{

					delete *it;
					it = lstBullets.erase(it);
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

	for (list<Object*>::iterator it = lstBullets.begin(); it != lstBullets.end(); it++)
	{
		delete *it;
	}
	lstBullets.clear();

	Graphic::Destroy();
}