/*
** Description:
** Game Images' structure
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#ifndef IMAGE_H_
    #define IMAGE_H_

    #include <SFML/Graphics.h>

    typedef struct s_image {
        char *source;
        sfTexture *texture;
        sfSprite *sprite;
    } t_image;

    void destroyImage(t_image *image);
    void destroyImages(t_image **image);
    t_image *createImage(char const *path);

#endif /* !IMAGE_H_ */