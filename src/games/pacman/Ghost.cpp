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



bool Ghost::tryMove(Map &map, Direction direction)
{
	if (checkDir(direction)) {
		BasePacmanEntity::tryMove(map, direction);
		nextDirection = direction;
	}
	return true;
}

bool Ghost::checkDir(Direction direction)
{
	if (nextDirection == Direction::RIGHT && direction == Direction::LEFT)
		return false;
	if (nextDirection == Direction::LEFT && direction == Direction::RIGHT)
		return false;
	if (nextDirection == Direction::TOP && direction == Direction::BOTTOM)
		return false;
	if (nextDirection == Direction::BOTTOM && direction == Direction::TOP)
		return false;
	return true;
}


