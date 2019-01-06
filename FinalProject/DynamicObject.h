#pragma once
#include "Object.h"


class DynamicObject :public Object
{
public:
	DynamicObject();
	virtual void move(sf::Vector2f &);
	virtual sf::Sprite & getActiveObject();
	
};
