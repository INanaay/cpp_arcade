/*
** EPITECH PROJECT, 2018
** Epitech scolarship project (4 years remaining)
** File description:
**      Made on 2018/03 by lebovin
*/

#ifndef CPP_ARCADE_ALLEGROWRAPPER_HPP
# define CPP_ARCADE_ALLEGROWRAPPER_HPP

# include <allegro5/allegro.h>
# include <allegro5/allegro_font.h>
# include <allegro5/allegro_ttf.h>
# include <allegro5/allegro_native_dialog.h>
# include "../core/IGlib.hpp"

# define SCR_WIDTH 720
# define SCR_HEIGHT	640

class AllegroWrapper : public IGlib
{
public:
	AllegroWrapper();
	~AllegroWrapper() = default;
	void DrawMenu(MenuInformations, CoreInformations);
  void InitWindow();
	void DestroyWindow();
	void Clear();
	void Display();
	std::pair<UserEvent, char> getLastEvent();
	char getCharacter() {return 0;};
	void DrawMap(Map &);
	void DrawEntity(Entity &) {};
private:
	ALLEGRO_DISPLAY *m_display;
	ALLEGRO_EVENT_QUEUE *m_queue;
	ALLEGRO_FONT *m_font;
};

#endif //CPP_ARCADE_ALLEGROWRAPPER_HPP
