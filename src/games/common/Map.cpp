/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/04 by lebovin
*/

#include <map>
#include <fstream>
#include "../../../inc/games/common/Map.hpp"
#include "../../../inc/core/GameException.hpp"

void Map::loadFile(const std::string &path,
		   std::map<EntityType, Entity> &assets)
{
	std::string line;
	std::ifstream fstream(path);
	std::vector<std::string> buffer;

	if (!fstream)
		throw GameException("Cannot load given map.");
	while (std::getline(fstream, line))
		buffer.push_back(line);
	checkMap(buffer);
	for (std::size_t y = 0; y < buffer.size(); y++)
	{
		line = buffer[y];
		for (std::size_t x = 0; x < line.size(); x++)
		{
			auto type = (EntityType) (line[x] - '0');
			if (assets.find(type) == assets.end())
				throw GameException("Malformated map.");
			auto entity = assets[type];
			entity.cellPosition.first = x;
			entity.cellPosition.second = y;
			entity.screenPosition.first = x * 30;
			entity.screenPosition.second = y * 30;
			m_entities[entity.cellPosition] = entity;
		}
	}
	m_width = line.size();
	m_height = buffer.size();
}

void Map::checkMap(const std::vector<std::string> &map)
{
	if (map.empty())
		throw GameException("Map is empty.");

	auto baseSize = map[0].size();

	for (const auto &row: map)
		if (row.size() != baseSize)
			throw GameException("Map must have the same row size");
}

Entity &Map::getEntityAt(std::pair<uint, uint> &position)
{
	if (m_entities.find(position) == m_entities.end())
		throw GameException("Out of map limits.");
	return (m_entities[position]);
}

std::pair<std::size_t, std::size_t> &Map::getCenteredPosition() const
{
	auto pos = std::pair<std::size_t, std::size_t>(m_width / 2,
						       m_height/ 2);
	return (pos);
}

std::map<std::pair<std::size_t, std::size_t>, Entity> &Map::getEntities()
{
	return m_entities;
}
