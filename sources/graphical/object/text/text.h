/*
** Description:
** Scene's Text structure
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#ifndef TEXT_H_
    #define TEXT_H_

    #include <SFML/Window.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>

    #include <string.h>

    #include "object.h"

    typedef struct s_TextClass {

        /* Inheritance */
        Class base;

        /* Special Definition*/
        char*           content;
        unsigned int    size;
        sfVector2f      position;
        sfColor         color;
        sfFont*         font;
        sfText*         text;

        /* Methods definitions */
        void (*__display__)(struct s_TextClass*, sfRenderWindow*);
    } TextClass;

    #define displayText(t, w) ((TextClass*)t)->__display__(t, w)

    #define ORANGE  (sfColor){255, 140, 0, 255}
    #define YELLOW  (sfColor){255, 255, 0, 255}
    #define PURPLE  (sfColor){128, 0, 128, 255}
    #define RED     sfRed
    #define GREEN   sfGreen
    #define BLUE    sfBlue
    #define BLACK   sfBlack
    #define WHITE   sfWhite

    extern const Class *Text;

#endif /* !TEXT_H_ */