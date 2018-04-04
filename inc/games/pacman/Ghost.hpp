/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/04 by lebovin
*/

#ifndef CPP_ARCADE_GHOST_HPP
#define CPP_ARCADE_GHOST_HPP

#include <utility>
#include "BasePacmanEntity.hpp"

class Ghost : BasePacmanEntity
{
public:
	//CTOR DTOR
	Ghost(std::pair<std::size_t, std::size_t> &position);
};

#endif //CPP_ARCADE_GHOST_HPP
