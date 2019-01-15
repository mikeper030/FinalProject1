#include "headers/AlertDialog.h"



AlertDialog::AlertDialog()
{
	float s_width = sf::VideoMode::getDesktopMode().width*0.25;
	float s_height = sf::VideoMode::getDesktopMode().height*0.20;
	sf::Font font;
	font.loadFromFile("DS-DIG.TTF");
	m_title.setFont(font);
	m_description.setFont(font);

	m_title.setString("title");
	m_description.setString("description");
	m_title.setFillColor(sf::Color::White);
	m_description.setFillColor(sf::Color::White);
	m_title.setStyle(sf::Text::Bold);
	m_description.setStyle(sf::Text::Bold);

	m_title.setCharacterSize(s_height / 15);
	m_description.setCharacterSize(s_height / 15);

	float b_height = s_width * 0.25;
	float b_width = s_height * 0.15;
	m_background.setSize(sf::Vector2f(b_width,b_height));
	m_background.setFillColor(sf::Color::Color(149, 176, 168));
	m_background.setPosition(sf::Vector2f(s_width/2-m_background.getLocalBounds().width/2,s_height/2-m_background.getLocalBounds().height/2));
    
	

}

void AlertDialog::setTitle(std::string title)
{
	m_title.setString(title);
}

void AlertDialog::setDescription(std::string desc)
{
	m_description.setString(desc);
}

void AlertDialog::draw(sf::RenderWindow & w)
{
	w.draw(m_background);
	w.draw(m_title);
	w.draw(m_description);
}


