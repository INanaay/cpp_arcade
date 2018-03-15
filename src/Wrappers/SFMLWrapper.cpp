/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/03 by lebovin
*/

#include <ncurses.h>
#include <iostream>
#include "../../inc/Wrappers/SFMLWrapper.hpp"

extern "C" SFMLWrapper *create_lib()
{
	return new SFMLWrapper();
}

void SFMLWrapper::InitWindow()
{
	m_win.create(sf::VideoMode(SCR_WIDTH, SCR_HEIGHT), "MENU");
	if (!m_font.loadFromFile("ressources/fonts/Consolas.ttf"))
		throw (std::exception());
}

void	SFMLWrapper::DestroyWindow()
{
	m_win.close();
}

void SFMLWrapper::Clear()
{
	m_win.clear();
}

void SFMLWrapper::Display()
{
	m_win.display();
}

std::pair<UserEvent, char> SFMLWrapper::getLastEvent()
{
	sf::Event	event;
	std::pair<UserEvent, char> lastEvent = std::make_pair<UserEvent, char>(UserEvent::NONE, 0);

	while (m_win.pollEvent(event))
	{
		if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			lastEvent.first = UserEvent::ESCAPE;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			lastEvent.first = UserEvent::ENTER;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			lastEvent.first = UserEvent::LEFT;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			lastEvent.first = UserEvent::RIGHT;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			lastEvent.first = UserEvent::UP;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			lastEvent.first = UserEvent::DOWN;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::PageUp))
			lastEvent.first = UserEvent::LIB_NEXT;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::PageDown))
			lastEvent.first = UserEvent::LIB_PREV;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			lastEvent.first = UserEvent::ACTION1;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
			lastEvent.first = UserEvent::ACTION2;
		else if (event.type == sf::Event::TextEntered)
		{
			if (event.text.unicode < 128 &&
					(static_cast<char>(event.text.unicode) == '\b' ||
					 isalnum(static_cast<char>(event.text.unicode)) != 0))
			{
				lastEvent.first = UserEvent::TEXT;
				lastEvent.second = static_cast<char>(event.text.unicode);
			}
		}
	}
	return lastEvent;
}

void	SFMLWrapper::drawGames(std::vector<std::string> games, std::string game)
{
	int posX = SCR_WIDTH;
	int posY = SCR_HEIGHT / 4;

	sf::Text	title("Games :", m_font);
	title.setFillColor(sf::Color(150, 150, 150));
	title.setPosition(posX, posY);
	posY += 40;
	m_win.draw(title);
	for (std::string i : games)
	{
		sf::Text	name(i, m_font);
		if (i == game)
			name.setFillColor(sf::Color(250, 0, 0));
		else
			name.setFillColor(sf::Color(150, 150, 150));
		name.setPosition(posX, posY);
		posY += 40;
		m_win.draw(name);
	}
}

void	SFMLWrapper::DrawMenu(MenuInformations menu, CoreInformations core)
{
	sf::Text name("name : " + menu.name, m_font, 30);
	sf::Text title("ARCADE", m_font, 60);
	sf::Text scores("Scoreboard : \n", m_font, 30);
	sf::Text lib("SFML", m_font, 30);

	lib.setFillColor(sf::Color(150, 150, 150));
	lib.setPosition(SCR_WIDTH, 0);
	name.setFillColor(sf::Color(150, 150, 150));
	name.setPosition(0, 0);
	title.setFillColor(sf::Color(150, 150, 150));
	title.setPosition(SCR_WIDTH / 2, 0);
	scores.setFillColor(sf::Color(150, 150, 150));
	scores.setPosition(0, SCR_HEIGHT / 4);
	drawGames(core.games, menu.game);
	m_win.draw(lib);
	m_win.draw(scores);
	m_win.draw(name);
	m_win.draw(title);
}
