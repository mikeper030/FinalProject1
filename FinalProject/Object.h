#pragma once
#include <SFML/Graphics.hpp>

class Player;
class SmartGuard;
class DummyGuard;
class Wall;
class Rock;


class Object
{
public:
	Object(std::string texture_name, sf::Vector2f position, sf::Vector2f size);
	

	virtual void draw(sf::RenderWindow &) =0;
	virtual void setPoisition(sf::Vector2f &)=0;
	virtual sf::Vector2f getPosition() const =0;
	virtual sf::Sprite& getSprite();
	
	//double dispatch collision management
	virtual void collide(Object& otherObject) = 0;
	virtual void collide(Player& otherObject) = 0;
	virtual void collide(SmartGuard& otherObject) = 0;
	virtual void collide(DummyGuard& otherobject) = 0;
	virtual void collide(Wall& otherObject) = 0;
	virtual void collide(Rock& otherObject) = 0;

protected:
	sf::Vector2f  m_position;
	sf::Sprite m_sprite;
	sf::Texture m_texture;
};

