#include "headers/PauseMenu.h"

PauseMenu::PauseMenu(){}

int PauseMenu::pauseGame(sf::RenderWindow & window, sf::Event & event, int w, int h)
{

	m_pauseRect.setSize(sf::Vector2f(w / 3, h / 2));
	m_pauseRect.setFillColor(sf::Color::Black);
	
	m_pauseRect.setPosition(w/2- w/3/2, h/2- h / 4);

	m_resumeRect.setSize(sf::Vector2f(w/3*0.6, h/8));
	m_resumeRect.setFillColor(sf::Color::Red);
	
	m_resumeRect.setPosition(w / 2 - (w / 3 * 0.6)/2, h*0.3);

	m_restartLevelRect.setSize(sf::Vector2f(w / 3 * 0.6, h / 8));
	m_restartLevelRect.setFillColor(sf::Color::Red);
	m_restartLevelRect.setPosition(w / 2- (w / 3 * 0.6) / 2,h*0.45);

	m_quitGameRect.setSize(sf::Vector2f(w / 3 * 0.6, h / 8));
	m_quitGameRect.setFillColor(sf::Color::Red);
	
	m_quitGameRect.setPosition(w / 2 - (w / 3 * 0.6) / 2, h*0.6);


	m_font.loadFromFile("res/sansation.ttf");

	

	m_Resume_Game.setFont(m_font);
	m_Resume_Game.setFillColor(sf::Color::Yellow);
	m_Resume_Game.setString("Resume Game");
	m_Resume_Game.setCharacterSize(h / 30);
	m_Resume_Game.setStyle(sf::Text::Bold);
	m_Resume_Game.setPosition(w/2-m_Resume_Game.getLocalBounds().width/2, h *0.34);
	

	m_Restart_Game.setFont(m_font);
	m_Restart_Game.setFillColor(sf::Color::Yellow);
	m_Restart_Game.setString("Restart Game");
	m_Restart_Game.setCharacterSize(h / 30);
	m_Restart_Game.setStyle(sf::Text::Bold);
	m_Restart_Game.setPosition(w / 2 - m_Restart_Game.getLocalBounds().width / 2, h*0.49);
	

	m_Quit_Game.setFont(m_font);
	m_Quit_Game.setFillColor(sf::Color::Yellow);
	m_Quit_Game.setString("Quit Game");
	m_Quit_Game.setCharacterSize(h / 30);
	m_Quit_Game.setStyle(sf::Text::Bold);
	m_Quit_Game.setPosition(w / 2 - m_Quit_Game.getLocalBounds().width / 2, h*0.64);
	
	sf::Event evnt;

	drawPause(window);
	window.display();

	while (window.waitEvent(evnt))
	{
		//get mouse position 
		sf::Vector2i mouse = sf::Mouse::getPosition(window);
		//compute global boundries
		sf::Vector2f mouse_world = window.mapPixelToCoords(mouse);
		if (evnt.mouseButton.button == sf::Mouse::Button::Left)
		{
			if (m_quitGameRect.getGlobalBounds().contains(mouse_world))
			{
				window.close();
			}

			if (m_resumeRect.getGlobalBounds().contains(mouse_world))
			{
				return 1;
			}

			if (m_restartLevelRect.getGlobalBounds().contains(mouse_world))
			{
				return 2;
			}
		}
	}
	return 3;
}

void PauseMenu::drawPause(sf::RenderWindow & window)
{

	window.draw(m_pauseRect);
	window.draw(m_resumeRect);
	window.draw(m_restartLevelRect);
	window.draw(m_quitGameRect);
	window.draw(m_Pause_Game);
	window.draw(m_Resume_Game);
	window.draw(m_Restart_Game);
	window.draw(m_Quit_Game);
}
