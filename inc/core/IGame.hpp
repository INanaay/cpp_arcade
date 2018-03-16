/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/03 by lebovin
*/

#ifndef CPP_ARCADE_IGAME_HPP
#define CPP_ARCADE_IGAME_HPP

#include <bits/unique_ptr.h>
#include "IGlib.hpp"
#include "Core.hpp"

class IGame
{
public:
	~IGame() = default;
	virtual void Run() = 0;
	virtual void Stop() = 0;
	virtual void Init(std::unique_ptr<IGlib> library, Map &map) = 0;
};

#endif //CPP_ARCADE_IGAME_HPP
