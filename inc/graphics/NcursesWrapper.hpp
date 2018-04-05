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
	void drawMenu(MenuInformations, CoreInformations);
	void initWindow();
  void destroyWindow();
	void clear();
	void display();
	std::pair<UserEvent, char> getLastEvent();
	void drawMap(std::vector<Entity> &entities);
	void drawEntity(const Entity &);
private:
    	std::string getPlayerName();
    	WINDOW *scoresWindow;
	void drawScores(std::map<std::string, std::vector<Score>>, std::string);

};

#endif //CPP_ARCADE_NCURSESWRAPPER_HPP
