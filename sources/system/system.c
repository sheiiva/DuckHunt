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

#include "clock.h"

typedef struct s_class {

    /* Inheritance */
    Class base;

    /* Special Defintion*/
    Object *clock;
    sfEvent event;
    int state;
} SystemClass;

static void System_ctor(SystemClass *this, va_list *args)
{
    (void)args;

    // Initialize internal resources
    this->clock = new(Clock);
    this->state = MENUSCENE;

    printf("System()\n");
}

static void System_dtor(SystemClass *this)
{
    // Release internal resources
    delete(this->clock);

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
    .clock = NULL,
    .state = 0
};

const Class *System = (const Class *)&_description;