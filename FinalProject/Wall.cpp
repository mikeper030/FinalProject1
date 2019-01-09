#include "Wall.h"
#include <iostream>
#include "DummyGuard.h"
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

void Wall::collide(Object & otherObject, const std::vector<std::unique_ptr<DynamicObject>>& movable, 
	const std::vector<std::unique_ptr<StaticObject>>& statics)
{
}

void Wall::collide(Player & otherObject, const std::vector<std::unique_ptr<DynamicObject>>& movable,
	const std::vector<std::unique_ptr<StaticObject>>& statics)
{
}

void Wall::collide(SmartGuard & otherObject, const std::vector<std::unique_ptr<DynamicObject>>& movable, 
	const std::vector<std::unique_ptr<StaticObject>>& statics)
{
}

void Wall::collide(DummyGuard & otherobject, const std::vector<std::unique_ptr<DynamicObject>>& movable, 
	const std::vector<std::unique_ptr<StaticObject>>& statics)
{
	otherobject.changeDirection();
	std::cout << "change";
}

void Wall::collide(Wall & otherObject, const std::vector<std::unique_ptr<DynamicObject>>& movable,
	const std::vector<std::unique_ptr<StaticObject>>& statics)
{
}

void Wall::collide(Rock & otherObject, const std::vector<std::unique_ptr<DynamicObject>>& movable, 
	const std::vector<std::unique_ptr<StaticObject>>& statics)
{
}
