#include "headers/Timer.h"
#include <sstream>
#include <iostream>
Timer::Timer(int seconds)
	:unlimited(false)
{
	m_time = seconds;
}

void Timer::setTime(int seconds)
{
	
	m_time = seconds;
}
void Timer::setUnlimitedTimeMode(bool b)
{
	unlimited = b;
	if(b)m_time = -2;
}
void Timer::secondPassed()
{
	if(!unlimited)m_time--;
}
int Timer::getElapsedTimeAsSeconds() const
{
	return m_time;
}
std::string Timer::getTimeFormatted() 
{
	
	if (m_time == -2)
	{
		std::string s;
		s = "-:--";
		return s;
	}
	std::ostringstream o;
	int minutes = m_time/60;
	int seconds = m_time%60;
	
	if (seconds >= 10)
		o << minutes << ":" << seconds;
	else
		o << minutes << ":0" << seconds;
	std::string f(o.str()); m_time_formatted=f;
	return m_time_formatted;
}

bool Timer::isFinished() const
{
	return m_time==0;
}
