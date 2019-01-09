#include "SmartGuard.h"



SmartGuard::SmartGuard(sf::Vector2f  position, sf::Vector2f size)
	:Guard("guard.png",position,size)
{
}

void SmartGuard::move(sf::Vector2f & pos, const std::vector<std::unique_ptr<DynamicObject>>& movable, const std::vector<std::unique_ptr<StaticObject>>& statics)
{
}


void SmartGuard::setDeltaAspeed(float time, float speed)
{
	m_delta_time = time;
	m_speed = speed;
}

void SmartGuard::collide(Object & otherObject, const std::vector<std::unique_ptr<DynamicObject>>& movable, 
	const std::vector<std::unique_ptr<StaticObject>>& statics)
{
}

void SmartGuard::collide(Player & otherObject, const std::vector<std::unique_ptr<DynamicObject>>& movable,
	const std::vector<std::unique_ptr<StaticObject>>& statics)
{
}

void SmartGuard::collide(SmartGuard & otherObject, const std::vector<std::unique_ptr<DynamicObject>>& movable,
	const std::vector<std::unique_ptr<StaticObject>>& statics)
{
}

void SmartGuard::collide(DummyGuard & otherobject, const std::vector<std::unique_ptr<DynamicObject>>& movable, 
	const std::vector<std::unique_ptr<StaticObject>>& statics)
{
}

void SmartGuard::collide(Wall & otherObject, const std::vector<std::unique_ptr<DynamicObject>>& movable,
	const std::vector<std::unique_ptr<StaticObject>>& statics)
{
}

void SmartGuard::collide(Rock & otherObject, const std::vector<std::unique_ptr<DynamicObject>>& movable, 
	const std::vector<std::unique_ptr<StaticObject>>& statics)
{
}
