#include "headers/DummyGuard.h"
#include "headers/GameBoardManager.h"

////////////////////////////////////////////////////////
// c'tor guard
////////////////////////////////////////////////////////
DummyGuard::DummyGuard(sf::Vector2f  position, sf::Vector2f size)
	:Guard("res/guard.png",position,size)
{
	int range = 4;
	
	//random the direction
	m_direction = rand() % range + 1;
	m_prev_direction = m_direction;
	setPoisition(position);
	m_start_pos = position;
}

void DummyGuard::changeDirection()
{
	
		int range = 4;	
		//random the direction		
		
		m_direction = rand() % range + 1;
		
		if(m_prev_direction==m_direction)
			m_direction = rand() % range + 1;
		std::cout << m_direction;
		//m_prev_direction = m_direction;
	
}

//@override
bool DummyGuard::collides(sf::Sprite & fr, const std::vector<std::unique_ptr<DynamicObject>>& objects1, const std::vector<std::unique_ptr<StaticObject>>& objects2)
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
			other->collide(*this,i);
			return true;
		}
	}
	i = 0;
	for (const auto& other : objects2)
	{
		if (fr.getGlobalBounds().intersects(other->getSprite().getGlobalBounds()))
		{
			other->collide(*this,i);
			return true;
		}
	}
	return false;
}


//@override
void DummyGuard::checkAupdate(sf::Vector2f & pos, const std::vector<std::unique_ptr<DynamicObject>>& objects1, const std::vector<std::unique_ptr<StaticObject>>& objects2)
{
	if (!collides(m_sprite, objects1, objects2))
	{
		m_sprite.move(pos);
		m_position = (pos);
	}
	else
	{
		m_sprite.move(-pos);
		m_position = (-pos);
	}
}



////////////////////////////////////////////////////////////
//  move active object
////////////////////////////////////////////////////////////
void DummyGuard::move(sf::Vector2f&,sf::Vector2f& pos,const std::vector<std::unique_ptr<DynamicObject>>& objects1, const std::vector<std::unique_ptr<StaticObject>>& objects2)
{		
	//std::cout << m_direction;
	sf::Vector2f v;
	switch (m_direction)
		{

		case 1:
			//right
			v = sf::Vector2f{ m_speed*m_delta_time , 0.f };
			checkAupdate(v, objects1, objects2);
			  break;
		
		case 2:
			//left
			v = sf::Vector2f{ -m_speed * m_delta_time, 0.f };
			checkAupdate(v, objects1, objects2);
			   break;
		case 3:
			//up
			v = sf::Vector2f{ 0.f,m_speed*m_delta_time };
	        	checkAupdate(v, objects1, objects2);
				break;
		case 4:
			//down
			v = sf::Vector2f{ 0.f, m_delta_time*-m_speed };
			checkAupdate(v, objects1, objects2);
				
				break;	
	}
	
}



void DummyGuard::setDeltaAspeed(float time, float speed)
{
	m_delta_time = time;
	m_speed = speed;
}

void DummyGuard::collide(Object & otherObject, int index)
{
}

void DummyGuard::collide(Player & player, int index)
{
	player.dropLife();

}

void DummyGuard::collide(SmartGuard & otherObject, int index)
{
}

void DummyGuard::collide(DummyGuard & dummyGuard, int index)
{
	dummyGuard.changeDirection();
}

void DummyGuard::collide(Wall & otherObject, int index)
{

}

void DummyGuard::collide(Rock & otherObject, int index)
{
}

void DummyGuard::collide(Bomb & bomb, int index)
{
	//collision of dummy guard and bomb first make guard invisible
	GameBoardManager::getDynamicObjects().erase(GameBoardManager::getDynamicObjects().begin() + index);
	//now add score
	GameBoardManager::addScore();
}


