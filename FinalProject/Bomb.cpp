#include "Bomb.h"
#include "StaticObject.h"


Bomb::Bomb(sf::Vector2f position, sf::Vector2f size)
	:StaticObject("bomb.png", position, size)
{
}

void Bomb::draw(sf::RenderWindow & w)
{
}

void Bomb::setPoisition(sf::Vector2f &)
{
}

sf::Vector2f Bomb::getPosition() const
{
	return sf::Vector2f();
}

void Bomb::collide(Object & otherObject, const std::vector<std::unique_ptr<DynamicObject>>& movable, 
	const std::vector<std::unique_ptr<StaticObject>>& statics)
{
}

void Bomb::collide(Player & otherObject, const std::vector<std::unique_ptr<DynamicObject>>& movable, 
	const std::vector<std::unique_ptr<StaticObject>>& statics)
{
}

void Bomb::collide(Object & otherObject, const std::vector<std::unique_ptr<Object>>& objects)
{
}

void Bomb::collide(SmartGuard & otherObject, const std::vector<std::unique_ptr<DynamicObject>>& movable, 
	const std::vector<std::unique_ptr<StaticObject>>& statics)
{
}

void Bomb::collide(DummyGuard & otherobject, const std::vector<std::unique_ptr<DynamicObject>>& movable,
	const std::vector<std::unique_ptr<StaticObject>>& statics)
{
}

void Bomb::collide(Wall & otherObject, const std::vector<std::unique_ptr<DynamicObject>>& movable,
	const std::vector<std::unique_ptr<StaticObject>>& statics)
{
}

void Bomb::collide(Rock & otherObject, const std::vector<std::unique_ptr<DynamicObject>>& movable,
	const std::vector<std::unique_ptr<StaticObject>>& statics)
{
}

