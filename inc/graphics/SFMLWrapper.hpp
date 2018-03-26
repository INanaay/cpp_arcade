/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/03 by lebovin
*/

#ifndef CPP_ARCADE_SFMLWRAPPER_HPP
# define CPP_ARCADE_SFMLWRAPPER_HPP

# include <SFML/Graphics.hpp>
#include "../core/IGlib.hpp"

# define SCR_WIDTH 720
# define SCR_HEIGHT	640

class SFMLWrapper : public IGlib
{
public:
	SFMLWrapper();
	~SFMLWrapper() = default;
	void DrawMenu(MenuInformations, CoreInformations);
  void InitWindow();
	void DestroyWindow();
	void Clear();
	void Display();
	std::pair<UserEvent, char> getLastEvent();
	char getCharacter();
	void DrawMap(Map &) {};
	void DrawEntity(Entity &) {};
private:
	void	drawGames(std::vector<std::pair<std::string, std::string>>, std::pair<std::string, std::string>);
	std::unique_ptr<sf::RenderWindow> m_win;
	sf::Font	*m_font;
};

#endif //CPP_ARCADE_SFMLWRAPPER_HPP
