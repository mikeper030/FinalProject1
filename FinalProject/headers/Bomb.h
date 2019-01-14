#pragma once
#include "StaticObject.h"
#include "DynamicObject.h"
class Bomb :public StaticObject
{
public:
	Bomb(sf::Vector2f position, sf::Vector2f size);
	void draw(sf::RenderWindow & w) override;
	static std::vector<sf::IntRect> &getSheet();
	
	bool &isFinished();

	static void loadSheet();
	
	
	bool collides(sf::Sprite & fr, const std::vector<std::unique_ptr<DynamicObject>>& objects1, const std::vector<std::unique_ptr<StaticObject>>& objects2) override;

	void collide(Object& otherObject, int index) override;
	void collide(Player& otherObject, int index) override;
	void collide(SmartGuard& otherObject, int index) override;
	void collide(DummyGuard& otherobject, int index)override;
	void collide(Wall& otherObject, int index) override;
	void collide(Rock& otherObject, int index) override;
	void collide(Bomb& bomb, int index) override;


private:
	static std::vector<sf::IntRect> m_sheet;
	sf::Clock m_timer;
	sf::Texture explosion;
	int sprite_index = 0;
	bool is_finished = false;
	bool is_blowing=false;
};

