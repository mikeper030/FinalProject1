#include "headers/Guard.h"
#include <iostream>



////////////////////////////////////////////////////////
// c'tor guard
////////////////////////////////////////////////////////

Guard::Guard(std::string s,sf::Vector2f  position, sf::Vector2f size)
	:DynamicObject(s,position,size)
{
	
}
