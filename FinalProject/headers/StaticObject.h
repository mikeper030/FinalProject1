#pragma once
#include "Object.h"

class StaticObject :public Object
//abstract static objects class
{
public:
	StaticObject(std::string, sf::Vector2f position, sf::Vector2f size);
	
};

