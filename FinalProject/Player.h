#pragma once
#include "DynamicObject.h"



class Player :public DynamicObject
{
public:
	Player(sf::Vector2f  position, sf::Vector2f size);
	void setPoisition(sf::Vector2f & position);
	void draw(sf::RenderWindow & w);
	void move(sf::Vector2f& new_position);
	sf::Vector2f getPosition();
	sf::Sprite & getActiveObject();
};

