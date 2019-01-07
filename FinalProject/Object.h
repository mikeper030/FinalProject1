#pragma once
#include <SFML/Graphics.hpp>

class Object
{
public:
	Object();
	virtual void draw(sf::RenderWindow &)=0;
	virtual void setPoisition(sf::Vector2f &)=0;
	virtual sf::Vector2f getPosition()=0;


protected:
	sf::Vector2f  m_position;
	sf::Sprite m_sprite;
	sf::Texture m_texture;
};

