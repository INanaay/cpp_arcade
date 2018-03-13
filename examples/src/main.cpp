//
// EPITECH PROJECT, 2018
// main
// File description:
// main
//

#include <dlfcn.h>
#include <iostream>
#include "./Glib/NcursesWrapper.hpp"
#include "./Core.hpp"

int main(int argc, char **argv)
{
	Core Core(argv[1]);

	Core.start();
	return 0;
}
