#include "headers/MainMenu.h"

MainMenu::MainMenu(int s_width,int s_height)
	:m_screen_width(s_width),m_screen_height(s_height)
{
	font.loadFromFile("res/1stenterprisesexpand.ttf");
	m_tex.loadFromFile("res/inter.png");
	m_tex.setSmooth(true);
	rectInter.setSize(sf::Vector2f(s_width, s_height));
	m_sprite.setTexture(m_tex);
	m_sprite.setPosition(0, 0);
	m_sprite.scale(sf::Vector2f(4.8,4.1));
	
	newGame_botton.setSize(sf::Vector2f(s_width / 6, s_height / 12));
	exitGame_botton.setSize(sf::Vector2f(s_width / 6, s_height / 12));
	newGame_botton.setFillColor(sf::Color::Red);
	newGame_botton.setPosition(m_screen_width / 10, m_screen_height*0.69);

	exitGame_botton.setFillColor(sf::Color::Red);
	exitGame_botton.setPosition(m_screen_width / 10, m_screen_height*0.79);
	
	menu_newGame.setFont(font);
	menu_newGame.setCharacterSize(m_screen_height / 30);
	menu_newGame.setPosition(m_screen_width*0.11, m_screen_height*0.71);
	menu_newGame.setFillColor(sf::Color::Black);
	menu_newGame.setString("New Game");

	menu_exitGame.setFont(font);
	menu_exitGame.setCharacterSize(m_screen_height / 30);
	menu_exitGame.setPosition(m_screen_width *0.11, m_screen_height*0.81);
	menu_exitGame.setFillColor(sf::Color::Black);
	menu_exitGame.setString("Exit Game");
}

bool MainMenu::newGame(sf::Event & event , sf::RenderWindow & window)
{
	
	//get mouse position 
	sf::Vector2i mouse = sf::Mouse::getPosition(window);
	//compute global boundries
	sf::Vector2f mouse_world = window.mapPixelToCoords(mouse);

	if (event.mouseButton.button == sf::Mouse::Button::Left)
	{
		if (exitGame_botton.getGlobalBounds().contains(mouse_world))
		{
			window.close();
		}
	}

	if (event.mouseButton.button == sf::Mouse::Button::Left)
	{
		if (newGame_botton.getGlobalBounds().contains(mouse_world))
		{
			return true;
		}
	}
	return false;
}
void MainMenu::setEnd()
{
	m_tex.loadFromFile("res/endgame.jpg");
	m_tex.setSmooth(true);
	end.setPosition(sf::Vector2f(0, 0));
	end.setTexture(m_tex);
	end.scale(sf::Vector2f(2.6,3));
	m_sprite = end;
}
void MainMenu::draw(sf::RenderWindow & window)
{
	//window.draw(rectInter);
	window.draw(m_sprite);
	window.draw(newGame_botton);
	window.draw(exitGame_botton);
	window.draw(menu_newGame);
	window.draw(menu_exitGame);
	

}
