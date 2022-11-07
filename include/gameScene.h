/*
** Description:
** Game scene values
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#ifndef GAMESCENE_H_
    #define GAMESCENE_H_

    #include <stdio.h>
    #include "duck.h"
    #include "scene.h"

    #define GAME_MAX_DUCKS       5

    /* IMAGES */

    #define GAME_IMAGENUMBER     2

    #define GAME_BACKGROUND      0
    #define GAME_BACKGROUND_PATH "assets/images/gameScene/background.png"

    /* SOUNDS */

    #define GAME_SOUNDNUMER      0

    /* TEXTS */

    #define GAME_TEXTNUMBER      2

    #define GAME_FONT_PATH       "assets/fonts/VarelaRound-Regular.ttf"

    #define GAME_SCORE_LABEL     0
    #define GAME_SCORE           1

    void updateScore(t_scene *scene, int score);
    t_scene *initGameScene(const sfRenderWindow *window);

#endif /* !GAMESCENE_H_ */