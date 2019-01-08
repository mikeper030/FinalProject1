#include "Rock.h"
#include <iostream>

////////////////////////////////////////////////////////
// c'tor rock
////////////////////////////////////////////////////////
Rock::Rock(sf::Vector2f position, sf::Vector2f size)
	:StaticObject("rock.png",position,size)
{
}
//////////////////////////////////////////////////////////
//  draw objet 
//////////////////////////////////////////////////////////

//@override
void Rock::draw(sf::RenderWindow & w)
{
	w.draw(m_sprite);
}
////////////////////////////////////////////////////////
// setting position by getting new position
////////////////////////////////////////////////////////

//override
void Rock::setPoisition(sf::Vector2f & position)
{
	m_position = position;
}
////////////////////////////////////////////////////////////
//  getting position of rock
////////////////////////////////////////////////////////////

//override
sf::Vector2f Rock::getPosition() const
{
	return m_position;
}

void Rock::collide(Object & otherObject)
{
}

void Rock::collide(Player & otherObject)
{
}

void Rock::collide(SmartGuard & otherObject)
{
}

void Rock::collide(DummyGuard & otherobject)
{
}

void Rock::collide(Wall & otherObject)
{
}

void Rock::collide(Rock & otherObject)
{
}



