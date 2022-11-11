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

    #include "object.h"

    typedef struct s_ImageClass {

        /* Inheritance */
        Class base;

        /* Special Definition*/
        char*       filePath;
        sfTexture*  texture;
        sfSprite*   sprite;
        sfVector2f  position;

        /* Methods definitions */
        void (*__display__)(struct s_ImageClass*, sfRenderWindow*);
    } ImageClass;

    #define displayImage(i, w) ((ImageClass*)i)->__display__(i, w)

    extern const Class *Image;

#endif /* !IMAGE_H_ */