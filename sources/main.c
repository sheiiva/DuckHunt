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

#include <stdio.h>

void process(t_system *system, t_scene **scenes)
{
    sfVector2f pos = {0, 0};

    pos.x = sfMouse_getPositionRenderWindow(system->window->window).x - (CROSS_WIDTH / 2);
	pos.y = sfMouse_getPositionRenderWindow(system->window->window).y - (CROSS_WIDTH / 2);
    setPos(scenes[0]->images[1], pos);
    sfSprite_setPosition(scenes[0]->images[1]->sprite, pos);
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
        evenManager(system);
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
    t_scene **scenes = initScenes();

    if (!system || !scenes) {
        destroyAll(system, scenes);
        return (84);
    }
    gameloop(system, scenes);
    destroyAll(system, scenes);
    return (0);
}