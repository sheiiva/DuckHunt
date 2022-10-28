/*
** Description:
** Image Manager
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#include "image.h"
#include "my.h"

void destroyImage(t_image *image)
{
    free(image->source);
    if (image->texture)
        sfTexture_destroy(image->texture);
    if (image->sprite)
        sfSprite_destroy(image->sprite);
}

void destroyImages(t_image **image)
{
    int i = 0;

    while (image[i]) {
        destroyImage(image[i]);
        i += 1;
    }
}

t_image *createImage(char const *path)
{
    t_image *image = malloc(sizeof(t_image));

    if (!image)
        return (NULL);
    image->source = my_strdup(path);
    if (!image->source) {
        destroyImage(image);
        return (NULL);
    }
    image->texture = sfTexture_createFromFile(path, NULL);
    if (!image->texture) {
        destroyImage(image);
        return (NULL);
    }
    image->sprite = sfSprite_create();
    if (!image->sprite) {
        destroyImage(image);
        return (NULL);
    }
    sfSprite_setTexture(image->sprite, image->texture, sfTrue);
    return (image); 
}
