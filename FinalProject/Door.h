#pragma once
#include "StaticObject.h"
#include <iostream>
class Door :public StaticObject
{
public:
	Door(sf::Vector2f position, sf::Vector2f size);
	void draw(sf::RenderWindow & w);
	void setPoisition(sf::Vector2f &);
	sf::Vector2f getPosition();
};

