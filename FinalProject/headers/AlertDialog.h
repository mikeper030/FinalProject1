#pragma once
#include <SFML/Graphics.hpp>
#include <string>
class AlertDialog
{
public:
	AlertDialog();
	void setTitle(std::string title);
	void setDescription(std::string desc);
	void draw(sf::RenderWindow&w);

private:
	int m_width, m_height;
	sf::Font font;
	sf::Text m_title,m_description;
	sf::RectangleShape m_background;

};

