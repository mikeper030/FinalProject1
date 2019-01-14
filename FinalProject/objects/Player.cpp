#include "headers/Player.h"
#include <iostream>

//static initialization================
std::vector<sf::IntRect> Player::sheet;
sf::Vector2f Player::m_pos; 
int Player::m_lives = 4;
//=====================================

////////////////////////////////////////////////////////
// c'tor Player
////////////////////////////////////////////////////////
Player::Player(sf::Vector2f  position, sf::Vector2f size)
	:DynamicObject("res/Bomberman.png",position,size)
{
	m_texture.loadFromFile("res/Bomberman.png");
	m_sprite.setTexture(m_texture);
	m_start_pos = position;
	float sprite_width = 18;
	float sprite_height = 24;
	sf::IntRect rectSourceSprite1(0, 0, sprite_width, sprite_height);
	sf::IntRect rectSourceSprite2(sprite_width * 3, 0, sprite_width, sprite_height);
	sf::IntRect rectSourceSprite3(sprite_width * 6, 0, sprite_width, sprite_height);
	sf::IntRect rectSourceSprite4(sprite_width * 9, 0, sprite_width, sprite_height);
	sheet.push_back(rectSourceSprite1);
	sheet.push_back(rectSourceSprite2);
	sheet.push_back(rectSourceSprite3);
	sheet.push_back(rectSourceSprite4);
	m_pos = getPosition();
	moving = true;
	
	float width = 216 / 12;
	float height = 24;
	

	m_sprite.setTextureRect(rectSourceSprite3);
	m_sprite.setPosition(sf::Vector2f(position));
	m_sprite.scale(sf::Vector2f(size.x / (width*1.3 ), size.y / (height*1.3 )));
	m_position = position;

}

////////////////////////////////////////////////////////
// setting position by getting new position
////////////////////////////////////////////////////////
std::vector<sf::IntRect>& Player::getSheet()
{
	return sheet;
}

//////////////////////////////////////////////////////////
//  draw object 
//////////////////////////////////////////////////////////


//@override
bool Player::collides(sf::Sprite & fr, const std::vector<std::unique_ptr<DynamicObject>>& objects1, const std::vector<std::unique_ptr<StaticObject>>& objects2)
{
	int index = 0;
	for (const auto& other : objects1)
	{
		// Don't collide with ourselves and bombs
		if (this == other.get())
		{
			continue;
		}

		if (fr.getGlobalBounds().intersects(other->getSprite().getGlobalBounds()))
		{

			other->collide(*this, index );
			moving = false;
			return true;
		}
	}
	for (const auto& other : objects2)
	{
		std::string name = typeid(*other).name();
		if (name.compare("class Bomb") == 0)
			continue;
		
		
			

		if (fr.getGlobalBounds().intersects(other->getSprite().getGlobalBounds()))
		{
			other->collide(*this, index);
			
			return true;
		}

	}
	
	return false;

}

void Player::dropLife()
{
	switch (m_lives)
	{
	case 4:
		m_lives = 3;
		//m_pos = m_start_pos;
		//m_sprite.move(m_start_pos);
		Controller::setRestart(true);
		break;
	case 3:
		m_lives = 2;
		//m_pos = m_start_pos;
		//m_sprite.move(m_start_pos);
		Controller::setRestart(true);
		break;
	case 2:
		m_lives = 1;
		//m_pos = m_start_pos;
		//m_sprite.move(m_start_pos);
		Controller::setRestart(true);
		break;
	case 1:
		m_lives = 0;
		//m_pos = m_start_pos;
		//m_sprite.move(m_start_pos);
		Controller::setRestart(true);
		break;
	}
	
}
int Player::getLives()
{
	return m_lives;
}

//@override
void Player::checkAupdate(sf::Vector2f & pos, const std::vector<std::unique_ptr<DynamicObject>>& objects1, const std::vector<std::unique_ptr<StaticObject>>& objects2)
{

}
sf::Vector2f& Player::getPosition()
{
	return m_pos;
}
////////////////////////////////////////////////////////////
//  move active object
////////////////////////////////////////////////////////////
//@override
void Player::move(sf::Vector2f& player_pos,sf::Vector2f& pos, const std::vector<std::unique_ptr<DynamicObject>>& movable,
	const std::vector<std::unique_ptr<StaticObject>>& statics)
{
	m_sprite.move(pos);
	sf::Vector2f x = m_sprite.getPosition();
	setPoisition(x);
	m_pos = m_sprite.getPosition();
	
	if (collides(m_sprite, movable, statics))
	{	
		
		
		m_sprite.move(-pos);
		m_pos = m_sprite.getPosition();
		sf::Vector2f n = m_sprite.getPosition();
		setPoisition(n);
	}
		
}






void Player::setDeltaAspeed(float time, float speed)
{
	m_delta_time = time;
	m_speed = speed;
}

void Player::setMoving(bool move)
{
	
}

void Player::collide(Object & otherObject, int index)
{
}

void Player::collide(Player & otherObject, int index)
{

}

void Player::collide(SmartGuard & otherObject, int index)
{
	dropLife();
 }

void Player::collide(DummyGuard & otherobject, int index)
{
	dropLife();
}

void Player::collide(Wall & otherObject, int index)
{
}

void Player::collide(Rock & otherObject, int index)
{
}

void Player::collide(Bomb & bomb, int index)
{
	dropLife();
}
