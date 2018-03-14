/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/03 by lebovin
*/

#include <iostream>
#include "SFMLWrapper.hpp"

extern "C" SFMLWrapper *create_lib()
{
	return new SFMLWrapper;
}

void	SFMLWrapper::DestroyWindow()
{
	m_win.close();
}

void	SFMLWrapper::InitWindow()
{
	m_win.create(sf::VideoMode(720, 640), "MENU");
	if (!m_font.loadFromFile("./Consolas.ttf"))
      throw (std::exception());
}

void	SFMLWrapper::DrawMenu()
{
/*	std::vector<sf::RectangleShape> boxes = setBoxes();
	std::string	name = "";
	sf::Text	text = sf::Text("name : " + name, m_font, 30);
	sf::Event	event;

	if (!m_texture.loadFromFile("./batman.jpg"))
		exit(84);
	m_sprite = sf::Sprite(m_texture);
	text.setFillColor(sf::Color(50, 50, 50));
	text.setPosition(100, 100);
	while (m_win.isOpen())
	{
		m_win.clear();
		while (m_win.pollEvent(event)) {
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				return ;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
				return ;
			if (event.type == sf::Event::TextEntered)
			{
				if (event.text.unicode < 128)
				{
					if (static_cast<char>(event.text.unicode) == '\b' && name.length() > 0)
						name.erase(name.size() - 1, 1);
					if (name.length() < 3 && static_cast<char>(event.text.unicode) != '\b')
						name += static_cast<char>(event.text.unicode);
					text = sf::Text("name : " + name, m_font, 30);
					text.setFillColor(sf::Color(50, 50, 50));
					text.setPosition(100, 100);
				}
			}
		}
		m_win.draw(m_sprite);
		showMenu(boxes, &m_win);
		showScore(m_font, &m_win);
		m_win.draw(text);
		m_win.display();
	}*/
}
