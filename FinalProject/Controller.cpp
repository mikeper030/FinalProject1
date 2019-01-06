#include "Controller.h"



Controller::Controller()
{
}

void Controller::startGame(std::string  name_file)
{
	sf::RenderWindow window(sf::VideoMode(900, 500, 32), "Bomberman",
		sf::Style::Titlebar | sf::Style::Close);;
	sf::RectangleShape winRec(sf::Vector2f(900, 500));
	winRec.setFillColor(sf::Color::Color(149, 176, 168));
	winRec.setPosition(0, 0);

	sf::RectangleShape boardRec(sf::Vector2f(900, 400));
	boardRec.setFillColor(sf::Color::Color(255, 173, 43));
	boardRec.setPosition(0, 100);

	sf::Clock clock;


	std::ifstream file(name_file);
	if (!file.good())
		return;
	GameBoardManager game(file);
	game.readSizeOfBoard();
	game.createBoardByFile();
	float width = 216 / 12;
	float height = 24;
	sf::IntRect rectSourceSprite1(0, 0, width, height);
	sf::IntRect rectSourceSprite2(width * 3, 0, width, height);
	sf::IntRect rectSourceSprite3(width * 6, 0, width, height);
	sf::IntRect rectSourceSprite4(width * 9, 0, width, height);



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
			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Right))
			{
				//if (clock.getElapsedTime().asSeconds() > 1.0f) {
				game.updateRobot({ 5,0 }, rectSourceSprite2, 3, 5, width);
				std::cout << "down" << std::endl;
				//clock.restart();
				break;
				//}
			}
			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Down))
			{
				//if (clock.getElapsedTime().asSeconds() > 1.0f) {
				game.updateRobot({ 0.f,5 }, rectSourceSprite3, 6, 8, width);
				std::cout << "left" << std::endl;
				//clock.restart();
				break;
				//}
			}
			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Left))
			{
				//if (clock.getElapsedTime().asSeconds() > 1.0f) {
				game.updateRobot({ -5,0 }, rectSourceSprite4, 9, 11, width);
				std::cout << "left" << std::endl;
				//clock.restart();
				break;
				//}
			}
			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Up))
			{
				//if (clock.getElapsedTime().asSeconds() > 1.0f) {
				game.updateRobot({ 0,-5 }, rectSourceSprite1, 0, 2, width);
				std::cout << "right" << std::endl;
				//clock.restart();
				break;
				//	}
			}
		}
		window.clear();
		window.draw(winRec);
		window.draw(boardRec);
		game.draw(window);
		window.display();
	}
}



