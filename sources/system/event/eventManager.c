/*
** Description:
** EventManager's class Definition
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#include "new.h"
#include "eventManager.h"

#include "eventOnClose.h"

static void EventManager_handleEvents(EventManagerClass *this, SystemClass *system)
{
    while (sfRenderWindow_pollEvent(system->window->window, &(this->event))) {
        for (size_t i = 0; i < len(this->eventArray); i++)
            runEvent(getitem(this->eventArray, i), this, system);
    }
}

static void EventManager_ctor(EventManagerClass *this, va_list *args)
{
    this->eventArray = new(Array, va_arg(*args, size_t), IEvent);

    printf("EventManager()\n");
}

static void EventManager_dtor(EventManagerClass *this)
{
    // Release internal resources
    (void)this;

    delete(this->eventArray);
    printf("~EventManager()\n");
}

static const EventManagerClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(EventManagerClass),
        .__name__ = "EventManager",
        .__ctor__ = (ctor_t)&EventManager_ctor,
        .__dtor__ = (dtor_t)&EventManager_dtor,
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
    .__handleEvents__ = &EventManager_handleEvents,
};

const Class *EventManager = (const Class *)&_description;