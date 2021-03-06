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
#include <random>
#include "../../core/Entity.hpp"

class Map
{
public:
	//CTOR DTOR
	Map() = default;
	~Map() = default;

	//PROPERTIES
	Entity &getEntityAt(std::pair<std::size_t, std::size_t> position);
	std::pair<std::size_t, std::size_t> getCenteredPosition() const;
	std::map<std::pair<std::size_t, std::size_t>, Entity> &getEntities();
	std::pair<std::size_t, std::size_t> getDimensions() const;

	//FUNCTIONS
	void loadFile(const std::string &path,
		      std::map<EntityType, Entity> &assets);
	std::pair<std::size_t, std::size_t> getFreePosition();

private:
	std::size_t m_width;
	std::size_t m_height;
	std::default_random_engine m_randomEngine;
	std::uniform_int_distribution<std::size_t> m_widthRandomRange;
	std::uniform_int_distribution<std::size_t> m_heightRandomRange;
	std::map<std::pair<std::size_t, std::size_t>, Entity> m_entities;

	void checkMap(const std::vector<std::string> &map);
};


#endif //CPP_ARCADE_MAP_HPP
