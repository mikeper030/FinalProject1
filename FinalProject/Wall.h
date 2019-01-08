#pragma once
#include "StaticObject.h"

class Wall :public StaticObject
{
public:
	Wall(sf::Vector2f position, sf::Vector2f size);
	void draw(sf::RenderWindow & w);
	void setPoisition(sf::Vector2f &);
	sf::Vector2f getPosition() const;
	

	void collide(Object& otherObject, const std::vector<std::unique_ptr<Object>>& objects) override;
	void collide(Player& otherObject, const std::vector<std::unique_ptr<Object>>& objects) override;
	void collide(SmartGuard& otherObject, const std::vector<std::unique_ptr<Object>>& objects) override;
	void collide(DummyGuard& otherobject, const std::vector<std::unique_ptr<Object>>& objects)override;
	void collide(Wall& otherObject, const std::vector<std::unique_ptr<Object>>& objects) override;
	void collide(Rock& otherObject, const std::vector<std::unique_ptr<Object>>& objects) override;
private:
};

