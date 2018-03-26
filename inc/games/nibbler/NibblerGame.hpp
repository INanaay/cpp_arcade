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
	void Run();
	void Stop();
	void Init(std::unique_ptr<IGlib> library, Map &map);
private:
	Map m_map;
	std::vector<Entity> m_snake;
	std::unique_ptr<IGlib> m_library;

	void drawSnake(std::vector<Entity> &snake);
};


#endif //CPP_ARCADE_NIBBLER_HPP
