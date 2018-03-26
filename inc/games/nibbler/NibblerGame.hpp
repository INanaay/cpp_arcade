/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/03 by lebovin
*/

#ifndef CPP_ARCADE_NIBBLER_HPP
#define CPP_ARCADE_NIBBLER_HPP


#include "../../../inc/core/IGame.hpp"

class Nibbler : public IGame
{
public:
	virtual void Run() = 0;
	virtual void Stop() = 0;
	virtual void Init(std::unique_ptr<IGlib> library, Map &map) = 0;
private:
	Map m_map;

	void printMap();
};


#endif //CPP_ARCADE_NIBBLER_HPP
