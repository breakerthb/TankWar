#ifndef __GRAPHIC_H__
#define __GRAPHIC_H__

#include <graphics.h>

#define SCREEN_WIDTH	1024
#define SCREEN_HEIGHT	768

class Graphic
{
public:
	static void Create();
	static void Destroy();

	static int GetScreenWidth();
	static int GetScreenHeight();

private:
	static int m_screen_width;
	static int m_screen_height;
};



#endif