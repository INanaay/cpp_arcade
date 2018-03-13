/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/03 by lebovin
*/

#ifndef CPP_ARCADE_NCURSESWRAPPER_HPP
#define CPP_ARCADE_NCURSESWRAPPER_HPP

#include "IGlib.hpp"

class	NcursesWrapper : public IGlib
{
public:
	NcursesWrapper() = default;
	~NcursesWrapper() = default;
	virtual void	drawMenu();
    	virtual void initWindow() {};
    	virtual void destroyWindow() {};
private:
    	void getName();

};

#endif //CPP_ARCADE_NCURSESWRAPPER_HPP
