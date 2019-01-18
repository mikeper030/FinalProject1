#pragma once
#include "DynamicObject.h"
#include "StaticObject.h"
#include "GameBoardManager.h"
#include "SoundUtils.h"

class Player :public DynamicObject
{
public:
	Player(sf::Vector2f  position, sf::Vector2f size,SoundUtils&s);
	static std::vector<sf::IntRect>& getSheet();
	

	static sf::Vector2f& getPosition();
	
	void move(sf::Vector2f& player,sf::Vector2f& pos, const std::vector<std::unique_ptr<DynamicObject>>& movable, const std::vector<std::unique_ptr<StaticObject>>& statics) override;
	
	
	void checkAupdate(sf::Vector2f & pos, const std::vector<std::unique_ptr<DynamicObject>>& objects1, const std::vector<std::unique_ptr<StaticObject>>& objects2) override;
	
	 bool collides(sf::Sprite & fr, const std::vector<std::unique_ptr<DynamicObject>>& objects1, const std::vector<std::unique_ptr<StaticObject>>& objects2) override;
	 
	 static void dropLife();
	 static int getLives() ;
	 static void setLife(int);
	 void setDeltaAspeed(float, float);
	 void setMoving(bool move);
	void collide(Object & otherObject , int index) override;
	 void collide(Player& otherObject, int index) override;
	 void collide(SmartGuard& otherObject, int index) override;
	 void collide(DummyGuard& otherobject, int index)override;
	 void collide(Wall& otherObject, int index)override;
	  void collide(Rock& otherObject, int index) override;
	  void collide(Bomb& bomb, int index) override;

	  void consumeGift();

private:
	static SoundUtils m_sound;
	bool moving;
	static int m_lives;
	static sf::Vector2f m_pos;
	static std::vector<sf::IntRect> sheet;
	//sf::Music death;
	sf::Sound death;
	sf::SoundBuffer s;


};

