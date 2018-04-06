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
	m_entity.type = EntityType::ENEMY;
	m_entity.ascii = 'G';
	m_entity.sprite = "resources/pacman/ghost.png";
}
