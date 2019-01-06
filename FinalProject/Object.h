#pragma once
#include <SFML/Graphics.hpp>

class Object
{
public:
	Object();
	virtual void draw(sf::RenderWindow &);
	virtual void setPoisition(sf::Vector2f &);
	virtual sf::Vector2f getPosition();


protected:
	sf::Vector2f  m_position;
	sf::Sprite m_sprite;
	sf::Texture m_texture;
};

