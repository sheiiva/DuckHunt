/*
** Description:
** Scene's Image structure
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#ifndef IMAGE_H_
    #define IMAGE_H_

    #include <SFML/Window.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>

    #include <string.h>
    #include <math.h>

    #include "object.h"

    typedef struct s_ImageClass {

        /* Inheritance */
        Class base;

        /* Special Definition*/
        char*       filePath;
        sfTexture*  texture;
        sfSprite*   sprite;
        sfVector2f  position;
        int         offset;

        /* Methods definitions */
        void (*__display__)(struct s_ImageClass*, sfRenderWindow*);
        void (*__setRotation__)(struct s_ImageClass*, float);
        void (*__setPosition__)(struct s_ImageClass*, sfVector2f);
        void (*__setRect__)(struct s_ImageClass*, sfIntRect);
        sfVector2f (*__getPosition__)(struct s_ImageClass*);
    } ImageClass;

    #define displayImage(i, w)          ((ImageClass*)i)->__display__(i, w)
    #define setImagePosition(i, p)      ((ImageClass*)i)->__setPosition__(i, p)
    #define getImagePosition(i)         ((ImageClass*)i)->__getPosition__(i)
    #define setImageRotation(i, a)      ((ImageClass*)i)->__setRotation__(i, a)
    #define setImageRect(i, r)          ((ImageClass*)i)->__setRect__(i, r)

    #define degToRad(angleInDegrees) ((angleInDegrees) * M_PI / 180.0)
    #define radToDeg(angleInRadians) ((angleInRadians) * 180.0 / M_PI)

    extern const Class *Image;

#endif /* !IMAGE_H_ */