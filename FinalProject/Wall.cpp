#include "Wall.h"
#include <iostream>

////////////////////////////////////////////////////////
// c'tor wall
////////////////////////////////////////////////////////
Wall::Wall(sf::Vector2f position, sf::Vector2f size)
	:StaticObject("wall.png",position,size)
{
	

}
//////////////////////////////////////////////////////////
//  draw object 
//////////////////////////////////////////////////////////

//@override java style..
void Wall::draw(sf::RenderWindow & w)
{
	w.draw(m_sprite);
}
////////////////////////////////////////////////////////
// setting position by getting new position
////////////////////////////////////////////////////////

//@override
void Wall::setPoisition(sf::Vector2f & position)
{
	m_position = position;
}
////////////////////////////////////////////////////////////
//  getting position of wall
////////////////////////////////////////////////////////////
sf::Vector2f Wall::getPosition() const
{
	return m_position;
}

void Wall::collide(Object & otherObject)
{
}

void Wall::collide(Player & otherObject)
{
}

void Wall::collide(SmartGuard & otherObject)
{
}

void Wall::collide(DummyGuard & otherobject)
{
}

void Wall::collide(Wall & otherObject)
{
}

void Wall::collide(Rock & otherObject)
{
}


