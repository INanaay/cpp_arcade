/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/04 by lebovin
*/

#ifndef CPP_ARCADE_PACMANGAME_HPP
#define CPP_ARCADE_PACMANGAME_HPP

#include "../../core/IGame.hpp"
#include "Pacman.hpp"
#include "Ghost.hpp"
#include "../common/Map.hpp"

class PacmanGame : public IGame
{
public:
	//CTOR
	PacmanGame() = default;

	//FUNCS
	void initEntities();
	void init(std::unique_ptr<IGlib> library) override;
	UserEvent run() override;
	void stop() override;

	//PROPERTIES
	void setLib(std::unique_ptr<IGlib> ptr) override;
	std::unique_ptr<IGlib> getLib() override;
	size_t getScore();

private:
	//FIELDS
	Map m_map;
	Pacman m_player;
	std::vector<Ghost> m_ghosts;
	std::unique_ptr<IGlib> m_library;
	std::map<EntityType, Entity> m_assets;

	//FUNCS
	void initAssets();
};


#endif //CPP_ARCADE_PACMANGAME_HPP
