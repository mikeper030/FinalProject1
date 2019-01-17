#include "headers/Bomb.h"
#include "headers/StaticObject.h"
#include <iostream>
#include "headers/Rock.h"
#include "headers/GameBoardManager.h"

//static initializiation===============
std::vector<sf::IntRect> Bomb::m_sheet;
//=====================================


Bomb::Bomb(sf::Vector2f position, sf::Vector2f size)
	:StaticObject("res/bomb.png", position, size) 
{
	m_texture.setSmooth(true);
	m_texture.loadFromFile("res/bomb.png");
	explosion.loadFromFile("res/explosion_sheet.png");
	font.loadFromFile("res/DS-DIGI.TTF");
	bomb_counter.setFillColor(sf::Color::Red);
	bomb_counter.setFont(font);
	bomb_counter.setCharacterSize(size.x / 2);
	bomb_counter.setString("4");
	
}

//@override 
void Bomb::draw(sf::RenderWindow&w)
{
	sf::Vector2f current_pos = m_sprite.getPosition();
	if (!is_blowing)
	{
		if (m_timer.getElapsedTime().asSeconds() < 4)
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
			//only handle explosion blast on several frames
			if (sprite_index > 0 && sprite_index < 40)
			{
				collides(m_sprite, GameBoardManager::getDynamicObjects(), GameBoardManager::getStaticObjects());
			}
			m_sprite.setTexture(explosion);
			m_sprite.setTextureRect(m_sheet.at(sprite_index));
			if (sprite_index == 0) 
			{
				current_pos.x = current_pos.x - 50;
				current_pos.y = current_pos.y - 50;
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
	bool c = false;
	int i = 0;
	for (const auto& other : objects1)
	{	
		if (other!=nullptr&&m_sprite.getGlobalBounds().intersects(other->getSprite().getGlobalBounds()))
		{	
			other->collide(*this, i);
			c= true;
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
		//do not consume collisions if wall is in the blast //fixes bugs! 
		if (other!=nullptr&&fr.getGlobalBounds().intersects(other->getSprite().getGlobalBounds()) && typeid(*other) != typeid(Wall))
		{
			other->collide(*this, i);
			c = true;
		}
		i++;
	}
	return c;
}

void Bomb::collide(Player & player, int index)
{
	GameBoardManager::restartLevel();
	player.dropLife();
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

