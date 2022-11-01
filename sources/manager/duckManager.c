/*
** Description:
** Duck Manager
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#include "gameScene.h"
#include "image.h"

#include <stdlib.h>

t_duck *updateDuckSprite(t_duck *duck)
{
    (duck->offset < (3 * DUCK_IMSIZE)) ? (duck->offset += 110) : (duck->offset = 0);

    duck->rect.top = 0;
	duck->rect.left = duck->offset;
	duck->rect.width = DUCK_IMSIZE;
	duck->rect.height = DUCK_IMSIZE;
    sfSprite_setTextureRect(duck->image->sprite, duck->rect);
    return (duck);
}

t_duck *updateDuckPosition(t_duck *duck)
{
    duck->image->position.x += MINSPEED + (rand() % MAXSPEED);
    sfSprite_setPosition(duck->image->sprite, duck->image->position);
    return (duck);
}

t_duck **updateDucksPosition(t_duck **ducks)
{
    int i =  0;

    while (i < MAX_DUCKS) {
        updateDuckSprite(ducks[i]);
        updateDuckPosition(ducks[i]);
        i += 1;
    }
    return (ducks);
}

void destroyDuck(t_duck *duck)
{
    destroyImage(duck->image);
    free(duck);
}

void destroyDucks(t_duck **ducks)
{
    int i = 0;

    while (ducks[i]) {
        destroyDuck(ducks[i]);
        i += 1;
    }
}

void drawDuck(sfRenderWindow* window, t_duck *duck)
{
    drawImage(window, duck->image);
}

void drawDucks(sfRenderWindow* window, t_duck **ducks)
{
    int i = 0;

    while (ducks[i]) {
        drawDuck(window, ducks[i]);
        i += 1;
    }
}

t_duck *createDuck()
{
    t_duck *duck = malloc(sizeof(t_duck));

    if (!duck)
        return (NULL);
    duck->image = createImage(DUCK_PATH, (sfVector2f){0, 0});
    if (!duck->image) {
        destroyDuck(duck);
        return (NULL);
    }
    duck->rect = (sfIntRect){0, duck->offset, DUCK_IMSIZE, DUCK_IMSIZE};
    return (duck); 
}

t_duck **createDuckArray(size_t size)
{
    t_duck **array = malloc(sizeof(t_duck*) * (size + 1));
    size_t i = 0;

    if (!array)
        return (NULL);
    while (i <= size) {
        array[i] = NULL;
        i += 1;
    }
    return (array);
}