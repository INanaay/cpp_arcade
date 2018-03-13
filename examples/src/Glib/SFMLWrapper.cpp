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

void	SFMLWrapper::destroyWindow()
{
	m_win.close();
}

void	SFMLWrapper::initWindow()
{
	m_win.create(sf::VideoMode(1920, 1080), "MENU");
	if (!m_font.loadFromFile("./Consolas.ttf"))
      throw (std::exception());
}

static std::vector<sf::RectangleShape>	setBoxes()
{
	std::vector<sf::RectangleShape>	boxes;
	sf::RectangleShape box1(sf::Vector2f(200, 40));

	box1.setFillColor(sf::Color(200, 200, 200));
	box1.setOutlineThickness(3);
	box1.setOutlineColor(sf::Color(0, 0, 0));
	box1.setPosition(100, 100);
	boxes.push_back(box1);
	return boxes;
}

static void	showMenu(std::vector<sf::RectangleShape> boxes,
		sf::RenderWindow *win)
{
	for (sf::RectangleShape box : boxes) {
		win->draw(box);
	}
}

void	SFMLWrapper::drawMenu()
{
	std::vector<sf::RectangleShape> boxes = setBoxes();
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
		m_win.draw(text);
		m_win.display();
	}
}
