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
private:
	int m_screen_height, m_screen_width;
};
