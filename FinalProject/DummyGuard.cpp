#include "DummyGuard.h"
#include "GameBoardManager.h"


////////////////////////////////////////////////////////
// c'tor guard
////////////////////////////////////////////////////////
DummyGuard::DummyGuard(sf::Vector2f  position, sf::Vector2f size)
	:Guard("guard.png",position,size)
{
	int range = 4;
	
	//random the direction
	m_direction = rand() % range + 1;
	m_prev_direction = m_direction;
	setPoisition(position);
}
//////////////////////////////////////////////////////////
//  draw object 
//////////////////////////////////////////////////////////

//@override
void DummyGuard::draw(sf::RenderWindow & w)
{
	w.draw(m_sprite);
}
////////////////////////////////////////////////////////
// setting position by getting new position
////////////////////////////////////////////////////////

//@override
void DummyGuard::setPoisition(sf::Vector2f &position)
{
	m_position = position;
}


void DummyGuard::changeDirection()
{
	//steps or direction reset
	
		//std::cout << "start";

		int range = 4;
		
		//random the direction
		
		
		m_direction = rand() % range + 1;
		
		if(m_prev_direction==m_direction)
			m_direction = rand() % range + 1;
		
		std::cout << m_direction;
		//m_prev_direction = m_direction;
	

}

bool DummyGuard::collides(sf::Sprite& fr, const std::vector<std::unique_ptr<DynamicObject>>& objects1, const std::vector<std::unique_ptr<StaticObject>>& objects2)
{
	for (const auto& other : objects1)
	{
		// Don't collide with ourselves
		if (this == other.get())
		{
			continue;
		}

		if (fr.getGlobalBounds().intersects(other->getSprite().getGlobalBounds()))
		{
			
			//other->collide(*this, objects1,objects2);
			
			
			return true;

		}
		
	}
	for (const auto& other : objects2)
	{
		


		if (fr.getGlobalBounds().intersects(other->getSprite().getGlobalBounds()))
		{

			//other->collide(*this, objects1,objects2);


			return true;

		}

	}
	return false;
}

void DummyGuard::checkAupdate(sf::Vector2f& pos, const std::vector<std::unique_ptr<DynamicObject>>& objects1,
	const std::vector<std::unique_ptr<StaticObject>>& objects2)
{
	if (!collides(m_sprite, objects1, objects2))
	{

		m_sprite.move(pos);


	}
	else
	{
		collide(*this, objects1, objects2);
		m_sprite.move(-pos);
	}


}
////////////////////////////////////////////////////////////
//  move active object
////////////////////////////////////////////////////////////
void DummyGuard::move(sf::Vector2f& pos,const std::vector<std::unique_ptr<DynamicObject>>& objects1, const std::vector<std::unique_ptr<StaticObject>>& objects2)
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


////////////////////////////////////////////////////////////
//  getting position of guard
////////////////////////////////////////////////////////////

//@override
sf::Vector2f DummyGuard::getPosition() const
{
	return m_position;
}

void DummyGuard::setDeltaAspeed(float time, float speed)
{
	m_delta_time = time;
	m_speed = speed;
}

void DummyGuard::collide(Object & otherObject, const std::vector<std::unique_ptr<DynamicObject>>& movable, 
	const std::vector<std::unique_ptr<StaticObject>>& statics)
{
}

void DummyGuard::collide(Player & otherObject, const std::vector<std::unique_ptr<DynamicObject>>& movable, 
	const std::vector<std::unique_ptr<StaticObject>>& statics)
{
}

void DummyGuard::collide(SmartGuard & otherObject, const std::vector<std::unique_ptr<DynamicObject>>& movable,
	const std::vector<std::unique_ptr<StaticObject>>& statics)
{
}

void DummyGuard::collide(DummyGuard & otherobject, const std::vector<std::unique_ptr<DynamicObject>>& movable,
	const std::vector<std::unique_ptr<StaticObject>>& statics)
{
	otherobject.changeDirection();
}

void DummyGuard::collide(Wall & otherObject, const std::vector<std::unique_ptr<DynamicObject>>& movable,
	const std::vector<std::unique_ptr<StaticObject>>& statics)
{

}

void DummyGuard::collide(Rock & otherObject, const std::vector<std::unique_ptr<DynamicObject>>& movable, 
	const std::vector<std::unique_ptr<StaticObject>>& statics)
{
}


