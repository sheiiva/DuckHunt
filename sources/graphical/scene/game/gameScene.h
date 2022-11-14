/*
** Description:
** Game Scene structure
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#ifndef GAMESCENE_H_
    #define GAMESCENE_H_

    #include "iScene.h"

    typedef struct s_GameSceneClass {

        /* Inheritance */
        ISceneClass iScene;

        /* Special Definition*/
    } GameSceneClass;

    extern const Class *GameScene;

    #define GAME_EVENTNUMBER    1

    /* IMAGES */
    #define GAME_IMAGENUMBER    1

    #define GAME_BACKGROUND     0
    #define GAME_BACKGROUND_PATH "assets/images/gameScene/background.png"

    /* TEXTS */
    #define GAME_TEXTNUMBER     0

    #define GAME_FONT_PATH "assets/fonts/m29.ttf"

    /* SOUNDS */
    #define GAME_SOUNDNUMBER     0

#endif /* !GAMESCENE_H_ */