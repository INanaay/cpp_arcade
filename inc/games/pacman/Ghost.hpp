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
#include "../common/Map.hpp"

class Ghost : public BasePacmanEntity
{
public:
	//CTOR DTOR
	explicit Ghost(std::pair<std::size_t, std::size_t> &position);

	bool tryMove(Map &map, Direction dir) final;
	Direction checkDir(Map);
	void changeSprite(std::string file);
private:
	Direction goNext(std::vector<Direction>);
	Direction goRandom(std::vector<Direction>);

};

#endif //CPP_ARCADE_GHOST_HPP
