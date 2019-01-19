#pragma once
#include <SFML/Graphics.hpp>
#include "PauseMenu.h"
#include "DynamicObject.h"
#include "StaticObject.h"
#include "TimeUtils.h"
#include "SoundUtils.h"
#include "Hud.h"
#include "AlertDialog.h"
#include "MainMenu.h"
class GameBoardManager;
class Controller
{
public:
	Controller();
	void startGame(std::string name_file);
	void getCommand(int command, bool & isPause, bool & isPlaying, GameBoardManager & manager, TimeUtils & t, Hud & hud);
	static bool levelFinsihed();
	static void setRestart(bool b);
	static bool restart();
	static void setLevelFinished(bool b);
	static void setGameOver(bool b);
	void updateDisplay(sf::RenderWindow & window, bool & isPlaying, sf::RectangleShape & winRec, sf::RectangleShape & boardRec, GameBoardManager & manager, Hud & hud, MainMenu & main);

 
private:
	int m_screen_height, m_screen_width;
	static bool is_level_finished, should_restart, game_over;
	bool should_exit;
	sf::Sprite m_cursor;
	SoundUtils sound;
	PauseMenu pauseMenu;

	
};
