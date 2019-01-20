
#include "headers/Controller.h"
#include "headers/Bomb.h"
#include "headers/GameBoardManager.h"
#include "headers/SoundUtils.h"
//static initializers======================
bool Controller::is_level_finished = false;
bool Controller::should_restart = false;
bool Controller::game_over = false;

//=========================================



Controller::Controller():should_exit(false){}

void Controller::startGame(std::string  name_file)
{
	 float playerSpeed = 380.f;
	 float guardSpeed = 150.f;
	 // for low resolution support
	if (sf::VideoMode::getDesktopMode().width <= 1920.f)
	{
		playerSpeed = 190.f;
		guardSpeed = 65.f;
	}
	sf::Clock timer;
	const sf::Time time = sf::seconds(2.f);
	
	Bomb::loadSheet();
	//change this to enable main menu
	bool isPlaying = false;
	bool isPause = false;
	sound.playIntro();
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
	
	
	
	MainMenu mainMenu(m_screen_width,m_screen_height);
	GameBoardManager manager(file,sound,window);
	//in game head up display
	manager.readSizeOfBoard();
	manager.createBoardByFile();
	TimeUtils t(manager.getCurrentTimeLimit());
	
	if (manager.getCurrentTimeLimit() == -1)
		t.setUnlimitedTimeMode(true);
	Hud hud(0, 4, manager.getLevelBombsMax(),1 , m_screen_width, m_screen_height,t);
	
	AlertDialog dialog;
	
	int command = 0;
	sf::Clock clock;
	
	while (window.isOpen())
	{
		// Handle events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Window closed or escape key pressed: exit
			if ((event.type == sf::Event::Closed) ||
				((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape||should_exit)))
			{
				window.close();
				break;
			}
			else
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
				{
					sound.playIntro();
					command = pauseMenu.pauseGame(window, event, m_screen_width, m_screen_height);
					getCommand(command,isPause,isPlaying,manager,t,hud);
				}
		}
		float deltaTime = (float) 0.007;
		if (mainMenu.newGame(event, window))
		{
			sound.stopIntro();
			isPlaying = true;
		}
		if (isPlaying)
		{			
			manager.moveGuards(sf::Vector2f{ 0,0 }, deltaTime, guardSpeed, manager.getDynamicObjects(), manager.getStaticObjects());
			manager.updateRobot(18,playerSpeed,deltaTime,event);
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
							updateDisplay(window, isPlaying, winRec, boardRec, manager, hud, mainMenu);
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
					sound.playFail();
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
							updateDisplay(window, isPlaying, winRec, boardRec, manager, hud, mainMenu);
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
					if (game_over)
					{
						game_over = false;
						manager.restartGame(t);
						hud.setBombs(manager.getLevelBombsMax());
						hud.setAlert(false);
						hud.setBombs(manager.getLevelBombsMax());
						hud.setLevelNO(1);
						Player::setLife(4);
						hud.setLife(4);
						hud.setScore(0);
					}
				clock.restart();
			}
			
			hud.updateTime();
			
		}
			updateDisplay(window, isPlaying, winRec, boardRec, manager, hud,mainMenu);
			window.display();
	}




	
}
void Controller::getCommand(int command,bool&isPause,bool&isPlaying,GameBoardManager&manager,TimeUtils&t,Hud&hud)
{
	switch (command)
	{
	case 1:
		isPause = false;
		isPlaying = true;
		sound.stopIntro();
		break;
	case 2:
		isPause = true;
		
		manager.restartGame(t);
	
		hud.setAlert(false);
		hud.setBombs(manager.getLevelBombsMax());
		hud.setLevelNO(1);
		Player::setLife(4);
		hud.setLife(4);
		hud.setScore(0);
		manager.restartGame(t);
		sound.stopIntro();
		break;
	case 3:
		break;
		should_exit = true;
		isPause = true;
		isPlaying = false;
		sound.stopIntro();
	default:
		
		break;
	}
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

void Controller::setGameOver(bool b)
{
	game_over = b;
}


void Controller::updateDisplay(sf::RenderWindow&window,bool&isPlaying,sf::RectangleShape&winRec,sf::RectangleShape&boardRec,GameBoardManager&manager,Hud&hud,MainMenu&main_menu)
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
		main_menu.draw(window);
		
	}

	// Display things on screen
	
}