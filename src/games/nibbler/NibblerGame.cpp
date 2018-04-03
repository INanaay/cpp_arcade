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

	wallEntity.ascii = 'X';
	wallEntity.type = EntityType::WALL;
	wallEntity.direction = Direction::TOP;
	wallEntity.sprite = "ressources/nibbler/wall.png";

	appleEntity.ascii = 'A';
	appleEntity.type = EntityType::PICKUP;
	appleEntity.direction = Direction::TOP;
	appleEntity.sprite = "ressources/nibbler/apple.png";

	grassEntity.ascii = ' ';
	grassEntity.type = EntityType::EMPTY;
	grassEntity.direction = Direction::TOP;
	grassEntity.sprite = "ressources/nibbler/grass.png";

	m_assets[EntityType::WALL] = wallEntity;
	m_assets[EntityType::EMPTY] = grassEntity;
	m_assets[EntityType::PICKUP] = appleEntity;
	m_map()
}

bool NibblerGame::eventHandler(std::pair<UserEvent, char> event)
{
//	auto currentDir = m_snake[0].getDirection();

	if (event.first == UserEvent::ESCAPE)
		return true;
/*	if (event.first == UserEvent::RIGHT && currentDir != Direction::LEFT)
		m_snake[0].setNextDirection(Direction::RIGHT);
	else if (event.first == UserEvent::LEFT && currentDir != Direction::RIGHT)
		m_snake[0].setNextDirection(Direction::LEFT);
	else if (event.first == UserEvent::UP && currentDir != Direction::BOTTOM)
		m_snake[0].setNextDirection(Direction::TOP);
	else if (event.first == UserEvent::DOWN && currentDir != Direction::TOP)
		m_snake[0].setNextDirection(Direction::BOTTOM);*/
	return false;
}

UserEvent NibblerGame::Run()
{
	std::pair<UserEvent, char> event;

	while (1)
	{
		m_library->Clear();
		event = m_library->getLastEvent();
		if (event.first == UserEvent::LIB_NEXT || event.first == UserEvent::LIB_PREV)
			return event.first;
		if (eventHandler(event))
			break ;
		/*m_library->DrawMap(m_map);
		moveSnake();
		for (auto &entity: m_snake)
			m_library->DrawEntity(entity);*/
		m_library->Display();
	}
	return UserEvent::ESCAPE;
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
	setLib(std::move(library));
	m_map.loadFile("./resources/nibbler/test.map", m_assets);
/*	Entity head;
	Entity body;
	Entity tail;

	head.setPosition({4 * 30, 10 * 30});
	head.setCase({4, 9});
	head.setSprite("ressources/nibbler/head.png");
	head.setAscii('O');
	head.setSize(1);
	head.setSpeed(1);
	head.setDirection(Direction::TOP);
	head.setNextDirection(Direction::TOP);
	head.setType(EntityType::PLAYER);

	body.setPosition({4 * 30, 11 * 30});
	body.setCase({4, 10});
	body.setSprite("ressources/nibbler/body.png");
	body.setAscii('O');
	body.setSize(1);
	body.setSpeed(1);
	body.setDirection(Direction::TOP);
	body.setNextDirection(Direction::TOP);
	body.setType(EntityType::PLAYER);

	tail.setPosition({4 * 30, 12 * 30});
	tail.setCase({4, 11});
	tail.setSprite("ressources/nibbler/tail.png");
	tail.setAscii('O');
	tail.setSize(1);
	tail.setSpeed(1);
	tail.setDirection(Direction::TOP);
	body.setNextDirection(Direction::TOP);
	tail.setType(EntityType::PLAYER);

	m_snake.push_back(head);
	m_snake.push_back(body);
	m_snake.push_back(tail);

	loadMap("ressources/nibbler/test.map");
	popApple();*/
}

/*void NibblerGame::loadMap(const std::string &path)
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
		{
			printf("wall touched\n");
			return (true);
		}
		else if (entity.getType() == EntityType::PLAYER &&
			 entity.getCase() == headCase)
		{
			printf("snake touched\n");
			return (true);
		}
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
	int check = 0;
	bool append = m_snake[0].getCase() == m_apple.getCase();
	if (append && m_appleState == 1)
	{
		m_appleState = 2;
		Entity empty = m_assets[EntityType::EMPTY];
		empty.setCase(m_apple.getCase());
		empty.setPosition(m_apple.getPosition());
		m_map[m_appleIndex] = empty;
	}
	if (m_appleState == 3)
	printf("APPLE %d %d\n", m_apple.getCase().first, m_apple.getCase().second);
for (std::size_t i = 0; i < m_snake.size(); i++)
{
	if (m_appleState == 3) {
	printf("snake n*%d\n", (int)i);
	printf("%d %d\n", m_snake[i].getCase().first, m_snake[i].getCase().second);
	}
	if (m_snake[i].getCase() == m_apple.getCase())
			check = 1;
}

	if (check == 0 && m_appleState == 3)
	{
		printf("POP\n");
		m_appleState = 1;
		auto block = m_snake[1];
		auto popCase = m_apple.getCase();
		block.setCase(m_apple.getCase());
		block.setPosition(m_apple.getPosition());
		auto tail = m_snake[m_snake.size() - 1];
		if (tail.getCase().first == block.getCase().first)
		{
			if (tail.getCase().second > block.getCase().second) {
				block.setDirection(Direction::BOTTOM);
				popCase.second += 1;
			}
			else {
				block.setDirection(Direction::TOP);
				popCase.second -= 1;
			}
		} else {
			if (tail.getCase().first > block.getCase().first) {
				block.setDirection(Direction::RIGHT);
			}
			else {
				block.setDirection(Direction::LEFT);
			}
		}
		block.setCase(popCase);
		m_snake.push_back(block);
		Entity empty = m_assets[EntityType::EMPTY];
		empty.setCase(m_apple.getCase());
		empty.setPosition(m_apple.getPosition());
		m_map[m_appleIndex] = empty;
		popApple();
		printf("new : %d %d\n", block.getCase().first, block.getCase().second);
		for (auto &entity: m_snake)
			m_library->DrawEntity(entity);
		m_library->Display();
		sleep(2);
	}

	for (std::size_t i = 0; i < m_snake.size(); i++)
	{
		auto &entity = m_snake[i];
		auto pos = entity.getPosition();
		auto currentCase = entity.getCase();

		if (i == m_snake.size() - 1 && append)
		{
			auto it = m_snake.begin() + i - 1;
			m_snake.insert(it, entity);
			popApple();
			append = false;
		}

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
			if (check == 0 && m_appleState == 2)
			{
				m_appleState = 3;
			}
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

void NibblerGame::popApple()
{
	m_apple.setSize(1);
	m_apple.setSpeed(0);
	m_apple.setAscii('A');
	m_appleState = 1;
	m_apple.setType(EntityType::PICKUP);
	m_apple.setDirection(Direction::TOP);
	m_apple.setSprite("ressources/nibbler/apple.png");

	int index;
	Entity entity;
	do
	{
		index = rand() % m_map.size();
		entity = m_map[index];
	} while (entity.getType() != EntityType::EMPTY);

	auto cases = entity.getCase();
	auto position = std::pair<float, float>(cases.first * 30,
						cases.second * 30);
	m_appleIndex = index;
	m_apple.setCase(cases);
	m_apple.setPosition(position);
	m_map[index] = m_apple;

}*/
