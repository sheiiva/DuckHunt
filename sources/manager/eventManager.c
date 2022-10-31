/*
** Description:
** Event Manager
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#include "system.h"
#include "event.h"

void onClose(t_system *system)
{
    /* Close window : exit */
    if (system->event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape)) {
        sfRenderWindow_close(system->window->window);
        system->state = QUIT;
    }
}

void (*checkEvent[NUMEVENT])(t_system*) = {
    onClose
};

void evenManager(t_system *system)
{
    int i = 0;

    /* Process events */
    while (sfRenderWindow_pollEvent(system->window->window, &(system->event))) {
        while (i < NUMEVENT) {
            checkEvent[i](system);
            i += 1;
        }
    }
}