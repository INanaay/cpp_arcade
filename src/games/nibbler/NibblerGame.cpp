/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/03 by lebovin
*/

#include <unistd.h>
#include <fstream>
#include <iostream>
#include "../../../inc/games/nibbler/NibblerGame.hpp"
#include "../../../inc/core/GameException.hpp"

extern "C" NibblerGame *create_game()
{
	return new NibblerGame();
}

NibblerGame::NibblerGame()
{

}

void NibblerGame::eventHandler(std::pair<UserEvent, char> event)
{
	if (event.first == UserEvent::ESCAPE)
	{
		m_library->DestroyWindow();
		std::exit(0);
	}
}

void NibblerGame::Run()
{
	std::pair<UserEvent, char> event;

	while (1)
	{
		m_library->Clear();
		event = m_library->getLastEvent();
		eventHandler(event);
		m_library->DrawMap(m_map);
		m_library->Display();
	}
}

void NibblerGame::Stop()
{

}

void NibblerGame::Init(std::unique_ptr<IGlib> library)
{
	m_library = std::move(library);
	loadMap("ressources/nibbler/test.map");
}

void NibblerGame::loadMap(const std::string &path)
{
	std::string line;
	std::ifstream fstream(path);

	if (!fstream)
		throw GameException("Cannot load given map.");
	while (std::getline(fstream, line))
		m_map.push_back(line);
}
