/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/03 by lebovin
*/

#include <dlfcn.h>
#include <iostream>
#include "Core.hpp"

Core::Core(const char *nameLib)
{
	loadLib(nameLib);
}

void	Core::start()
{
	m_lib->initWindow();
	m_lib->drawMenu();
	m_lib->destroyWindow();
}

void	Core::loadLib(const char *nameLib)
{
	void	*handle = dlopen(nameLib, RTLD_LAZY);
	IGlib	*(*create)();

	if (!handle) {
		std::cerr << "Error, failed to open graphic library." << std::endl;
		std::exit(84);
	}
	create = (IGlib* (*)())dlsym(handle, "create_lib");
	if (!create) {
		std::cerr << "Error, failed to retreive functins." << std::endl;
		std::exit(84);
	}
	m_lib = create();
}
