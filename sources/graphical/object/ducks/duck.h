/*
** Description:
** Duck's structure
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#ifndef DUCK_H_
    #define DUCK_H_

    #include "object.h"
    #include "image.h"

    typedef struct s_DuckClass {

        /* Inheritance */
        Class base;

        /* Special Definition*/
        ImageClass*     image;
        sfVector2f      direction;
        unsigned int    speed;

        /* Methods definitions */
        void (*__display__)(struct s_DuckClass*, sfRenderWindow*);
        void (*__move__)(struct s_DuckClass*);
    } DuckClass;

    #define displayDuck(d, w)   ((DuckClass*)d)->__display__(i, w)
    #define moveDuck(d)         ((DuckClass*)d)->__move__(d)

    extern const Class *Duck;

    #define DUCK_PATH       "assets/images/gameScene/duck.png"
    #define DUCK_IMSIZE     110

    #define MINSPEED    15
    #define MAXSPEED    20

#endif /* !DUCK_H_ */