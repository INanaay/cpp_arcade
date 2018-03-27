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
	virtual UserEvent Run() = 0;
	virtual void Stop() = 0;
	virtual void Init(std::unique_ptr<IGlib> library) = 0;
	virtual std::unique_ptr<IGlib> getLib() = 0;
	virtual void setLib(std::unique_ptr<IGlib>) = 0;
};

#endif //CPP_ARCADE_IGAME_HPP
