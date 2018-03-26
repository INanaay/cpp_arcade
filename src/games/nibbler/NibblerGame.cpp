/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/03 by lebovin
*/

#include "../../../inc/games/nibbler/NibblerGame.hpp"

extern "C" NibblerGame *create_game()
{
	return new NibblerGame();
}

NibblerGame::NibblerGame()
{

}

void NibblerGame::Run()
{
	printf("run\n");
/*	while (1)
		m_library->DrawMap(m_map);*/
}

void NibblerGame::Stop()
{

}

void NibblerGame::Init(std::unique_ptr<IGlib> library, Map &map)
{
	m_map = map;
	m_library = std::move(library);
}
