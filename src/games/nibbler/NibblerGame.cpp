/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/03 by lebovin
*/

#include <unistd.h>
#include <fstream>
#include <iostream>
#include "../../../inc/games/nibbler/NibblerGame.hpp"
#include "../../../inc/core/GameException.hpp"
#include "../../../inc/core/EntityType.hpp"

extern "C" NibblerGame *create_game()
{
	return new NibblerGame();
}

NibblerGame::NibblerGame()
{
	Entity wallEntity;
	Entity appleEntity;
	Entity grassEntity;

	wallEntity.setSize(1);
	wallEntity.setSpeed(0);
	wallEntity.setAscii('X');
	wallEntity.setDirection(Direction::TOP);
	wallEntity.setSprite("ressources/nibbler/wall.png");

	appleEntity.setSize(1);
	appleEntity.setSpeed(0);
	appleEntity.setAscii('A');
	appleEntity.setDirection(Direction::TOP);
	appleEntity.setSprite("ressources/nibbler/apple.png");

	grassEntity.setSize(1);
	grassEntity.setSpeed(0);
	grassEntity.setAscii(' ');
	grassEntity.setDirection(Direction::TOP);
	grassEntity.setSprite("ressources/nibbler/grass.png");

	m_assets[EntityType::WALL] = wallEntity;
	m_assets[EntityType::EMPTY] = grassEntity;
	m_assets[EntityType::PICKUP] = appleEntity;
}

void NibblerGame::eventHandler(std::pair<UserEvent, char> event)
{
	if (event.first == UserEvent::ESCAPE)
	{
		m_library->DestroyWindow();
		std::exit(0);
	}
}

UserEvent NibblerGame::Run()
{
	std::pair<UserEvent, char> event;

	while (!isGameFinished())
	{
		m_library->Clear();
		event = m_library->getLastEvent();
		if (event.first == UserEvent::LIB_NEXT || event.first == UserEvent::LIB_PREV)
			return event.first;
		eventHandler(event);
		m_library->DrawMap(m_map);
		drawSnake();
		m_library->Display();
	}
	return UserEvent::NONE;
}

void NibblerGame::Stop()
{

}

std::unique_ptr<IGlib>	NibblerGame::getLib()
{
	return std::move(m_library);
}

void NibblerGame::setLib(std::unique_ptr<IGlib> library)
{
	m_library = std::move(library);
}

void NibblerGame::Init(std::unique_ptr<IGlib> library)
{
	Entity head;
	Entity body;
	Entity tail;

	head.setPosition({4 * 30, 10 * 30});
	head.setSprite("ressources/nibbler/head.png");
	head.setAscii('O');
	head.setSize(1);
	head.setSpeed(1);
	head.setDirection(Direction::TOP);

	body.setPosition({4 * 30, 11 * 30});
	body.setSprite("ressources/nibbler/body.png");
	body.setAscii('O');
	body.setSize(1);
	body.setSpeed(1);
	body.setDirection(Direction::TOP);

	tail.setPosition({4 * 30, 12 * 30});
	tail.setSprite("ressources/nibbler/tail.png");
	tail.setAscii('O');
	tail.setSize(1);
	tail.setSpeed(1);
	tail.setDirection(Direction::TOP);

	m_snake.push_back(head);
	m_snake.push_back(body);
	m_snake.push_back(tail);

	setLib(std::move(library));
	loadMap("ressources/nibbler/test.map");
}

void NibblerGame::loadMap(const std::string &path)
{
	std::string line;
	std::ifstream fstream(path);
	std::vector<std::string> buffer;

	if (!fstream)
		throw GameException("Cannot load given map.");
	while (std::getline(fstream, line))
		buffer.push_back(line);
	for (std::size_t y = 0; y < buffer.size(); y++)
	{
		line = buffer[y];
		for (std::size_t x = 0; x < line.size(); x++)
		{
			auto type = (EntityType)(line[x] - '0');
			if (m_assets.find(type) == m_assets.end())
				continue ;
			auto entity = m_assets[type];
			entity.setPosition({x * 30, y * 30});
			m_map.push_back(entity);
		}
	}
}
bool NibblerGame::isGameFinished()
{
	return false;
}
void NibblerGame::drawSnake()
{
	for (std::size_t i = m_snake.size() - 1; i > 0; i--)
	{
		auto &entity = m_snake[i];
		auto &next = m_snake[i - 1];

		entity.setPosition(next.getPosition());
		entity.setDirection(next.getDirection());
	}
	auto &head = m_snake[0];

	auto event = m_library->getLastEvent();
	std::cout << (int)event.first << std::endl;
	if (event.first == UserEvent::RIGHT)
		head.setDirection(Direction::RIGHT);
	else if (event.first == UserEvent::LEFT)
		head.setDirection(Direction::LEFT);
	else if (event.first == UserEvent::UP)
		head.setDirection(Direction::TOP);
	else if (event.first == UserEvent::DOWN)
		head.setDirection(Direction::BOTTOM);

	auto position = head.getPosition();
	if (head.getDirection() == Direction::TOP)
		position.second -= 30;
	else if (head.getDirection() == Direction::RIGHT)
		position.first += 30;
	else if (head.getDirection() == Direction::BOTTOM)
		position.second += 30;
	else
		position.first -= 30;
	head.setPosition(position);
	for (auto &entity: m_snake)
		m_library->DrawEntity(entity);
}
