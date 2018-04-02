/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/03 by lebovin
*/

#include <unistd.h>
#include <time.h>
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
	wallEntity.setType(EntityType::WALL);
	wallEntity.setDirection(Direction::TOP);
	wallEntity.setSprite("ressources/nibbler/wall.png");

	appleEntity.setSize(1);
	appleEntity.setSpeed(0);
	appleEntity.setAscii('A');
	appleEntity.setType(EntityType::PICKUP);
	appleEntity.setDirection(Direction::TOP);
	appleEntity.setSprite("ressources/nibbler/apple.png");

	grassEntity.setSize(1);
	grassEntity.setSpeed(0);
	grassEntity.setAscii(' ');
	grassEntity.setType(EntityType::EMPTY);
	grassEntity.setDirection(Direction::TOP);
	grassEntity.setSprite("ressources/nibbler/grass.png");

	m_assets[EntityType::WALL] = wallEntity;
	m_assets[EntityType::EMPTY] = grassEntity;
	m_assets[EntityType::PICKUP] = appleEntity;
}

void NibblerGame::eventHandler(std::pair<UserEvent, char> event)
{
	auto currentDir = m_snake[0].getDirection();

	if (event.first == UserEvent::ESCAPE)
	{
		m_library->DestroyWindow();
		std::exit(0);
	}
	if (event.first == UserEvent::RIGHT && currentDir != Direction::LEFT)
		m_snake[0].setNextDirection(Direction::RIGHT);
	else if (event.first == UserEvent::LEFT && currentDir != Direction::RIGHT)
		m_snake[0].setNextDirection(Direction::LEFT);
	else if (event.first == UserEvent::UP && currentDir != Direction::BOTTOM)
		m_snake[0].setNextDirection(Direction::TOP);
	else if (event.first == UserEvent::DOWN && currentDir != Direction::TOP)
		m_snake[0].setNextDirection(Direction::BOTTOM);
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
		moveSnake();
		for (auto &entity: m_snake)
			m_library->DrawEntity(entity);
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
	head.setCase({4, 10});
	head.setSprite("ressources/nibbler/head.png");
	head.setAscii('O');
	head.setSize(1);
	head.setSpeed(1);
	head.setDirection(Direction::TOP);
	head.setNextDirection(Direction::TOP);
	head.setType(EntityType::PLAYER);

	body.setPosition({4 * 30, 11 * 30});
	body.setCase({4, 11});
	body.setSprite("ressources/nibbler/body.png");
	body.setAscii('O');
	body.setSize(1);
	body.setSpeed(1);
	body.setDirection(Direction::TOP);
	body.setNextDirection(Direction::TOP);
	body.setType(EntityType::PLAYER);

	tail.setPosition({4 * 30, 12 * 30});
	tail.setCase({4, 12});
	tail.setSprite("ressources/nibbler/tail.png");
	tail.setAscii('O');
	tail.setSize(1);
	tail.setSpeed(1);
	tail.setDirection(Direction::TOP);
	tail.setType(EntityType::PLAYER);

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
			entity.setCase({x, y});
			m_map.push_back(entity);
		}
	}
}

bool NibblerGame::isGameFinished()
{
	auto headCase = m_snake[0].getCase();
	for (auto &entity: m_map)
		if (entity.getType() == EntityType::WALL &&
		    entity.getCase() == headCase)
			return (true);
		else if (entity.getType() == EntityType::PLAYER &&
			 entity.getCase() == headCase)
			return (true);
	return (false);
}

void NibblerGame::chooseNextDir(Entity &entity, std::size_t i)
{
	if (i < m_snake.size() - 1)
		m_snake[i + 1].setNextDirection(entity.getDirection());
	entity.setDirection(entity.getNextDirection());
}

void NibblerGame::moveSnake()
{
	for (std::size_t i = 0; i < m_snake.size(); i++)
	{
		auto &entity = m_snake[i];
		auto pos = entity.getPosition();
		auto currentCase = entity.getCase();

		if (entity.getDirection() == Direction::TOP)
			pos.second -= 5;
		else if (entity.getDirection() == Direction::RIGHT)
			pos.first += 5;
		else if (entity.getDirection() == Direction::BOTTOM)
			pos.second += 5;
		else
			pos.first -= 5;
		entity.setPosition(pos);
		if ((int)(pos.first) % 30 == 0 && (int)(pos.second) % 30 == 0)
		{
			chooseNextDir(entity, i);
			if (entity.getDirection() == Direction::TOP)
				currentCase.second -= 1;
			else if (entity.getDirection() == Direction::RIGHT)
				currentCase.first += 1;
			else if (entity.getDirection() == Direction::BOTTOM)
				currentCase.second += 1;
			else
				currentCase.first -= 1;
			entity.setCase(currentCase);
		}
	}
}
