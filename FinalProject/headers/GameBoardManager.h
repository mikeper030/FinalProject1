#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <fstream>
#include <memory>
#include "DynamicObject.h"
#include "StaticObject.h"
#include "Player.h"
#include "DummyGuard.h"
#include "Rock.h"
#include "Wall.h"
#include "Door.h"
#include "Bomb.h"
#include "Controller.h"
#include "BonusGift.h"

class GameBoardManager
{
public:
	
	

	GameBoardManager(std::ifstream & file);
	void readSizeOfBoard();
   void createBoardByFile();
	void moveGuards(sf::Vector2f pos, float delta, float speed, const std::vector<std::unique_ptr<DynamicObject>>& movable, const std::vector<std::unique_ptr<StaticObject>>& statics);
	static std::vector<std::unique_ptr<StaticObject>> &getStaticObjects() ;
	static std::vector<std::unique_ptr<DynamicObject>> &getDynamicObjects();
	static void addScore();
	static int getScore();
	
	int &getCurrentTimeLimit();
	void updateRobot(int width, float playerSpeed, float deltaTime);
	std::vector<Bomb>& getBombs();
	static int &getLevelBombsMax();
	void draw(sf::RenderWindow & w);
	void updateRobot(sf::Vector2f  new_position, sf::IntRect &rectSourceSprite, int first, int lest, float width, const std::vector<std::unique_ptr<DynamicObject>>& objects1, const std::vector<std::unique_ptr<StaticObject>>& objects2);
	static void restartLevel();
	int getCurrentLevel() const;
     void goToNextLevel();
	
private:
	float m_rows, m_cols, m_tile_width,m_tile_height;
	
	int  m_time_level,m_curr_level;
	std::ifstream & m_file;
	static float m_score,m_guards_num;
	static int m_bombs_limit, m_bombs_counter;
	std::vector<std::unique_ptr<Object>> m_all;
	static std::vector<std::unique_ptr<DynamicObject>> m_active;
	static std::vector<std::unique_ptr<StaticObject>> m_static;
	std::vector<Bomb> m_bombs;
	


};

