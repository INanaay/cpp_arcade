/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/03 by lebovin
*/

#ifndef CPP_ARCADE_SFMLWRAPPER_HPP
# define CPP_ARCADE_SFMLWRAPPER_HPP

# include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../core/EntityType.hpp"
#include "../core/IGlib.hpp"

# define SCR_WIDTH 720
# define SCR_HEIGHT 640

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
	void DrawMap(std::vector<Entity> &map);
	void DrawEntity(Entity &entity);
private:
	void drawGames(std::vector<std::pair<std::string, std::string>>,
		       std::pair<std::string, std::string>);
	sf::Font *m_font;
	std::unique_ptr<sf::RenderWindow> m_win;
	std::map<EntityType, sf::Sprite> m_assets;
	std::map<std::string, sf::Texture> m_cache;
	sf::Music m_music;

};

#endif //CPP_ARCADE_SFMLWRAPPER_HPP
