#include "SmartGuard.h"



SmartGuard::SmartGuard(sf::Vector2f  position, sf::Vector2f size)
	:Guard("guard.png",position,size)
{
}
//@override
bool SmartGuard::collides(sf::Sprite & fr, const std::vector<std::unique_ptr<DynamicObject>>& objects1, const std::vector<std::unique_ptr<StaticObject>>& objects2)
{
	return false;
}
//@override
void SmartGuard::checkAupdate(sf::Vector2f & pos, const std::vector<std::unique_ptr<DynamicObject>>& objects1, const std::vector<std::unique_ptr<StaticObject>>& objects2)
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

void SmartGuard::collide(Object & otherObject, int index)
{
}

void SmartGuard::collide(Player & otherObject, int index)
{
}

void SmartGuard::collide(SmartGuard & otherObject, int index)
{
}

void SmartGuard::collide(DummyGuard & otherobject, int index)
{
}

void SmartGuard::collide(Wall & otherObject, int index)
{
}

void SmartGuard::collide(Rock & otherObject, int index)
{
}

void SmartGuard::collide(Bomb & bomb, int index)
{
}
