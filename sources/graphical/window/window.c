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

typedef struct s_class {

    /* Inheritance */
    Class base;

    /* Special Definition*/
    sfVideoMode mode;
    sfRenderWindow* window;
} WindowClass;

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
};

const Class *Window = (const Class *)&_description;