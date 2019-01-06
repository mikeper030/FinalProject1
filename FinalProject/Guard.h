#pragma once
#include "DynamicObject.h"


class Guard :public DynamicObject
{
public:
	Guard(sf::Vector2f  position, sf::Vector2f size);
	void draw(sf::RenderWindow & w);
	void setPoisition(sf::Vector2f &);
	void move(sf::Vector2f& new_position);
	sf::Sprite & getActiveObject();
	sf::Vector2f getPosition();
};

