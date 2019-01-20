#pragma once
#include <string>
//A utility class for countdown timer implementation
class TimeUtils
{
public:
	TimeUtils(int seconds);
	static void restart();
	void setTime(int seconds);
	void setUnlimitedTimeMode(bool b);
	void secondPassed();
	int getElapsedTimeAsSeconds() const ; 
	std::string getTimeFormatted();
	bool isFinished() const;
private:
	std::string m_time_formatted;
	bool unlimited;
	static int m_time,start_time;
};

