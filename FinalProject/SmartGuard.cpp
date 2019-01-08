#include "SmartGuard.h"



SmartGuard::SmartGuard(sf::Vector2f  position, sf::Vector2f size)
	:Guard("guard.png",position,size)
{
}

void SmartGuard::move(sf::Vector2f & pos, const std::vector<std::unique_ptr<Object>>& objects)
{
}

void SmartGuard::setDeltaAspeed(float time, float speed)
{
	m_delta_time = time;
	m_speed = speed;
}


void SmartGuard::collide(Object & otherObject)
{
}

void SmartGuard::collide(Player & otherObject)
{
}

void SmartGuard::collide(SmartGuard & otherObject)
{
}

void SmartGuard::collide(DummyGuard & otherobject)
{
}

void SmartGuard::collide(Wall & otherObject)
{
}

void SmartGuard::collide(Rock & otherObject)
{
}


