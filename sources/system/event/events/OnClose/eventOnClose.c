/*
** Description:
** Scene's Interface class definition
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#include "new.h"
#include "raise.h"
#include "array.h"

#include "eventOnClose.h"

void EventOnClose_run(IEventClass *this, EventManagerClass *eventManager, SystemClass* system)
{
    (void)this;

    if (eventManager->event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape)) {
        sfRenderWindow_close(system->window->window);
        system->state = QUIT;
    }
}

static void EventOnClose_ctor(EventOnCloseClass *this, va_list *args)
{
    (void)this;
    (void)args;

    printf("~EventOnClose()\n");
}

static void EventOnClose_dtor(EventOnCloseClass *this)
{
    (void)this;

    printf("~EventOnClose()\n");
}

static const EventOnCloseClass _description = {
    { /* IEvent struct */
        {   /* Class struct */
            .__size__ = sizeof(EventOnCloseClass),
            .__name__ = "EventOnClose",
            .__ctor__ = (ctor_t)&EventOnClose_ctor,
            .__dtor__ = (dtor_t)&EventOnClose_dtor,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = NULL,
            .__gt__ = NULL,
            .__lt__ = NULL
        },
        /* Methods definitions */
        .__run__ = &EventOnClose_run,
    }
};

const Class *EventOnClose = (const Class *)&_description;