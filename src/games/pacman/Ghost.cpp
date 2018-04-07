/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/04 by lebovin
*/

#include "../../../inc/games/pacman/Ghost.hpp"
#include "../../../inc/games/common/Map.hpp"

Ghost::Ghost(std::pair<std::size_t, std::size_t> &position)
	: BasePacmanEntity(position)
{
	m_speed = 3;
	m_entity.type = EntityType::ENEMY;
	m_entity.ascii = 'G';
	m_entity.sprite = "resources/pacman/ghost.png";
}

bool Ghost::tryMove(Map &map, Direction dir)
{
	auto ndir = checkDir(map);
	BasePacmanEntity::tryMove(map, dir);
	nextDirection = ndir;
	return true;
}

Direction Ghost::goNext(std::vector<Direction> adjCases)
{
	Direction opposite;

	if (m_entity.direction == Direction::TOP)
		opposite = Direction::BOTTOM;
	else if (m_entity.direction == Direction::BOTTOM)
		opposite = Direction::TOP;
	else if (m_entity.direction == Direction::LEFT)
		opposite = Direction::RIGHT;
	else
		opposite = Direction::LEFT;
	if (adjCases[0] != opposite)
		return adjCases[0];
	else
		return adjCases[1];
}

Direction Ghost::goRandom(std::vector<Direction> adjCases)
{
	if (adjCases[0] == Direction::LEFT)
		return adjCases[0];
	int rand = std::rand() % adjCases.size();
	return adjCases[rand];
}

Direction Ghost::checkDir(Map map)
{
	std::vector<Direction> adjCases;

	std::pair<std::size_t, std::size_t> top(m_entity.cellPosition.first, m_entity.cellPosition.second - 1);
	if (map.getEntityAt(top).type == EntityType::EMPTY)
		adjCases.push_back(Direction::TOP);
	std::pair<std::size_t, std::size_t> bot(m_entity.cellPosition.first, m_entity.cellPosition.second + 1);
	if (map.getEntityAt(bot).type == EntityType::EMPTY)
		adjCases.push_back(Direction::BOTTOM);
	std::pair<std::size_t, std::size_t> left(m_entity.cellPosition.first - 1, m_entity.cellPosition.second);
	if (map.getEntityAt(left).type == EntityType::EMPTY)
		adjCases.push_back(Direction::LEFT);
	std::pair<std::size_t, std::size_t> right(m_entity.cellPosition.first + 1, m_entity.cellPosition.second);
	if (map.getEntityAt(right).type == EntityType::EMPTY)
		adjCases.push_back(Direction::RIGHT);
	if (adjCases.size() == 0)
		return goNext(adjCases);
	else
		return goRandom(adjCases);
}
