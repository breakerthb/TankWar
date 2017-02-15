#ifndef __GRAPHIC_H__
#define __GRAPHIC_H__

#include <graphics.h>

#include "model/Rect.h"

#define SCREEN_WIDTH	1024
#define SCREEN_HEIGHT	768

#define BATTLE_GROUND_X1 5
#define BATTLE_GROUND_Y1 5
#define BATTLE_GROUND_X2 800
#define BATTLE_GROUND_Y2 (SCREEN_HEIGHT - BATTLE_GROUND_Y1)

class Graphic
{
public:
	static void Create();
	static void Destroy();

	static void DrawBattleGround();

	static int GetScreenWidth();
	static int GetScreenHeight();

	static Rect GetBattleGround();

	static void ShowScore();
	static void ShowGameLevel(int nLevel);

private:
	static Rect m_rectScreen;
	static Rect m_rectBattleGround;

	static char m_pArray[100];
};

#endif