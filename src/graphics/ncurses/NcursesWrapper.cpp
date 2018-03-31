/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/03 by lebovin
*/

#include <ncurses.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <unistd.h>
#include "../../../inc/graphics/NcursesWrapper.hpp"


extern "C" NcursesWrapper *create_lib()
{
	return new NcursesWrapper();
}

void NcursesWrapper::InitWindow()
{
	initscr();
	curs_set(0);
	noecho();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	scoresWindow = subwin(stdscr, LINES - 2, COLS / 2, 1, COLS / 2 - 1);
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

	if (ch == 27) {
		lastEvent.first = UserEvent::ESCAPE;
	}
	else if (ch == KEY_PPAGE)
		lastEvent.first =  UserEvent::LIB_NEXT;
	else if (ch == KEY_NPAGE)
		lastEvent.first = UserEvent::LIB_PREV;
	else if (ch == KEY_UP)
		lastEvent.first = UserEvent::UP;
	else if (ch == KEY_LEFT)
		lastEvent.first = UserEvent::LEFT;
	else if (ch == KEY_RIGHT)
		lastEvent.first = UserEvent::RIGHT;
	else if (ch == KEY_DOWN)
		lastEvent.first = UserEvent::DOWN;
	else if (ch == '\n') {
		lastEvent.first = UserEvent::ENTER;
		clear();
	}
	else if (ch == 127 ||  ch == KEY_DC|| ch == KEY_BACKSPACE) {
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
	std::string name = "Player Name : "  + menu.name;
	std::string libName = "Library : Ncurses";
	std::string game = "Choose Game : " + menu.game.first;

	clear();
	box(stdscr, ACS_VLINE, ACS_HLINE);
	box(scoresWindow, ACS_VLINE, ACS_HLINE);
	mvwprintw(stdscr, 5, 5, name.c_str());
	mvwprintw(stdscr, 10, 5, game.c_str());
	mvwprintw(stdscr, 15, 5, libName.c_str());
	mvwprintw(scoresWindow, 1, 1, "High Scores");
	DrawScores(core.scores, menu.game.first);
}

void NcursesWrapper::DrawMap(std::vector<Entity> &map)
{
	for (auto &entity: map)
		DrawEntity(entity);
}

void NcursesWrapper::DrawEntity(Entity &entity)
{
	int x, y;
	char toDraw;
		std::ofstream fileStream("Debug", std::ios::in);



	x = entity.getPosition().first;
	y = entity.getPosition().second;

	x /= 29;
	y /= 29;
	toDraw = entity.getAscii();
	mvwaddch(stdscr, y, x, toDraw);
	usleep(200);
}

/* This function is temporary */

bool test(std::pair<std::string, uint> i,  std::pair<std::string, uint> j)
{
	return i.second > j.second;
}

void NcursesWrapper::DrawScores(std::map<std::string, std::vector<Score>> scores, std::string game) {

	if (!(scores.find(game) == scores.end())) {
		{
			auto vector = scores[game];
			std::sort(vector.begin(), vector.end(), test);
			int y = 3;
			for (unsigned int i = 0; i < vector.size(); i++) {
				mvwprintw(scoresWindow, y, 1, vector[i].first.c_str());
				mvwprintw(scoresWindow, y, 10, std::to_string(vector[i].second).c_str());
				y++;
			}
		}
	}
}
