/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/03 by lebovin
*/

#ifndef CPP_ARCADE_ENTITY_HPP
#define CPP_ARCADE_ENTITY_HPP

#include <string>
#include <utility>
#include "Direction.hpp"
#include "EntityType.hpp"

struct Entity
{
	char ascii;
	EntityType type;
	std::string sprite;
	Direction direction;
	std::pair<std::size_t, std::size_t> cellPosition;
	std::pair<std::size_t, std::size_t> screenPosition;
};


#endif //CPP_ARCADE_ENTITY_HPP
