/*
** Description:
** Main Function
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#include "sources.h"
#include "system.h"
#include "event.h"
#include "gameScene.h"

void process(t_system *system, t_scene **scenes)
{
    sfTime time = sfClock_getElapsedTime(system->clock);

	if ((time.microseconds / 1000000.0) > 0.1) {
        if (system->state == GAMESCENE) {
            updateCrossAirPosition(system, scenes);
            updateDucksPosition(scenes[GAMESCENE]->ducks);
        }
		sfClock_restart(system->clock);
	}
}

void gameloop(t_system *system, t_scene **scenes)
{
    /* Start the game loop */
    while (sfRenderWindow_isOpen(system->window->window)) {
        /* Manage Event */
        evenManager(system, scenes);
        if (system->state == QUIT) {
            return;
        }
        /* Clear the screen */
        clearWindow(system->window->window);
        /* Process Event */
        process(system, scenes);
        /* Display Screen */
        displayAll(system->window->window, scenes[system->state]);
    }
}

int main()
{
    t_system *system = initSystem();
    t_scene **scenes = NULL;

    if (!system) {
        destroyAll(system, scenes);
        return (84);
    }
    if (!(scenes = initScenes(system->window->window))) {
        destroyAll(system, scenes);
        return (84);
    }
    gameloop(system, scenes);
    destroyAll(system, scenes);
    return (0);
}