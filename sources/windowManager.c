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

sfRenderWindow *createWindow(sfVideoMode mode)
{
    return sfRenderWindow_create(mode, "Duck Hunt", sfResize | sfClose, NULL);;
}

void destroyWindow(t_window *window)
{
    free(window->window);
    free(window);
}

t_window *initWindow()
{
    t_window *window = malloc(sizeof(t_window));

    if (!window)
        return (NULL);
    window->mode = (sfVideoMode){800, 600, 32};
    if (!(window->window = createWindow(window->mode))) {
        destroyWindow(window);
        return (NULL);
    }
    return (window);
}