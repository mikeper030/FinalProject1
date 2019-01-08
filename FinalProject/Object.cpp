#include "Object.h"
#include <iostream>







Object::Object(std::string texture_name, sf::Vector2f position, sf::Vector2f size)
{
	if (texture_name!="Bomberman.png")
	//if player is passed we can not use default beahvior will be overridden in 
   //player class
	{
		m_texture.loadFromFile(texture_name);
		m_sprite.setTexture(m_texture);
		m_sprite.setPosition(sf::Vector2f(position));
		m_sprite.scale(sf::Vector2f(size.x / 40, size.y / 40));
		m_position = position;
		std::cout << "size :" << std::endl;
		std::cout << "wall  " << size.x << " " << size.y << std::endl;
		std::cout << "position :" << std::endl;
		std::cout << "wall  " << position.x << " " << position.y << std::endl;
	}
}

void Object::draw(sf::RenderWindow & w)
{

}


void Object::setPoisition(sf::Vector2f &v)
{
}

sf::Vector2f Object::getPosition() const 
{
	return sf::Vector2f();
}

sf::Sprite & Object::getSprite() 
{
	return m_sprite;
}



