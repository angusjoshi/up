#include "platform.h"
#include "game.h"
Platform::Platform()
{

}
Platform::Platform(const Point& pos, int width)
	:m_Pos(pos), 
	m_Width(width),
	m_Spikey(false),
	m_Bouncy(false),
	m_Fragile(false)
{
}
void Platform::Update()
{
	m_Pos.y -= g_Game.m_VOffset;
}
void Platform::Draw(HDC hdc)
{

	Rectangle(hdc, m_Pos.x, m_Pos.y, m_Pos.x + m_Width, m_Pos.y + 10);
}

