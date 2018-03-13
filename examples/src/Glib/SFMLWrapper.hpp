/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/03 by lebovin
*/

#ifndef CPP_ARCADE_SFMLWRAPPER_HPP
# define CPP_ARCADE_SFMLWRAPPER_HPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "IGlib.hpp"

class	SFMLWrapper : public IGlib
{
public:
	SFMLWrapper() = default;
	~SFMLWrapper() = default;
	void	drawMenu();
	void	initWindow();
	void	destroyWindow();
private:
	sf::RenderWindow	m_win;
	sf::Texture	m_texture;
	sf::Sprite	m_sprite;
	sf::Font	m_font;
};

#endif //CPP_ARCADE_SFMLWRAPPER_HPP
