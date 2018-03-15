/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/03 by lebovin
*/

#ifndef INFORMATIONS_HPP
# define INFORMATIONS_HPP

#include <vector>
#include <map>
#include <string>

using Score = std::pair<std::string, uint>;
using Map = std::vector<std::string>;

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

#endif //INFORMATION _HPP
