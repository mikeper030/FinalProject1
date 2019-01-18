#pragma once
#include <SFML/Graphics.hpp>
#include "SFML/Audio.hpp"

class PauseMenu
{

public:
	PauseMenu();
	int pauseGame(sf::RenderWindow & window, sf::Event & event, int h, int w);
	void drawPause(sf::RenderWindow & window);
private:
	sf::RectangleShape m_pauseRect, m_resumeRect, m_restartLevelRect, m_quitGameRect;
	sf::Text m_Pause_Game, m_Resume_Game, m_Restart_Game, m_Quit_Game;
	sf::Event m_event;
	sf::Font m_font;
};
