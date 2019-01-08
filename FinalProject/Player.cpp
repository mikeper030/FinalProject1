#include "Player.h"
#include <iostream>

////////////////////////////////////////////////////////
// c'tor robot
////////////////////////////////////////////////////////
Player::Player(sf::Vector2f  position, sf::Vector2f size)
	:DynamicObject("Bomberman.png",position,size)
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

//override
void Player::setPoisition(sf::Vector2f & position)
{
	m_position = position;
}
//////////////////////////////////////////////////////////
//  draw object 
//////////////////////////////////////////////////////////

//override
void Player::draw(sf::RenderWindow & w)
{
	w.draw(m_sprite);
}

////////////////////////////////////////////////////////////
//  move active object
////////////////////////////////////////////////////////////
//@override
void Player::move(sf::Vector2f& pos, const std::vector<std::unique_ptr<Object>>& rects)
{
	m_sprite.move(pos);
}


////////////////////////////////////////////////////////////
//  getting position of robot
////////////////////////////////////////////////////////////

//override
sf::Vector2f Player::getPosition() const
{
	return m_position;
}
//////////////////////////////////////////////////////////////
//  get object
//////////////////////////////////////////////////////////////



void Player::setDeltaAspeed(float time, float speed)
{
	m_delta_time = time;
	m_speed = speed;
}



void Player::collide(Object & otherObject)
{
}

void Player::collide(Player & otherObject)
{
}

void Player::collide(SmartGuard & otherObject)
{
}

void Player::collide(DummyGuard & otherobject)
{
}

void Player::collide(Wall & otherObject)
{
}

void Player::collide(Rock & otherObject)
{
}


