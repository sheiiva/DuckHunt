/*
** Description:
** Event Manager
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#include "sources.h"
#include "system.h"
#include "gameScene.h"
#include "menuScene.h"

void onShootDuck(t_system *system, t_scene **scenes)
{
    int i = 0;

    /* Check if Game Scene */
    if (system->state != GAMESCENE)
        return;
    /* Mouse click event */
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfFalse)
        return;
    while (i < GAME_MAX_DUCKS) {
        if (click_on_sprite(scenes[GAMESCENE]->ducks[i]->image->sprite, system->window->window)) {
            updateScore(scenes[GAMESCENE], 1);
            resetDuck(scenes[GAMESCENE]->ducks[i], system->window->window);
        }
        i += 1;
    }
}

void onPlay(t_system *system, t_scene **scenes)
{
    if (system->state != MENUSCENE)
        return;
    if (mouse_on_text(scenes[MENUSCENE]->texts[MENU_PLAY]->text, system->window->window))
        sfText_setColor(scenes[MENUSCENE]->texts[MENU_PLAY]->text, sfRed);
    else
        sfText_setColor(scenes[MENUSCENE]->texts[MENU_PLAY]->text, sfWhite);
    if (click_on_text(scenes[MENUSCENE]->texts[MENU_PLAY]->text, system->window->window))
        system->state = GAMESCENE;
}

void onClose(t_system *system, __UNUSED__ t_scene **scenes)
{
    /* Close window : exit */
    if (system->event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape)) {
        sfRenderWindow_close(system->window->window);
        system->state = QUIT;
    }
}

void (*checkEvent[NUMEVENT])(t_system*, t_scene**) = {
    onClose,
    onShootDuck,
    onPlay
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