#ifndef __SHAPE_H__
#define __SHAPE_H__

#include "../Model/Rect.h"

class Shape
{
public:
	static bool CheckPointInRect(Point& point, Rect& rect);
	static bool CheckIntersect(Rect& rectA, Rect& rectB);
};

#endif