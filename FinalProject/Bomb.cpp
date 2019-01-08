#include "Bomb.h"
#include "StaticObject.h"


Bomb::Bomb(sf::Vector2f position, sf::Vector2f size)
	:StaticObject("bomb.png", position, size)
{
}

void Bomb::draw(sf::RenderWindow & w)
{
}

void Bomb::setPoisition(sf::Vector2f &)
{
}

sf::Vector2f Bomb::getPosition() const
{
	return sf::Vector2f();
}

void Bomb::collide(Object & otherObject)
{
}

void Bomb::collide(Player & otherObject)
{
}

void Bomb::collide(SmartGuard & otherObject)
{
}

void Bomb::collide(DummyGuard & otherobject)
{
}

void Bomb::collide(Wall & otherObject)
{
}

void Bomb::collide(Rock & otherObject)
{
}



