/*
** Description:
** Event's structure
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#ifndef EVENT_H_
    #define EVENT_H_

    #include "system.h"

    #define NUMEVENT    3

    void evenManager(t_system *system, t_scene **scenes);

    sfBool click_on_sprite(sfSprite *sprite, sfRenderWindow *window);
    sfBool mouse_on_sprite(sfSprite *sprite, sfRenderWindow *window);
    sfBool click_on_text(sfText *text, sfRenderWindow *window);
    sfBool mouse_on_text(sfText *text, sfRenderWindow *window);

#endif /* !EVENT_H_ */