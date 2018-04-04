/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/04 by lebovin
*/

#include "../../../inc/games/pacman/PacmanGame.hpp"

UserEvent PacmanGame::Run()
{
	auto &mapEntities = m_map.getEntities();
	for (const auto &entry: mapEntities)
		m_library->DrawEntity(entry.second);

	return UserEvent ::NONE;
}

void PacmanGame::Stop()
{

}

void PacmanGame::Init(std::unique_ptr<IGlib> library)
{
	setLib(std::move(library));
	m_map.loadFile("resources/pacman/map.test", m_assets);
}

std::unique_ptr<IGlib> PacmanGame::getLib()
{
	return (std::move(m_library));
}

void PacmanGame::setLib(std::unique_ptr<IGlib> ptr)
{
	m_library = std::move(ptr);
}

void PacmanGame::initAssets()
{
	Entity wallEntity;
	wallEntity.type = EntityType ::WALL;
	wallEntity.ascii = 'X';
	wallEntity.sprite = "resources/pacman/wall.png";
	wallEntity.direction = Direction ::TOP;
}
