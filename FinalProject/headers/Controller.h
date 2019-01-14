#pragma once
#include <SFML/Graphics.hpp>
#include "GameBoardManager.h"
#include "DynamicObject.h"
#include "StaticObject.h"
#include "GameBoardManager.h"
#include "Timer.h"

class Controller
{
public:
	Controller();
	void startGame(std::string name_file);
	bool newGame(sf::Event & event, sf::Texture & texture, sf::RectangleShape & newGame_botton, sf::RectangleShape & exitGame_botton, sf::Font & font, sf::Text & menu_newGame, sf::Text & menu_exitGame, sf::RenderWindow & window);
	static bool levelFinsihed();
	static void setRestart(bool b);
	static bool restart();
	static void setLevelFinished(bool b);
private:
	int m_screen_height, m_screen_width;
	static bool is_level_finished,should_restart;
	
};
