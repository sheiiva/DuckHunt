/*
** Description:
** Window's class definition
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#include "new.h"
#include "raise.h"

#include "window.h"

static sfBool Window_isOpen(WindowClass *this)
{
    return sfRenderWindow_isOpen(this->window);
}

void Window_clear(WindowClass *this)
{
    sfRenderWindow_clear(this->window, sfBlack);
}

void Window_display(WindowClass *this)
{
    sfRenderWindow_display(this->window);
}

static void Window_ctor(WindowClass *this, va_list *args)
{
    (void)args;

    // Initialize internal resources
    this->mode = (sfVideoMode){1280, 800, 32};
    this->window = sfRenderWindow_create(this->mode, "Duck Hunt", sfResize | sfClose, NULL);
    if (!this->window)
        raise("Cannot create window.");

    sfRenderWindow_setMouseCursorVisible(this->window, sfFalse);
    sfRenderWindow_setFramerateLimit(this->window, FRAMERATE);

    printf("Window()\n");
}

static void Window_dtor(WindowClass *this)
{
    // Release internal resources
    if (this->window)
        sfRenderWindow_destroy(this->window);

    printf("~Window()\n");
}

static const WindowClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(WindowClass),
        .__name__ = "Window",
        .__ctor__ = (ctor_t)&Window_ctor,
        .__dtor__ = (dtor_t)&Window_dtor,
        .__str__ = NULL,
        .__add__ = NULL,
        .__sub__ = NULL,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .window = NULL,
    /* Methods definitions */
    .__clear__ =    &Window_clear,
    .__display__ =  &Window_display,
    .__isOpen__ =   &Window_isOpen,
};

const Class *Window = (const Class *)&_description;