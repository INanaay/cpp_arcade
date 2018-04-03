/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/04 by lebovin
*/

#ifndef CPP_ARCADE_MAP_HPP
#define CPP_ARCADE_MAP_HPP

#include <map>
#include <string>
#include <vector>
#include "../../core/Entity.hpp"

class Map
{
public:
	//CTOR DTOR
	Map() = default;
	~Map() = default;

	//PROPERTIES
	Entity &getEntityAt(std::pair<uint, uint> &position);

	//FUNCTIONS
	void loadFile(const std::string &path,
		      std::map<EntityType, Entity> &assets);

private:
	std::size_t m_width;
	std::size_t m_height;
	std::map<std::pair<uint, uint>, Entity> m_entities;

	void checkMap(const std::vector<std::string> &map);
};


#endif //CPP_ARCADE_MAP_HPP