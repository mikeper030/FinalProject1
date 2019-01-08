#pragma once
#include "StaticObject.h"

class Rock :public StaticObject
{
public:
	Rock(sf::Vector2f position, sf::Vector2f size);
	void draw(sf::RenderWindow &);
	void setPoisition(sf::Vector2f &);
	sf::Vector2f getPosition() const;
	
	void collide(Object& otherObject) override;
	void collide(Player& otherObject) override;
	void collide(SmartGuard& otherObject) override;
	void collide(DummyGuard& otherobject)override;
	void collide(Wall& otherObject) override;
	void collide(Rock& otherObject) override;
};

