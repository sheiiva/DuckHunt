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

    #include <stdlib.h>
    #include <SFML/Graphics.h>

    #include "image.h"

    #define DUCK_IMSIZE 110

    #define MINSPEED    4
    #define MAXSPEED    20

    #define POPMARGIN   100

    // int direction;

    #define DUCK_PATH "assets/images/gameScene/duck.png"

    typedef struct s_duck {
        int offset;
        int speed;
        sfIntRect rect;
        t_image *image;
    } t_duck;

    t_duck **createDuckArray(size_t size);
    t_duck *createDuck();
    void drawDucks(sfRenderWindow* window, t_duck **ducks);
    void drawDuck(sfRenderWindow* window, t_duck *duck);
    void destroyDucks(t_duck **ducks);
    void destroyDuck(t_duck *duck);
    t_duck *updateDuckPosition(t_duck *duck);
    t_duck **updateDucksPosition(t_duck **ducks);
    void resetDuck(t_duck *duck, const sfRenderWindow *window);

#endif /* !DUCK_H_ */