#include "EnemyTank.h"

void EnemyTank::RandomTank()
{
	m_pos.SetX(rand() % Graphic::GetBattleGround().GetWidth());
	m_pos.SetY(rand() % Graphic::GetBattleGround().GetHeight());
	m_color = WHITE;
	m_dir = (Dir)(Dir::UP + (rand() % 4));
	m_step = 2;
}

void EnemyTank::Display()
{
	COLORREF fill_color_save = getfillcolor();
	COLORREF color_save = getcolor();

	setfillcolor(m_color);
	setcolor(m_color);
	
	fillrectangle(m_pos.GetX() - 6, m_pos.GetY() - 6, m_pos.GetX() + 6, m_pos.GetY() + 6);

	fillrectangle(m_rectSphere.GetStartPoint().GetX(), m_rectSphere.GetStartPoint().GetY(),
		m_rectSphere.GetStartPoint().GetX() + 4, m_rectSphere.GetStartPoint().GetY() + 4);
	fillrectangle(m_rectSphere.GetEndPoint().GetX() - 4, m_rectSphere.GetStartPoint().GetY(),
		m_rectSphere.GetEndPoint().GetX(), m_rectSphere.GetStartPoint().GetY() + 4);

	fillrectangle(m_rectSphere.GetStartPoint().GetX(), m_rectSphere.GetEndPoint().GetY() - 4,
		m_rectSphere.GetStartPoint().GetX() + 4, m_rectSphere.GetEndPoint().GetY());
	fillrectangle(m_rectSphere.GetEndPoint().GetX() - 4, m_rectSphere.GetEndPoint().GetY() - 4,
		m_rectSphere.GetEndPoint().GetX(), m_rectSphere.GetEndPoint().GetY());
	
	switch (m_dir)
	{
	case UP:
		line(m_pos.GetX(), m_pos.GetY(), m_pos.GetX(), m_pos.GetY() - 15);
		break;
	case DOWN:
		line(m_pos.GetX(), m_pos.GetY(), m_pos.GetX(), m_pos.GetY() + 15);
		break;
	case LEFT:
		line(m_pos.GetX(), m_pos.GetY(), m_pos.GetX() - 15, m_pos.GetY());
		break;
	case RIGHT:
		line(m_pos.GetX(), m_pos.GetY(), m_pos.GetX() + 15, m_pos.GetY());
		break;
	default:
		break;
	}

	setcolor(color_save);
	setfillcolor(fill_color_save);
}

void EnemyTank::Move()
{
	switch (m_dir)
	{
	case UP:
		m_pos.SetY(m_pos.GetY() - m_step);
		if (m_pos.GetY() < Graphic::GetBattleGround().GetStartPoint().GetY())
			m_pos.SetY(Graphic::GetBattleGround().GetEndPoint().GetY() - 1);
		break;
	case DOWN:
		m_pos.SetY(m_pos.GetY() + m_step);
		if (m_pos.GetY() > Graphic::GetBattleGround().GetEndPoint().GetY())
			m_pos.SetY(Graphic::GetBattleGround().GetStartPoint().GetY() + 1);
		break;
	case LEFT:
		m_pos.SetX(m_pos.GetX() - m_step);
		if (m_pos.GetX() < Graphic::GetBattleGround().GetStartPoint().GetX())
			m_pos.SetX(Graphic::GetBattleGround().GetEndPoint().GetX() - 1);
		break;
	case RIGHT:
		m_pos.SetX(m_pos.GetX() + m_step);
		if (m_pos.GetX() > Graphic::GetBattleGround().GetEndPoint().GetX())
			m_pos.SetX(Graphic::GetBattleGround().GetStartPoint().GetX() + 1);
		break;
	default:
		break;
	}

	CalculateSphere();
}

void EnemyTank::CalculateSphere()
{
	switch (m_dir)
	{
	case UP:
	case DOWN:
		m_rectSphere.Set(m_pos.GetX() - 13, m_pos.GetY() - 10, m_pos.GetX() + 13, m_pos.GetY() + 10);
		break;
	case LEFT:
	case RIGHT:
		m_rectSphere.Set(m_pos.GetX() - 10, m_pos.GetY() - 13, m_pos.GetX() + 10, m_pos.GetY() + 13);
		break;
	default:
		break;
	}
}