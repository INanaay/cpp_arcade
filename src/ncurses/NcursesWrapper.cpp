/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/03 by lebovin
*/

#include <ncurses.h>
#include "NcursesWrapper.hpp"

void arcade::NcursesWrapper::initWindow(arcade::Point<std::size_t> size,
					std::string name)
{
	initscr();
}

std::string arcade::NcursesWrapper::showMenu(std::vector<std::string> gfxName,
					     std::vector<std::string> gameName)
{

}
std::string arcade::NcursesWrapper::getPlayerName()
{
	return nullptr;
}
void arcade::NcursesWrapper::setTraductor(const std::map<unsigned char,
	arcade::Traductor> &traductors)
{
	m_traductors = traductors;
}
void arcade::NcursesWrapper::drawEntity(std::vector<arcade::AEntity> &sprite)
{

}
void arcade::NcursesWrapper::drawMap(
	const std::vector<std::vector<unsigned char>> &map)
{

}
arcade::IGfxManager::Keys arcade::NcursesWrapper::getEvent()
{
	return Keys::ACTION;
}
