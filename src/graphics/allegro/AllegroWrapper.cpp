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

extern "C" AllegroWrapper *create_lib()
{
	return new AllegroWrapper();
}

AllegroWrapper::AllegroWrapper()
{
}

void AllegroWrapper::DrawMenu(MenuInformations menu, CoreInformations core)
{
	(void)menu;
	(void)core;
	ALLEGRO_DISPLAY*display;
    ALLEGRO_KEYBOARD_STATE key;
    ALLEGRO_MOUSE_STATE mouse;
    ALLEGRO_TEXTLOG *console; // une console

    if (!al_init())
        printf("al_init()\n");

    if (!al_install_keyboard())
        printf("al_install_keyboard()\n");

    if (!al_install_mouse())
        printf("al_install_mouse()\n");

    display = al_create_display(800, 600);
    if (!display)
        printf("al_create_display()\n");

    // création et ouverture
    console = al_open_native_text_log("Ma console", 0);
    if (!console)
        printf("al_open_native_text_log(\"Ma console\", 0)\n");

    int mx = 0;
    int my = 0;
    do{
        al_get_keyboard_state(&key);
        al_get_mouse_state(&mouse);

        // écrire dans la console
        if (console != NULL && (mx!=mouse.x || my!= mouse.y)){
            mx = mouse.x;
            my = mouse.y;
            al_append_native_text_log(console,
                 "position souris : %d, %d\n", mx, my);
        }

        //fermer la console
        if (al_key_down(&key, ALLEGRO_KEY_ENTER)){
            al_close_native_text_log(console);
            console = NULL;
        }

    } while (!al_key_down(&key, ALLEGRO_KEY_ESCAPE));

    al_destroy_display(display);
}
