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
	wallEntity.sprite = "resources/nibbler/wall.png";

	appleEntity.ascii = 'A';
	appleEntity.type = EntityType::PICKUP;
	appleEntity.direction = Direction::TOP;
	appleEntity.sprite = "resources/nibbler/apple.png";

	grassEntity.ascii = ' ';
	grassEntity.type = EntityType::EMPTY;
	grassEntity.direction = Direction::TOP;
	grassEntity.sprite = "resources/nibbler/grass.png";

	m_assets[EntityType::WALL] = wallEntity;
	m_assets[EntityType::EMPTY] = grassEntity;
	m_assets[EntityType::PICKUP] = appleEntity;
}

bool NibblerGame::eventHandler(std::pair<UserEvent, char> event)
{
	auto currentDir = m_snake[0].direction;

	if (event.first == UserEvent::NONE)
		return false;
	if (event.first == UserEvent::ESCAPE)
		return true;
	if (event.first == UserEvent::RIGHT && currentDir != Direction::LEFT)
		m_snake[0].nextDirection = (Direction::RIGHT);
	else if (event.first == UserEvent::LEFT && currentDir != Direction::RIGHT)
		m_snake[0].nextDirection = (Direction::LEFT);
	else if (event.first == UserEvent::UP && currentDir != Direction::BOTTOM)
		m_snake[0].nextDirection = (Direction::TOP);
	else if (event.first == UserEvent::DOWN && currentDir != Direction::TOP)
		m_snake[0].nextDirection = (Direction::BOTTOM);
	return false;
}

UserEvent NibblerGame::Run()
{
	std::pair<UserEvent, char> event;

	while (1)
	{
		event = m_library->getLastEvent();
		if (event.first == UserEvent::LIB_NEXT || event.first == UserEvent::LIB_PREV)
			return event.first;
		if (eventHandler(event))
			break ;
		moveSnake();
		m_library->Clear();
		for (auto i : m_map.getEntities()) {
			m_library->DrawEntity(i.second);
		}
		for (auto i : m_snake) {
			m_library->DrawEntity(i);
		}
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

	srand(time(NULL));
	m_apple.ascii = ('A');
	m_apple.type = (EntityType::PICKUP);
	m_apple.direction = (Direction::TOP);
	m_apple.sprite = ("resources/nibbler/apple.png");
	auto posInit = m_map.getCenteredPosition();
	SnakeEntity snake;
	snake.cellPosition = posInit;
	snake.screenPosition = std::pair<std::size_t, std::size_t>(posInit.first * 30,
			posInit.second * 30);
	snake.ascii = 'O';
	snake.sprite = "resources/nibbler/snake.png";
	snake.direction = Direction::TOP;
	snake.nextDirection = Direction::TOP;
	m_snake.push_back(snake);
	for (int i = 0; i < 3; i++)
	{
		posInit.second += 1;
		snake.cellPosition = posInit;
		snake.screenPosition = std::pair<std::size_t, std::size_t>(posInit.first * 30,
				posInit.second * 30);
		snake.ascii = 'O';
		snake.sprite = "resources/nibbler/snake.png";
		snake.direction = Direction::TOP;
		snake.nextDirection = Direction::TOP;
		m_snake.push_back(snake);
	}
	popApple();
}

void	NibblerGame::checkCol()
{
	auto nextCase = m_snake[0].cellPosition;

	switch (m_snake[0].direction)
	{
		case (Direction::TOP) :
			nextCase.second -= 1;
			break;
		case (Direction::BOTTOM) :
			nextCase.second += 1;
			break;
		case (Direction::LEFT) :
			nextCase.first -= 1;
			break;
		case (Direction::RIGHT) :
			nextCase.first += 1;
			break;
	}
	if (m_map.getEntityAt(nextCase).type == EntityType::WALL) {
		m_library->DestroyWindow();
		printf("wall\n");
		std::exit(0);
	}
	for (auto i : m_snake)
	{
		if (nextCase == i.cellPosition) {
			m_library->DestroyWindow();
		printf("Snake\n");
		std::exit(0);
		}
	}
}

void	NibblerGame::checkApple()
{
	if (m_map.getEntityAt(m_snake[0].cellPosition).type == EntityType::PICKUP)
	{
		m_snake.push_back(m_prevSnake);
		m_map.getEntityAt(m_apple.cellPosition).type = EntityType::EMPTY;
		m_map.getEntityAt(m_apple.cellPosition).sprite = "resources/nibbler/grass.png";
		popApple();
	}
}

void	NibblerGame::moveSnake()
{
	Direction prev;

	for (int i = 0; i < (int)m_snake.size(); i++) {
		if (m_snake[i].screenPosition.first % 30 == 0 &&
				m_snake[i].screenPosition.second % 30 == 0)
		{
			m_snake[i].direction = m_snake[i].nextDirection;
			if (i == 0) {
				checkCol();
				checkApple();
				m_prevSnake = m_snake[m_snake.size() - 1];
			}
			else
					m_snake[i].nextDirection = prev;
			if (m_snake[i].direction == Direction::TOP)
				m_snake[i].cellPosition.second -= 1;
			else if (m_snake[i].direction == Direction::BOTTOM)
				m_snake[i].cellPosition.second += 1;
			else if (m_snake[i].direction == Direction::LEFT)
				m_snake[i].cellPosition.first -= 1;
			else if (m_snake[i].direction == Direction::RIGHT)
				m_snake[i].cellPosition.first += 1;
			prev = m_snake[i].direction;
		}
		if (m_snake[i].direction == Direction::TOP)
			m_snake[i].screenPosition.second -= 5;
		else if (m_snake[i].direction == Direction::BOTTOM)
			m_snake[i].screenPosition.second += 5;
		else if (m_snake[i].direction == Direction::LEFT)
			m_snake[i].screenPosition.first -= 5;
		else if (m_snake[i].direction == Direction::RIGHT)
			m_snake[i].screenPosition.first += 5;
	}
}

void NibblerGame::popApple()
{
	auto size = m_map.getDimensions();
	auto randPos = std::make_pair(rand() % (size.first), rand() % size.second);
	bool ok = false;

	while (ok == false) {
		randPos = std::make_pair(rand() % (size.first), rand() % size.second);
		for (auto i : m_snake) {
			ok = true;
			if (i.cellPosition == randPos)
				ok = false;
			if (m_map.getEntityAt(randPos).type != EntityType::EMPTY)
				ok = false;
		}
	}
	m_apple.cellPosition = randPos;
	m_apple.screenPosition = std::pair<std::size_t, std::size_t>(randPos.first * 30,
			randPos.second * 30);
	Entity &entity = m_map.getEntityAt(m_apple.cellPosition);
	entity = m_apple;
}
