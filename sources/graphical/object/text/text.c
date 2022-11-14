/*
** Description:
** Text's class definition
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#include "new.h"
#include "raise.h"
#include "array.h"

#include "text.h"

static void Text_display(TextClass *this, sfRenderWindow *window)
{
    sfRenderWindow_drawText(window, this->text, NULL);
}

static void Text_ctor(TextClass *this, va_list *args)
{
    // Initialize internal resources
    if (!(this->content = strdup(va_arg(*args, char*))))
        raise("Can't duplicate content");
    this->size = va_arg(*args, unsigned int);
    this->position = va_arg(*args, sfVector2f);
    this->color = va_arg(*args, sfColor);
    if (!(this->font = sfFont_createFromFile(va_arg(*args, char*))))
        raise("Can't create Sprite");
    if (!(this->text = sfText_create()))
        raise("Can't create sfText");
    // Set text settings
    sfText_setString(this->text, this->content);
    sfText_setPosition(this->text, this->position);
	sfText_setColor(this->text, this->color);
    sfText_setFont(this->text, this->font);
    sfText_setCharacterSize(this->text, this->size);

    printf("Text()\n");
}

static void Text_dtor(TextClass *this)
{
    // Release internal resources
    if (!this)
        return;
    free(this->content);
    if (this->text)
        sfText_destroy(this->text);
    if (this->font)
        sfFont_destroy(this->font);

    printf("~Text()\n");
}

static const TextClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(TextClass),
        .__name__ = "Text",
        .__ctor__ = (ctor_t)&Text_ctor,
        .__dtor__ = (dtor_t)&Text_dtor,
        .__str__ = NULL,
        .__add__ = NULL,
        .__sub__ = NULL,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .content = NULL,
    .size = 0,
    .font = NULL,
    .text = NULL,
    /* Methods definitions */
    .__display__ = &Text_display,
};

const Class *Text = (const Class *)&_description;