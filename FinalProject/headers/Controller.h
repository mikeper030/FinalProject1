#pragma once
#include <SFML/Graphics.hpp>

#include "DynamicObject.h"
#include "StaticObject.h"
#include "Timer.h"
#include "Hud.h"
#include "AlertDialog.h"

class GameBoardManager;
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

	void updateDisplay(sf::RenderWindow & window, bool & isPlaying, sf::RectangleShape & winRec, sf::RectangleShape & boardRec, GameBoardManager & manager, Hud & hud, sf::RectangleShape & rectInter, sf::RectangleShape & newGame_botton, sf::RectangleShape & exitGame_botton, sf::Text & menu_newGame, sf::Text & menu_exitGame, sf::Sprite & soundIcon);
 
private:
	int m_screen_height, m_screen_width;
	static bool is_level_finished,should_restart;
	
};
