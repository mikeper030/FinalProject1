#include "DummyGuard.h"
#include "GameBoardManager.h"


////////////////////////////////////////////////////////
// c'tor guard
////////////////////////////////////////////////////////
DummyGuard::DummyGuard(sf::Vector2f  position, sf::Vector2f size)
	:Guard("guard.png",position,size)
{
	
}
//////////////////////////////////////////////////////////
//  draw objet 
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



////////////////////////////////////////////////////////////
//  move active object
////////////////////////////////////////////////////////////
void DummyGuard::move(sf::Vector2f& pos,const std::vector<std::unique_ptr<Object>>& objects)
{
	
	//std::cout << m_delta_time;
	if (m_setps == 0 || m_direction == 0)
	{
		std::cout << "start";
		
		int range = 4;
		m_setps = 100;
		m_direction = rand() % range + 1;
	}
	sf::Vector2f v;
	switch (m_direction)
		{

		case 1:
			//right
			
			v = sf::Vector2f{ m_speed*m_delta_time , 0.f };
			m_sprite.move(v);
			m_setps--;
			break;

		case 2:
			//left
			v = sf::Vector2f{ -m_speed * m_delta_time, 0.f };
			m_sprite.move(v);
			m_setps--;
			break;

		case 3:
			//up
			v = sf::Vector2f{ 0.f,-m_speed*m_delta_time };
			m_sprite.move(v);
			m_setps--;
			break;

		case 4:
			//down
			v = sf::Vector2f{ 0.f, m_delta_time*m_speed };
			m_sprite.move(v);
			m_setps--;
			break;
		
	}

	
	for (const auto& other : objects)
	{
		// Don't collide with ourselves
		if (this == other.get())
		{
			continue;
		}

		if (m_sprite.getGlobalBounds().intersects(other->getSprite().getGlobalBounds()))
		{
			other->collide(*this,objects);
			
		}
	}
	
	//m_sprite.move(pos);

}
void DummyGuard::resetPosition()
{
	m_setps = 0;
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



void DummyGuard::collide(Object & otherObject, const std::vector<std::unique_ptr<Object>>& objects)
{
	otherObject.collide(*this,objects);

}

void DummyGuard::collide(Player & otherObject, const std::vector<std::unique_ptr<Object>>& objects)
{
	otherObject.collide(*this,objects);
}

void DummyGuard::collide(SmartGuard & otherObject, const std::vector<std::unique_ptr<Object>>& objects)
{
	//otherObject.collide(*this,objects);
}

void DummyGuard::collide(DummyGuard & otherobject, const std::vector<std::unique_ptr<Object>>& objects)
{
}

void DummyGuard::collide(Wall & otherObject, const std::vector<std::unique_ptr<Object>>& objects)
{
	//otherObject.collide(*this, objects);
}

void DummyGuard::collide(Rock & otherObject, const std::vector<std::unique_ptr<Object>>& objects)
{
	//otherObject.collide(*this, objects);
}

