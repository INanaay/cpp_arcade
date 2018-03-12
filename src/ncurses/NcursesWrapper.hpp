/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/03 by lebovin
*/

#ifndef CPP_ARCADE_NCURSESWRAPPER_HPP
#define CPP_ARCADE_NCURSESWRAPPER_HPP

#include "../../inc/core/IGfxManager.hpp"

namespace arcade
{
	class NcursesWrapper : public IGfxManager
	{
	public:
		~NcursesWrapper() override = default;

		void initWindow(arcade::Point<std::size_t> size, std::string name) override;
		void setTraductor(const std::map<unsigned char, Traductor> &map) override;
		void drawEntity(std::vector<AEntity> &sprite) override;
		void drawMap(const std::vector<std::vector<unsigned char>> &map) override;

		Keys getEvent() override;
		std::string showMenu(std::vector<std::string> gfxName, std::vector<std::string> gameName) override;
		std::string getPlayerName() override;

	};
}

#endif //CPP_ARCADE_NCURSESWRAPPER_HPP
