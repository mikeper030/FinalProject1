#include "headers/Object.h"
#include <iostream>







Object::Object(std::string texture_name, sf::Vector2f position, sf::Vector2f size)
   
{
	
	if (texture_name!="res/Bomberman.png")
	//if player is passed we can not use default beahvior will be overridden in 
   //player class
	{
		m_texture.loadFromFile(texture_name);
		m_sprite.setTexture(m_texture);
		m_sprite.setPosition(sf::Vector2f(position));
		m_sprite.scale(sf::Vector2f(size.x / 40, size.y / 40));
		m_start_scale = sf::Vector2f(size.x / 40, size.y / 40);
		m_position = position;
		m_start_pos = position;
		std::cout << "size :" << std::endl;
		std::cout << "wall  " << size.x << " " << size.y << std::endl;
		std::cout << "position :" << std::endl;
		std::cout << "wall  " << position.x << " " << position.y << std::endl;
	}
}

void Object::draw(sf::RenderWindow & w)
{
	if(is_visible)
	w.draw(m_sprite);
}


void Object::setPoisition(sf::Vector2f &v)
{
	m_position = v;
}

sf::Vector2f Object::getPosition() const 
{
	return m_position;
}

sf::Sprite & Object::getSprite() 
{
	return m_sprite;
}

void Object::setVisible(bool b)
{
	if (!b)
		m_sprite.setScale(0, 0);
	else if (b && !is_visible)
		m_sprite.setScale(m_start_scale);

	is_visible = b;
}

bool Object::isVisible() const
{
	return is_visible;
}

void Object::setStartPosition()
{
	m_position = m_start_pos;
	m_sprite.setPosition(m_position);
}



