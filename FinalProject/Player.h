#pragma once
#include "DynamicObject.h"
#include "StaticObject.h"


class Player :public DynamicObject
{
public:
	Player(sf::Vector2f  position, sf::Vector2f size);
	void setPoisition(sf::Vector2f & position);
	void draw(sf::RenderWindow & w)override;
	void move(sf::Vector2f& pos, const std::vector<std::unique_ptr<DynamicObject>>& movable, const std::vector<std::unique_ptr<StaticObject>>& statics) override;
	
	sf::Vector2f getPosition() const override;

	 void setDeltaAspeed(float, float);

	void collide(Object & otherObject, const std::vector<std::unique_ptr<DynamicObject>>& movable, const std::vector<std::unique_ptr<StaticObject>>& statics) override;
	 void collide(Player& otherObject, const std::vector<std::unique_ptr<DynamicObject>>& movable, const std::vector<std::unique_ptr<StaticObject>>& statics) override;
	 void collide(SmartGuard& otherObject, const std::vector<std::unique_ptr<DynamicObject>>& movable, const std::vector<std::unique_ptr<StaticObject>>& statics) override;
	 void collide(DummyGuard& otherobject, const std::vector<std::unique_ptr<DynamicObject>>& movable, const std::vector<std::unique_ptr<StaticObject>>& statics )override;
	 void collide(Wall& otherObject, const std::vector<std::unique_ptr<DynamicObject>>& movable, const std::vector<std::unique_ptr<StaticObject>>& staticss)override;
	  void collide(Rock& otherObject, const std::vector<std::unique_ptr<DynamicObject>>& movable, const std::vector<std::unique_ptr<StaticObject>>& statics) override;
};

