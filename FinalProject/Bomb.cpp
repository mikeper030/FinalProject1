#include "Bomb.h"
#include "StaticObject.h"
#include <iostream>
#include "Rock.h"
#include "GameBoardManager.h"
//static initializiation===============
std::vector<sf::IntRect> Bomb::m_sheet;
//=====================================


Bomb::Bomb(sf::Vector2f position, sf::Vector2f size)
	:StaticObject("bomb.png", position, size) 
{
	m_texture.setSmooth(true);
	m_texture.loadFromFile("bomb.png");
	explosion.loadFromFile("explosion_sheet.png");
	
}

//@override 
void Bomb::draw(sf::RenderWindow&w)
{
	sf::Vector2f current_pos = m_sprite.getPosition();
	if (!is_blowing)
	{
		
		if (m_timer.getElapsedTime().asSeconds() < 3)
		{
			m_sprite.setTexture(m_texture);
			w.draw(m_sprite);
		}
		else
		{
			is_blowing = true;
		
			
		}
	}
	else
	{
		
		if (m_timer.getElapsedTime().asSeconds() > 0.03 && sprite_index<81)
		{
			
			m_sprite.setTexture(explosion);
			m_sprite.setTextureRect(m_sheet.at(sprite_index));
			if (sprite_index == 0) 
			{
				current_pos.x = current_pos.x - 50;
				current_pos.y = current_pos.y - 50;
				collides(m_sprite, GameBoardManager::getDynamicObjects(), GameBoardManager::getStaticObjects());

			}
			
			m_sprite.setPosition(current_pos);
			sprite_index++;
			m_timer.restart();
		}
		else
		{
			if (sprite_index == 81)
			{
				is_finished = true;
			}
		}
		w.draw(m_sprite);
	}
	
} 
std::vector<sf::IntRect>& Bomb::getSheet()
{
	return m_sheet;
}


bool &Bomb::isFinished() 
{
	return is_finished;
}
void Bomb::loadSheet()
{
	m_sheet.clear();
	int row_index = 0;
	int col_index = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++, col_index += 100)
		{
			sf::IntRect sourceSprite(col_index, row_index, 100, 100);
			m_sheet.push_back(sourceSprite);
		}
		col_index = 0;
		row_index += 100;
	}
}



bool Bomb::collides(sf::Sprite & fr, const std::vector<std::unique_ptr<DynamicObject>>& objects1, const std::vector<std::unique_ptr<StaticObject>>& objects2)
{
	int i = 0;
	for (const auto& other : objects1)
	{
		
		if (fr.getGlobalBounds().intersects(other->getSprite().getGlobalBounds()))
		{
			other->collide(*this, i);
			return true;
		}
		i++;
	}
	i = 0;
	for (const auto& other : objects2)
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
		i++;
	}
	return false;
}

void Bomb::collide(Player & player, int index)
{

}

void Bomb::collide(Object & object, int index)
{
}

void Bomb::collide(SmartGuard & smartGuard, int index)
{
}

void Bomb::collide(DummyGuard & dummyGuard, int index)
{
}

void Bomb::collide(Wall & wall, int index)
{
	//nothing should happen..
}

void Bomb::collide(Rock & rock, int index)
{
	
}

void Bomb::collide(Bomb & bomb, int index)
{
}

