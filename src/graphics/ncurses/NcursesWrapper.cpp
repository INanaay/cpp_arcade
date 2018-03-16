/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/03 by lebovin
*/

#include <ncurses.h>
#include <iostream>
#include "../../../inc/graphics/NcursesWrapper.hpp"

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
		refresh(); }
	clear();
	return name;
}

void NcursesWrapper::InitWindow()
{
	initscr();
	curs_set(0);
	noecho();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	scores = subwin(stdscr, LINES - 2, COLS / 2, 1, COLS / 2 - 1);
}

void NcursesWrapper::DestroyWindow()
{
	endwin();
}

void NcursesWrapper::Clear()
{
}

void NcursesWrapper::Display()
{
	refresh();
}

std::pair<UserEvent, char> NcursesWrapper::getLastEvent()
{
	std::pair<UserEvent, char> lastEvent = std::make_pair<UserEvent, char>(UserEvent::NONE, 0);
	int ch = getch();

	if (ch == 27)
		lastEvent.first =  UserEvent::ESCAPE;
	else if (ch == KEY_PPAGE)
		lastEvent.first =  UserEvent::LIB_NEXT;
	else if (ch == KEY_NPAGE)
		lastEvent.first = UserEvent::LIB_PREV;
	else if (ch == KEY_UP)
		lastEvent.first =  UserEvent::UP;
	else if (ch == KEY_DOWN)
		lastEvent.first =  UserEvent::DOWN;
	else if (ch == '\n')
		lastEvent.first =  UserEvent::ENTER;
	else if (ch == 127 ||  ch == KEY_DC|| ch == KEY_BACKSPACE) {
		clear();
		lastEvent.first = UserEvent::TEXT;
		lastEvent.second = '\b';
	}
	else if (isalnum(ch)) {
		lastEvent.first = UserEvent::TEXT;
		lastEvent.second = ch;
	}
	else
		lastEvent.first = UserEvent::NONE;
	return lastEvent;
}



void	NcursesWrapper::DrawMenu(MenuInformations menu, CoreInformations core)
{
	menu = menu;
	core = core;
	//std::string name = "Player Name :"  + getPlayerName();

	box(stdscr, ACS_VLINE, ACS_HLINE);
	box(scores, ACS_VLINE, ACS_HLINE);
	mvwprintw(stdscr, 5, 5, menu.name.c_str());
	mvwprintw(stdscr, 10, 5, "Choose Game :");
	mvwprintw(stdscr, 15, 5, "Choose Library :");
	mvwprintw(scores, 1, 1, "High Scores");


}
