/*
** Description:
** EventManager's class Definition
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#include "new.h"
#include "system.h"
#include "eventManager.h"

// void onClose(SystemClass *system)
// {
//     /* Close window : exit */
//     if (system->EventManager.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape)) {
//         sfRenderWindow_close(system->window->window);
//         system->state = QUIT;
//     }
// }

static void EventManager_handleEvents(EventManagerClass *this, SystemClass *system)
{
    while (sfRenderWindow_pollEvent(system->window->window, &(this->event))) {
        if (this->event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape)) {
            sfRenderWindow_close(system->window->window);
            system->state = QUIT;
        }
    }
}

static void EventManager_ctor(EventManagerClass *this, va_list *args)
{
    (void)this;
    (void)args;

    printf("EventManager()\n");
}

static void EventManager_dtor(EventManagerClass *this)
{
    // Release internal resources
    (void)this;

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
    .__getEvent__ = &EventManager_handleEvents,
};

const Class *EventManager = (const Class *)&_description;