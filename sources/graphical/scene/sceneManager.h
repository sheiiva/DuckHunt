/*
** Description:
** Scene Manager's structure
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#ifndef SCENEMANAGER_H_
    #define SCENEMANAGER_H_

    #include <SFML/Window.h>
    #include <SFML/Graphics.h>

    #include "object.h"
    #include "array.h"

    typedef struct s_SceneManagerClass {

        /* Inheritance */
        Class base;

        /* Special Definition*/
        Object*     scenesArray;
    } SceneManagerClass;

    extern const Class *SceneManager;

    #define createscene(c, ...) ((Container*)c)->__setitem__(c, __VA_ARGS__)

    #define SCENENUMBER     2

    #define I_MENUSCENE     0
    #define I_GAMESCENE     1

#endif /* !SCENEMANAGER_H_ */