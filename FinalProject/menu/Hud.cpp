#include "headers/Hud.h"
#include <sstream>
#include <iostream>
Hud::Hud(int score, int lives, int level_bombs, int level_no, int s_width, int s_height, Timer&t)
	:m_timer(t)
{

	font.loadFromFile("res/DS-DIGI.TTF");
	points.setFont(font);
	levelNO.setFont(font);
	bombsLeft.setFont(font);
	life.setFont(font);
	timer_text.setFont(font);


	life.setFillColor(sf::Color::White);
	points.setFillColor(sf::Color::White);
	bombsLeft.setFillColor(sf::Color::White);
	levelNO.setFillColor(sf::Color::White);
	timer_text.setFillColor(sf::Color::White);

	life.setStyle(sf::Text::Bold);
	points.setStyle(sf::Text::Bold);
	bombsLeft.setStyle(sf::Text::Bold);
	levelNO.setStyle(sf::Text::Bold);
	timer_text.setStyle(sf::Text::Bold);

	life.setCharacterSize(s_height / 15);
	points.setCharacterSize(s_height / 15);
	bombsLeft.setCharacterSize(s_height / 15);
	levelNO.setCharacterSize(s_height / 15);
	timer_text.setCharacterSize(s_height / 15);

	setScore(score);
	setBombs(level_bombs);
	setLevelNO(level_no);
	setLife(lives);


	timer_text.setPosition(s_width*0.02 - timer_text.getLocalBounds().width / 2, s_height / 50);
	life.setPosition(s_width*0.2 - life.getLocalBounds().width / 2, s_height / 50);
	points.setPosition(s_width*0.4 - points.getLocalBounds().width / 2, s_height / 50);
	levelNO.setPosition(s_width*0.6 - levelNO.getLocalBounds().width / 2, s_height / 50);
	bombsLeft.setPosition(s_width*0.8 - bombsLeft.getLocalBounds().width / 2, s_height / 50);
}

void Hud::draw(sf::RenderWindow & w)
{
	w.draw(timer_text);
	w.draw(life);
	w.draw(bombsLeft);
	w.draw(levelNO);
	w.draw(points);
}

void Hud::setScore(int score)
{
	std::ostringstream o;
	o << "SCORE: " << score;
	std::string f(o.str());
	points.setString(f);
}

void Hud::setLevelNO(int num)
{
	std::ostringstream o;
	o << "LEVEL: " << num;
	std::string f(o.str());
	levelNO.setString(f);
}

void Hud::setLife(int lives)
{
	std::ostringstream o;
	o << "LIVES: " << lives;
	std::string f(o.str());
	life.setString(f);
}
void Hud::setTimer(Timer&t)
{
	m_timer = t;
}
void Hud::setBombs(int bombs)
{
	std::ostringstream o;
	o << "BOMBS: " << bombs;
	std::string f(o.str());
	bombsLeft.setString(f);
}


void Hud::updateTime()
{

	timer_text.setString(m_timer.getTimeFormatted());
}
