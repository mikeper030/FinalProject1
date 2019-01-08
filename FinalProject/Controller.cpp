#include "Controller.h"



Controller::Controller()
{
}

void Controller::startGame(std::string  name_file)
{
	const float playerSpeed = 300.f;
	const float guardSpeed = 100.f;
	
	sf::Clock timer;
	const sf::Time time = sf::seconds(2.f);
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
	float width = 216 / 12;
	float height = 24;
	sf::IntRect rectSourceSprite1(0, 0, width, height);
	sf::IntRect rectSourceSprite2(width * 3, 0, width, height);
	sf::IntRect rectSourceSprite3(width * 6, 0, width, height);
	sf::IntRect rectSourceSprite4(width * 9, 0, width, height);

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

		if (isPlaying)
		{
			float deltaTime = clock.restart().asSeconds();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{

				//if (clock.getElapsedTime().asSeconds() > 1.0f) {
				manager.updateRobot({ playerSpeed * deltaTime ,0.f }, rectSourceSprite2, 3, 5, width);
				std::cout << "right" << std::endl;
				//clock.restart();
				
				//}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				//if (clock.getElapsedTime().asSeconds() > 1.0f) {
				manager.updateRobot({ 0.f,playerSpeed * deltaTime }, rectSourceSprite3, 6, 8, width);
				std::cout << "down" << std::endl;
				//clock.restart();
				
				//}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				//if (clock.getElapsedTime().asSeconds() > 1.0f) {
				manager.updateRobot({ -playerSpeed * deltaTime ,0.f }, rectSourceSprite4, 9, 11, width);
				std::cout << "left" << std::endl;
				//clock.restart();
				
				//}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				//if (clock.getElapsedTime().asSeconds() > 1.0f) {
				manager.updateRobot({ 0.f,-playerSpeed * deltaTime }, rectSourceSprite1, 0, 2, width);
				std::cout << "up" << std::endl;
				//clock.restart();
			
				//	}

			}
			
			//if (timer.getElapsedTime() > time) 
			//{
				manager.moveGuards(sf::Vector2f{ 0,0 }, deltaTime, guardSpeed, manager.getObjects());
				timer.restart();
			//}
		}

		// Clear the window
		window.clear(sf::Color(50, 200, 50));

		if (isPlaying)
		{
			// Draw the paddles and the ball
			window.draw(winRec);
			window.draw(boardRec);
			manager.draw(window);
		}
		else
		{
			// Draw the pause message
			//window.draw(pauseMessage);
		}

		// Display things on screen
		window.display();
	}




	
}



