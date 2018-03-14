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

void	Core::showMenu()
{
	UserEvent	event;
	char	c;
	std::string	name = "";

	while (1)
	{
		c = 0;
		event = UserEvent::NONE;
		m_lib->Clear();
		event = m_lib->getLastEvent();
		c = m_lib->getCharacter();
		m_lib->DrawMenu();
		printf("%d %d\n", c, event);
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
	fs::directory_iterator iterator("games");

	for (auto &entry: iterator)
	{
		std::cout << entry << std::endl;
	}
}

void Core::loadLibrairies()
{

}

void Core::loadScoreBoard()
{

}
