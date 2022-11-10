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

    #include "object.h"

    typedef struct s_MenuSceneClass {

        /* Inheritance */
        ISceneClass iScene;

        /* Special Definition*/
    } MenuSceneClass;

    extern const Class *MenuScene;

    #define MENU_IMAGENUMBER    1

    #define MENU_BACKGROUND      0
    #define MENU_BACKGROUND_PATH "assets/images/gameScene/background.png"

#endif /* !MENUSCENE_H_ */