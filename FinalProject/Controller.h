#pragma once
#include <SFML/Graphics.hpp>
#include "GameBoardManager.h"
#include "DynamicObject.h"
#include "StaticObject.h"
class Controller
{
public:
	Controller();
	void startGame(std::string name_file);
	bool newGame(sf::Event & event, sf::Texture & texture, sf::RectangleShape & newGame_botton, sf::RectangleShape & exitGame_botton, sf::Font & font, sf::Text & menu_newGame, sf::Text & menu_exitGame, sf::RenderWindow & window);
private:
	int m_screen_height, m_screen_width;
};
