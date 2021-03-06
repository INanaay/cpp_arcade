/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/03 by lebovin
*/

#include <string>
#include <memory>
#include <utility>
#include <cstring>
#include <dlfcn.h>
#include <iostream>
#include <algorithm>
#include <experimental/filesystem>
#include <fstream>
#include "../../inc/core/Core.hpp"
#include "../../inc/core/CoreException.hpp"

Core::Core(const std::string &libname)
{
	m_handle = NULL;
	loadGames();
	loadLibrairies();
	loadScoreBoard();
	loadGraphicLibrary(libname.c_str());
	m_pathLib.second = libname;
	std::string prefix = "/lib_arcade_";
	std::size_t n_idx = libname.find(prefix);
	m_pathLib.first = libname.substr(n_idx + prefix.size());
}

void	Core::Start()
{
	m_lib->initWindow();
	showMenu();
}

static std::pair<std::string, std::string>incLibs(CoreInformations core, std::pair<std::string, std::string> toFind)
{
		auto it = std::find(core.games.begin(), core.games.end(), toFind);
		if (it == core.games.end())
		{
			std::cerr << "error in change games" << std::endl;
			throw std::exception();
		}	
		int index = it - core.games.begin();
		if (index < (int)core.games.size() - 1)
			return core.games[index + 1];
		else
			return core.games[0];
}

static std::pair<std::string, std::string>	decLibs(CoreInformations core, std::pair<std::string, std::string> toFind)
{
		auto it = std::find(core.games.begin(), core.games.end(), toFind);
		if (it == core.games.end())
		{
			std::cerr << "error in change games" << std::endl;
			throw std::exception();
		}	
		int index = it - core.games.begin();
		if (index > 0)
			return core.games[index - 1];
		else
			return core.games[core.games.size() - 1];
}

void	Core::loadNextLib()
{
	m_lib->destroyWindow();
	system("reset");
	auto it = std::find(m_libraries.begin(), m_libraries.end(), m_pathLib);
		if (it == m_libraries.end())
		{
			std::cerr << "error in change Glib" << std::endl;
			std::exit(84);
		}	
		int index = it - m_libraries.begin();
		if (index > 0)
		{
			loadGraphicLibrary((m_libraries[index - 1]).second.c_str());
			m_pathLib = m_libraries[index - 1];
		}
		else
		{
			loadGraphicLibrary((m_libraries[m_libraries.size() - 1]).second.c_str());
			m_pathLib = m_libraries[m_libraries.size() - 1];
		}
		m_lib->initWindow();
}

void	Core::loadPrevLib()
{
	m_lib->destroyWindow();
	system("reset");
	auto it = std::find(m_libraries.begin(), m_libraries.end(), m_pathLib);
		if (it == m_libraries.end())
		{
			std::cerr << "error in change Glib" << std::endl;
			throw std::exception();
		}	
		int index = it - m_libraries.begin();
		if (index < (int)m_libraries.size() - 1)
		{
			loadGraphicLibrary((m_libraries[index + 1]).second.c_str());
			m_pathLib = m_libraries[index + 1];
		}
		else
		{
			loadGraphicLibrary((m_libraries[0]).second.c_str());
			m_pathLib = m_libraries[0];
		}
		m_lib->initWindow();
}

void	Core::runGame(MenuInformations menu)
{
	(void)menu;
	void *handle = dlopen(menu.game.second.c_str(), RTLD_NOW);
	IGame	*(*create)();

	if (!handle)
	{
		std::cerr << "Cannot open game library." << std::endl;
		std::cerr << dlerror() << std::endl;
		throw std::exception();
	}
	create = (IGame* (*)())dlsym(handle, "create_game");
	if (!create)
	{
		std::cerr << "Game library is incompatible." << std::endl;
		throw std::exception();
	}
	m_game = std::unique_ptr<IGame>(create());
	loopGame();
	m_scores[menu.game.first].push_back({menu.name, m_game->getScore()});
	serializeScores(menu.game.first, m_scores[menu.game.first]);
}

