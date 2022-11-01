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

void updateCrossAirPosition(t_system *system, t_scene **scenes)
{
    sfVector2f pos = {0, 0};

    pos.x = sfMouse_getPositionRenderWindow(system->window->window).x - (CROSS_WIDTH / 2);
    pos.y = sfMouse_getPositionRenderWindow(system->window->window).y - (CROSS_WIDTH / 2);
    setPos(scenes[GAMESCENE]->images[CROSSAIR], pos);
    sfSprite_setPosition(scenes[GAMESCENE]->images[CROSSAIR]->sprite, pos);
}

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

void display(sfRenderWindow* window, t_scene *scene)
{
    drawScene(window, scene);
    sfRenderWindow_display(window);
}

void clear(sfRenderWindow* window)
{
    sfRenderWindow_clear(window, sfBlack);
}

void gameloop(t_system *system, t_scene **scenes)
{
    /* Start the game loop */
    while (sfRenderWindow_isOpen(system->window->window) && (system->state != QUIT)) {
        /* Clear the screen */
        clear(system->window->window);
        /* Manage Event */
        evenManager(system, scenes);
        /* Process Event */
        process(system, scenes);
        /* Display Screen */
        display(system->window->window, scenes[system->state]);
    }
}

void destroyAll(t_system *system, t_scene **scenes)
{
    destroyScenes(scenes);
    destroySystem(system);
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