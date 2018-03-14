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
	argc = argc;
	Core Core(argv[1]);

	Core.Start();
	return 0;
}
