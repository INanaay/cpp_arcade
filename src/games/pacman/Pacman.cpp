/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/04 by lebovin
*/

#include <iostream>
#include "../../../inc/games/pacman/Pacman.hpp"
#include "../../../inc/games/pacman/BasePacmanEntity.hpp"

Pacman::Pacman(std::pair<std::size_t, std::size_t> &position)
: BasePacmanEntity(position)
{
	m_speed = 3;
	m_mouthOpen = true;
	m_entity.type = EntityType::PLAYER;
	m_entity.ascii = 'C';
	m_entity.sprite = "resources/pacman/open.png";
}

bool Pacman::tryMove(Map &map)
{
	auto moved = BasePacmanEntity::tryMove(map);

	if (moved)
		changeSkin();
	return (moved);
}

void Pacman::changeSkin()
{
	if (m_mouthOpen)
	{
		m_mouthOpen = false;
		m_entity.ascii = 'C';
		m_entity.sprite = "resources/pacman/close.png";
	}
	else
	{
		m_mouthOpen = true;
		m_entity.ascii = 'c';
		m_entity.sprite = "resources/pacman/open.png";
	}
}

