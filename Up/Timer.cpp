#include "timer.h"

Timer::Timer()
{
	m_LastTime = clock();
	m_TimeDelta = 0;
}
void Timer::Update()
{
	clock_t currTime = clock();
	m_TimeDelta = ((float)(currTime - m_LastTime)) / CLOCKS_PER_SEC;
	m_LastTime = currTime;
}
void Timer::Reset()
{
	m_TimeDelta = 0;
	m_LastTime = clock();
}