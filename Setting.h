#ifndef __SETTING_H__
#define __SETTING_H__

#include <list>

using namespace std;

class Setting
{
public:
	static void NewGameLevel();
	static void TankDamaged();

	static int GetLife()
	{
		return m_nLife;
	}

	static void Die()
	{
		m_nLife -= 1;
	}

	static int GetGameLevel()
	{
		return m_nGameLevel;
	}

	static int GetTankLevel()
	{
		return m_nTankLevel;
	}

	static int GetTankNum()
	{
		return m_nTankNum;
	}

	static int GetSumScore()
	{
		return m_nSumScore;
	}

	static int GetTankSum()
	{
		return m_nTankSum;
	}

	static bool m_bNewLevel;

private:
	static int m_nLife; // 生命值

	static int m_nGameLevel;	// 当前游戏关卡
	static int m_nTankLevel;	// 当前坦克级别
	
	static int m_nTankNum;		// 当前坦克数

	static int m_nSumScore;		// 总分

	static int m_nTankScore;	// 击毁坦克得分
	
	static int m_nTankSum;		// 共击毁坦克数
};

#endif