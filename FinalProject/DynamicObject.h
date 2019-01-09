#pragma once
#include "Object.h"




class DynamicObject :public Object
//abstract Dynamic objects base class

{
public:
	DynamicObject(std::string, sf::Vector2f, sf::Vector2f);
	
	virtual void move(sf::Vector2f& pos , const std::vector<std::unique_ptr<DynamicObject>>& movable, const std::vector<std::unique_ptr<StaticObject>>& statics)=0;
	
	
	virtual void setDeltaAspeed(float, float) = 0;
	
	
	//virtual void collide(Bomb& otherObject) = 0;

protected:
	float m_delta_time;
	float m_speed;
	int m_prev_direction = 0;
	int m_direction = 0;

	
};
