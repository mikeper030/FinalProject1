#pragma once
#include <SFML/Graphics.hpp>
#include "TimeUtils.h"
class Hud
{
public:
	Hud(int score, int lives, int level_bombs, int level_no, int s_width, int s_height, TimeUtils&t);
	void setAlert(bool);
	void draw(sf::RenderWindow&w);
	void setScore(int score);
	void setLevelNO(int num);
	bool lowOnTime() const;
	void setLife(int lives);
	void setTimer(TimeUtils & t);
	void setBombs(int bombs);
	static void restart();
	void updateTime();
private:
	TimeUtils&m_timer;
	sf::Text points, life, bombsLeft, levelNO, timer_text;
	sf::Font font;
};

