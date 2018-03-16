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


class IGlib {
public:
	virtual ~IGlib() = default;

	virtual void InitWindow() = 0;
	virtual void DestroyWindow() = 0;
	virtual void DrawMenu(MenuInformations, CoreInformations) = 0;
	virtual void Clear() = 0;
	virtual void Display() = 0;

	virtual std::pair<UserEvent, char> getLastEvent() = 0;
};

#endif //CPP_ARCADE_IGLIB_HPP
