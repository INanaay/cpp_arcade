/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/03 by lebovin
*/

#ifndef CPP_ARCADE_NIBBLER_HPP
#define CPP_ARCADE_NIBBLER_HPP


#include "../../core/IGame.hpp"
#include "../../core/EntityType.hpp"

class NibblerGame : public IGame
{
public:
	NibblerGame();
	UserEvent Run();
	void Stop();
	void Init(std::unique_ptr<IGlib> library);
	std::unique_ptr<IGlib> getLib();
	void setLib(std::unique_ptr<IGlib>);
private:
	Entity m_apple;
	int m_appleState;
	int m_appleIndex;
	std::vector<Entity> m_map;
	std::vector<Entity> m_snake;
	std::unique_ptr<IGlib> m_library;
	std::map<EntityType, Entity> m_assets;

	void loadMap(const std::string &path);
	void moveSnake();
	void eventHandler(std::pair<UserEvent, char>);
	bool isGameFinished();
	void chooseNextDir(Entity &, std::size_t);
	void popApple();
};


#endif //CPP_ARCADE_NIBBLER_HPP
