#include "Door.h"
#include "DummyGuard.h"


////////////////////////////////////////////////////////
// c'tor door
////////////////////////////////////////////////////////
Door::Door(sf::Vector2f position, sf::Vector2f size)
	:StaticObject("door.png",position,size)
{
}

bool Door::collides(sf::Sprite & fr, const std::vector<std::unique_ptr<DynamicObject>>& objects1, const std::vector<std::unique_ptr<StaticObject>>& objects2)
{
	return false;
}



void Door::collide(Object & otherObject, int index)
{
}

void Door::collide(Player & otherObject, int index)
{
}

void Door::collide(SmartGuard & otherObject, int index)
{
}

void Door::collide(DummyGuard & otherobject, int index)
{
	otherobject.changeDirection();
}

void Door::collide(Wall & otherObject, int index)
{
}

void Door::collide(Rock & otherObject, int index)
{
}

void Door::collide(Bomb & bomb, int index)
{
}
