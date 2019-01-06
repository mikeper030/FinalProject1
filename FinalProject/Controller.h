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
	Object m_object;
};
