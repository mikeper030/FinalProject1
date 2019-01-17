#include "Menu.h"
#include <iostream>


Menu::Menu()
{
}

int Menu::pauseGame(sf::RenderWindow & window, sf::Event & event, int h, int w, sf::Music & soundClick)
{
	std::cout << "work ok" << std::endl;

	m_pauseRect.setSize(sf::Vector2f(h, w));
	m_pauseRect.setFillColor(sf::Color::Black);
	m_pauseRect.setPosition(0, 0);

	m_resumeRect.setSize(sf::Vector2f(300, 100));
	m_resumeRect.setFillColor(sf::Color::Red);
	m_resumeRect.setPosition(200, 50);

	m_restartLevelRect.setSize(sf::Vector2f(300, 100));
	m_restartLevelRect.setFillColor(sf::Color::Red);
	m_restartLevelRect.setPosition(200, 200);

	m_quitGameRect.setSize(sf::Vector2f(300, 100));
	m_quitGameRect.setFillColor(sf::Color::Red);
	m_quitGameRect.setPosition(200, 350);


	m_font.loadFromFile("res/sansation.ttf");

	m_Pause_Game.setFont(m_font);
	m_Pause_Game.setPosition(200, 0);
	m_Pause_Game.setFillColor(sf::Color::Yellow);
	m_Pause_Game.setString("Pause Game");
	m_Pause_Game.setCharacterSize(20);
	m_Pause_Game.setStyle(sf::Text::Bold);

	m_Resume_Game.setFont(m_font);
	m_Resume_Game.setPosition(200, 100);
	m_Resume_Game.setFillColor(sf::Color::Yellow);
	m_Resume_Game.setString("Resume Game");
	m_Resume_Game.setCharacterSize(20);
	m_Resume_Game.setStyle(sf::Text::Bold);

	m_Restart_Game.setFont(m_font);
	m_Restart_Game.setPosition(200, 250);
	m_Restart_Game.setFillColor(sf::Color::Yellow);
	m_Restart_Game.setString("Restart Game");
	m_Restart_Game.setCharacterSize(20);
	m_Restart_Game.setStyle(sf::Text::Bold);

	m_Quit_Game.setFont(m_font);
	m_Quit_Game.setPosition(200, 400);
	m_Quit_Game.setFillColor(sf::Color::Yellow);
	m_Quit_Game.setString("Quit Game");
	m_Quit_Game.setCharacterSize(20);
	m_Quit_Game.setStyle(sf::Text::Bold);
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
			std::cout << "work 1" << std::endl;

			if (m_quitGameRect.getGlobalBounds().contains(mouse_world))
			{
				std::cout << "work click" << std::endl;

				window.close();
			}

			if (m_resumeRect.getGlobalBounds().contains(mouse_world))
			{
				std::cout << "work click" << std::endl;
				return 1;
			}

			if (m_restartLevelRect.getGlobalBounds().contains(mouse_world))
			{
				std::cout << "work click" << std::endl;
				return 2;
			}
		}
	}
	return 3;
}

void Menu::drawPause(sf::RenderWindow & window)
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

Menu::~Menu()
{
}
