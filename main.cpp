#pragma warning(disable:4996)

#include <iostream>
#include <conio.h>
#include <time.h>

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

	Tank* pTank[MAX_TANKS];

	for (int i = 0; i < MAX_TANKS; i++)
	{
		pTank[i] = new EnemyTank();
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

			for (int i = 0; i < MAX_TANKS; i++)
			{
				pTank[i]->Move();
				pTank[i]->Display();
			}
		}

		Sleep(200);
	}
	
	for (int i = 0; i < MAX_TANKS; i++)
	{
		delete pTank[i];
	}

	Graphic::Destroy();
}