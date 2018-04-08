/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/04 by lebovin
*/

#ifndef CPP_ARCADE_ABSTRACTPACMANENTITY_HPP
#define CPP_ARCADE_ABSTRACTPACMANENTITY_HPP


#include "../../core/Entity.hpp"
#include "../common/Map.hpp"

class BasePacmanEntity
{
public:
	//CTOR DTOR
	BasePacmanEntity() = default;
	BasePacmanEntity(std::pair<std::size_t, std::size_t> &position);
	~BasePacmanEntity() = default;

	//FUNC
	virtual bool tryMove(Map &map);

	//PROPERTIES
	const Entity &getEntity() const;

	Direction nextDirection;
protected:
	//FIELDS
	Entity m_entity;
	std::size_t m_speed;
};


#endif //CPP_ARCADE_ABSTRACTPACMANENTITY_HPP
