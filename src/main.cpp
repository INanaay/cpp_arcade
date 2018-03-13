/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/03 by lebovin
*/

#include <iostream>
#include <dlfcn.h>
#include "./Glib/ncurses/NcursesWrapper.hpp"

int main(int ac, char **av)
{
	void *handle = dlopen(av[1], RTLD_LAZY);
	if (!handle) {
		std::cout << "error" << std::endl;
		return 84;
	}
	typedef IGlib* create_t();

	create_t* creat=(create_t*)dlsym(handle,"create");

	if (!creat)
	{
		std::cout << "no creat" << std::endl;
		return 84;
	}
	IGlib *uuu = creat();
	uuu->drawMenu();
	delete uuu;
	return 0;
}
