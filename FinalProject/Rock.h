#pragma once
#include "StaticObject.h"

class Rock :public StaticObject
{
public:
	Rock(sf::Vector2f position, sf::Vector2f size);
	void draw(sf::RenderWindow &);
	void setPoisition(sf::Vector2f &);
	sf::Vector2f getPosition() const;
	
	void collide(Object& otherObject, const std::vector<std::unique_ptr<DynamicObject>>& movable, const std::vector<std::unique_ptr<StaticObject>>& statics) override;
	void collide(Player& otherObject, const std::vector<std::unique_ptr<DynamicObject>>& movable, const std::vector<std::unique_ptr<StaticObject>>& statics) override;
	void collide(SmartGuard& otherObject, const std::vector<std::unique_ptr<DynamicObject>>& movable, const std::vector<std::unique_ptr<StaticObject>>& statics) override;
	void collide(DummyGuard& otherobject, const std::vector<std::unique_ptr<DynamicObject>>& movable, const std::vector<std::unique_ptr<StaticObject>>& statics)override;
	void collide(Wall& otherObject, const std::vector<std::unique_ptr<DynamicObject>>& movable, const std::vector<std::unique_ptr<StaticObject>>& statics) override;
	void collide(Rock& otherObject, const std::vector<std::unique_ptr<DynamicObject>>& movable, const std::vector<std::unique_ptr<StaticObject>>& statics) override;
};

