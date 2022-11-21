/*
** Description:
** Image's Interface class definition
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#include "new.h"
#include "raise.h"
#include "array.h"

#include "image.h"

static sfVector2f Image_getPosition(ImageClass *this)
{
    return sfSprite_getPosition(this->sprite);
}

static void Image_setPosition(ImageClass *this, sfVector2f position)
{
    sfSprite_setPosition(this->sprite, position);
}

static void Image_setRotation(ImageClass *this, float angle)
{
    sfSprite_setRotation(this->sprite, angle);
}

static void Image_display(ImageClass *image, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, image->sprite, NULL);
}

static void Image_ctor(ImageClass *this, va_list *args)
{
    // Initialize internal resources
    if (!(this->filePath = strdup(va_arg(*args, char*))))
        raise("Can't duplicate path");
    if (!(this->texture = sfTexture_createFromFile(this->filePath, NULL)))
        raise("Can't create Texture from file");
    if (!(this->sprite = sfSprite_create()))
        raise("Can't create Sprite");
    this->position = va_arg(*args, sfVector2f);
    sfSprite_setPosition(this->sprite, this->position);
    sfSprite_setTexture(this->sprite, this->texture, sfTrue);

    printf("Image()\n");
}

static void Image_dtor(ImageClass *this)
{
    // Release internal resources
    free(this->filePath);
    if (this->texture)
        sfTexture_destroy(this->texture);
    if (this->sprite)
        sfSprite_destroy(this->sprite);

    printf("~Image()\n");
}

static const ImageClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(ImageClass),
        .__name__ = "Image",
        .__ctor__ = (ctor_t)&Image_ctor,
        .__dtor__ = (dtor_t)&Image_dtor,
        .__str__ = NULL,
        .__add__ = NULL,
        .__sub__ = NULL,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .filePath = NULL,
    .texture = NULL,
    .sprite = NULL,
    /* Methods definitions */
    .__display__ = &Image_display,
    .__setRotation__ = &Image_setRotation,
    .__setPosition__ = &Image_setPosition,
    .__getPosition__ = &Image_getPosition
};

const Class *Image = (const Class *)&_description;