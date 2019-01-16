
#include "headers/Controller.h"
#include "headers/Bomb.h"
#include "headers/GameBoardManager.h"
//static initializers======================
bool Controller::is_level_finished = false;
bool Controller::should_restart = false;
//=========================================

Controller::Controller(){}

void Controller::startGame(std::string  name_file)
{
	 float playerSpeed = 380.f;
	 float guardSpeed = 150.f;
	 // for low resolution support
	if (sf::VideoMode::getDesktopMode().width <= 1920)
	{
		playerSpeed = 190.f;
		guardSpeed = 65.f;
	}
	sf::Clock timer;
	const sf::Time time = sf::seconds(2.f);
	
	Bomb::loadSheet();
	//change this to enable main menu
	bool isPlaying = true;

	m_screen_width = sf::VideoMode::getDesktopMode().width*0.7;
	m_screen_height = sf::VideoMode::getDesktopMode().height*0.75;
	
	sf::RenderWindow window(sf::VideoMode(m_screen_width, m_screen_height, 32), "Bomberman",
	sf::Style::Titlebar | sf::Style::Close);
	//window.setIcon()
	sf::RectangleShape winRec(sf::Vector2f(m_screen_width, m_screen_height));
	winRec.setFillColor(sf::Color::Color(149, 176, 168));
	winRec.setPosition(0, 0);

	sf::RectangleShape boardRec(sf::Vector2f(m_screen_width, m_screen_height*0.9));
	boardRec.setFillColor(sf::Color::Color(255, 173, 43));
	boardRec.setPosition(0, m_screen_height*0.15);

	


	std::ifstream file(name_file);
	if (!file.good())
		return;
	GameBoardManager manager(file);
	manager.readSizeOfBoard();
	manager.createBoardByFile();
	//in game head up display
	Timer t(manager.getCurrentTimeLimit());
	if (manager.getCurrentTimeLimit() == -1)
		t.setUnlimitedTimeMode(true);
	Hud hud(0, 4, manager.getLevelBombsMax(),1 , m_screen_width, m_screen_height,t);
	
	AlertDialog dialog;
	sf::Texture texture;
	texture.loadFromFile("res/inter.png");
	texture.setSmooth(true);
	sf::RectangleShape rectInter(sf::Vector2f(m_screen_width, m_screen_height));
	rectInter.setTexture(&texture);
	rectInter.setPosition(0, 0);
	sf::Texture soundTexture;
	soundTexture.loadFromFile("res/music.png");
	sf::Sprite soundIcon(soundTexture);
	soundIcon.setPosition(20, 20);


	sf::RectangleShape newGame_botton(sf::Vector2f(m_screen_width/10, m_screen_height/10));
	sf::RectangleShape exitGame_botton(sf::Vector2f(m_screen_width / 10, m_screen_height / 10));
	sf::Font font;
	font.loadFromFile("res/1stenterprisesexpand.ttf");
	sf::Text menu_newGame;
	sf::Text menu_exitGame;

	sf::Clock clock;
	
	while (window.isOpen())
	{
		// Handle events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Window closed or escape key pressed: exit
			if ((event.type == sf::Event::Closed) ||
				((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
			{
				window.close();
				break;
			}
			
		}
		float deltaTime = (float) 0.005;
		if (newGame(event, texture, newGame_botton, exitGame_botton, font, menu_newGame, menu_exitGame, window))
		{
			isPlaying = true;
		}
		if (isPlaying)
		{			
			manager.moveGuards(sf::Vector2f{ 0,0 }, 0.005, guardSpeed, manager.getDynamicObjects(), manager.getStaticObjects());
			manager.updateRobot(18,playerSpeed,deltaTime);
			if (clock.getElapsedTime().asSeconds() > 1)
			{
				if (is_level_finished)//level finsihed successfully
				{
					std::ostringstream o;
					sf::Clock temp;
					while (1)
					{

						if (temp.getElapsedTime().asSeconds() < 3)
						{
							dialog.setTitle("Success!");
							dialog.setDescription("Level starting...");
							updateDisplay(window, isPlaying, winRec, boardRec, manager, hud, rectInter, newGame_botton, exitGame_botton, menu_newGame, menu_exitGame, soundIcon);
							
							dialog.draw(window);
							window.display();
						}
						else
						{
							
							is_level_finished = false;
							t.setTime(manager.getCurrentTimeLimit());
							if (manager.getCurrentTimeLimit() == -1)
								t.setUnlimitedTimeMode(true);
							manager.goToNextLevel();
							hud.setAlert(false);
						
							break;
						}
						
					}
				}
				t.secondPassed();
				if (hud.lowOnTime())
				{
					hud.setAlert(true);
				}
				if (t.isFinished()||should_restart)
				{
					if (should_restart)
					{
						Player::dropLife();
						should_restart = false;
					}
					sf::Clock temp;
					while (1)
					{
						if (temp.getElapsedTime().asSeconds() < 3)
						{
							updateDisplay(window, isPlaying, winRec, boardRec, manager, hud, rectInter, newGame_botton, exitGame_botton, menu_newGame, menu_exitGame, soundIcon);
							dialog.setDescription("Level restarting...");
							dialog.setTitle("Wasted!");
							dialog.draw(window);
							window.display();
						}
						else
							break;
					}
					
					hud.setAlert(false);
					manager.restartLevel();
					t.setTime(manager.getCurrentTimeLimit());
				}
				clock.restart();
			}
			
			hud.updateTime();
			
		}
		
			updateDisplay(window, isPlaying, winRec, boardRec, manager, hud, rectInter, newGame_botton, exitGame_botton, menu_newGame, menu_exitGame, soundIcon);
			window.display();

		
	}




	
}


bool Controller::newGame(sf::Event  & event, sf::Texture & texture, sf::RectangleShape & newGame_botton,
	sf::RectangleShape & exitGame_botton, sf::Font & font,
	sf::Text& menu_newGame, sf::Text & menu_exitGame, sf::RenderWindow & window)
{
	newGame_botton.setFillColor(sf::Color::Red);
	newGame_botton.setPosition(65, 400);

	exitGame_botton.setFillColor(sf::Color::Red);
	exitGame_botton.setPosition(65, 470);

	menu_newGame.setFont(font);
	menu_newGame.setCharacterSize(30);
	menu_newGame.setPosition(73, 405);
	menu_newGame.setFillColor(sf::Color::Black);
	menu_newGame.setString("New Game");

	menu_exitGame.setFont(font);
	menu_exitGame.setCharacterSize(30);
	menu_exitGame.setPosition(73, 475);
	menu_exitGame.setFillColor(sf::Color::Black);
	menu_exitGame.setString("Exit Game");

	//get mouse position 
	sf::Vector2i mouse = sf::Mouse::getPosition(window);
	//compute global boundries
	sf::Vector2f mouse_world = window.mapPixelToCoords(mouse);

	if (event.mouseButton.button == sf::Mouse::Button::Left)
	{
		if (exitGame_botton.getGlobalBounds().contains(mouse_world))
		{
			window.close();
		}
	}

	if (event.mouseButton.button == sf::Mouse::Button::Left)
	{
		if (newGame_botton.getGlobalBounds().contains(mouse_world))
		{
			return true;
		}
	}
	return false;
}

bool Controller::levelFinsihed()
{
	return is_level_finished;
}
void Controller::setRestart(bool b)
{
	should_restart = b;
}
bool Controller::restart()
{
	return should_restart;
}

void Controller::setLevelFinished(bool b)
{
	is_level_finished = b;
}


void Controller::updateDisplay(sf::RenderWindow&window,bool&isPlaying,sf::RectangleShape&winRec,sf::RectangleShape&boardRec,GameBoardManager&manager,Hud&hud,
	sf::RectangleShape&rectInter,sf::RectangleShape&newGame_botton,sf::RectangleShape&exitGame_botton,sf::Text&menu_newGame,sf::Text&menu_exitGame,sf::Sprite&soundIcon)
{
	// Clear the window
	window.clear(sf::Color(50, 200, 50));

	if (isPlaying)
	{

		window.draw(winRec);
		window.draw(boardRec);
		manager.draw(window);
		hud.setScore(manager.getScore());
		hud.setBombs(manager.getLevelBombsMax());
		hud.setLevelNO(manager.getCurrentLevel());
		hud.setLife(Player::getLives());
		hud.draw(window);
	}
	else
	{
		// Draw the pause message

		// Draw the pause message
		//window.draw(pauseMessage);
		window.draw(rectInter);
		window.draw(newGame_botton);
		window.draw(exitGame_botton);
		window.draw(menu_newGame);
		window.draw(menu_exitGame);
		window.draw(soundIcon);

	}

	// Display things on screen
	
}