/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/03 by lebovin
*/

#ifndef CORE_HPP
# define CORE_HPP

#include <memory>
# include "IGlib.hpp"

using Map = std::vector<std::string>
using Score = std::pair<std::string, uint>>

struct CoreInformations
{
	std::vector<std::string> games;
	std::vector<std::string> libraries;
	std::map<std::string, std::vector<Score>> scores;
};

struct MenuInformations
{
	std::string name;
	std::string game;
	std::string library;
};

class Core
{
public:
	Core(const std::string &libname);
	~Core() = default;
private:
	std::unique_ptr<IGlib> m_lib;
	std::vector<std::string> m_games;
	std::vector<std::string> m_libraries;

	void start();
	void showMenu();
	void loadGraphicLibrary(const char *);
};

#endif //CORE_HPP
