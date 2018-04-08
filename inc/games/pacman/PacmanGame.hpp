/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/04 by lebovin
*/

#ifndef CPP_ARCADE_PACMANGAME_HPP
#define CPP_ARCADE_PACMANGAME_HPP

#include <ctime>
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
	void init(std::unique_ptr<IGlib> library) override;
	UserEvent run() override;
	UserEvent moveEntities();
	void stop() override;

	//PROPERTIES
	void setLib(std::unique_ptr<IGlib> ptr) override;
	std::unique_ptr<IGlib> getLib() override;
	size_t getScore();

private:
	//FIELDS
	Map m_map;
	Pacman m_player;
	std::size_t m_score;
	std::vector<Ghost> m_ghosts;
	std::unique_ptr<IGlib> m_library;
	std::vector<Entity> m_bonus;
	std::map<EntityType, Entity> m_assets;
	std::map<std::pair<std::size_t, std::size_t>, Entity> m_coins;
	bool m_canEatGhosts;
	std::clock_t timer;

	//FUNCS
	UserEvent moveAndInteract();
	void initCoins();
	void initAssets();
	void initEntities();
	void initBonus();
	bool checkEndGame();
	void changeGhostSrpite();
};


#endif //CPP_ARCADE_PACMANGAME_HPP
