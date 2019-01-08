#pragma once
#include "DynamicObject.h"


class Guard :public DynamicObject

{
public:
	Guard();
	Guard(sf::Vector2f  position, sf::Vector2f size);
	
	Guard(std::string, sf::Vector2f position, sf::Vector2f size);

};

