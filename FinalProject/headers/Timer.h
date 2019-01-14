#pragma once
#include <string>
//A utility class for countdown timer implementation
class Timer
{
public:
	Timer(int seconds);
	void setTime(int seconds);
	void secondPassed();
	std::string &getTimeFormatted();
	bool isFinished() const;
private:
	std::string m_time_formatted;
	int m_time;
};

