#include "Door.h"



////////////////////////////////////////////////////////
// c'tor door
////////////////////////////////////////////////////////
Door::Door(sf::Vector2f position, sf::Vector2f size)
	:StaticObject("door.png",position,size)
{
}
//////////////////////////////////////////////////////////
//  draw objet 
//////////////////////////////////////////////////////////

//@override 
void Door::draw(sf::RenderWindow & w) 
{
	w.draw(m_sprite);
}
////////////////////////////////////////////////////////
// setting position by getting new position
////////////////////////////////////////////////////////

//@override
void Door::setPoisition(sf::Vector2f & position)
{
	m_position = position;
}
////////////////////////////////////////////////////////////
//  getting position of door
////////////////////////////////////////////////////////////

//@override
sf::Vector2f Door::getPosition() const
{
	return m_position;
}

void Door::collide(Object & otherObject)
{
}

void Door::collide(Player & otherObject)
{
}

void Door::collide(SmartGuard & otherObject)
{
}

void Door::collide(DummyGuard & otherobject)
{
}

void Door::collide(Wall & otherObject)
{
}

void Door::collide(Rock & otherObject)
{
}

