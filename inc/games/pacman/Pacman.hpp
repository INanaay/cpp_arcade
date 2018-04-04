/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/04 by lebovin
*/

#ifndef CPP_ARCADE_PACMAN_HPP
#define CPP_ARCADE_PACMAN_HPP


#include <utility>
#include "BasePacmanEntity.hpp"
#include "../../core/Entity.hpp"
#include "../../core/Direction.hpp"

class Pacman : BasePacmanEntity
{
public:
	//CTOR DTOR
	Pacman(std::pair<std::size_t, std::size_t> &position);

	//FUNC
	void move(Direction direction) final;

private:
	//FIELDS
	bool m_mouthOpen;

	//FUNC
	void changeSkin();
};


#endif //CPP_ARCADE_PACMAN_HPP
