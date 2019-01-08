#pragma once
#include "DynamicObject.h"



class Player :public DynamicObject
{
public:
	Player(sf::Vector2f  position, sf::Vector2f size);
	void setPoisition(sf::Vector2f & position);
	void draw(sf::RenderWindow & w)override;
	void move(sf::Vector2f& pos, const std::vector<std::unique_ptr<Object>>& rects) override;
	
	sf::Vector2f getPosition() const override;

	 void setDeltaAspeed(float, float);

	void collide(Object & otherObject) override;
	 void collide(Player& otherObject) override;
	 void collide(SmartGuard& otherObject) override;
	 void collide(DummyGuard& otherobject) override;
	 void collide(Wall& otherObject)override;
	  void collide(Rock& otherObject) override;
};

