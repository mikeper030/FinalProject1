#include "headers/BonusGift.h"
#include "headers/DynamicObject.h"
#include "headers/StaticObject.h"
#include "headers/GameBoardManager.h" 
#include "headers/SmartGuard.h"
BonusGift::BonusGift(sf::Vector2f position, sf::Vector2f size,bool b)
	:StaticObject("res/gift.png",position,size),is_hidden(b)
{
}


//@override
bool BonusGift::collides(sf::Sprite & fr, const std::vector<std::unique_ptr<DynamicObject>>& objects1, const std::vector<std::unique_ptr<StaticObject>>& objects2)
{
	int i = 0;
	for (const auto& other : objects1)
	{
		// Don't collide with ourselves
		if (fr.getGlobalBounds().intersects(other->getSprite().getGlobalBounds()))
		{
			other->collide(*this, i);
			return true;
		}
	}
	i = 0;
	for (const auto& other : objects2)
	{
		if (this == other.get())
		{
			continue;
		}
		if (fr.getGlobalBounds().intersects(other->getSprite().getGlobalBounds()))
		{
			other->collide(*this, i);
			return true;
		}
	}
	return false;
}



void BonusGift::collide(Object & otherObject, int index)
{
}

void BonusGift::collide(Player & player, int index)
{
	player.consumeGift();
	GameBoardManager::getStaticObjects().at(index)->setVisible(false);

}

void BonusGift::collide(SmartGuard & guard, int index)
{
	guard.changeDirection();
	
}

void BonusGift::collide(DummyGuard & guard, int index)
{
	guard.changeDirection();
}

void BonusGift::collide(Wall & otherObject, int index)
{
}

void BonusGift::collide(Rock & otherObject, int index)
{
}

void BonusGift::collide(Bomb & bomb, int index)
{
	if (!is_hidden)
	{
		GameBoardManager::getStaticObjects().at(index)->setVisible(false);
	}
	

}
