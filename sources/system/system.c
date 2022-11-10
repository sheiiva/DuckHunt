/*
** Description:
** System's class Definition
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#include "new.h"
#include "system.h"

#include "window.h"
#include "clock.h"
#include "sceneManager.h"

typedef struct s_class {

    /* Inheritance */
    Class base;

    /* Special Definition*/
    int     state;
    Object* window;
    Object* clock;
    Object* sceneManager;
    sfEvent event;
} SystemClass;

static void System_ctor(SystemClass *this, va_list *args)
{
    (void)args;

    // Initialize internal resources
    this->state = MENUSCENE;
    this->window = new(Window);
    this->clock = new(Clock);
    this->sceneManager = new(SceneManager);

    printf("System()\n");
}

static void System_dtor(SystemClass *this)
{
    // Release internal resources
    delete(this->window);
    delete(this->clock);
    delete(this->sceneManager);

    printf("~System()\n");
}

static const SystemClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(SystemClass),
        .__name__ = "System",
        .__ctor__ = (ctor_t)&System_ctor,
        .__dtor__ = (dtor_t)&System_dtor,
        .__str__ = NULL,
        .__add__ = NULL,
        .__sub__ = NULL,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .state = 0,
    .window = NULL,
    .clock = NULL,
    .sceneManager = NULL,
};

const Class *System = (const Class *)&_description;