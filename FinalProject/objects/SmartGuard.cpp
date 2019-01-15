#include "headers/SmartGuard.h"
#include "headers/StaticObject.h"
#include "headers/Player.h"
#include "headers/DummyGuard.h"
#include <iostream>

SmartGuard::SmartGuard(sf::Vector2f  position, sf::Vector2f size)
	:Guard("res/SmartGuard.png",position,size)
{
	m_sprite.scale(sf::Vector2f((size.x / 40)*0.4, (size.y / 40)*0.4));
}
void SmartGuard::changeDirection()
{
	int range = 4;
	//random the direction		
	m_direction = rand() % range + 1;

	if (m_prev_direction == m_direction)
		m_direction = rand() % range + 1;

}
//@override
void SmartGuard::checkAupdate(sf::Vector2f & pos, const std::vector<std::unique_ptr<DynamicObject>>& objects1, const std::vector<std::unique_ptr<StaticObject>>& objects2)
{

}
bool SmartGuard::collides(sf::Sprite & fr, const std::vector<std::unique_ptr<DynamicObject>>& objects1, const std::vector<std::unique_ptr<StaticObject>>& objects2)
{
	int i = 0;
	for (const auto& other : objects1)
	{
		// Don't collide with ourselves
		if (this == other.get())
		{
			continue;
		}

		if (fr.getGlobalBounds().intersects(other->getSprite().getGlobalBounds()))
		{
			other->collide(*this, i);
			return true;
		}
	}
	i = 0;
	for (const auto& other : objects2)
	{
		if (fr.getGlobalBounds().intersects(other->getSprite().getGlobalBounds()))
		{
			other->collide(*this, i);
			return true;
		}
	}
	return false;
}
bool SmartGuard::collides(sf::Vector2f new_position, sf::Sprite & fr, const std::vector<std::unique_ptr<DynamicObject>>& objects1, const std::vector<std::unique_ptr<StaticObject>>& objects2)
{
	sf::Sprite copy_guard;
	copy_guard.setTexture(*fr.getTexture());
	copy_guard.setScale(fr.getScale());
	copy_guard.setPosition(sf::Vector2f(new_position));

	int i = 0;
	for (const auto& other : objects1)
	{
		// Don't collide with ourselves
		if (this == other.get())
		{
			continue;
		}

		if (copy_guard.getGlobalBounds().intersects(other->getSprite().getGlobalBounds()))
		{
			other->collide(*this, i);
			return true;
		}
		i++;
	}
	i = 0;
	for (const auto& other : objects2)
	{
		if (copy_guard.getGlobalBounds().intersects(other->getSprite().getGlobalBounds()))
		{
			other->collide(*this, i);
			return true;
		}
	}
	return false;
}
void SmartGuard::move(sf::Vector2f&Playerposition,sf::Vector2f & pos, const std::vector<std::unique_ptr<DynamicObject>>& movable, const std::vector<std::unique_ptr<StaticObject>>& statics)
{
	if (m_direction != 0)
	{
		pos = getStep(m_direction);
		
		if (!collides(m_sprite, movable, statics))
		{
			m_sprite.move(pos);
			m_position = (pos);
		}
		else
		{
			m_sprite.move(-pos);
			m_position = (-pos);
		    m_direction = 0;

		}	
	}
	else
	{
		if (std::abs(m_sprite.getPosition().x - Playerposition.x) > std::abs((m_sprite.getPosition().x + (m_speed*m_delta_time)) - Playerposition.x)
			&& !collides(sf::Vector2f(m_sprite.getPosition().x + (m_speed*m_delta_time), m_sprite.getPosition().y), m_sprite, movable, statics))
		{
			m_sprite.move(pos.x + (m_speed*m_delta_time), pos.y);
		}
		else
			if (std::abs(m_sprite.getPosition().x - Playerposition.x) > std::abs((m_sprite.getPosition().x - (m_speed*m_delta_time)) - Playerposition.x)
				&& !collides(sf::Vector2f(m_sprite.getPosition().x - (m_speed*m_delta_time), m_sprite.getPosition().y), m_sprite, movable, statics))
			{

				m_sprite.move(pos.x - (m_speed*m_delta_time), pos.y);
				/*if (collides(m_sprite, objects1, objects2))
					m_sprite.move(pos.x+(m_speed*m_delta_time) ,pos.y );*/
			}
			else
				if (std::abs(m_sprite.getPosition().y - Playerposition.y) > std::abs((m_sprite.getPosition().y - (m_speed*m_delta_time)) - Playerposition.y)
					&& !collides(sf::Vector2f(m_sprite.getPosition().x, m_sprite.getPosition().y - (m_speed*m_delta_time)), m_sprite, movable, statics))
				{

					m_sprite.move(pos.x, pos.y - (m_speed * m_delta_time));

				}
				else
					if (std::abs(m_sprite.getPosition().y - Playerposition.y) > std::abs((m_sprite.getPosition().y + (m_speed*m_delta_time)) - Playerposition.y)
						&& !collides(sf::Vector2f(m_sprite.getPosition().x, m_sprite.getPosition().y + (m_speed*m_delta_time)), m_sprite, movable, statics))
					{
						m_sprite.move(pos.x, pos.y + (m_speed * m_delta_time));
					}
	}
}
sf::Vector2f  SmartGuard::getStep(int direction)
{
	sf::Vector2f v;
	switch (m_direction)
	{

	case 1:
		//right
		v = sf::Vector2f{ m_speed*m_delta_time , 0.f };
		break;

	case 2:
		//left
		v = sf::Vector2f{ -m_speed * m_delta_time, 0.f };
		break;
	case 3:
		//up
		v = sf::Vector2f{ 0.f,m_speed*m_delta_time };
		break;
	case 4:
		//down
		v = sf::Vector2f{ 0.f, m_delta_time*-m_speed };

		break;
	}
	return v;
}


void SmartGuard::setDeltaAspeed(float time, float speed)
{
	m_delta_time = time;
	m_speed = speed;
}

void SmartGuard::collide(Object & otherObject, int index)
{
}

void SmartGuard::collide(Player & player, int index)
{
	player.dropLife();

}

void SmartGuard::collide(SmartGuard & otherObject, int index)
{
}

void SmartGuard::collide(DummyGuard & dummyGuard, int index)
{
	dummyGuard.changeDirection();
}

void SmartGuard::collide(Wall & otherObject, int index)
{

}

void SmartGuard::collide(Rock & otherObject, int index)
{
}

void SmartGuard::collide(Bomb & bomb, int index)
{
	//collision of dummy guard and bomb first make guard invisible
	GameBoardManager::getDynamicObjects().erase(GameBoardManager::getDynamicObjects().begin() + index);
	//now add score
	GameBoardManager::addScore();
}
