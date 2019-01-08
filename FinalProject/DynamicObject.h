#pragma once
#include "Object.h"




class DynamicObject :public Object
//abstract Dynamic objects base class

{
public:
	DynamicObject(std::string, sf::Vector2f, sf::Vector2f);
	
	virtual void move(sf::Vector2f& pos , const std::vector<std::unique_ptr<Object>>& rects)=0;
	
	
	virtual void setDeltaAspeed(float, float) = 0;
	
	
	//virtual void collide(Bomb& otherObject) = 0;

protected:
	int m_delta_time;
	int m_speed;

	
};
