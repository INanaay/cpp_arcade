/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/03 by lebovin
*/

#ifndef CORE_HPP
# define CORE_HPP

# include "./Glib/IGlib.hpp"

class	Core
{
public:
	Core(const char *);
	~Core() = default;
	void	loadLib(const char *);
	void	start();
	void	drawMenu();
	const std::vector<std::string> &getM_libsTab() const;
	void setM_libsTab(const std::vector<std::string> &m_libsTab);
	const std::vector<std::string> &getM_gamesTab() const;
	void setM_gamesTab(const std::vector<std::string> &m_gamesTab);
	void createLibsTab();
	void createGamesTab();
private:
	bool endsWith(const std::string &str, const std::string &suffix) const;
	IGlib	*m_lib;
	std::vector<std::string> m_libsTab;
	std::vector<std::string> m_gamesTab;
};

#endif //CORE_HPP
