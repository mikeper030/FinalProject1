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


class GameBoardManager
{
public:
	
	

	GameBoardManager(std::ifstream & file);
	void readSizeOfBoard();
	void createBoardByFile(int,int);
	void moveGuards(sf::Vector2f pos, float delta, float speed, const std::vector<std::unique_ptr<DynamicObject>>& movable, const std::vector<std::unique_ptr<StaticObject>>& statics);
	static std::vector<std::unique_ptr<StaticObject>> &getStaticObjects() ;
	static std::vector<std::unique_ptr<DynamicObject>> &getDynamicObjects();
	void updateRobot(int width, float playerSpeed, float deltaTime);
	std::vector<Bomb>& getBombs();

	void draw(sf::RenderWindow & w);
	void updateRobot(sf::Vector2f  new_position, sf::IntRect &rectSourceSprite, int first, int lest, float width, const std::vector<std::unique_ptr<DynamicObject>>& objects1, const std::vector<std::unique_ptr<StaticObject>>& objects2);
	void updateBombs(sf::RenderWindow & w);
private:
	float m_rows, m_cols, m_bombs_limit, m_time_level, m_size_width,m_size_height;
	std::ifstream & m_file;
	std::vector<std::unique_ptr<Object>> m_all;
	static std::vector<std::unique_ptr<DynamicObject>> m_active;
	static std::vector<std::unique_ptr<StaticObject>> m_static;
	std::vector<Bomb> m_bombs;
	


};

