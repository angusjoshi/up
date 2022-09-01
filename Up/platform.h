#pragma once
#include "point.h"
#include "framework.h"

class Platform
{
public:
	Platform();
	Platform(const Point& pos, int width);
	void Update();
	void Draw(HDC hdc);
	Point m_Pos;
	int m_Width;
	bool m_Spikey;
	bool m_Bouncy;
	bool m_Fragile;
};
