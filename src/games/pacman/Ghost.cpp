/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/04 by lebovin
*/

#include <unistd.h>
#include "../../../inc/games/pacman/Ghost.hpp"
#include "../../../inc/games/common/Map.hpp"

Ghost::Ghost(std::pair<std::size_t, std::size_t> &position)
	: BasePacmanEntity(position)
{
	m_speed = 3;
	m_entity.type = EntityType::ENEMY;
	m_entity.ascii = 'G';
	nextDirection = Direction::TOP;
	m_entity.sprite = "resources/pacman/ghost.png";
}

std::pair<std::size_t, std::size_t>	Ghost::incPos()
{
	auto nextCell = m_entity.cellPosition;

	switch (m_entity.direction)
	{
	case Direction::RIGHT:
		nextCell.first += 1;
		m_entity.screenPosition.first += m_speed;
		break;
	case Direction::LEFT:
		nextCell.first -= 1;
		m_entity.screenPosition.first -= m_speed;
		break;
	case Direction::TOP:
		nextCell.second -= 1;
		m_entity.screenPosition.second -= m_speed;
		break;
	case Direction::BOTTOM:
		nextCell.second += 1;
		m_entity.screenPosition.second += m_speed;
		break;
	}
	return (nextCell);
}

static Direction takeOpposite(Direction dir)
{
	if (dir == Direction::TOP)
		return Direction::BOTTOM;
	else if (dir == Direction::BOTTOM)
		return Direction::TOP;
	else if (dir == Direction::LEFT)
		return Direction::RIGHT;
	else
		return Direction::LEFT;
}

Direction Ghost::chooseNextDir(Map &map, std::pair<std::size_t, std::size_t> nextCell)
{
	Direction opposite = takeOpposite(m_entity.direction);
	std::vector<Direction> possibleWays;

	std::pair<std::size_t, std::size_t> top(nextCell.first, nextCell.second - 1);
	if (map.getEntityAt(top).type != EntityType::WALL)
		possibleWays.push_back(Direction::TOP);
	std::pair<std::size_t, std::size_t> bot(nextCell.first, nextCell.second + 1);
	if (map.getEntityAt(bot).type != EntityType::WALL)
		possibleWays.push_back(Direction::BOTTOM);
	std::pair<std::size_t, std::size_t> left(nextCell.first - 1, nextCell.second);
	if (map.getEntityAt(left).type != EntityType::WALL)
		possibleWays.push_back(Direction::LEFT);
	std::pair<std::size_t, std::size_t> right(nextCell.first + 1, nextCell.second);
	if (map.getEntityAt(right).type != EntityType::WALL)
		possibleWays.push_back(Direction::RIGHT);
	if (possibleWays.size() == 1)
		return possibleWays[0];
	if (nextCell.second == 9 && (nextCell.first < 3 || nextCell.first > 18))
		return opposite;
	int i = 0;
	for (auto way : possibleWays) {
		if (way == opposite)
			possibleWays.erase(possibleWays.begin() + i);
		i++;
	}
	return possibleWays[std::rand() % (possibleWays.size())];
}

bool Ghost::tryMove(Map &map)
{
	auto nextCell = incPos();
	(void)nextCell;
	if (m_entity.screenPosition.first % 30 == 0 && m_entity.screenPosition.second % 30 == 0) {
		m_entity.cellPosition.first = m_entity.screenPosition.first / 30;
		m_entity.cellPosition.second = m_entity.screenPosition.second / 30;
		m_entity.direction = chooseNextDir(map, nextCell);
	}
	return true;
}

void Ghost::changeSprite(std::string file)
{
	m_entity.sprite = file;
}
