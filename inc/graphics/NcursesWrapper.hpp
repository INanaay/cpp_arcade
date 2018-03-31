/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/03 by lebovin
*/

#ifndef CPP_ARCADE_NCURSESWRAPPER_HPP
#define CPP_ARCADE_NCURSESWRAPPER_HPP

#include <curses.h>
#include "../core/IGlib.hpp"

class NcursesWrapper : public IGlib
{
public:
	NcursesWrapper() = default;
	~NcursesWrapper() = default;
	void DrawMenu(MenuInformations, CoreInformations);
	void InitWindow();
  void DestroyWindow();
	void Clear();
	void Display();
	std::pair<UserEvent, char> getLastEvent();
	void DrawMap(std::vector<Entity> &entities);
	void DrawEntity(Entity &) {};
private:
    	std::string getPlayerName();
    	WINDOW *scores;

};

#endif //CPP_ARCADE_NCURSESWRAPPER_HPP
