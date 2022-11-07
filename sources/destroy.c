/*
** Description:
** Destroy Function
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#include "system.h"
#include "scene.h"

void destroyAll(t_system *system, t_scene **scenes)
{
    destroyScenes(scenes);
    destroySystem(system);
}