#include "Door.h"



////////////////////////////////////////////////////////
// c'tor door
////////////////////////////////////////////////////////
Door::Door(sf::Vector2f position, sf::Vector2f size)
{
	m_texture.loadFromFile("door.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(sf::Vector2f(position));
	m_sprite.scale(sf::Vector2f(size.x / 40, size.y / 40));
	m_position = position;
	std::cout << "size :" << std::endl;
	std::cout << "wall  " << size.x << " " << size.y << std::endl;
	std::cout << "position :" << std::endl;
	std::cout << "wall  " << position.x << " " << position.y << std::endl;

}
//////////////////////////////////////////////////////////
//  draw objet 
//////////////////////////////////////////////////////////
void Door::draw(sf::RenderWindow & w)
{
	w.draw(m_sprite);
}
////////////////////////////////////////////////////////
// setting position by getting new position
////////////////////////////////////////////////////////
void Door::setPoisition(sf::Vector2f & position)
{
	m_position = position;
}
////////////////////////////////////////////////////////////
//  getting position of door
////////////////////////////////////////////////////////////
sf::Vector2f Door::getPosition()
{
	return m_position;
}

