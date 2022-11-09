/*
** Description:
** System's structure
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#ifndef SYSTEM_H_
    #define SYSTEM_H_

    #include <SFML/Audio.h>
    #include <SFML/Window.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>

    #include "object.h"

    #define TIMEREFRESH 0.1

    enum _GAMESTATE {
        QUIT=       -1,
        MENUSCENE=  0,
        GAMESCENE=  1,
    };

    extern const Class *System;

#endif /* !SYSTEM_H_ */