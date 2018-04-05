/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/03 by JOJO
*/

#ifndef CPP_ARCADE_IGLIB_HPP
# define CPP_ARCADE_IGLIB_HPP

# include "Informations.hpp"
# include "UserEvent.hpp"
#include "Entity.hpp"


class IGlib {
public:
	virtual ~IGlib() = default;

	virtual void clearWindow() = 0;
	virtual void display() = 0;
	virtual void initWindow() = 0;
	virtual void destroyWindow() = 0;
	virtual void drawEntity(const Entity &entity) = 0;
	virtual void drawMap(std::vector<Entity> &map) = 0;
	virtual void drawMenu(MenuInformations, CoreInformations) = 0;
	virtual void drawScore(size_t, int posx, int posy) = 0;

	virtual std::pair<UserEvent, char> getLastEvent() = 0;
};

#endif //CPP_ARCADE_IGLIB_HPP
