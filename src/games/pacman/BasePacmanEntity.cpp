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
	nextDirection = Direction ::TOP;
	m_entity.direction = Direction ::TOP;
	m_entity.cellPosition.first = position.first;
	m_entity.cellPosition.second = position.second;
	m_entity.screenPosition.first = position.first * 30;
	m_entity.screenPosition.second = position.second * 30;
}

bool BasePacmanEntity::tryMove(Map &map)
{
	auto entityPosition = m_entity.cellPosition;
	auto screenPosition = m_entity.screenPosition;


	switch (m_entity.direction)
	{
		case Direction::RIGHT:
			if (entityPosition.first < 20)
				entityPosition.first += 1;
			screenPosition.first += m_speed;
			break;
		case Direction::LEFT:
			if (entityPosition.first > 0)
				entityPosition.first -= 1;
			screenPosition.first -= m_speed;
			break;
		case Direction::TOP:
			entityPosition.second -= 1;
			screenPosition.second -= m_speed;
			break;
		case Direction::BOTTOM:
			entityPosition.second += 1;
			screenPosition.second += m_speed;
			break;
	}

	auto entityAtPosition = map.getEntityAt(entityPosition);
	if (entityAtPosition.type == EntityType::WALL)
	{
		m_entity.direction = nextDirection;
		return false;
	}

	m_entity.screenPosition.first = screenPosition.first;
	m_entity.screenPosition.second = screenPosition.second;

	if (m_entity.screenPosition.first % 30 == 0 && m_entity.screenPosition.second % 30 == 0)
	{
		m_entity.direction = nextDirection;
		m_entity.cellPosition.first = m_entity.screenPosition.first / 30;
		m_entity.cellPosition.second = m_entity.screenPosition.second / 30;
		if (m_entity.cellPosition.first == 0 && m_entity.cellPosition.second == 9)
			m_entity.screenPosition.first = 20 * 30;
		if (m_entity.cellPosition.first == 21 && m_entity.cellPosition.second == 9)
			m_entity.screenPosition.first = 0 * 30;
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
