//
// EPITECH PROJECT, 2018
// main
// File description:
// main
//

#include <dlfcn.h>
#include <iostream>
#include "../inc/Common/Core.hpp"
#include "../inc/Wrappers/NcursesWrapper.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Wrong number of args !" << std::endl;
		return 84;
	}
	Core Core(argv[1]);

	Core.Start();
	return 0;
}
