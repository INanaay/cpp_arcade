//
// EPITECH PROJECT, 2018
// main
// File description:
// main
//

#include <dlfcn.h>
#include <iostream>
#include "../inc/Wrappers/NcursesWrapper.hpp"
#include "../inc/Core/Core.hpp"

int main(int argc, char **argv)
{
	argc = argc;
	Core Core(argv[1]);

	Core.start();
	return 0;
}
