//
// Created by NANAA on 02/04/18.
//

#include <unistd.h>
#include <vector>
#include <memory>
#include <iostream>
#include "../../../inc/graphics/SDLWrapper.hpp"
#include "../../../inc/core/EntityType.hpp"
#include <SDL2/SDL_image.h>
#include "../../../inc/core/UserEvent.hpp"
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_video.h>
#include <algorithm>

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
	m_font = TTF_OpenFont("resources/fonts/Consolas.ttf", 30);
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
	SDL_DestroyRenderer(m_renderer);
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
		case SDL_QUIT:
			lastEvent.first = UserEvent::ESCAPE;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
				case SDLK_RETURN:
					lastEvent.first = UserEvent::ENTER;
					break;
				case SDLK_ESCAPE:
					lastEvent.first = UserEvent::ESCAPE;
					break;
				case SDLK_BACKSPACE:
					lastEvent.first = UserEvent::TEXT;
					lastEvent.second = '\b';
					break;
				case SDLK_LEFT:
					lastEvent.first = UserEvent::LEFT;
					break;
				case SDLK_RIGHT:
					lastEvent.first = UserEvent::RIGHT;
					break;
				case SDLK_UP:
					lastEvent.first = UserEvent::UP;
					break;
				case SDLK_DOWN:
					lastEvent.first = UserEvent::DOWN;
					break;
				case SDLK_PAGEUP:
					lastEvent.first = UserEvent::LIB_NEXT;
					break;
				case SDLK_PAGEDOWN:
					lastEvent.first = UserEvent::LIB_PREV;
					break;
				case SDLK_SPACE:
					lastEvent.first = UserEvent::ACTION1;
					break;
				case SDLK_TAB:
					lastEvent.first = UserEvent::ACTION2;
					break;
				default:
					lastEvent.first = UserEvent::TEXT;
					lastEvent.second = static_cast<char>(event.key.keysym.sym);
					break;
			}
		default:
			break;
	}
	return lastEvent;
};

void SDLWrapper::DrawText(std::string text, int posx, int posy)
{
	SDL_Rect textRect;
	SDL_Surface *textSurface = TTF_RenderText_Solid(m_font, text.c_str(), m_color);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(m_renderer, textSurface);
	textRect.x = posx;
	textRect.y = posy;
	SDL_QueryTexture(texture, NULL, NULL, &textRect.w, &textRect.h);
	SDL_RenderCopy(m_renderer, texture, NULL, &textRect);
}

void SDLWrapper::DrawMap(std::vector<Entity> &map)
{
	for (auto &entity: map)
		DrawEntity(entity);
}


void SDLWrapper::drawGames(std::vector<std::pair<std::string, std::string>>, std::pair<std::string, std::string>) {}

void SDLWrapper::DrawMenu(MenuInformations menu, CoreInformations core)
{
	core = core;
	DrawText("Name :" + menu.name, 0, 0);
	DrawText("ACADE", SCR_WIDTH / 3, 0);
	DrawText("SDL", SCR_WIDTH * 3 / 4, 0);
	DrawText("Choose game : " + menu.game.first, 0, 40);
	DrawText("ScoreBoard", SCR_WIDTH / 2 - 90, 140);

	if (!(core.scores.find(menu.game.first) == core.scores.end())) {
		{
			auto vector = core.scores[menu.game.first];
			//std::sort(vector.begin(), vector.end(), test);
			int y = 160;
			for (unsigned int i = 0; i < vector.size(); i++) {
				DrawText(vector[i].first, 0, y);
				DrawText(std::to_string(vector[i].second), 80, y);
				y += 30;
			}
		}
	}
}

void SDLWrapper::DrawEntity(Entity &entity)
{
	SDL_Rect r;
	r.x = entity.cellPosition.first;
	r.y = entity.cellPosition.second;
	r.w = 30;
	r.h = 30;

	if (entity.ascii == 'O') {
		SDL_SetRenderDrawColor(m_renderer, 0, 0, 255, 255);
		SDL_RenderDrawRect(m_renderer, &r);
		SDL_RenderFillRect(m_renderer, &r);
	}
	else
	{
		SDL_Texture *img;
		int w, h;

		if (m_cache.find((entity.sprite)) == m_cache.end())
		{
			img = IMG_LoadTexture(m_renderer, entity.sprite.c_str());
			m_cache[entity.sprite] = img;
		}
		else
			img = m_cache[entity.sprite];

		SDL_QueryTexture(img, NULL, NULL, &w, &h);
		SDL_Rect texr; texr.x = entity.cellPosition.first;
		texr.y = entity.cellPosition.second;
		texr.w = w;
		texr.h = h;
		SDL_RenderCopy(m_renderer, img, NULL, &texr);

	}
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 0);
	usleep(20);
}
