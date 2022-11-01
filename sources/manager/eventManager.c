/*
** Description:
** Event Manager
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#include "system.h"
#include "gameScene.h"
#include "event.h"

sfBool mouse_on_sprite(sfSprite *sprite, sfRenderWindow *window)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(sprite);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if (mouse.x > rect.left && mouse.x < rect.left + rect.width
        && mouse.y > rect.top && mouse.y < rect.top + rect.height)
        return (sfTrue);
    return (sfFalse);
}

sfBool click_on_sprite(sfSprite *sprite, sfRenderWindow *window)
{
    if (mouse_on_sprite(sprite, window) && sfMouse_isButtonPressed(sfMouseLeft))
        return (sfTrue);
    return (sfFalse);
}
#include <stdio.h>
void onShootDuck(t_system *system, t_scene **scenes)
{
    /* Mouse click event */
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfFalse)
        return;
    /* Check if Game Scene */
    if (system->state != GAMESCENE)
        return;
    int i = 0;
    while (i < MAX_DUCKS) {
        if (click_on_sprite(scenes[GAMESCENE]->ducks[i]->image->sprite, system->window->window)) {
            printf("shoot!\n");
        }
        i += 1;
    }
}

void onClose(t_system *system, t_scene **scenes)
{
    (void)scenes;
    /* Close window : exit */
    if (system->event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape)) {
        sfRenderWindow_close(system->window->window);
        system->state = QUIT;
    }
}

void (*checkEvent[NUMEVENT])(t_system*, t_scene**) = {
    onClose,
    onShootDuck
};

void evenManager(t_system *system, t_scene **scenes)
{
    int i = 0;

    /* Process events */
    while (sfRenderWindow_pollEvent(system->window->window, &(system->event))) {
        while (i < NUMEVENT) {
            checkEvent[i](system, scenes);
            i += 1;
        }
    }
}