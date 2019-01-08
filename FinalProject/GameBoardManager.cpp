#include "GameBoardManager.h"

static std::vector<std::unique_ptr<Object>> m_all = { };

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
	std::cout << rows << " " << cols << " " << time << " " << bomb << std::endl;
	m_rows = rows;
	m_cols = cols;
	m_number_bombs = bomb;
	m_time_level = time;
}
//////////////////////////////////////////////////////////
//  create board by file board.txt 
/////////////////////////////////////////////////////////
void GameBoardManager::createBoardByFile(int s_height,int s_width)
{
	std::string str;
	int i = 0;
	float size_width = s_width / m_cols;
	float size_height = s_height / m_rows;
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
				m_active.push_back(std::make_unique<Player>(v, sf::Vector2f(size_width, size_height)));
				m_all.push_back(std::make_unique<Player>(v, sf::Vector2f(size_width, size_height)));
				break;
			case '!':
				m_active.push_back(std::make_unique<DummyGuard>(v, sf::Vector2f(size_width, size_height)));
				m_all.push_back(std::make_unique<DummyGuard>(v, sf::Vector2f(size_width, size_height)));

				break;
			case '@':
				m_static.push_back(std::make_unique<Rock>(v, sf::Vector2f(size_width, size_height)));
				m_all.push_back(std::make_unique<Rock>(v, sf::Vector2f(size_width, size_height)));

				break;
			case '#':
				m_static.push_back(std::make_unique<Wall>(v, sf::Vector2f(size_width, size_height)));
				m_all.push_back(std::make_unique<Wall>(v, sf::Vector2f(size_width, size_height)));

				break;
			case 'D':
				m_static.push_back(std::make_unique<Door>(v, sf::Vector2f(size_width, size_height)));
				m_all.push_back(std::make_unique<Door>(v, sf::Vector2f(size_width, size_height)));

				break;
			default:
				break;
			}
			v.x += size_width;
		}
		v.x = 0;
		v.y += size_height;
	}
}


void GameBoardManager::moveGuards(sf::Vector2f pos, int delta,int speed, const std::vector<std::unique_ptr<Object>>& objs)
{
	
	for (std::unique_ptr<DynamicObject> &obj : m_active)
	{
		std::string name = typeid(*obj).name();
		if (name.compare("class DummyGuard") == 0)
		{
			std::cout << "move dummy guard"<<std::endl;
			obj->move(pos,objs);
			obj->setDeltaAspeed(delta, speed);
		}
		
	}
}


 std::vector<std::unique_ptr<Object>>& GameBoardManager::getObjects() 
{
	 return m_all;
}

/////////////////////////////////////////////////////////
//  draw the board 
/////////////////////////////////////////////////////////
void GameBoardManager::draw(sf::RenderWindow & w)
{
	for (size_t i = 0; i < m_active.size(); i++)
	{
		m_active[i]->draw(w);
	}
	for (size_t i = 0; i < m_static.size(); i++)
	{
		m_static[i]->draw(w);
	}
}
//////////////////////////////////////////////////////////
// robot move
///////////////////////////////////////////////////////////
void GameBoardManager::updateRobot(sf::Vector2f  new_position, sf::IntRect &rectSourceSprite
	, int first, int last, float width)
{
	for (int i = 0; i < m_active.size(); i++)
	{
		std::cout << "move robot 1" << typeid(*m_active[i]).name() << std::endl;
		std::string name;
		name = typeid(*m_active[i]).name();
		if (name.compare("class Player") == 0)
		{
			if (rectSourceSprite.left == width * last)
				rectSourceSprite.left = width * first;
			else
				rectSourceSprite.left += width;
			std::cout << "move robot 2";
			m_active[i]->getSprite().setTextureRect(rectSourceSprite);
			m_active[i]->getSprite().move(new_position);
		}
	}
}

