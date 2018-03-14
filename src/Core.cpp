/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/03 by lebovin
*/

#include <dlfcn.h>
#include <iostream>
#include "Core.hpp"
#include <dirent.h>

Core::Core(const char *nameLib)
{
	LoadGraphicLibrary(nameLib);
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

void	Core::LoadGraphicLibrary(const char *nameLib)
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

bool Core::endsWith(const std::string &str, const std::string &suffix) const
{
	return str.size() >= suffix.size() &&
	       str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}

void Core::createLibsTab()
{
	DIR *dpdf;
	struct dirent *epdf;
	std::string toAdd;

	dpdf = opendir("lib");
	if (dpdf == NULL)
		throw std::exception_ptr();
	while ((epdf = readdir(dpdf)))
	{
		toAdd = epdf->d_name;
		if (endsWith(epdf->d_name, ".so")) {
			m_libsTab.push_back(toAdd);
		}

	}
	closedir(dpdf);
}

const std::vector<std::string> &Core::getM_libsTab() const {
	return m_libsTab;
}

void Core::setM_libsTab(const std::vector<std::string> &m_libsTab) {
	Core::m_libsTab = m_libsTab;
}

const std::vector<std::string> &Core::getM_gamesTab() const {
	return m_gamesTab;
}

void Core::setM_gamesTab(const std::vector<std::string> &m_gamesTab) {
	Core::m_gamesTab = m_gamesTab;
}
