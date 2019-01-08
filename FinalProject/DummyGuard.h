#pragma once
#include "Guard.h"
class Object;
class DummyGuard :public Guard
{
public:
	
	DummyGuard(sf::Vector2f  position, sf::Vector2f size);

	void draw(sf::RenderWindow & w) override;
	void setPoisition(sf::Vector2f &);
	
	void move(sf::Vector2f & new_position, const std::vector<std::unique_ptr<Object>>& objects);

	
	
	sf::Vector2f getPosition() const;
	 void setDeltaAspeed(float, float) override;

	 void collide(Object& otherObject) override;
	 void collide(Player& otherObject) override;
	 void collide(SmartGuard& otherObject) override;
	 void collide(DummyGuard& otherobject)override;
	  void collide(Wall& otherObject) override;
	  void collide(Rock& otherObject) override;
	  void randomMove();
};

