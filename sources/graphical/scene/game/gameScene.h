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
    #define GAME_IMAGENUMBER    5

    #define GAME_BACKGROUND         0
    #define GAME_BACKGROUND_PATH    "assets/images/gameScene/background.png"
    #define GAME_TILES              1
    #define GAME_TILES_PATH         "assets/images/gameScene/tiles.png"
    #define GAME_ATH                2
    #define GAME_ATH_PATH           "assets/images/gameScene/ath.png"
    #define GAME_AMMO               3
    #define GAME_AMMO_PATH           "assets/images/gameScene/ammo.png"
    #define GAME_WDUCK              4
    #define GAME_WDUCK_PATH         "assets/images/gameScene/ducks.png"

    /* TEXTS */
    #define GAME_TEXTNUMBER     6

    #define GAME_HIT_LABEL          0
    #define GAME_SCORE_LABEL        1
    #define GAME_SCORE              2
    #define GAME_ROUND_LABEL        3
    #define GAME_ROUND              4
    #define GAME_SHOT               5

    #define GAME_FONT_PATH "assets/fonts/m29.ttf"

    /* SOUNDS */
    #define GAME_SOUNDNUMBER     0

#endif /* !GAMESCENE_H_ */