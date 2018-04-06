/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/04 by lebovin
*/

#include <iostream>
#include "../../../inc/games/pacman/BasePacmanEntity.hpp"

BasePacmanEntity::BasePacmanEntity
(std::pair<std::size_t, std::size_t> &position)
{
	m_speed = 0;
	m_nextDirection = Direction ::TOP;
	m_entity.direction = Direction ::TOP;
	m_entity.cellPosition.first = position.first;
	m_entity.cellPosition.second = position.second;
	m_entity.screenPosition.first = position.first * 30;
	m_entity.screenPosition.second = position.second * 30;
}

bool BasePacmanEntity::tryMove(Map &map, Direction direction)
{
	(void)direction;

	switch (m_entity.direction)
	{
		case Direction::RIGHT:
			m_entity.screenPosition.first += m_speed;
			break;
		case Direction::LEFT:
			m_entity.screenPosition.first -= m_speed;
			break;
		case Direction::TOP:
			m_entity.screenPosition.second -= m_speed;
			break;
		case Direction::BOTTOM:
			m_entity.screenPosition.second += m_speed;
			break;
	}

	auto entityAtPosition = map.getEntityAt(m_entity.cellPosition);
	if (entityAtPosition.type == EntityType::WALL)
		return false;

	if (m_entity.screenPosition.first % 30 == 0 && m_entity.screenPosition.second % 30 == 0)
	{
		m_entity.direction = m_nextDirection;
		m_entity.cellPosition.first = m_entity.screenPosition.first / 30;
		m_entity.cellPosition.second = m_entity.screenPosition.second / 30;
		return (true);
	}

	return false;
}
const Entity &BasePacmanEntity::getEntity() const
{
	return (m_entity);
}
void BasePacmanEntity::setNextDirection(Direction nextDirection)
{
	m_nextDirection = nextDirection;
}
