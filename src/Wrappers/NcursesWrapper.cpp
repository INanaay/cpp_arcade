/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/03 by lebovin
*/

#include <ncurses.h>
#include <iostream>
#include "../../inc/Wrappers/NcursesWrapper.hpp"

extern "C" NcursesWrapper *create_lib()
{
	return new NcursesWrapper();
}


std::string NcursesWrapper::getPlayerName()
{
	std::string name;
	std::string enterName = "Enter Name";
	int ch;

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

void NcursesWrapper::InitWindow()
{
	initscr();
}

void NcursesWrapper::Clear()
{
	clear();
}

void NcursesWrapper::Display() {}


std::pair<UserEvent, char> NcursesWrapper::getLastEvent()
{
/*	int ch = getch();

	if (ch == 27)
		return UserEvent::ESCAPE;
	if (ch == KEY_PPAGE)
		return UserEvent::LIB_NEXT;
	if (ch == KEY_NPAGE)
		return UserEvent::LIB_PREV;
	if (ch == KEY_UP)
		return UserEvent::UP;
	if (ch == KEY_DOWN)
		return UserEvent::DOWN;
	if (ch == KEY_ENTER)
		return UserEvent::ENTER;
	return UserEvent::NONE;*/
	return std::make_pair<UserEvent, char>(UserEvent::NONE, 0);
}

void	NcursesWrapper::DrawMenu(MenuInformations menu)
{
	menu = menu;
	std::string name = "Player Name :"  + getPlayerName();

	curs_set(0);
	nodelay(stdscr, TRUE);
	scores = subwin(stdscr, LINES - 2,  COLS / 2, 1, COLS / 2 - 1);
	box(stdscr, ACS_VLINE, ACS_HLINE);
	box(scores, ACS_VLINE, ACS_HLINE);
	mvwprintw(stdscr, 5, 5, name.c_str());
	mvwprintw(stdscr, 10, 5, "Choose Game :");
	mvwprintw(stdscr, 15, 5, "Choose Library :");
	mvwprintw(scores, 1, 1, "High Scores");

	}
