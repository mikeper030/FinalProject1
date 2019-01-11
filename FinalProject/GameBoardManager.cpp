#include "GameBoardManager.h"
#include "Bomb.h"

//static initialization================
std::vector<std::unique_ptr<DynamicObject>> GameBoardManager::m_active;
std::vector<std::unique_ptr<StaticObject>> GameBoardManager::m_static;
//=====================================

GameBoardManager::GameBoardManager(std::ifstream & file)
	:m_file(file)
{
}
//////////////////////////////////////////////////////////
// get the size of board by file
/////////////////////////////////////////////////////////
void GameBoardManager::readSizeOfBoard()
{
	std::string line;
	getline(m_file, line);
	std::istringstream iss;
	iss.str(line);
	int rows, cols, time, bomb;
	iss >> rows >> cols >> time >> bomb;
	//std::cout << rows << " " << cols << " " << time << " " << bomb << std::endl;
	m_rows = rows;
	m_cols = cols;
	m_bombs_limit = bomb;
	m_time_level = time;
}
//////////////////////////////////////////////////////////
//  create board by file board.txt 
/////////////////////////////////////////////////////////
void GameBoardManager::createBoardByFile(int s_height,int s_width)
{
	std::string str;
	int i = 0;
	 m_size_width = s_width / m_cols;
	 m_size_height = s_height / m_rows;
	sf::Vector2f v;
	v = { 0,80 };

	while (!m_file.eof())
	{
		getline(m_file, str);
		for (int j = 0; j < m_cols; j++)
		{
			switch (str[j])
			{
			case '/':
				
				m_active.push_back(std::make_unique<Player>(v, sf::Vector2f(m_size_width, m_size_height)));
				break;
			case '!':
				m_active.push_back(std::make_unique<DummyGuard>(v, sf::Vector2f(m_size_width, m_size_height)));
				break;
			case '@':
				m_static.push_back(std::make_unique<Rock>(v, sf::Vector2f(m_size_width, m_size_height)));
			

				break;
			case '#':
				m_static.push_back(std::make_unique<Wall>(v, sf::Vector2f(m_size_width, m_size_height)));
				

				break;
			case 'D':
				m_static.push_back(std::make_unique<Door>(v, sf::Vector2f(m_size_width, m_size_height)));
				

				break;
			default:
				break;
			}
			v.x += m_size_width;
		}
		v.x = 0;
		v.y += m_size_height;
	}
}


void GameBoardManager::moveGuards(sf::Vector2f pos, float delta,float speed, const std::vector<std::unique_ptr<DynamicObject>>& movable,
	const std::vector<std::unique_ptr<StaticObject>>& statics)
{
	
	for (std::unique_ptr<DynamicObject> &obj : m_active)
	{
		std::string name = typeid(*obj).name();
		if (name.compare("class DummyGuard") == 0)
		{
			
			obj->setDeltaAspeed(delta, speed);
			obj->move(pos,movable,statics);
			
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

void GameBoardManager::updateRobot(int width,float playerSpeed,float deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		updateRobot({ playerSpeed * deltaTime ,0.f }, Player::getSheet().at(1), 3, 5, width, getDynamicObjects(), getStaticObjects());
	}
	else
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		updateRobot({ 0.f,playerSpeed * deltaTime }, Player::getSheet().at(2), 6, 8, width, getDynamicObjects(), getStaticObjects());
	}
	else
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
	updateRobot({ -playerSpeed * deltaTime ,0.f }, Player::getSheet().at(3), 9, 11, width, getDynamicObjects(),getStaticObjects());
	}
	else
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		updateRobot({ 0.f,-playerSpeed * deltaTime }, Player::getSheet().at(0), 0, 2, width, getDynamicObjects(), getStaticObjects());
	}
	else
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		Bomb b(Player::getPosition(),sf::Vector2f(m_size_width,m_size_height));
		m_bombs.push_back(b);
	}
}

std::vector<Bomb>& GameBoardManager::getBombs()
{
	return m_bombs;
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
			m_active[i]->move(new_position, objects1, objects2);
		}
	}
}

void GameBoardManager::updateBombs(sf::RenderWindow& w) 
{
	
}