#include "Point.h"

void Point::Set(int x, int y)
{
	m_x = x;
	m_y = y;
}

void Point::SetX(int x)
{
	m_x = x;
}

void Point::SetY(int y)
{
	m_y = y;
}

int Point::GetX()
{
	return m_x;
}

int Point::GetY()
{
	return m_y;
}
