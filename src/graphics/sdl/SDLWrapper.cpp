//
// Created by NANAA on 02/04/18.
//

#include <vector>
#include <memory>
#include <iostream>
#include "../../../inc/graphics/SDLWrapper.hpp"
#include "../../../inc/core/EntityType.hpp"
#include "../../../inc/core/UserEvent.hpp"
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_video.h>

extern "C" SDLWrapper *create_lib()
{
	return new SDLWrapper();
}

SDLWrapper::SDLWrapper()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0 )
	{
		std::cout << "Cant init SDL" << std::endl;
		throw new std::exception;
	}
	if( TTF_Init() == -1 ) {
		std::cout << "Cant init TTF" << std::endl;
		throw new std::exception;
	}
	m_font = TTF_OpenFont("test.ttf", 28);
	if (!m_font) {
		std::cout << "Cant open font\n";
		throw std::exception();
	}
}

void SDLWrapper::InitWindow()
{
	SDL_CreateWindowAndRenderer(SCR_WIDTH, SCR_HEIGHT, 0, &m_window, &m_renderer);
	m_color = {255, 255, 255, 1};
}

void SDLWrapper::DestroyWindow()
{
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

void SDLWrapper::Clear() {}

void SDLWrapper::Display() {}

std::pair<UserEvent, char> SDLWrapper::getLastEvent()
{
	SDL_Event event;
	std::pair<UserEvent, char> lastEvent = std::make_pair<UserEvent, char>(UserEvent::NONE, 0);
	SDL_PollEvent(&event);
	switch (event.type) {
		case SDLK_ESCAPE:
			lastEvent.first = UserEvent::ESCAPE;
			break;
		case SDL_QUIT:
			lastEvent.first = UserEvent::ESCAPE;
			break;
		default:
			break;
	}
	return lastEvent;
};

void SDLWrapper::DrawMap(std::vector<Entity> &map) {map = map;}

void SDLWrapper::drawGames(std::vector<std::pair<std::string, std::string>>, std::pair<std::string, std::string>) {}

void SDLWrapper::DrawMenu(MenuInformations, CoreInformations)
{
	auto s_text = TTF_RenderText_Solid(m_font, "Fils de pute", m_color);
	SDL_Rect rect_dest;
	rect_dest.x = 0;
	rect_dest.y = 0;
	rect_dest.w = s_text->w;
	rect_dest.h = s_text->h;
	auto screen = SDL_GetWindowSurface(m_window);
	SDL_BlitSurface(s_text, NULL, screen, &rect_dest);
}

void SDLWrapper::DrawEntity(Entity &entity) {entity = entity;}
