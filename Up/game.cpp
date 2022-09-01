#include "game.h"
#include "jumper.h"
#include "platform.h"

static const float DRAW_TIME = 0.016f;

bool Game::Initialise()
{
	srand(time(NULL));
	m_VOffset = 0;
	m_ScrollSpeed = 0;
	m_NextPlatform = 200;
	m_Jumper = new Jumper(Point(500, 500));
	m_Platforms.push_back(new Platform(Point(450, 600), 100));
	m_Platforms.push_back(new Platform(Point(450, 400), 100));
	m_Platforms.push_back(new Platform(Point(450, 200), 100));
	m_Platforms.push_back(new Platform(Point(450, 0), 100));
	m_Platforms.push_back(new Platform(Point(450, -200), 100));

	return true;
}
void Game::Update(bool &needRedraw)
{
	m_Timer.Update();

	m_Jumper->Update();
	for (auto itPlat = m_Platforms.begin(); itPlat != m_Platforms.end();)
	{
		if ((*itPlat)->m_Pos.y > 1000)
		{
			delete *itPlat;
			itPlat = m_Platforms.erase(itPlat);
		}
		else
		{
			(*itPlat)->Update();
			itPlat++;
		}
	}
	m_NextPlatform += m_VOffset;
	if (m_NextPlatform < 0.f)
	{
		m_NextPlatform = randRange(150, 50);
		int nextX = randRange(m_Platforms.back()->m_Pos.x, 500);
		int nextWidth = randRange(100, 190);
		if (nextX > 1500 - nextWidth) nextX = 1500 - nextWidth;
		if (nextX < 0) nextX = 0;
		m_Platforms.push_back(new Platform(Point(nextX, -200), nextWidth));
	}
	static float nextDraw = 0.f;
	nextDraw -= m_Timer.m_TimeDelta;
	if (nextDraw < 0.f)
	{
		nextDraw = DRAW_TIME;
		needRedraw = true;
	}
	else
	{
		needRedraw = false;
	}
	m_VOffset = 0;
}
void Game::Draw(HDC hdc, PAINTSTRUCT* ps)
{
	HBRUSH redBrush = CreateSolidBrush(RGB(255, 0, 0));
	HBRUSH greenBrush = CreateSolidBrush(RGB(0, 255, 0));
	HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));
	if (m_Jumper)
	{
		SelectObject(hdc, redBrush);
		m_Jumper->Draw(hdc);
	}
	
	
	SelectObject(hdc, blueBrush);
	for (auto itPlatform = m_Platforms.begin(); itPlatform != m_Platforms.end();
		itPlatform++)
	{
		(*itPlatform)->Draw(hdc);
	}

	DeleteObject(redBrush);
	DeleteObject(greenBrush);
	DeleteObject(blueBrush);

}
Game::~Game()
{
	for (auto itPlat = m_Platforms.begin(); itPlat != m_Platforms.end();
		itPlat++)
	{
		delete *itPlat;
	}
	m_Jumper = NULL;
}