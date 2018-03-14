/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/03 by lebovin
*/

#ifndef CORE_HPP
# define CORE_HPP

#include <memory>
# include "./Glib/IGlib.hpp"

class Core
{
public:
	Core(const std::string &libname);
	~Core() = default;
private:
	std::unique_ptr<IGlib> m_lib;
	std::vector<std::string> m_games;
	std::vector<std::string> m_librairies;

	void start();
	void showMenu();
	void loadGraphicLibrary(const char *);
};

#endif //CORE_HPP
