#pragma once
#include"Guard.h"
class SmartGuard :public Guard
{
public:
	SmartGuard(sf::Vector2f position, sf::Vector2f size);
    void move(sf::Vector2f& pos ,const std::vector<std::unique_ptr<DynamicObject>>& movable, const std::vector<std::unique_ptr<StaticObject>>& statics) override;
	
	
	void setDeltaAspeed(float time , float speed) ;
	 
	void collide(Object& otherObject, const std::vector<std::unique_ptr<DynamicObject>>& movable, const std::vector<std::unique_ptr<StaticObject>>& statics) override;
	void collide(Player& otherObject, const std::vector<std::unique_ptr<DynamicObject>>& movable, const std::vector<std::unique_ptr<StaticObject>>& statics) override;
	void collide(SmartGuard& otherObject, const std::vector<std::unique_ptr<DynamicObject>>& movable, const std::vector<std::unique_ptr<StaticObject>>& statics) override;
	void collide(DummyGuard& otherobject, const std::vector<std::unique_ptr<DynamicObject>>& movable, const std::vector<std::unique_ptr<StaticObject>>& statics)override;
	void collide(Wall& otherObject, const std::vector<std::unique_ptr<DynamicObject>>& movable, const std::vector<std::unique_ptr<StaticObject>>& statics) override;
	void collide(Rock& otherObject, const std::vector<std::unique_ptr<DynamicObject>>& movable, const std::vector<std::unique_ptr<StaticObject>>& statics) override;
};

