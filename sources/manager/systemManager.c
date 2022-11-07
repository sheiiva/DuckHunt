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

void displayAll(sfRenderWindow* window, t_scene *scene)
{
    drawScene(window, scene);
    sfRenderWindow_display(window);
}

void destroySystem(t_system *system)
{
    sfClock_destroy(system->clock);
    if (!system)
        return;
    if (system->window)
        destroyWindow(system->window);
    free(system);
}

t_system *initSystem()
{
    t_system *system = malloc(sizeof(t_system));

    if(!system)
        return (NULL);
    system->window = initWindow();
    if (!system->window) {
        destroySystem(system);
        return (NULL);
    }
    sfRenderWindow_setFramerateLimit(system->window->window, 60);
    system->clock = sfClock_create();
    system->state = MENUSCENE;
    return (system);
}