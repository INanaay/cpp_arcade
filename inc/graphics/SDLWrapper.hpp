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


# define SCR_WIDTH 1000
# define SCR_HEIGHT 1000

class SDLWrapper : public IGlib
{
	struct SDLAudio
	{
		SDL_AudioSpec wavSpec;
		Uint32 wavLength;
		Uint8 *wavBuffer;
	};
public:
	SDLWrapper();
	~SDLWrapper() = default;
	void drawMenu(MenuInformations, CoreInformations);
	void initWindow();
	void destroyWindow();
	void clearWindow();
	void display();
	std::pair<UserEvent, char> getLastEvent();
	void drawMap(std::vector<Entity> &map);
	void drawEntity(const Entity &entity);
	virtual void drawScore(size_t, int posx, int posy);
private:
	void drawGames(std::vector<std::pair<std::string, std::string>>,
		       std::pair<std::string, std::string>);
	SDL_Window *m_window;
	SDL_Renderer *m_renderer;
	TTF_Font *m_font;
	SDL_Color m_color;
	SDLAudio m_audio;

	void drawText(std::string text, int posx, int posy) const;
	std::map<std::string, SDL_Texture *> m_cache;

};

#endif //CPP_ARCADE_SFMLWRAPPER_HPP
