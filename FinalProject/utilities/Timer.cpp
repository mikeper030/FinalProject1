#include "headers/Timer.h"
#include <sstream>
#include <iostream>
Timer::Timer(int seconds)
{
	m_time = seconds;
}

void Timer::setTime(int seconds)
{
	m_time = seconds;
}
void Timer::secondPassed()
{
	m_time--;
}
std::string & Timer::getTimeFormatted() 
{
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
