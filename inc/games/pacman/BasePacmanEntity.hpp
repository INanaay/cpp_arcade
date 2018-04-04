/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/04 by lebovin
*/

#ifndef CPP_ARCADE_ABSTRACTPACMANENTITY_HPP
#define CPP_ARCADE_ABSTRACTPACMANENTITY_HPP


#include "../../core/Entity.hpp"

class BasePacmanEntity
{
public:
	//CTOR DTOR
	BasePacmanEntity() = default;
	BasePacmanEntity(std::pair<std::size_t, std::size_t> &position);
	~BasePacmanEntity() = default;

	//FUNC
	virtual void move(Direction direction);

	//PROPERTIES
	const Entity &getEntity() const;
protected:
	//FIELDS
	Entity m_entity;

	//FUNC
	bool tryMoveCell();
};


#endif //CPP_ARCADE_ABSTRACTPACMANENTITY_HPP
