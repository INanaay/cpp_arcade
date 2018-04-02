//
// EPITECH PROJECT, 2018
// SDL header
// File description:
// sdl header
//

#ifndef CPP_ARCADE_SDLWRAPPER_HPP
# define CPP_ARCADE_SDLWRAPPER_HPP

#include <SDL2/SDL.h>
#include <vector>
#include <memory>
#include <SDL2/SDL_ttf.h>
#include "../../inc/core/UserEvent.hpp"
#include "../core/IGlib.hpp"


# define SCR_WIDTH 720
# define SCR_HEIGHT	640

class SDLWrapper : public IGlib
{
public:
	SDLWrapper();
	~SDLWrapper() = default;
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
	SDL_Window *m_window;
	SDL_Renderer *m_renderer;
	TTF_Font *m_font;
	SDL_Color m_color;
	SDL_Rect textRect;
	void DrawText(std::string text, int posx, int posy);

};

#endif //CPP_ARCADE_SFMLWRAPPER_HPP
