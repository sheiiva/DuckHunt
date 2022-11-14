/*
** Description:
** Menu Scene structure
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#ifndef MENUSCENE_H_
    #define MENUSCENE_H_

    #include "iScene.h"

    typedef struct s_MenuSceneClass {

        /* Inheritance */
        ISceneClass iScene;

        /* Special Definition*/
    } MenuSceneClass;

    extern const Class *MenuScene;

    #define MENU_EVENTNUMBER    2

    /* IMAGES */
    #define MENU_IMAGENUMBER    1

    #define MENU_SEP     0
    #define MENU_SEP_PATH "assets/images/menuScene/sep.png"

    /* TEXTS */
    #define MENU_TEXTNUMBER     4

    #define MENU_TITLE          0
    #define MENU_TITLE2         1
    #define MENU_PLAYBUTTON     2
    #define MENU_CREDITS        3

    #define MENU_FONT_PATH "assets/fonts/m29.ttf"

    /* SOUNDS */
    #define MENU_SOUNDNUMBER     0

#endif /* !MENUSCENE_H_ */