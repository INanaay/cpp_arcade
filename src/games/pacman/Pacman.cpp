/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/04 by lebovin
*/

#include "../../../inc/games/pacman/Pacman.hpp"
#include "../../../inc/games/pacman/BasePacmanEntity.hpp"

Pacman::Pacman(std::pair<std::size_t, std::size_t> &position)
: BasePacmanEntity(position)
{
	m_mouthOpen = true;
	m_entity.type = EntityType::PLAYER;
	m_entity.ascii = 'C';
	m_entity.sprite = "resources/pacman/open.png";
}

void Pacman::move(Direction direction)
{
	BasePacmanEntity::move(direction);

	if (tryMoveCell())
		changeSkin();
}

void Pacman::changeSkin()
{
	if (m_mouthOpen)
	{
		m_entity.ascii = 'C';
		m_entity.sprite = "resources/pacman/open.png";
	}
	else
	{
		m_entity.ascii = 'c';
		m_entity.sprite = "resources/pacman/close.png";
	}
}

