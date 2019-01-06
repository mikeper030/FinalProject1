#include "Player.h"
#include <iostream>

////////////////////////////////////////////////////////
// c'tor robot
////////////////////////////////////////////////////////
Player::Player(sf::Vector2f  position, sf::Vector2f size)
{
	m_texture.loadFromFile("Bomberman.png");
	float width = 216 / 12;
	float height = 24;
	sf::IntRect rectSourceSprite(width * 6, 0, width, height);
	m_sprite.setTexture(m_texture);
	m_sprite.setTextureRect(rectSourceSprite);
	m_sprite.setPosition(sf::Vector2f(position));
	m_sprite.scale(sf::Vector2f(size.x / (width * 2), size.y / (height * 2)));
	m_position = position;



	std::cout << "size :" << std::endl;
	std::cout << "robot  " << size.x << " " << size.y << std::endl;
	std::cout << "position :" << std::endl;
	std::cout << "robot  " << position.x << " " << position.y << std::endl;

}
////////////////////////////////////////////////////////
// setting position by getting new position
////////////////////////////////////////////////////////
void Player::setPoisition(sf::Vector2f & position)
{
	m_position = position;
}
//////////////////////////////////////////////////////////
//  draw objet 
//////////////////////////////////////////////////////////
void Player::draw(sf::RenderWindow & w)
{
	w.draw(m_sprite);
}
////////////////////////////////////////////////////////////
//  move active object
////////////////////////////////////////////////////////////
void Player::move(sf::Vector2f & new_position)
{
	m_sprite.move(new_position);
}
////////////////////////////////////////////////////////////
//  getting position of robot
////////////////////////////////////////////////////////////
sf::Vector2f Player::getPosition()
{
	return m_position;
}
//////////////////////////////////////////////////////////////
//  get object
//////////////////////////////////////////////////////////////
sf::Sprite & Player::getActiveObject()
{
	return m_sprite;
}


