/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/03 by lebovin
*/

#include <unistd.h>
#include <iostream>
#include <vector>
#include <memory>
#include "../../../inc/graphics/AllegroWrapper.hpp"
#include "../../../inc/core/Informations.hpp"
#include "../../../inc/core/UserEvent.hpp"
#include "../../../inc/core/EntityType.hpp"

static std::vector<std::pair<int, char>> tabAlpha = {
	{ALLEGRO_KEY_A, 'A'},
	{ALLEGRO_KEY_B, 'B'},
	{ALLEGRO_KEY_C, 'C'},
	{ALLEGRO_KEY_D, 'D'},
	{ALLEGRO_KEY_E, 'E'},
	{ALLEGRO_KEY_F, 'F'},
	{ALLEGRO_KEY_G, 'G'},
	{ALLEGRO_KEY_I, 'H'},
	{ALLEGRO_KEY_I, 'I'},
	{ALLEGRO_KEY_J, 'J'},
	{ALLEGRO_KEY_K, 'K'},
	{ALLEGRO_KEY_L, 'L'},
	{ALLEGRO_KEY_M, 'M'},
	{ALLEGRO_KEY_N, 'N'},
	{ALLEGRO_KEY_O, 'O'},
	{ALLEGRO_KEY_P, 'P'},
	{ALLEGRO_KEY_Q, 'Q'},
	{ALLEGRO_KEY_R, 'R'},
	{ALLEGRO_KEY_S, 'S'},
	{ALLEGRO_KEY_T, 'T'},
	{ALLEGRO_KEY_U, 'U'},
	{ALLEGRO_KEY_V, 'V'},
	{ALLEGRO_KEY_W, 'W'},
	{ALLEGRO_KEY_X, 'X'},
	{ALLEGRO_KEY_Y, 'Y'},
	{ALLEGRO_KEY_Z, 'Z'},
	{ALLEGRO_KEY_BACKSPACE, '\b'}
};

extern "C" AllegroWrapper *create_lib()
{
	return new AllegroWrapper();
}

AllegroWrapper::AllegroWrapper()
{
	int ok = 1;

	if (!al_init())
		ok = 0;
	m_display = al_create_display(SCR_WIDTH, SCR_HEIGHT);
	if (!m_display)
		ok = 0;
	if (!al_install_keyboard())
		ok = 0;
	m_queue = al_create_event_queue();
	if (!m_queue)
		ok = 0;
	al_init_font_addon();
	al_init_ttf_addon();
	m_font = al_load_ttf_font("./ressources/fonts/Consolas.ttf", 30, 0);
	if (!m_font)
		ok = 0;
	al_register_event_source(m_queue, al_get_keyboard_event_source());
	if (ok == 0) {
		printf("error in InitWindow Allegro.");
		std::exit(84);
	}
}

void	AllegroWrapper::InitWindow()
{
}

void	AllegroWrapper::DestroyWindow()
{
  al_destroy_display(m_display);
}

void	AllegroWrapper::Clear()
{
	al_clear_to_color(al_map_rgb(0, 0, 0));
}

void	AllegroWrapper::Display()
{
	al_flip_display();
}

static std::pair<UserEvent, char> eventText(int key)
{
	std::pair<UserEvent, char> lastEvent = std::make_pair<UserEvent, char>(UserEvent::NONE, 0);

	for (auto i : tabAlpha)
	{
		if (i.first == key) {
			lastEvent.first = UserEvent::TEXT;
			lastEvent.second = i.second;
			return lastEvent;
		}
	}
	return lastEvent;
}

std::pair<UserEvent, char>	AllegroWrapper::getLastEvent()
{
	ALLEGRO_EVENT	ev;
	ALLEGRO_TIMEOUT timeout;
	std::pair<UserEvent, char> lastEvent = std::make_pair<UserEvent, char>(UserEvent::NONE, 0);

	al_init_timeout(&timeout, 0.06);
	al_flush_event_queue(m_queue);
	bool getevent =	al_wait_for_event_until(m_queue, &ev, &timeout);
	if (getevent && ev.type == ALLEGRO_EVENT_KEY_DOWN)
	{
		if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
			lastEvent.first = UserEvent::ESCAPE;
		else if (ev.keyboard.keycode == ALLEGRO_KEY_PGDN)
			lastEvent.first = UserEvent::LIB_PREV;
		else if (ev.keyboard.keycode == ALLEGRO_KEY_PGUP)
			lastEvent.first = UserEvent::LIB_NEXT;
		else if (ev.keyboard.keycode == ALLEGRO_KEY_SPACE)
			lastEvent.first = UserEvent::ACTION1;
		else if (ev.keyboard.keycode == ALLEGRO_KEY_TAB)
			lastEvent.first = UserEvent::ACTION2;
		else if (ev.keyboard.keycode == ALLEGRO_KEY_ENTER)
			lastEvent.first = UserEvent::ENTER;
		else if (ev.keyboard.keycode == ALLEGRO_KEY_UP)
			lastEvent.first = UserEvent::UP;
		else if (ev.keyboard.keycode == ALLEGRO_KEY_DOWN)
			lastEvent.first = UserEvent::DOWN;
		else if (ev.keyboard.keycode == ALLEGRO_KEY_LEFT)
			lastEvent.first = UserEvent::LEFT;
		else if (ev.keyboard.keycode == ALLEGRO_KEY_RIGHT)
			lastEvent.first = UserEvent::RIGHT;
		else
			lastEvent = eventText(ev.keyboard.keycode);
	}
	return lastEvent;
}

void AllegroWrapper::DrawMenu(MenuInformations menu, CoreInformations core)
{
	std::string fullName = "Name : " + menu.name;
	std::string game = "Selected game : " + menu.game.first;
	(void)core;

	al_draw_text(m_font, al_map_rgb(150, 150, 150), 0, 0, ALLEGRO_ALIGN_LEFT, fullName.c_str());
	al_draw_text(m_font, al_map_rgb(150, 150, 150), 0, 100, ALLEGRO_ALIGN_LEFT, game.c_str());
}

void	AllegroWrapper::DrawMap(std::vector<Entity> &map)
{
	(void)map;
	al_draw_text(m_font, al_map_rgb(150, 150, 150), 0, 0, ALLEGRO_ALIGN_LEFT, "GAME");
}
