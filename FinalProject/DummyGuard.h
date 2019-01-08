#pragma once
#include "Guard.h"
class Object;
class DummyGuard :public Guard
{
public:
	
	DummyGuard(sf::Vector2f  position, sf::Vector2f size);

	void draw(sf::RenderWindow & w) override;
	void setPoisition(sf::Vector2f &);
	
	void move(sf::Vector2f& pos, const std::vector<std::unique_ptr<Object>>& objects);

	void resetPosition();

	
	
	sf::Vector2f getPosition() const;
	 void setDeltaAspeed(float, float) override;

	 void collide(Object& otherObject, const std::vector<std::unique_ptr<Object>>& objects) override;
	 void collide(Player& otherObject, const std::vector<std::unique_ptr<Object>>& objects) override;
	 void collide(SmartGuard& otherObject, const std::vector<std::unique_ptr<Object>>& objects) override;
	 void collide(DummyGuard& otherobject, const std::vector<std::unique_ptr<Object>>& objects)override;
	  void collide(Wall& otherObject, const std::vector<std::unique_ptr<Object>>& objects) override;
	  void collide(Rock& otherObject, const std::vector<std::unique_ptr<Object>>& objects) override;
private:
	int m_setps = 100;
	int m_direction = 0;
};

