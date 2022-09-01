#pragma once
#include "point.h"
#include "framework.h"

class Jumper
{
public:
	Jumper();
	Jumper(const Point& pos);
	void Update();
	void Draw(HDC hdc);

	Point m_Vel;
	Point m_Pos;
	bool m_Dead;

	virtual void Jump();
	virtual void Die();
};
