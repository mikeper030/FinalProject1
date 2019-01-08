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
void DummyGuard::move(sf::Vector2f & pos, const std::vector<std::unique_ptr<Object>>& objects)
{
	for (const auto& other : objects)
	{
		// Don't collide with ourselves
		if (this == other.get())
		{
			continue;
		}

		if (m_sprite.getGlobalBounds().intersects(other->getSprite().getGlobalBounds()))
		{
			other->collide(*this);
		}
	}
	m_sprite.move(pos);

	
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



void DummyGuard::collide(Object & otherObject)
{
	otherObject.collide(*this);

}

void DummyGuard::collide(Player & otherObject)
{
	//player strike
}

void DummyGuard::collide(SmartGuard & otherObject)
{
}

void DummyGuard::collide(DummyGuard & otherobject)
{
}

void DummyGuard::collide(Wall & otherObject)
{
	randomMove();
}

void DummyGuard::collide(Rock & otherObject)
{
}

void DummyGuard::randomMove()
{
	sf::Vector2f v;
	int range = 4;
	int num = rand() % range + 1;
	
	switch (num)
	{
	case 1:
		//right
		v = {float( m_speed * m_delta_time) , 0.f };
		move(v,GameBoardManager::getObjects());
		break;
	
	case 2:
		//left
		v = { float(-m_speed * m_delta_time) , 0.f};
		move(v,GameBoardManager::getObjects());
		break;
	
	case 3:
		//up
		v = { 0.f,float( m_speed * m_delta_time) };
		move(v, GameBoardManager::getObjects());
		break;
	
	case 4:
		//down
		v = { 0.f, float(-m_speed * m_delta_time) };
		move(v, GameBoardManager::getObjects());
		break;

	}
}