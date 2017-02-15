#include "MainTank.h"

#include "Bullet.h"

void MainTank::SetDir(Dir dir)
{
	m_dir = dir;
}

void MainTank::DrawTankBody()
{
	fillrectangle(m_pos.GetX() - 6, m_pos.GetY() - 6, m_pos.GetX() + 6, m_pos.GetY() + 6);

	switch (m_dir)
	{
	case UP:
	case DOWN:
		fillrectangle(m_rectSphere.GetStartPoint().GetX(), m_rectSphere.GetStartPoint().GetY(),
			m_rectSphere.GetStartPoint().GetX() + 4, m_rectSphere.GetEndPoint().GetY());
		fillrectangle(m_rectSphere.GetEndPoint().GetX() - 4, m_rectSphere.GetStartPoint().GetY(),
			m_rectSphere.GetEndPoint().GetX(), m_rectSphere.GetEndPoint().GetY());
		break;
	case LEFT:
	case RIGHT:
		fillrectangle(m_rectSphere.GetStartPoint().GetX(), m_rectSphere.GetStartPoint().GetY(),
			m_rectSphere.GetEndPoint().GetX(), m_rectSphere.GetStartPoint().GetY() + 4);
		fillrectangle(m_rectSphere.GetStartPoint().GetX(), m_rectSphere.GetEndPoint().GetY() - 4,
			m_rectSphere.GetEndPoint().GetX(), m_rectSphere.GetEndPoint().GetY());
		break;
	default:
		break;
	}
}

void MainTank::Display()
{
	COLORREF fill_color_save = getfillcolor();
	COLORREF color_save = getcolor();

	setfillcolor(m_color);
	setcolor(m_color);

	DrawTankBody();

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

void MainTank::Move()
{
	switch (m_dir)
	{
	case UP:
		m_pos.SetY(m_pos.GetY() - m_step);
		if (m_rectSphere.GetStartPoint().GetY() < Graphic::GetBattleGround().GetStartPoint().GetY())
			m_pos.SetY(m_pos.GetY() + m_step);
		break;
	case DOWN:
		m_pos.SetY(m_pos.GetY() + m_step);
		if (m_rectSphere.GetEndPoint().GetY() > Graphic::GetBattleGround().GetEndPoint().GetY())
			m_pos.SetY(m_pos.GetY() - m_step);
		break;
	case LEFT:
		m_pos.SetX(m_pos.GetX() - m_step);
		if (m_rectSphere.GetStartPoint().GetX() < Graphic::GetBattleGround().GetStartPoint().GetX())
			m_pos.SetX(m_pos.GetX() + m_step);
		break;
	case RIGHT:
		m_pos.SetX(m_pos.GetX() + m_step);
		if (m_rectSphere.GetEndPoint().GetX() > Graphic::GetBattleGround().GetEndPoint().GetX())
			m_pos.SetX(m_pos.GetX() - m_step);
		break;
	default:
		break;
	}

	CalculateSphere();
}

void MainTank::CalculateSphere()
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

void MainTank::Shoot(list<Object*>& lstBullets)
{
	Bullet* pBullet = new Bullet(m_pos, m_dir, m_color);
	pBullet->SetStep(20);

	lstBullets.push_back(pBullet);
}

void MainTank::Boom(list<Object*>& lstBombs)
{

}