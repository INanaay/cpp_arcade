/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/03 by lebovin
*/

#include <memory>
#include <utility>
#include <cstring>
#include <dlfcn.h>
#include <iostream>
#include <algorithm>
#include <experimental/filesystem>
#include <fstream>
#include "../../inc/Common/Core.hpp"
#include "../../inc/Common/UserEvent.hpp"
#include "../../inc/Common/CoreException.hpp"

Core::Core(const std::string &libname)
{
	loadGames();
	loadLibrairies();
	loadScoreBoard();
	loadGraphicLibrary(libname.c_str());
	m_pathLib = libname;
}

void	Core::Start()
{
	m_lib->InitWindow();
	showMenu();
}

static std::string	incLibs(CoreInformations core, std::string toFind)
{
		auto it = std::find(core.games.begin(), core.games.end(), toFind);
		if (it == core.games.end())
		{
			std::cerr << "error in change games" << std::endl;
			std::exit(84);
		}	
		int index = it - core.games.begin();
		if (index < (int)core.games.size() - 1)
			return core.games[index + 1];
		else
			return core.games[0];
}

static std::string	decLibs(CoreInformations core, std::string toFind)
{
		auto it = std::find(core.games.begin(), core.games.end(), toFind);
		if (it == core.games.end())
		{
			std::cerr << "error in change games" << std::endl;
			std::exit(84);
		}	
		int index = it - core.games.begin();
		if (index > 0)
			return core.games[index - 1];
		else
			return core.games[core.games.size() - 1];
}

void	Core::loadNextLib()
{
	m_lib->DestroyWindow();
	std::cout << m_pathLib << std::endl;
	auto it = std::find(m_libraries.begin(), m_libraries.end(), m_pathLib.substr(17));
		if (it == m_libraries.end())
		{
			std::cerr << "error in change Glib" << std::endl;
			std::exit(84);
		}	
		int index = it - m_libraries.begin();
		dlclose(m_handle);
		std::cout << "oui1" << std::endl;
		if (index > 0) {
			loadGraphicLibrary(("./lib/lib_arcade_" + m_libraries[index - 1]).c_str());
		m_pathLib = "./lib/lib_arcade_" + m_libraries[index - 1];
		}
		else {
			loadGraphicLibrary(("./lib/lib_arcade_" + m_libraries[m_libraries.size() - 1]).c_str());
		m_pathLib = "./lib/lib_arcade_" + m_libraries[m_libraries.size() - 1];
		}
		std::cout << m_pathLib << std::endl;
		m_lib->InitWindow();
		std::cout << "wuon" << std::endl;
}

void	Core::eventHandler(std::pair<UserEvent, char> event, MenuInformations &menu,
		CoreInformations &core)
{
	if (event.first == UserEvent::ESCAPE)
	{
		m_lib->DestroyWindow();
		std::exit(0);
	}
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
	else if (event.first == UserEvent::DOWN)
			menu.game = incLibs(core, menu.game);
	else if (event.first == UserEvent::UP)
			menu.game = decLibs(core, menu.game);
	else if (event.first == UserEvent::LIB_NEXT)
		loadNextLib();
	/*else if (event.first == UserEvent::LIB_PREV)
		std::exit(0);*/
}

void	Core::showMenu()
{
	std::pair<UserEvent, char>	event;
	MenuInformations menu = {"", m_games[0], m_pathLib};
	CoreInformations core = {m_games, m_libraries, m_scores};

	while (1)
	{
		m_lib->Clear();
		event = m_lib->getLastEvent();
		eventHandler(event, menu, core);
		m_lib->DrawMenu(menu, core);
		m_lib->Display();
	}
}

void	Core::loadGraphicLibrary(const char *nameLib)
{
	m_handle = dlopen(nameLib, RTLD_NOW);
	IGlib	*(*create)();

	if (!m_handle)
	{
		std::cerr << "Cannot open graphic library." << std::endl;
		std::exit(84);
	}
	create = (IGlib* (*)())dlsym(m_handle, "create_lib");
	if (!create)
	{
		std::cerr << "Graphic library is incompatible." << std::endl;
		std::exit(84);
	}
	std::cout << "loadG1" << std::endl;
	if (m_lib) {
		std::cout << "wallou" << std::endl;
		m_lib.release();
		m_lib.reset(create());
	}
	else
		m_lib = std::unique_ptr<IGlib>(create());
	std::cout << "loadG2" << std::endl;
	std::vector<std::pair<std::string, float>> list;
}

void Core::loadGames()
{
	const std::string dir = "games";
	const std::string suffix = ".so";
	const std::string prefix = "/game_arcade_";
	fs::directory_iterator iterator(dir);

	for (auto &entry: iterator)
	{
		std::string path = entry.path();
		std::size_t n_idx = path.find(prefix);
		if (n_idx == std::string::npos)
			continue;

		std::string game = path.substr(n_idx + prefix.size());
		if (game.find(".so") != game.size() - suffix.size())
			continue;

		m_games.push_back(game);
	}

	if (m_games.empty())
		throw CoreException("No games found.");
}

void Core::loadLibrairies()
{
	const std::string dir = "lib";
	const std::string suffix = ".so";
	const std::string prefix = "/lib_arcade_";
	fs::directory_iterator iterator(dir);

	for (auto &entry: iterator)
	{
		std::string path = entry.path();
		std::size_t n_idx = path.find(prefix);
		if (n_idx == std::string::npos)
			continue;

		std::string libname = path.substr(n_idx + prefix.size());
		if (libname.find(".so") != libname.size() - suffix.size())
			continue;

		m_libraries.push_back(libname);
	}

	if (m_libraries.empty())
		throw CoreException("No library found.");
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
			continue;

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
