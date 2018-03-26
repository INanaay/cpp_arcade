/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/03 by lebovin
*/

#ifndef CORE_HPP
# define CORE_HPP

# include <memory>
# include <experimental/filesystem>
# include "IGlib.hpp"
# include "IGame.hpp"

namespace fs = std::experimental::filesystem;

class Core
{
public:
	Core(const std::string &libname);
	~Core() = default;

	void Start();
private:
	std::unique_ptr<IGame> m_game;
	std::pair<std::string, std::string>	m_pathLib;
	std::unique_ptr<IGlib> m_lib;
	std::vector<std::pair<std::string, std::string>> m_games;
	std::vector<std::pair<std::string, std::string>> m_libraries;
	std::map<std::string, std::vector<Score>> m_scores;

	void showMenu();
	void	eventHandler(std::pair<UserEvent, char>, MenuInformations &, CoreInformations &);
	void loadGraphicLibrary(const char *);
	void	loadNextLib();
	void	loadPrevLib();

	void *m_handle;
	void loadGames();
	void loadLibrairies();
	void loadScoreBoard();
	void deserializeScores(const std::string &game,
			       const std::string &path);
	void serializeScores(const std::string &game,
			     std::vector<Score> &scores);
	void runGame(MenuInformations);
};

#endif //CORE_HPP
