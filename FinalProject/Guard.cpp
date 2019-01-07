#include "Guard.h"
#include <iostream>

////////////////////////////////////////////////////////
// c'tor guard
////////////////////////////////////////////////////////
Guard::Guard(sf::Vector2f  position, sf::Vector2f size)
{
	m_texture.loadFromFile("guard.png");
	m_sprite.setTexture(m_texture);
	//m_rectangle.setSize(size);
	m_sprite.setPosition(position);
	m_sprite.scale(sf::Vector2f(size.x / 40, size.y / 40));
	m_position = position;
	std::cout << "size :" << std::endl;
	std::cout << "guard  " << size.x << " " << size.y << std::endl;
	std::cout << "position :" << std::endl;
	std::cout << "guard  " << position.x << " " << position.y << std::endl;
}
//////////////////////////////////////////////////////////
//  draw objet 
//////////////////////////////////////////////////////////
//@override
void Guard::draw(sf::RenderWindow & w)
{
	w.draw(m_sprite);
}
////////////////////////////////////////////////////////
// setting position by getting new position
////////////////////////////////////////////////////////
//@override
void Guard::setPoisition(sf::Vector2f &position)
{
	m_position = position;
}
////////////////////////////////////////////////////////////
//  move active object
////////////////////////////////////////////////////////////
void Guard::move(sf::Vector2f & new_position)
{
	m_sprite.move(new_position);
}
sf::Sprite & Guard::getActiveObject()
{
	return m_sprite;
}
////////////////////////////////////////////////////////////
//  getting position of guard
////////////////////////////////////////////////////////////
sf::Vector2f Guard::getPosition()
{
	return m_position;
}

