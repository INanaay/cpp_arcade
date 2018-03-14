/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/03 by lebovin
*/

#ifndef CPP_ARCADE_NCURSESWRAPPER_HPP
#define CPP_ARCADE_NCURSESWRAPPER_HPP

#include "../Common/IGlib.hpp"
#include <curses.h>

class NcursesWrapper : public IGlib
{
public:
	NcursesWrapper() = default;
	~NcursesWrapper() = default;
	virtual void DrawMenu();
    	virtual void InitWindow();
    	virtual void DestroyWindow() {};
	virtual void Clear();
	virtual void Display();
	virtual UserEvent getLastEvent();
	virtual char getCharacter() {return 'a';};
private:
    	std::string getPlayerName();
    	WINDOW *scores;

};

#endif //CPP_ARCADE_NCURSESWRAPPER_HPP
