/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/03 by lebovin
*/

#ifndef CORE_HPP
# define CORE_HPP

#include <memory>
#include <experimental/filesystem>
# include "IGlib.hpp"

namespace fs = std::experimental::filesystem;

class Core
{
public:
	Core(const std::string &libname);
	~Core() = default;

	void Start();
private:
	std::unique_ptr<IGlib> m_lib;
	std::vector<std::string> m_games;
	std::vector<std::string> m_libraries;

	void showMenu();
	void loadGraphicLibrary(const char *);

	void loadGames();
	void loadLibrairies();
	void loadScoreBoard();
};

#endif //CORE_HPP
