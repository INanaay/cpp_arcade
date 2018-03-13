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


std::string NcursesWrapper::getPlayerName()
{
	std::string name;
	std::string enterName = "Enter Name";
	int ch;

	initscr();
	keypad(stdscr, TRUE);
	noecho();
	mvwprintw(stdscr, 10, 10, enterName.c_str());
	move(20, 10);
	for (int i = 0; i <= 2; i++) {
		move(20, 10 + i);
		ch = getch();
		name += ch;
		mvwprintw(stdscr, 20, 10, name.c_str());
		refresh();
	}
	clear();
	return name;
}

void	NcursesWrapper::drawMenu()
{
	int ch;
	std::string name = getPlayerName();
	curs_set(0);
	nodelay(stdscr, TRUE);
	while (1) {
		ch = getch();
		box(stdscr, ACS_VLINE, ACS_HLINE);
		mvwprintw(stdscr, 20, 10, name.c_str());
		if (ch == 27)
			break;
		refresh();
	}
	endwin();
}
