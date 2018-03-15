/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/03 by lebovin
*/

#include <memory>
#include <dlfcn.h>
#include <iostream>
#include <algorithm>
#include <experimental/filesystem>
#include "../../inc/Common/Core.hpp"
#include "../../inc/Common/UserEvent.hpp"

Core::Core(const std::string &libname)
{
	loadGames();
	loadLibrairies();
	loadScoreBoard();
	loadGraphicLibrary(libname.c_str());
}

void	Core::Start()
{
	//init games and libs avaible
	//init scores
	m_lib->InitWindow();
	showMenu();
	m_lib->DestroyWindow();
}

static void	eventHandler(std::pair<UserEvent, char> event, MenuInformations &menu)
{
	if (event.first == UserEvent::ESCAPE)
		std::exit(0);
	else if (event.first == UserEvent::ENTER)
	{
		std::cout << "Enter : " <<  menu.name << std::endl;
	}
	else if (event.first == UserEvent::TEXT)
	{
		if (event.second == '\b' && menu.name.length() > 0)
			menu.name.erase(menu.name.length() - 1, 1);
		if (menu.name.length() < 3 && event.second != '\b')
			menu.name += event.second;
	}
}

void	Core::showMenu()
{
	std::pair<UserEvent, char>	event;
	MenuInformations menu = {"", "", ""};

	while (1)
	{
		m_lib->Clear();
		event = m_lib->getLastEvent();
		eventHandler(event, menu);
		m_lib->DrawMenu(menu);
		m_lib->Display();
	}
}

void	Core::loadGraphicLibrary(const char *nameLib)
{
	void	*handle = dlopen(nameLib, RTLD_LAZY);
	IGlib	*(*create)();

	if (!handle)
	{
		std::cerr << "Cannot open graphic library." << std::endl;
		std::exit(84);
	}
	create = (IGlib* (*)())dlsym(handle, "create_lib");
	if (!create)
	{
		std::cerr << "Graphic librairy is incompatible." << std::endl;
		std::exit(84);
	}
	m_lib = std::unique_ptr<IGlib>(create());
	std::vector<std::pair<std::string, float>> list;
}

void Core::loadGames()
{
	/*fs::directory_iterator iterator("games");

	for (auto &entry: iterator)
	{
		std::cout << entry << std::endl;
	}*/
}

void Core::loadLibrairies()
{

}

void Core::loadScoreBoard()
{

}
