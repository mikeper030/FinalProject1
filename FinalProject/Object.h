#pragma once
#include <SFML/Graphics.hpp>

class Player;
class SmartGuard;
class DummyGuard;
class Wall;
class Rock;
class DynamicObject;
class StaticObject;
class Bomb;

class Object
{
public:
	Object(std::string texture_name, sf::Vector2f position, sf::Vector2f size);
	

	virtual void draw(sf::RenderWindow &) ;
	virtual void setPoisition(sf::Vector2f &);
	virtual sf::Vector2f getPosition() const ;
	virtual sf::Sprite& getSprite();
	virtual bool collides(sf::Sprite & fr, const std::vector<std::unique_ptr<DynamicObject>>& objects1, const std::vector<std::unique_ptr<StaticObject>>& objects2) = 0;

	//double dispatch collision management
	virtual void collide(Object& otherObject,int index) = 0;
	virtual void collide(Player& otherObject, int index) = 0;
	virtual void collide(SmartGuard& otherObject, int index) = 0;
	virtual void collide(DummyGuard& otherobject, int index) = 0;
	virtual void collide(Wall& otherObject, int index) = 0;
	virtual void collide(Rock& otherObject, int index) = 0;
	virtual void collide(Bomb& bomb, int index) = 0;
protected:
	sf::Vector2f  m_position;
	sf::Sprite m_sprite;
	sf::Texture m_texture;
};

