#include "Rock.h"
#include <iostream>

////////////////////////////////////////////////////////
// c'tor rock
////////////////////////////////////////////////////////
Rock::Rock(sf::Vector2f position, sf::Vector2f size)
{
	m_texture.loadFromFile("rock.png");
	m_sprite.setTexture(m_texture);
	//	m_sprite.setSize(size);
	m_sprite.setPosition(position);
	m_sprite.scale(sf::Vector2f(size.x / 40, size.y / 40));
	m_position = position;
	std::cout << "size :" << std::endl;
	std::cout << "rock  " << size.x << " " << size.y << std::endl;
	std::cout << "position :" << std::endl;
	std::cout << "rock  " << position.x << " " << position.y << std::endl;

}
//////////////////////////////////////////////////////////
//  draw objet 
//////////////////////////////////////////////////////////
void Rock::draw(sf::RenderWindow & w)
{
	w.draw(m_sprite);
}
////////////////////////////////////////////////////////
// setting position by getting new position
////////////////////////////////////////////////////////
void Rock::setPoisition(sf::Vector2f & position)
{
	m_position = position;
}
////////////////////////////////////////////////////////////
//  getting position of rock
////////////////////////////////////////////////////////////
sf::Vector2f Rock::getPosition()
{
	return m_position;
}



