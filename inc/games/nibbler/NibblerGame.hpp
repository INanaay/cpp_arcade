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
	std::vector<Entity> m_map;
	std::vector<Entity> m_snake;
	std::vector<Entity> m_apples;
	std::unique_ptr<IGlib> m_library;
	std::map<EntityType, Entity> m_assets;

	void loadMap(const std::string &path);
	void eventHandler(std::pair<UserEvent, char>);
	bool isGameFinished();
};


#endif //CPP_ARCADE_NIBBLER_HPP
