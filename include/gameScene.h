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

    #include "duck.h"
    #include "scene.h"

    #define MAX_DUCKS       5

    /* IMAGES */

    #define IMAGENUMBER     2

    #define BACKGROUND      0
    #define BACKGROUND_PATH "assets/images/gameScene/background.png"

    /* SOUNDS */

    #define SOUNDNUMER      0

    /* TEXTS */

    #define TEXTNUMBER      2

    #define FONT_PATH       "assets/fonts/VarelaRound-Regular.ttf"

    #define SCORE_LABEL     0
    #define SCORE           1

    void updateScore(t_scene *scene, int score);

#endif /* !GAMESCENE_H_ */