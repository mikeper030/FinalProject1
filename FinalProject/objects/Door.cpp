#include "headers/Door.h"
#include "headers/DummyGuard.h"
#include "headers/Controller.h"

////////////////////////////////////////////////////////
// c'tor door
////////////////////////////////////////////////////////
Door::Door(sf::Vector2f position, sf::Vector2f size)
	:StaticObject("res/door.png",position,size)
{
}

bool Door::collides(sf::Sprite & fr, const std::vector<std::unique_ptr<DynamicObject>>& objects1, const std::vector<std::unique_ptr<StaticObject>>& objects2)
{
	int i = 0;
	for (const auto& other : objects1)
	{
		// Don't collide with ourselves
		

		if (fr.getGlobalBounds().intersects(other->getSprite().getGlobalBounds()))
		{
			other->collide(*this, i);
			return true;
		}
	}
	i = 0;
	for (const auto& other : objects2)
	{
		if (this == other.get())
		{
			continue;
		}
		if (fr.getGlobalBounds().intersects(other->getSprite().getGlobalBounds()))
		{
			other->collide(*this, i);
			return true;
		}
	}
	return false;
}



void Door::collide(Object & otherObject, int index)
{
}

void Door::collide(Player & player, int index)
{
	Controller::setLevelFinished(true);
}

void Door::collide(SmartGuard & otherObject, int index)
{
}

void Door::collide(DummyGuard & guard, int index)
{
	guard.changeDirection();
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
