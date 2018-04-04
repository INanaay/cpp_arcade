/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/04 by lebovin
*/

#include "../../../inc/games/pacman/BasePacmanEntity.hpp"

BasePacmanEntity::BasePacmanEntity
(std::pair<std::size_t, std::size_t> &position)
{
	m_entity.cellPosition.first = position.first;
	m_entity.cellPosition.second = position.second;
	m_entity.screenPosition.first = position.first * 30;
	m_entity.screenPosition.second = position.second * 30;
}
void BasePacmanEntity::move(Direction direction)
{
	m_entity.direction = direction;

	switch (direction)
	{
		case Direction::TOP:
			m_entity.screenPosition.first += 5;
			break;
		case Direction::BOTTOM:
			m_entity.screenPosition.first -= 5;
			break;
		case Direction::LEFT:
			m_entity.screenPosition.second -= 5;
			break;
		case Direction::RIGHT:
			m_entity.screenPosition.second += 5;
			break;
	}
}
const Entity &BasePacmanEntity::getEntity() const
{
	return (m_entity);
}

bool BasePacmanEntity::tryMoveCell()
{
	auto cellX = (m_entity.screenPosition.first / 30);
	auto cellY = (m_entity.screenPosition.second / 30);

	auto newCell = m_entity.cellPosition.first != cellX ||
		       m_entity.cellPosition.second != cellY;

	if (newCell)
	{
		m_entity.cellPosition.first = cellX;
		m_entity.cellPosition.second = cellY;
	}

	return (newCell);
}
