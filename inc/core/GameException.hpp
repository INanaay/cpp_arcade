/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/03 by lebovin
*/

#ifndef CPP_ARCADE_GAMEEXCEPTION_HPP
#define CPP_ARCADE_GAMEEXCEPTION_HPP

#include <string>
#include <exception>

class GameException : public std::exception
{
public:
	explicit GameException(const std::string &message) : m_message(message)
	{

	}
	const char *what() const noexcept override
	{
		return m_message.c_str();
	}
private:
	std::string m_message;
};

#endif //CPP_ARCADE_GAMEEXCEPTION_HPP
