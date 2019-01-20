#pragma once
#include <SFML/Graphics.hpp>

class MainMenu 
{
public:
	MainMenu(int, int);
	bool newGame(sf::Event & event, sf::RenderWindow & window);
	void setEnd();
	void draw(sf::RenderWindow&window);
private:
	sf::RectangleShape newGame_botton, exitGame_botton, rectInter;
	sf::Sprite m_sprite,end;
	sf::Texture m_tex;
	sf::Font font;
	sf::Text menu_newGame;
	sf::Text menu_exitGame;
	int m_screen_width,m_screen_height;
};