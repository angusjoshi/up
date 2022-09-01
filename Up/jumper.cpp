#include "jumper.h"
#include "game.h"
#include "platform.h"
static const float SCROLL_THRESHOLD = 400;
static const int GRAVITY = 2000;
static const int JUMP_SPEED = 1000;
static const int MOVE_ACCEL = 2000;
static const int WIDTH = 50;	
static const int HEIGHT = 50;
static const int MAX_MOVE_SPEED = 300;
Jumper::Jumper()
{

}
Jumper::Jumper(const Point& pos)
	:m_Pos(pos), 
	m_Vel(Point(5, 0)),
	m_Dead(false)
{
}
void Jumper::Update()
{
	//update pos based on velocity
	float timeDelta = g_Game.m_Timer.m_TimeDelta;
	float deltaY = m_Vel.y * timeDelta;
	if (m_Vel.y > 0) {
		for (auto itPlat = g_Game.m_Platforms.begin(); itPlat != g_Game.m_Platforms.end();
			itPlat++)
		{
			Point platPos = (*itPlat)->m_Pos;
			int platWidth = (*itPlat)->m_Width;
			if (m_Pos.x + WIDTH > platPos.x && m_Pos.x < platPos.x + platWidth)
			{
				if (m_Pos.y + HEIGHT < platPos.y && m_Pos.y + HEIGHT + deltaY > platPos.y)
				{
					m_Vel.y = -JUMP_SPEED;
				}
			}
		}
	}
	m_Pos.x = m_Pos.x + m_Vel.x * timeDelta;
	if (m_Pos.y + deltaY < SCROLL_THRESHOLD)
	{
		g_Game.m_VOffset += deltaY;
	}
	else
	{
		m_Pos.y += deltaY;
	}
	m_Vel.y += GRAVITY * timeDelta;
	
	bool moving = false;
	if (GetKeyState(VK_LEFT) & 0x8000)
	{
		moving = true;
		if (m_Vel.x > -MAX_MOVE_SPEED)
		{
			m_Vel.x -= MOVE_ACCEL * timeDelta;
		}
	}
	if (GetKeyState(VK_RIGHT) & 0x8000)
	{
		moving = true;
		if (m_Vel.x < MAX_MOVE_SPEED)
		{
			m_Vel.x += MOVE_ACCEL * timeDelta;
		}
	}


	if (!moving)
	{
		if (m_Vel.x > 0)
		{
			m_Vel.x -= MOVE_ACCEL * timeDelta;
		}
		if (m_Vel.x < 0)
		{
			m_Vel.x += MOVE_ACCEL * timeDelta;
		}
	}
}
void Jumper::Jump()
{
}
void Jumper::Die()
{
	m_Dead = true;
}
void Jumper::Draw(HDC hdc)
{

	Rectangle(hdc, m_Pos.x, m_Pos.y, m_Pos.x + 50, m_Pos.y + 50);
}