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

void destroySystem(t_system *system)
{
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
    system->state = RUN;
    return (system);
}