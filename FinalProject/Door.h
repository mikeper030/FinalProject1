#pragma once
#include "StaticObject.h"
#include <iostream>
class Door :public StaticObject
{
public:
	Door(sf::Vector2f position, sf::Vector2f size);
	void draw(sf::RenderWindow & w) override;
	void setPoisition(sf::Vector2f &) override;
	sf::Vector2f getPosition() const override;

	void collide(Object& otherObject) override;
	void collide(Player& otherObject) override;
	void collide(SmartGuard& otherObject) override;
	void collide(DummyGuard& otherobject)override;
	void collide(Wall& otherObject) override;
	void collide(Rock& otherObject) override;
};

