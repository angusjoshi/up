#pragma once
#include <ctime>

class Timer
{
public:
	Timer();
	float m_TimeDelta;
	clock_t m_LastTime;
	void Update();
	void Reset();
};