#include "headers/GameBoardManager.h"
#include "headers/SmartGuard.h"
//static initialization===================================================
std::vector<std::unique_ptr<DynamicObject>> GameBoardManager::m_active;
std::vector<std::unique_ptr<StaticObject>> GameBoardManager::m_static;
int GameBoardManager::m_bombs_limit = 0;
int GameBoardManager::m_bombs_counter = 0;
float GameBoardManager::m_score = 0;
float GameBoardManager::m_guards_num = 0;
//========================================================================

GameBoardManager::GameBoardManager(std::ifstream & file, SoundUtils&sound)
	:m_file(file), m_curr_level(1), m_sound(sound), is_player_sound_on(false)
{
	font.loadFromFile("res/DS-DIGI.TTF");
}
//////////////////////////////////////////////////////////
// get the size of board by file
/////////////////////////////////////////////////////////

void GameBoardManager::readSizeOfBoard()
{
	std::string line;
	getline(m_file, line);
	if (line.empty())
	{
		TimeUtils t(0);
		
		restartGame(t);
	}
	std::istringstream iss;
	iss.str(line);
	int rows, cols, time, bombs;
	iss >> rows >> cols >> time >> bombs;
	m_rows = rows;
	m_cols = cols;
	m_bombs_limit = bombs;
	m_bombs_counter = bombs;
	m_time_level = time;
}
//////////////////////////////////////////////////////////
//  create level by file board.txt 
/////////////////////////////////////////////////////////
void GameBoardManager::createBoardByFile()
{
	bool game_finished = false;
	int s_width = sf::VideoMode::getDesktopMode().width*0.7;
	int  s_height = sf::VideoMode::getDesktopMode().height*0.75;
	std::string str;
	int i = 0;
	m_tile_width = s_width / m_cols;
	m_tile_height = s_height * 0.95 / m_rows;
	m_guards_num = 0;
	sf::Vector2f v;
	v = { 0,float(s_height / 9.5) };
	m_active.clear();
	m_static.clear();
	while (!m_file.eof())
	{
		getline(m_file, str);
		
		if (str.empty()) 
	        break;
		for (int j = 0; j < m_cols; j++)
		{
			switch (str[j])
			{
			case '/':

				m_active.push_back(std::make_unique<Player>(v, sf::Vector2f(m_tile_width, m_tile_height),m_sound));
				break;
			case '!':
				if (i == 0)
					m_active.push_back(std::make_unique<SmartGuard>(v, sf::Vector2f(m_tile_width, m_tile_height)));
				else
					m_active.push_back(std::make_unique<DummyGuard>(v, sf::Vector2f(m_tile_width, m_tile_height)));
				i++;
				m_guards_num++;
				break;
			case '@':
				m_static.push_back(std::make_unique<Rock>(v, sf::Vector2f(m_tile_width, m_tile_height)));
				break;
			case '#':
				m_static.push_back(std::make_unique<Wall>(v, sf::Vector2f(m_tile_width, m_tile_height)));
				break;
			case 'D':
				m_static.push_back(std::make_unique<Door>(v, sf::Vector2f(m_tile_width, m_tile_height)));
				break;
			case '+':
				m_static.push_back(std::make_unique<BonusGift>(v, sf::Vector2f(m_tile_width, m_tile_height), false));
				break;
			case '&':
				m_static.push_back(std::make_unique<BonusGift>(v, sf::Vector2f(m_tile_width, m_tile_height), true));
				m_static.push_back(std::make_unique<Rock>(v, sf::Vector2f(m_tile_width, m_tile_height)));

				break;
			default:
				break;
			}
			v.x += m_tile_width;
		}
		v.x = 0;
		v.y += m_tile_height;
	}
	
}

void GameBoardManager::moveGuards(sf::Vector2f pos, float delta, float speed, const std::vector<std::unique_ptr<DynamicObject>>& movable,
	const std::vector<std::unique_ptr<StaticObject>>& statics)
{

	for (std::unique_ptr<DynamicObject> &obj : m_active)
	{
		std::string name = typeid(*obj).name();
		if (name.compare("class DummyGuard") == 0)
		{
			for (std::unique_ptr<DynamicObject> &object1 : m_active)
			{
				name = typeid(*object1).name();
				if (name.compare("class Player") == 0)
				{
					obj->setDeltaAspeed(delta, speed);
					sf::Vector2f p = object1->getPosition();
					obj->move(p, pos, movable, statics);
				}
			}
		}
		//smart Guard move must get the player location first
		else {
			if (name.compare("class SmartGuard") == 0)
			{
				obj->setDeltaAspeed(delta, speed);
				for (const std::unique_ptr<DynamicObject> &object2 : m_active)
				{
					name = typeid(*object2).name();
					if (name.compare("class Player") == 0)
					{
						sf::Vector2f p = object2->getPosition();
						obj->move(p, pos, movable, statics);
					}
				}
			}
		}
	}
}

std::vector<std::unique_ptr<StaticObject>>& GameBoardManager::getStaticObjects()
{
	return m_static;
}

std::vector<std::unique_ptr<DynamicObject>>& GameBoardManager::getDynamicObjects()
{
	return m_active;
}

void GameBoardManager::addScore()
{
	m_score += 5 * m_guards_num;
}

