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
private:
	IGlib	*m_lib;
};

#endif //CORE_HPP
