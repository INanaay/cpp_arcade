//
// Created by NANAA on 02/04/18.
//

#include <vector>
#include <memory>
#include <iostream>
#include "../../../inc/graphics/SDLWrapper.hpp"
#include "../../../inc/core/EntityType.hpp"
#include "../../../inc/core/UserEvent.hpp"
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_video.h>

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
	m_font = TTF_OpenFont("ressources/fonts/Consolas.ttf", 30);
	if (!m_font) {
		std::cout << "Cant open font\n";
		throw std::exception();
	}
}


void SDLWrapper::InitWindow()
{
	m_window = SDL_CreateWindow("SDL_RenderClear",
				    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
				    SCR_WIDTH, SCR_HEIGHT,
				    0);
	m_renderer = SDL_CreateRenderer(m_window, -1, 0);

	m_color = {0, 0, 255, 255};

	 m_color = {255, 255, 255, 255};


}

void SDLWrapper::DestroyWindow()
{
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

void SDLWrapper::Clear()
{
	SDL_RenderClear(m_renderer);

}

void SDLWrapper::Display() {
	SDL_RenderPresent(m_renderer);
}

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

void SDLWrapper::DrawText(std::string text, int posx, int posy)
{
	SDL_Surface *textSurface = TTF_RenderText_Solid(m_font, text.c_str(), m_color);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(m_renderer, textSurface);
	textRect.x = posx;
	textRect.y = posy;
	SDL_QueryTexture(texture, NULL, NULL, &textRect.w, &textRect.h);
	SDL_RenderCopy(m_renderer, texture, NULL, &textRect);
}

void SDLWrapper::DrawMap(std::vector<Entity> &map) {map = map;}

void SDLWrapper::drawGames(std::vector<std::pair<std::string, std::string>>, std::pair<std::string, std::string>) {}

void SDLWrapper::DrawMenu(MenuInformations, CoreInformations)
{
	DrawText("Lol", 0, 0);
	DrawText("PD", 100, 100);
}

void SDLWrapper::DrawEntity(Entity &entity) {entity = entity;}
