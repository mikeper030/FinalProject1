#include "headers/Rock.h"
#include <iostream>
#include "headers/DummyGuard.h"
#include "headers/GameBoardManager.h"
#include "headers/SmartGuard.h"
////////////////////////////////////////////////////////
// c'tor rock
////////////////////////////////////////////////////////
Rock::Rock(sf::Vector2f position, sf::Vector2f size)
	:StaticObject("res/rock.png",position,size)
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

void Rock::collide(SmartGuard & guard, int index)
{
	guard.changeDirection();
}

void Rock::collide(DummyGuard & guard, int index)
{
	guard.changeDirection();
}

void Rock::collide(Wall & otherObject, int index)
{
}

void Rock::collide(Rock & otherObject, int index)
{

}

void Rock::collide(Bomb & bomb, int index)
{

	GameBoardManager::getStaticObjects().at(index)->setVisible(false);
}