void Core::loopGame()
{
	UserEvent gameEvent;
	m_game->init(std::move(m_lib));
	while (1) {
		gameEvent = m_game->run();
		if (gameEvent == UserEvent::LIB_NEXT) {
			m_lib = std::move(m_game->getLib());
			loadNextLib();
			m_game->setLib(std::move(m_lib));
		} else if (gameEvent == UserEvent::LIB_PREV) {
			m_lib = std::move(m_game->getLib());
			loadPrevLib();
			m_game->setLib(std::move(m_lib));
		}
		if (gameEvent == UserEvent::ESCAPE) {
			m_lib = std::move(m_game->getLib());
			return;
		}
	}
}

void	Core::eventHandler(std::pair<UserEvent, char> event, MenuInformations &menu,
		CoreInformations &core)
{

	 if (event.first == UserEvent::ENTER)
	{
		if (menu.name != "") {
			runGame(menu);
			core.scores = m_scores;
		}
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
	else if (event.first == UserEvent::LIB_PREV)
		loadPrevLib();
}

void	Core::showMenu()
{
	std::pair<UserEvent, char>	event;
	MenuInformations menu = {"", m_games[0], m_pathLib};
	CoreInformations core = {m_games, m_libraries, m_scores};


	while (1)
	{
		m_lib->clearWindow();
		event = m_lib->getLastEvent();
		if (event.first == UserEvent::ESCAPE) {
			m_lib->destroyWindow();
			return;
		}
		eventHandler(event, menu, core);
		m_lib->drawMenu(menu, core);
		m_lib->display();
	}
}

void	Core::loadGraphicLibrary(const char *nameLib)
{
	void *handle = dlopen(nameLib, RTLD_NOW);
	IGlib	*(*create)();

	if (!handle)
	{
		std::cerr << "Cannot open graphic library." << std::endl;
		std::cerr << dlerror() << std::endl;
		throw std::exception();
	}
	create = (IGlib* (*)())dlsym(handle, "create_lib");
	if (!create)
	{
		std::cerr << "Graphic library is incompatible." << std::endl;
		throw std::exception();
	}
	if (m_lib)
		m_lib.reset(create());
	else
		m_lib = std::unique_ptr<IGlib>(create());
	if (m_handle)
	{
		dlclose(m_handle);
		m_handle = handle;
	}
}

void Core::loadGames()
{
	const std::string dir = "games";
	const std::string suffix = ".so";
	const std::string prefix = "/lib_arcade_";
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

		std::pair<std::string, std::string> pairGame;
		pairGame.first = game;
		pairGame.second = path;
		m_games.push_back(pairGame);
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

		std::pair<std::string, std::string> pairLib;
		pairLib.first = libname;
		pairLib.second = path;
		m_libraries.push_back(pairLib);
	}

	if (m_libraries.empty())
		throw CoreException("No library found.");
}

void Core::loadScoreBoard()
{
	const std::string dir = "scores";
	const std::string suffix = ".so";
	const std::string prefix = "/arcade_score_";
	fs::directory_iterator iterator(dir);

	for (auto &entry: iterator)
	{
		std::string path = entry.path();
		std::size_t n_idx = path.find(prefix);
		if (n_idx == std::string::npos)
			continue;
		std::string game = path.substr(n_idx + prefix.size());
		if (path[path.size() - 1] != '~')
			deserializeScores(game, path);
	}
}

void Core::deserializeScores(const std::string &game, const std::string &path)
{
	std::ifstream fileStream(path);
	std::string key;
	int separatorPosition;
	std::string line;

	separatorPosition = game.find('.');
	key = game.substr(0, separatorPosition) + ".so";
	if (!fileStream)
		throw std::exception();

	while (std::getline(fileStream, line))
	{
		separatorPosition= line.find(':');
		std::string score = line.substr(0, separatorPosition);
		std::string name = line.substr(separatorPosition + 1, line.size());
		m_scores[key].push_back({name, std::stoi(score)});
	}
	fileStream.close();
}


void Core::serializeScores(const std::string &game, std::vector<Score> &scores)
{
	const std::string dir = "scores/";
	const std::string filename = "arcade_score_" + game;
	std::ofstream fileStream(dir + filename, std::ios::out | std::ios::trunc);

	std::sort(scores.begin(), scores.end(), [](std::pair<std::string, uint> i, std::pair<std::string, uint> j) {
		return i.second > j.second;
	});
	if (!fileStream)
		throw std::exception();
	unsigned int i = 0;
	while (i < scores.size() && i < 9) {
		fileStream << scores[i].second << ":" << scores[i].first << "\n";
		i++;
	}
	fileStream.close();
}
