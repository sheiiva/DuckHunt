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

    typedef struct s_SystemClass {

        /* Inheritance */
        Class base;

        /* Special Definition*/
        int     state;
        Object* window;
        Object* clock;
        Object* sceneManager;
        sfEvent event;

        /* Methods definitions*/
        void    (*__gameLoop__)(struct s_SystemClass*);
        void    (*__display__)(struct s_SystemClass*);
    } SystemClass;

    extern const Class *System;

    #define displaySystem(c)        ((SystemClass*)c)->__display__(c)
    #define gameLoop(c)             ((SystemClass*)c)->__gameLoop__(c)

    enum _GAMESTATE {
        QUIT=       -1,
        MENUSCENE=  0,
        GAMESCENE=  1,
    };

    #define TIMEREFRESH 0.1

#endif /* !SYSTEM_H_ */