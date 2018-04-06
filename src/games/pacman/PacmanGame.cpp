/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/04 by lebovin
*/

#include <iostream>
#include "../../../inc/games/pacman/PacmanGame.hpp"

extern "C" PacmanGame *create_game()
{
	return new PacmanGame();
}

UserEvent PacmanGame::run()
{
	auto &mapEntities = m_map.getEntities();

	while (true)
	{
		m_library->clearWindow();
		for (const auto &entry: mapEntities)
			m_library->drawEntity(entry.second);
		m_library->drawEntity(m_player.getEntity());
		for (const auto &entry: m_coins)
			m_library->drawEntity(entry.second);
		m_library->drawScore(m_score, 25, 0);
		moveEntities();
		m_library->display();
	}
	return UserEvent ::NONE;
}
void PacmanGame::moveEntities()
{
	auto userInput = m_library->getLastEvent();
	Direction direction = m_player.getEntity().direction;

	switch (userInput.first)
	{
		case UserEvent::DOWN:
			m_player.nextDirection = Direction::BOTTOM;
			break;
		case UserEvent::UP:
			m_player.nextDirection = Direction::TOP;
			break;
		case UserEvent::LEFT:
			m_player.nextDirection = Direction::LEFT;
			break;
		case UserEvent::RIGHT:
			m_player.nextDirection = Direction::RIGHT;
			break;
		default:
			break;
	}

	m_player.tryMove(m_map, direction);
	auto playerPosition = m_player.getEntity().cellPosition;
	auto it = m_coins.find(playerPosition);
	if (it != m_coins.end())
	{
		m_score += 10;
		m_coins.erase(it);
	}
}

void PacmanGame::stop()
{

}

void PacmanGame::init(std::unique_ptr<IGlib> library)
{
	setLib(std::move(library));
	initAssets();
	m_map.loadFile("resources/pacman/test.map", m_assets);
	initCoins();
	initEntities();
}

std::unique_ptr<IGlib> PacmanGame::getLib()
{
	return (std::move(m_library));
}

void PacmanGame::setLib(std::unique_ptr<IGlib> ptr)
{
	m_library = std::move(ptr);
}

void PacmanGame::initAssets()
{
	Entity wallEntity;
	wallEntity.type = EntityType ::WALL;
	wallEntity.ascii = 'X';
	wallEntity.sprite = "resources/pacman/wall.png";
	wallEntity.direction = Direction ::TOP;

	Entity groundEntity;
	groundEntity.type = EntityType ::EMPTY;
	groundEntity.ascii = ' ';
	groundEntity.sprite = "resources/pacman/empty.png";
	groundEntity.direction = Direction ::TOP;

	m_assets[wallEntity.type] = wallEntity;
	m_assets[groundEntity.type] = groundEntity;
}

void PacmanGame::initEntities()
{
	auto playerPosition = std::pair<std::size_t, std::size_t>(10, 11);
	m_player = Pacman(playerPosition);

	for (int i = 0; i < 4; i++)
	{
		auto position = m_map.getCenteredPosition();
		m_ghosts.push_back(Ghost(position));
	}
}

static bool isCoin(std::pair<std::size_t, std::size_t> entry)
{
	if (entry.second == 9) {
		if ((entry.first >= 5 && entry.first <= 7) ||
				(entry.first >= 13 && entry.first <= 15))
			return true;
		return false;
	}
	if (entry.second == 8 && entry.first == 10)
		return false;
	if (entry.second == 11 && entry.first == 10)
		return false;
	return true;
}

void PacmanGame::initCoins()
{
	auto &entities = m_map.getEntities();
	for (auto &entry: entities)
	{
		auto &entity = entry.second;
		if (entity.type == EntityType::EMPTY && isCoin(entry.first) == true)
		{
			Entity coinEntity;

			coinEntity.type = EntityType::PICKUP;
			coinEntity.ascii = 'o';
			coinEntity.sprite = "resources/pacman/coin.png";
			coinEntity.cellPosition.first = entity.cellPosition.first;
			coinEntity.cellPosition.second = entity.cellPosition.second;
			coinEntity.screenPosition.first = entity
								  .cellPosition.first * 30;
			coinEntity.screenPosition.second = entity
								   .cellPosition.second * 30;
			m_coins[coinEntity.cellPosition] = coinEntity;
		}
	}
}

size_t PacmanGame::getScore() {
	return m_score;
}