int GameBoardManager::getScore()
{
	return m_score;
}


int & GameBoardManager::getCurrentTimeLimit()
{
	return m_time_level;
}

void GameBoardManager::updateRobot(int width, float playerSpeed, float deltaTime, sf::Event&ev)
{

	//click press
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (!is_player_sound_on)
		{
			m_sound.playSteps();
			is_player_sound_on = true;
		}
		updateRobot({ playerSpeed * deltaTime ,0.f }, Player::getSheet().at(1), 3, 5, width, getDynamicObjects(), getStaticObjects());

	}
	else
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			if (!is_player_sound_on)
			{
				m_sound.playSteps();
				is_player_sound_on = true;
			}
			updateRobot({ 0.f,playerSpeed * deltaTime }, Player::getSheet().at(2), 6, 8, width, getDynamicObjects(), getStaticObjects());
		}
		else
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				if (!is_player_sound_on)
				{
					m_sound.playSteps();
					is_player_sound_on = true;
				}
				updateRobot({ -playerSpeed * deltaTime ,0.f }, Player::getSheet().at(3), 9, 11, width, getDynamicObjects(), getStaticObjects());
			}
			else
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					if (!is_player_sound_on)
					{
						m_sound.playSteps();
						is_player_sound_on = true;
					}
					updateRobot({ 0.f,-playerSpeed * deltaTime }, Player::getSheet().at(0), 0, 2, width, getDynamicObjects(), getStaticObjects());
				}
				else
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
					{
						if (m_bombs_counter > 0)
						{
							Bomb b(Player::getPosition(), sf::Vector2f(m_tile_width, m_tile_height), font,m_sound);
							m_bombs.push_back(b);
							m_bombs_counter--;
						}
					}
					else
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
						{
							Controller::setRestart(true);
						}
	                   //key release
						else
							if (ev.type == sf::Event::KeyReleased&&ev.key.code == sf::Keyboard::Up)
							{
								m_sound.stopSteps();
								is_player_sound_on = false;
							}
							else
								if (ev.type == sf::Event::KeyReleased&&ev.key.code == sf::Keyboard::Down)
								{
									m_sound.stopSteps();
									is_player_sound_on = false;

								}
								else
									if (ev.type == sf::Event::KeyReleased&&ev.key.code == sf::Keyboard::Left)
									{
										m_sound.stopSteps();
										is_player_sound_on = false;

									}
									else
										if (ev.type == sf::Event::KeyReleased&&ev.key.code == sf::Keyboard::Right)
										{
											m_sound.stopSteps();
											is_player_sound_on = false;

										}
}

std::vector<Bomb>& GameBoardManager::getBombs()
{
	return m_bombs;
}

int &GameBoardManager::getLevelBombsMax()
{
	return m_bombs_counter;
}



/////////////////////////////////////////////////////////
//  draw the board 
/////////////////////////////////////////////////////////
void GameBoardManager::draw(sf::RenderWindow & w)
{
	int j = 0;
	for (size_t i = 0; i < m_static.size(); i++)
	{
		m_static[i]->draw(w);
	}
	for (Bomb& b : m_bombs)
	{
		if (!b.isFinished())
			b.draw(w);
		else
		{
			//m_bombs.erase(&m_bombs[j]);

		}


		j++;
	}
	for (size_t i = 0; i < m_active.size(); i++)
	{
		m_active[i]->draw(w);
	}



}
//////////////////////////////////////////////////////////
// robot move
///////////////////////////////////////////////////////////
void GameBoardManager::updateRobot(sf::Vector2f  new_position, sf::IntRect &rectSourceSprite
	, int first, int last, float width, const std::vector<std::unique_ptr<DynamicObject>>& objects1, const std::vector<std::unique_ptr<StaticObject>>& objects2)
{
	for (int i = 0; i < m_active.size(); i++)
	{

		std::string name;
		name = typeid(*m_active[i]).name();
		if (name.compare("class Player") == 0)
		{
			if (rectSourceSprite.left == width * last)
				rectSourceSprite.left = width * first;
			else
				rectSourceSprite.left += width;

			m_active[i]->getSprite().setTextureRect(rectSourceSprite);
			sf::Vector2f p = m_active[i]->getPosition();
			m_active[i]->move(p, new_position, objects1, objects2);

		}
	}
}

void GameBoardManager::restartLevel()
{
	m_bombs_counter = m_bombs_limit;
	TimeUtils::restart();
	for (auto& a : m_static)
	{
		a->setStartPosition();
		a->setVisible(true);
	}
	for (auto& a : m_active)
	{
		a->setStartPosition();
		a->setVisible(true);
	}
}
int  GameBoardManager::getCurrentLevel() const
{
	return m_curr_level;
}
void GameBoardManager::goToNextLevel()
{
	m_sound.playSuccess();

	m_score = m_score + 20 * m_guards_num;
	m_curr_level++;
	readSizeOfBoard();
	createBoardByFile();

}


void GameBoardManager::restartGame(TimeUtils&time)
{
	
	m_file.clear();
	m_file.seekg(0);
	readSizeOfBoard();
	createBoardByFile();
	time.setTime(getCurrentTimeLimit());
	
	
}