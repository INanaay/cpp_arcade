/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/03 by lebovin
*/

#include <memory>
#include <dlfcn.h>
#include <iostream>
#include <dirent.h>
#include "Core.hpp"

Core::Core(const std::string &libname)
{
	loadGraphicLibrary(libname.c_str());
}

void	Core::start()
{
	createLibsTab();
	m_lib->initWindow();
	showMenu();
	m_lib->destroyWindow();
}

void	Core::showMenu()
{
	UserEvent	event;
	char	c;
	std::string	name = "";

	while (1)
	{
		c = 0;
		event = NONE;
		m_lib->clear();
		event = m_lib->getLastEvent();
		c = m_lib->getCharacter();
		m_lib->drawMenu();
		printf("%d %d\n", c, event);
		m_lib->display();
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
	m_lib = std::make_unique<IGlib>(create());
}