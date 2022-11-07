/*
** Description:
** Main Function
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#include "system.h"
#include "sources.h"

void updateCrossAirPosition(t_system *system, t_scene **scenes)
{
    sfVector2f pos = {0, 0};

    pos.x = sfMouse_getPositionRenderWindow(system->window->window).x - (CROSS_WIDTH / 2);
    pos.y = sfMouse_getPositionRenderWindow(system->window->window).y - (CROSS_WIDTH / 2);
    setPos(scenes[GAMESCENE]->images[CROSSAIR], pos);
    sfSprite_setPosition(scenes[GAMESCENE]->images[CROSSAIR]->sprite, pos);
}