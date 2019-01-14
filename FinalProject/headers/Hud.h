#pragma once
#include <SFML/Graphics.hpp>
#include "Timer.h"
class Hud
{
public:
	Hud(int score, int lives, int level_bombs, int level_no, int s_width, int s_height, Timer&t);
	void draw(sf::RenderWindow&w);
	void setScore(int score);
	void setLevelNO(int num);
	void setLife(int lives);
	void setTimer(Timer & t);
	void setBombs(int bombs);
	void updateTime();
private:
	Timer&m_timer;
	sf::Text points, life, bombsLeft, levelNO, timer_text;
	sf::Font font;
};

