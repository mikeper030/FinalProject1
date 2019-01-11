#include "Controller.h"
#include "Bomb.h"


Controller::Controller()	
 
{

}

void Controller::startGame(std::string  name_file)
{
	const float playerSpeed = 300.f;
	const float guardSpeed = 100.f;
	
	sf::Clock timer;
	const sf::Time time = sf::seconds(2.f);
	
	Bomb::loadSheet();
	//change this to enable main menu
	bool isPlaying = true;

	m_screen_width = sf::VideoMode::getDesktopMode().width*0.7;
	m_screen_height = sf::VideoMode::getDesktopMode().height*0.7;
	
	sf::RenderWindow window(sf::VideoMode(m_screen_width, m_screen_height, 32), "Bomberman",
	sf::Style::Titlebar | sf::Style::Close);;
	sf::RectangleShape winRec(sf::Vector2f(m_screen_width, m_screen_height));
	winRec.setFillColor(sf::Color::Color(149, 176, 168));
	winRec.setPosition(0, 0);

	sf::RectangleShape boardRec(sf::Vector2f(m_screen_width, m_screen_height));
	boardRec.setFillColor(sf::Color::Color(255, 173, 43));
	boardRec.setPosition(0, 100);

	sf::Clock clock;


	std::ifstream file(name_file);
	if (!file.good())
		return;
	
	GameBoardManager manager(file);
	manager.readSizeOfBoard();
	manager.createBoardByFile(m_screen_height,m_screen_width);
	
	
	
	sf::Texture texture;
	texture.loadFromFile("inter.png");
	sf::RectangleShape rectInter(sf::Vector2f(m_screen_width, m_screen_height));
	rectInter.setTexture(&texture);
	rectInter.setPosition(0, 0);
	sf::Texture soundTexture;
	soundTexture.loadFromFile("music.png");
	sf::Sprite soundIcon(soundTexture);
	soundIcon.setPosition(20, 20);


	sf::RectangleShape newGame_botton(sf::Vector2f(m_screen_width/10, m_screen_height/10));
	sf::RectangleShape exitGame_botton(sf::Vector2f(m_screen_width / 10, m_screen_height / 10));
	sf::Font font;
	font.loadFromFile("1stenterprisesexpand.ttf");
	sf::Text menu_newGame;
	sf::Text menu_exitGame;



	clock.restart();
	
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
		if (newGame(event, texture, newGame_botton, exitGame_botton, font, menu_newGame, menu_exitGame, window))
		{
			isPlaying = true;
		}
		if (isPlaying)
		{
			
			manager.moveGuards(sf::Vector2f{ 0,0 }, 0.005, guardSpeed, manager.getDynamicObjects(), manager.getStaticObjects());
			
			float deltaTime =(float) 0.005; //clock.restart().asSeconds();

			manager.updateRobot(18,playerSpeed,deltaTime);
			
			
			
		}

		// Clear the window
		window.clear(sf::Color(50, 200, 50));

		if (isPlaying)
		{
		    
			window.draw(winRec);
			window.draw(boardRec);
			manager.draw(window);
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


