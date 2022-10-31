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

void process(t_system *system)
{
    (void)system;
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
        process(system);
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