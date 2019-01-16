#include "headers/AlertDialog.h"
#include <iostream>


AlertDialog::AlertDialog()
{
	

	int s_width = sf::VideoMode::getDesktopMode().width*0.7;
	int s_height = sf::VideoMode::getDesktopMode().height*0.75;
	m_width = s_width;
	m_height = s_height;
	float b_width = s_width * 0.4;
	float b_height = s_height * 0.4;

	font.loadFromFile("res/DS-DIGI.TTF");
	m_background.setSize(sf::Vector2f(b_width, b_height));
	m_background.setOutlineThickness(1);
	m_background.setOutlineColor(sf::Color::White);
	m_background.setFillColor(sf::Color::Color(149, 176, 168));
	m_background.setPosition(sf::Vector2f(s_width / 2 - (b_width / 2), s_height / 2 - (b_height / 2)));
	//std::cout << s_width / 2 - (b_width);
	m_title.setFont(font);
	m_description.setFont(font);

	
	m_title.setFillColor(sf::Color::White);
	m_description.setFillColor(sf::Color::White);
	
	m_title.setStyle(sf::Text::Bold);
	m_description.setStyle(sf::Text::Bold);

	m_title.setCharacterSize(s_height / 15);
	m_description.setCharacterSize(s_height / 15);
	
	m_title.setString("title");
	m_description.setString("description");
	
	m_title.setPosition(sf::Vector2f(s_width/2-m_title.getLocalBounds().width/2, m_height*0.42));
	m_description.setPosition(sf::Vector2f(s_width / 2 - m_description.getLocalBounds().width / 2, s_height  *0.52));

	
	
	
	

}

void AlertDialog::setTitle(std::string title)
{
	m_title.setString(title);
	m_title.setPosition(sf::Vector2f(m_width / 2 - m_title.getLocalBounds().width / 2, m_height*0.42));

}

void AlertDialog::setDescription(std::string desc)
{
	m_description.setString(desc);
	m_description.setPosition(sf::Vector2f(m_width / 2 - m_description.getLocalBounds().width / 2, m_height  *0.52));

}

void AlertDialog::draw(sf::RenderWindow & w)
{
	w.draw(m_background);
	w.draw(m_title);
	w.draw(m_description);
}


