#pragma once
#include "Guard.h"
class Object;
class DynamicObject;
class StaticObject;

class DummyGuard :public Guard
{
public:
	
	DummyGuard(sf::Vector2f  position, sf::Vector2f size);

	
	

	void changeDirection();

	 bool collides(sf::Sprite & fr, const std::vector<std::unique_ptr<DynamicObject>>& objects1, const std::vector<std::unique_ptr<StaticObject>>& objects2) override;
	 void checkAupdate(sf::Vector2f & pos, const std::vector<std::unique_ptr<DynamicObject>>& objects1, const std::vector<std::unique_ptr<StaticObject>>& objects2) override;
	 void move(sf::Vector2f & pos, const std::vector<std::unique_ptr<DynamicObject>>& objects1, const std::vector<std::unique_ptr<StaticObject>>& objects2) override;

	
	 void setDeltaAspeed(float, float) override;

	 void collide(Object& otherObject, int index) override;
	 void collide(Player& otherObject, int index) override;
	 void collide(SmartGuard& otherObject, int index) override;
	 void collide(DummyGuard& otherobject, int index)override;
	  void collide(Wall& otherObject, int index) override;
	  void collide(Rock& otherObject, int index) override;
	  void collide(Bomb& bomb, int index) override;

private:
	
	
};

