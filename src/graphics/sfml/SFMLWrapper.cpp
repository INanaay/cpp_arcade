/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/03 by lebovin
*/

#include <unistd.h>
#include <iostream>
#include <vector>
#include <memory>
#include "../../../inc/graphics/SFMLWrapper.hpp"
#include "../../../inc/core/Informations.hpp"
#include "../../../inc/core/UserEvent.hpp"
#include "../../../inc/core/EntityType.hpp"

extern "C" SFMLWrapper *create_lib()
{
	return new SFMLWrapper();
}

SFMLWrapper::SFMLWrapper()
{
	m_win = std::make_unique<sf::RenderWindow>(sf::VideoMode(SCR_WIDTH, SCR_HEIGHT), "ARCADE");
	sf::Font	font;
	if (!font.loadFromFile("resources/fonts/Consolas.ttf"))
		throw (std::exception());
	m_font = new sf::Font(font);
	m_music = std::make_unique<sf::Music>();
	if (m_music->openFromFile("resources/Audio/wii.wav"))
		m_music->play();
}

void SFMLWrapper::InitWindow()
{
}

void SFMLWrapper::DestroyWindow()
{
	m_win->close();
}

void SFMLWrapper::Clear()
{
	m_win->clear();
}

void SFMLWrapper::Display()
{
	m_win->display();
}

std::pair<UserEvent, char> SFMLWrapper::getLastEvent()
{
	sf::Event event;
	std::pair<UserEvent, char> lastEvent = std::make_pair<UserEvent, char>(UserEvent::NONE, 0);

	while (m_win->pollEvent(event))
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

void SFMLWrapper::drawGames(std::vector<std::pair<std::string, std::string>>
			    games, std::pair<std::string, std::string> game)
{
	int posX = (SCR_WIDTH / 4 ) * 3;
	int posY = SCR_HEIGHT / 4;

	sf::Text	title("Games :", *m_font);
	title.setFillColor(sf::Color(150, 150, 150));
	title.setPosition(posX, posY);
	posY += 40;
	m_win->draw(title);
	for (std::pair<std::string, std::string> i : games)
	{
		sf::Text name(i.first, *m_font);

		if (i == game)
			name.setFillColor(sf::Color(250, 0, 0));
		else
			name.setFillColor(sf::Color(150, 150, 150));
		name.setPosition(posX, posY);
		posY += 40;
		m_win->draw(name);
	}
}

void SFMLWrapper::DrawMenu(MenuInformations menu, CoreInformations core)
{
	sf::Text name("name : " + menu.name, *m_font, 30);
	sf::Text title("ARCADE", *m_font, 60);
	sf::Text scores("Scoreboard : \n", *m_font, 30);
	sf::Text lib("SFML", *m_font, 30);

	lib.setFillColor(sf::Color(150, 150, 150));
	lib.setPosition(SCR_WIDTH * 3 / 4, 0);
	name.setFillColor(sf::Color(150, 150, 150));
	name.setPosition(0, 0);
	title.setFillColor(sf::Color(150, 150, 150));
	title.setPosition(SCR_WIDTH / 3, 0);
	scores.setFillColor(sf::Color(150, 150, 150));
	scores.setPosition(0, SCR_HEIGHT / 4);
	drawGames(core.games, menu.game);
	m_win->draw(lib);
	m_win->draw(scores);
	m_win->draw(name);
	m_win->draw(title);
}

void SFMLWrapper::DrawMap(std::vector<Entity> &map)
{
	for (auto &entity: map)
		DrawEntity(entity);
}

void SFMLWrapper::DrawEntity(const Entity &entity)
{
	sf::Sprite sprite;
	sf::Texture texture;

	if (m_cache.find(entity.sprite) == m_cache.end())
	{
		texture.loadFromFile(entity.sprite);
		m_cache[entity.sprite] = texture;
	}
	else
		texture = m_cache[entity.sprite];
	sprite = sf::Sprite(texture);
	sprite.setPosition(entity.screenPosition.first,
			entity.screenPosition.second);
	m_win->draw(sprite);
}
