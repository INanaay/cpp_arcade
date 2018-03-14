/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/03 by lebovin
*/

#ifndef CPP_ARCADE_NCURSESWRAPPER_HPP
#define CPP_ARCADE_NCURSESWRAPPER_HPP

#include "../Core/IGlib.hpp"
#include <curses.h>

class	NcursesWrapper : public IGlib
{
public:
	NcursesWrapper() = default;
	~NcursesWrapper() = default;
	virtual void drawMenu();
    	virtual void initWindow();
    	virtual void destroyWindow() {};
	virtual void clear();
	virtual void display();
	virtual UserEvent getLastEvent();
	virtual char getCharacter() {return 'a';};
private:
    	std::string getPlayerName();
    	void showScores();
    	WINDOW *scores;

};

#endif //CPP_ARCADE_NCURSESWRAPPER_HPP
