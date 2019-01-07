#pragma once
#include "Object.h"


class DynamicObject :public Object
{
public:
	DynamicObject();
	virtual void move(sf::Vector2f &)=0;
	virtual sf::Sprite & getActiveObject()=0;
	
};
