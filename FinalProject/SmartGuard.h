#pragma once
#include"Guard.h"
class SmartGuard :public Guard
{
public:
	SmartGuard(sf::Vector2f position, sf::Vector2f size);
    void move(sf::Vector2f& pos, const std::vector<std::unique_ptr<Object>>& rects) override;
	
	
	void setDeltaAspeed(float time , float speed) ;
	 
	void collide(Object& otherObject) override;
	void collide(Player& otherObject) override;
	void collide(SmartGuard& otherObject) override;
	void collide(DummyGuard& otherobject)override;
	void collide(Wall& otherObject) override;
	void collide(Rock& otherObject) override;
};

