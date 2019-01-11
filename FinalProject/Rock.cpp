#include "Rock.h"
#include <iostream>
#include "DummyGuard.h"
#include "GameBoardManager.h"
////////////////////////////////////////////////////////
// c'tor rock
////////////////////////////////////////////////////////
Rock::Rock(sf::Vector2f position, sf::Vector2f size)
	:StaticObject("rock.png",position,size)
{
}



////////////////////////////////////////////////////////////
//  getting position of rock
////////////////////////////////////////////////////////////


bool Rock::collides(sf::Sprite & fr, const std::vector<std::unique_ptr<DynamicObject>>& objects1, const std::vector<std::unique_ptr<StaticObject>>& objects2)
{
	return false;
}

void Rock::collide(Object & otherObjects, int index)
{
}

void Rock::collide(Player & otherObject, int index)
{
}

void Rock::collide(SmartGuard & otherObject, int index)
{
}

void Rock::collide(DummyGuard & otherobject, int index)
{
	otherobject.changeDirection();
}

void Rock::collide(Wall & otherObject, int index)
{
}

void Rock::collide(Rock & otherObject, int index)
{

}

void Rock::collide(Bomb & bomb, int index)
{
	std::cout << "deleted rock";
	GameBoardManager::getStaticObjects().erase(GameBoardManager::getStaticObjects().begin()+index);
}
