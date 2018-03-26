//
// EPITECH PROJECT, 2018
// main
// File description:
// main
//

#include <dlfcn.h>
#include <iostream>
#include "../../inc/core/Core.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Wrong number of args !" << std::endl;
		return 84;
	}
	std::string lib = argv[1];

	if (lib.size() > 1 && lib[0] == '.' && lib[1] == '/')
		lib = lib.substr(2);
	Core Core(lib);

	Core.Start();
	return 0;
}
