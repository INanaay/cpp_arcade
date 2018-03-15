/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/03 by lebovin
*/

#include <memory>
#include <cstring>
#include <dlfcn.h>
#include <iostream>
#include <algorithm>
#include <experimental/filesystem>
#include <fstream>
#include "../../inc/Common/Core.hpp"
#include "../../inc/Common/UserEvent.hpp"

Core::Core(const std::string &libname)
{
	loadGames();
	loadLibrairies();
	loadScoreBoard();
	loadGraphicLibrary(libname.c_str());
}

void	Core::Start()
{
	m_lib->InitWindow();
	showMenu();
	m_lib->DestroyWindow();
}

static void	eventHandler(std::pair<UserEvent, char> event, MenuInformations &menu)
{
	if (event.first == UserEvent::ESCAPE)
		std::exit(0);
	else if (event.first == UserEvent::ENTER)
	{
		std::cout << "Enter : " <<  menu.name << std::endl;
	}
	else if (event.first == UserEvent::TEXT)
	{
		if (event.second == '\b' && menu.name.length() > 0)
			menu.name.erase(menu.name.length() - 1, 1);
		if (menu.name.length() < 3 && event.second != '\b')
			menu.name += event.second;
	}
}

void	Core::showMenu()
{
	std::pair<UserEvent, char>	event;
	MenuInformations menu = {"", "", ""};

	while (1)
	{
		m_lib->Clear();
		event = m_lib->getLastEvent();
		eventHandler(event, menu);
		m_lib->DrawMenu(menu);
		m_lib->Display();
	}
}

void	Core::loadGraphicLibrary(const char *nameLib)
{
	void	*handle = dlopen(nameLib, RTLD_LAZY);
	IGlib	*(*create)();

	if (!handle)
	{
		std::cerr << "Cannot open graphic library." << std::endl;
		std::exit(84);
	}
	create = (IGlib* (*)())dlsym(handle, "create_lib");
	if (!create)
	{
		std::cerr << "Graphic library is incompatible." << std::endl;
		std::exit(84);
	}
	m_lib = std::unique_ptr<IGlib>(create());
	std::vector<std::pair<std::string, float>> list;
}

void Core::loadGames()
{
	const std::string dir = "games";
	const std::string suffix = ".so";
	const std::string prefix = "/arcade_game_";
	fs::directory_iterator iterator(dir);

	for (auto &entry: iterator)
	{
		std::string path = entry.path();
		std::size_t n_idx = path.find(prefix);
		if (n_idx == std::string::npos)
			throw std::exception();

		std::string game = path.substr(n_idx + prefix.size());
		if (game.find(".so") != game.size() - suffix.size())
			continue;

		m_games.push_back(game);
	}

	if (m_games.empty())
		throw std::exception();
}

void Core::loadLibrairies()
{
	const std::string dir = "libs";
	const std::string suffix = ".so";
	const std::string prefix = "/arcade_lib_";
	fs::directory_iterator iterator(dir);

	for (auto &entry: iterator)
	{
		std::string path = entry.path();
		std::size_t n_idx = path.find(prefix);
		if (n_idx == std::string::npos)
			throw std::exception();

		std::string libname = path.substr(n_idx + prefix.size());
		if (libname.find(".so") != libname.size() - suffix.size())
			continue;

		m_libraries.push_back(libname);
	}

	if (m_libraries.empty())
		throw std::exception();
}

void Core::loadScoreBoard()
{
	const std::string dir = "scores";
	const std::string suffix = ".sco";
	const std::string prefix = "/arcade_score_";
	fs::directory_iterator iterator(dir);

	for (auto &entry: iterator)
	{
		std::string path = entry.path();
		std::size_t n_idx = path.find(prefix);
		if (n_idx == std::string::npos)
			throw std::exception();

		std::string game = path.substr(n_idx + prefix.size());
		deserializeScores(game, path);
	}
}

void Core::deserializeScores(const std::string &game, const std::string &path)
{
	const std::size_t nameLength = 3;
	std::ifstream fileStream(path);

	if (!fileStream)
		throw std::exception();

	std::vector<Score> list;
	if (m_scores.find(game) != m_scores.end())
		list = m_scores[game];

	while (!fileStream.eof())
	{
		std::size_t score;
		char player[nameLength + 1];

		fileStream.read(player, nameLength);
		player[nameLength] = 0;
		if (fileStream.eof())
			throw std::exception(); //corrupted
		fileStream.read((char *)&score, sizeof(std::size_t));
		m_scores[game].push_back({player, score});
	}
}

void Core::serializeScores(const std::string &game, std::vector<Score> &scores)
{
	const std::size_t nameLength = 3;
	const std::string dir = "scores/";
	const std::string filename = "arcade_score_" + game;
	std::ofstream fileStream(dir + filename);

	if (!fileStream)
		throw std::exception();

	std::vector<Score> list;
	if (m_scores.find(game) != m_scores.end())
		list = m_scores[game];

	scores = scores;
	while (!fileStream.eof())
	{
		std::size_t score;
		char player[nameLength + 1];

		fileStream.write(player, nameLength);
		player[nameLength] = 0;
		if (fileStream.eof())
			throw std::exception(); //corrupted
		fileStream.write((char *)&score, sizeof(std::size_t));
	}
}
