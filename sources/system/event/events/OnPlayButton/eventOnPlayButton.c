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

#include "eventOnPlayButton.h"
#include "menuScene.h"
#include "text.h"

void EventOnPlayButton_run(__UNUSED__ IEventClass *this, __UNUSED__ EventManagerClass *eventManager, SystemClass* system)
{
    ISceneClass *currentScene = (ISceneClass*)getitem(system->sceneManager->scenesArray, I_MENUSCENE);
    TextClass *text =  (TextClass*)getitem(currentScene->texts, MENU_PLAYBUTTON);

    if (text->__mouseOnText__(text, system->window->window))
        setColor(text, RED);
    else
        setColor(text, ORANGE);
    if (text->__clickOnText__(text, system->window->window))
        system->state = I_GAMESCENE;
}

static void EventOnPlayButton_ctor(__UNUSED__ EventOnPlayButtonClass *this, __UNUSED__ va_list *args)
{
    printf("~EventOnPlayButton()\n");
}

static void EventOnPlayButton_dtor(__UNUSED__ EventOnPlayButtonClass *this)
{
    printf("~EventOnPlayButton()\n");
}

static const EventOnPlayButtonClass _description = {
    { /* IEvent struct */
        {   /* Class struct */
            .__size__ = sizeof(EventOnPlayButtonClass),
            .__name__ = "EventOnPlayButton",
            .__ctor__ = (ctor_t)&EventOnPlayButton_ctor,
            .__dtor__ = (dtor_t)&EventOnPlayButton_dtor,
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
        .__run__ = &EventOnPlayButton_run,
    }
};

const Class *EventOnPlayButton = (const Class *)&_description;