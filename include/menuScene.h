/*
** Description:
** Game scene values
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#ifndef MENUSCENE_H_
    #define MENUSCENE_H_

    #include <stdio.h>
    #include "scene.h"

    /* IMAGES */

    #define MENU_IMAGENUMBER     1

    #define MENU_BACKGROUND      0
    #define MENU_BACKGROUND_PATH "assets/images/gameScene/background.png"

    /* SOUNDS */

    #define MENU_SOUNDNUMER      0

    /* TEXTS */

    #define MENU_TEXTNUMBER      0

    #define MENU_FONT_PATH       "assets/fonts/VarelaRound-Regular.ttf"

    #define MENU_TITLE          0
    #define MENU_TITLE_LABEL    "DUCK HUNT"

    #define MENU_PLAY           1
    #define MENU_PLAY_LABEL           "PLAY"

    t_scene *initMenuScene(const sfRenderWindow *window);

#endif /* !MENUSCENE_H_ */