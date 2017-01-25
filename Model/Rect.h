#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include "Point.h"

class Rect
{
public:
	Rect(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0) : m_startPoint(x1, y1), m_endPoint(x2, y2){}
	Rect(const Point p1, const Point p2) : m_startPoint(p1), m_endPoint(p2){}
	Rect(const Rect& r1) : m_startPoint(r1.GetStartPoint()), m_endPoint(r1.GetEndPoint()){}
	~Rect(){};

	Rect& operator=(const Rect &rect)
	{
		m_startPoint = rect.GetStartPoint();
		m_endPoint = rect.GetEndPoint();

		return *this;
	}

	void Set(const Point pStart, const Point pEnd);
	void Set(int x1, int y1, int x2, int y2);

	void SetStartPoint(const Point p);
	void SetEndPoint(const Point p);

	Point GetStartPoint() const;
	Point GetEndPoint() const;

	Point GetTRPoint() const; // Get Top Right Point
	Point GetBLPoint() const; // Get Bottom Left Point

	int GetWidth();
	int GetHeight();


private:
	void Check();

	Point m_startPoint;
	Point m_endPoint;
};

#endif