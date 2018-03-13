/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/03 by lebovin
*/

#include <ncurses.h>
#include <iostream>
#include "NcursesWrapper.hpp"

extern "C" NcursesWrapper *create_lib()
{
	return new NcursesWrapper;
}

void	NcursesWrapper::drawMenu()
{
	initscr();
	printw("show menu !");
	refresh();
	getch();
	endwin();
}
