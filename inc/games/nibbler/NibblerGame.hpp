/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/03 by lebovin
*/

#ifndef CPP_ARCADE_NIBBLER_HPP
#define CPP_ARCADE_NIBBLER_HPP


#include "../../core/IGame.hpp"

class NibblerGame : public IGame
{
public:
	NibblerGame();
	void Run();
	void Stop();
	void Init(std::unique_ptr<IGlib> library);
private:
	Map m_map;
	std::vector<Entity> m_snake;
	std::unique_ptr<IGlib> m_library;

	void loadMap(const std::string &path);
	void eventHandler(std::pair<UserEvent, char>);
};


#endif //CPP_ARCADE_NIBBLER_HPP
