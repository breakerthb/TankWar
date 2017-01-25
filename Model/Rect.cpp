#include "Rect.h"

void Rect::Set(Point pStart, Point pEnd)
{
	m_startPoint = pStart;
	m_endPoint = pEnd;
}

void Rect::Set(int x1, int y1, int x2, int y2)
{
	m_startPoint.Set(x1, y1);
	m_endPoint.Set(x2, y2);
}

void Rect::SetStartPoint(Point p)
{
	m_startPoint = p;
}

void Rect::SetEndPoint(Point p)
{
	m_endPoint = p;
}

Point Rect::GetStartPoint() const
{
	return m_startPoint;
}

Point Rect::GetEndPoint() const
{
	return m_endPoint;
}

Point Rect::GetTRPoint() const
{
	Point p = m_startPoint;
	p.SetX(m_endPoint.GetX());

	return p;
}

Point Rect::GetBLPoint() const
{
	Point p = m_startPoint;
	p.SetY(m_endPoint.GetY());

	return p;
}

int Rect::GetWidth()
{
	return m_endPoint.GetX() - m_startPoint.GetX();
}

int Rect::GetHeight()
{
	return m_endPoint.GetY() - m_startPoint.GetY();
}

void Rect::Check()
{
	if (m_startPoint.GetX() > m_endPoint.GetX() || m_startPoint.GetY() > m_endPoint.GetY())
	{
		Point p = m_startPoint;
		m_startPoint = m_endPoint;
		m_endPoint = m_startPoint;
	}
}

