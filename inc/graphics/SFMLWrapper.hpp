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

# define SCR_WIDTH 1000
# define SCR_HEIGHT 1000

class SFMLWrapper : public IGlib
{
public:
	SFMLWrapper();
	~SFMLWrapper() = default;
	void drawMenu(MenuInformations, CoreInformations);
  void initWindow();
	void destroyWindow();
	void clearWindow();
	void display();
	std::pair<UserEvent, char> getLastEvent();
	void drawMap(std::vector<Entity> &map);
	void drawEntity(const Entity &entity);
	void drawScore(size_t, int posx, int posy);
private:
	void drawGames(std::vector<std::pair<std::string, std::string>>,
		       std::pair<std::string, std::string>);
	sf::Font *m_font;
	std::unique_ptr<sf::RenderWindow> m_win;
	std::map<EntityType, sf::Sprite> m_assets;
	std::map<std::string, sf::Texture> m_cache;
	std::unique_ptr<sf::Music> m_music;
	void drawScore() const;
	void drawText(std::string text, float posx, float posy);
};

#endif //CPP_ARCADE_SFMLWRAPPER_HPP
