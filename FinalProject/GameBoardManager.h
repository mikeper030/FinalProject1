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


class GameBoardManager
{
public:
	
	GameBoardManager(std::ifstream & file);
	void readSizeOfBoard();
	void createBoardByFile(int,int);
	void moveGuards(sf::Vector2f pos, float delta, float speed, const std::vector<std::unique_ptr<DynamicObject>>& movable, const std::vector<std::unique_ptr<StaticObject>>& statics);
	std::vector<std::unique_ptr<StaticObject>> &getStaticObjects() ;
	std::vector<std::unique_ptr<DynamicObject>> &getDynamicObjects();


	void draw(sf::RenderWindow & w);
	void updateRobot(sf::Vector2f  new_position, sf::IntRect &rectSourceSprite, int first, int lest, float width);
private:
	float m_rows, m_cols, m_number_bombs, m_time_level;
	std::ifstream & m_file;
	std::vector<std::unique_ptr<Object>> m_all;
	std::vector<std::unique_ptr<DynamicObject>> m_active;
	std::vector<std::unique_ptr<StaticObject>> m_static;


};

