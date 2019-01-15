#include "headers/Wall.h"
#include <iostream>
#include "headers/DummyGuard.h"
#include "headers/Player.h"
#include "headers/SmartGuard.h"
////////////////////////////////////////////////////////
// c'tor wall
////////////////////////////////////////////////////////
Wall::Wall(sf::Vector2f position, sf::Vector2f size)
	:StaticObject("res/wall.png",position,size)
{
	

}

bool Wall::collides(sf::Sprite & fr, const std::vector<std::unique_ptr<DynamicObject>>& objects1, const std::vector<std::unique_ptr<StaticObject>>& objects2)
{
	return false;
}

void Wall::collide(Object & otherObject, int index)
{
}

void Wall::collide(Player & player, int index)
{
	player.setMoving(false);
}

void Wall::collide(SmartGuard & guard, int index)
{
	guard.changeDirection();
	std::cout << "smart change direction";

}

void Wall::collide(DummyGuard & guard, int index)
{
	guard.changeDirection();
	
}

void Wall::collide(Wall & otherObject, int index)
{
}

void Wall::collide(Rock & otherObject, int index)
{

}

void Wall::collide(Bomb & bomb, int index)
{
	
}
