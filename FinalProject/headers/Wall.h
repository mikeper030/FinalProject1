#pragma once
#include "StaticObject.h"

class Wall :public StaticObject
{
public:
	Wall(sf::Vector2f position, sf::Vector2f size);
	
	bool collides(sf::Sprite & fr, const std::vector<std::unique_ptr<DynamicObject>>& objects1, const std::vector<std::unique_ptr<StaticObject>>& objects2) override;


	void collide(Object& otherObject, int index) override;
	void collide(Player& otherObject, int index) override;
	void collide(SmartGuard& otherObject, int index) override;
	void collide(DummyGuard& otherobject, int index)override;
	void collide(Wall& otherObject, int index) override;
	void collide(Rock& otherObject, int index) override;
	void collide(Bomb& bomb, int index) override;
private:
	bool is_collided = false;
};

