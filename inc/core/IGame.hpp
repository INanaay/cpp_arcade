/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/03 by lebovin
*/

#ifndef CPP_ARCADE_IGAME_HPP
#define CPP_ARCADE_IGAME_HPP

#include <memory>
#include "IGlib.hpp"

class IGame
{
public:
	~IGame() = default;
	virtual UserEvent run() = 0;
	virtual void stop() = 0;
	virtual void init(std::unique_ptr<IGlib> library) = 0;
	virtual std::unique_ptr<IGlib> getLib() = 0;
	virtual void setLib(std::unique_ptr<IGlib>) = 0;
};

#endif //CPP_ARCADE_IGAME_HPP
