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

    #define SCENENUMBER     1

    #define I_MENUSCENE     0
    #define I_GAMESCENE     1

    extern const Class *SceneManager;

    # define createscene(c, ...)    ((Container *)c)->__setitem__(c, __VA_ARGS__)

#endif /* !SCENEMANAGER_H_ */