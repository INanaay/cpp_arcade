/*
 ** EPITECH PROJECT, 2018
 ** Epitech scolarship project (4 years remaining)
 ** File description:
 **      Made on 2018/03 by ebernard
 */

#ifndef CPP_ARCADE_IGFXMANAGER_HPP
#define CPP_ARCADE_IGFXMANAGER_HPP

#include <string>
#include <vector>
#include <map>
#include "arcade.hpp"
#include "AEntity.hpp"

namespace arcade {
	class IGfxManager {
	public:
		virtual ~IGfxManager() = default;
		enum class Keys {
			NONE, CLOSE,
			UP, DOWN, LEFT, RIGHT, ACTION,
			NEXTGAME, PREVGAME,
			NEXTGFX, PREVGFX,
		};
		virtual void initWindow(arcade::Point <std::size_t> size, std::string name) = 0;
		/*
		** formatage -> gfxName\n\n\ngameName\n\n\nPlayerName
		*/
		virtual std::string showMenu(std::vector<std::string> gfxName, std::vector<std::string> gameName) = 0;
		virtual std::string getPlayerName() = 0;
		virtual void setTraductor(const std::map<unsigned char, Traductor> &map) = 0;
		virtual void drawEntity(std::vector<AEntity> &sprite) = 0;
		virtual void drawMap(const std::vector<std::vector<unsigned char>> &map) = 0;
		virtual arcade::IGfxManager::Keys getEvent() = 0;
	};
}

/*
** std::string getName();
** arcade::IGfxManager *entryPoint();
*/

#endif //CPP_ARCADE_IGFXMANAGER_HPP
