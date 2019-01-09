#pragma once
#include "Guard.h"
class Object;
class DynamicObject;
class StaticObject;

class DummyGuard :public Guard
{
public:
	
	DummyGuard(sf::Vector2f  position, sf::Vector2f size);

	void draw(sf::RenderWindow & w) override;
	void setPoisition(sf::Vector2f &);

	void changeDirection();

	bool collides(sf::Sprite & fr, const std::vector<std::unique_ptr<DynamicObject>>& objects1, const std::vector<std::unique_ptr<StaticObject>>& objects2);

	void checkAupdate(sf::Vector2f & pos, const std::vector<std::unique_ptr<DynamicObject>>& objects1, const std::vector<std::unique_ptr<StaticObject>>& objects2);

	void move(sf::Vector2f & pos, const std::vector<std::unique_ptr<DynamicObject>>& objects1, const std::vector<std::unique_ptr<StaticObject>>& objects2);

	

	

	
	
	sf::Vector2f getPosition() const;
	 void setDeltaAspeed(float, float) override;

	 void collide(Object& otherObject, const std::vector<std::unique_ptr<DynamicObject>>& movable, const std::vector<std::unique_ptr<StaticObject>>& statics) override;
	 void collide(Player& otherObject, const std::vector<std::unique_ptr<DynamicObject>>& movable, const std::vector<std::unique_ptr<StaticObject>>& statics) override;
	 void collide(SmartGuard& otherObject, const std::vector<std::unique_ptr<DynamicObject>>& movable, const std::vector<std::unique_ptr<StaticObject>>& statics) override;
	 void collide(DummyGuard& otherobject, const std::vector<std::unique_ptr<DynamicObject>>& movable, const std::vector<std::unique_ptr<StaticObject>>& statics)override;
	  void collide(Wall& otherObject, const std::vector<std::unique_ptr<DynamicObject>>& movable, const std::vector<std::unique_ptr<StaticObject>>& statics) override;
	  void collide(Rock& otherObject, const std::vector<std::unique_ptr<DynamicObject>>& movable, const std::vector<std::unique_ptr<StaticObject>>& statics) override;
private:
	
	
};

