#pragma once
#include"Guard.h"

class SmartGuard :public Guard
{
public:
	SmartGuard(sf::Vector2f position, sf::Vector2f size);
    void move(sf::Vector2f&player_pos,sf::Vector2f& pos ,const std::vector<std::unique_ptr<DynamicObject>>& movable, const std::vector<std::unique_ptr<StaticObject>>& statics) override;
	sf::Vector2f  getStep(int direction);
	void checkAupdate(sf::Vector2f & pos, const std::vector<std::unique_ptr<DynamicObject>>& objects1, const std::vector<std::unique_ptr<StaticObject>>& objects2) override;
	bool collides(sf::Vector2f  new_position, sf::Sprite & fr, const std::vector<std::unique_ptr<DynamicObject>>& objects1,
		const std::vector<std::unique_ptr<StaticObject>>& objects2);
	void setDeltaAspeed(float time , float speed) ;
	bool collides(sf::Sprite & fr, const std::vector<std::unique_ptr<DynamicObject>>& objects1, const std::vector<std::unique_ptr<StaticObject>>& objects2);
	void changeDirection();
	void collide(Object& otherObject, int index) override;
	void collide(Player& otherObject, int index) override;
	void collide(SmartGuard& otherObject, int index) override;
	void collide(DummyGuard& otherobject, int index)override;
	void collide(Wall& otherObject, int index) override;
	void collide(Rock& otherObject, int index) override;
	void collide(Bomb& bomb, int index) override;

};

