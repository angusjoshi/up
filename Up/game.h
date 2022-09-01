#pragma once
#include "framework.h"
#include "timer.h"
#include "point.h"
class Jumper;
class Platform;

//TODO: implement auto scrolling with increasing scrollspeed
//TODO: implement start menu
//TODO: implement pause and pause menu
//TODO: implement the spikey and super bouncy platforms

class Game
{
public:
	bool Initialise();
	void Update(bool &needRedraw);
	void Draw(HDC hdc, PAINTSTRUCT* ps);
	int m_ScrollSpeed;
	float m_VOffset;
	float m_NextPlatform;
	std::list<Platform*> m_Platforms;
	Jumper* m_Jumper;
	Timer m_Timer;


	~Game();
	static float randRange(float mid, int size)
	{
		int random = rand() % size;
		return random + mid - (size / 2);
	}
};
extern Game g_Game;