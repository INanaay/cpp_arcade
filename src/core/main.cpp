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

	try
	{
		Core Core(lib);
		Core.Start();
	}
	catch (std::exception ex)
	{
		std::cout << "wow, such an amazing error" << std::endl;
		std::cout << ex.what() << std::endl;
		return 84;
	}
	return 0;
}
