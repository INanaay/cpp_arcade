/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/03 by lebovin
*/

#ifndef CPP_ARCADE_COREEXCEPTION_HPP
#define CPP_ARCADE_COREEXCEPTION_HPP

#include <string>
#include <exception>

class CoreException : public std::exception
{
public:
	explicit CoreException(const std::string &message) : m_message(message)
	{

	}
	const char *what() const noexcept override
	{
		return m_message.c_str();
	}
private:
	std::string m_message;
};

#endif //CPP_ARCADE_COREEXCEPTION_HPP
