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

static sfBool mouse_on_text(sfText *text, sfRenderWindow *window)
{
    sfFloatRect rect = sfText_getGlobalBounds(text);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if (mouse.x > rect.left && mouse.x < rect.left + rect.width
        && mouse.y > rect.top && mouse.y < rect.top + rect.height)
        return (sfTrue);
    return (sfFalse);
}

static sfBool click_on_text(sfText *text, sfRenderWindow *window)
{
    if (mouse_on_text(text, window) && sfMouse_isButtonPressed(sfMouseLeft))
        return (sfTrue);
    return (sfFalse);
}

void EventOnPlayButton_run(IEventClass *this, EventManagerClass *eventManager, SystemClass* system)
{
    (void)this;
    (void)eventManager;
    //
    ISceneClass *currentScene = (ISceneClass*)getitem(system->sceneManager->scenesArray, MENUSCENE);
    TextClass *text =  (TextClass*)getitem(currentScene->texts, MENU_PLAYBUTTON);

    if (mouse_on_text(text->text, system->window->window))
        setColor(text, RED);
    else
        setColor(text, ORANGE);
    if (click_on_text(text->text, system->window->window))
        system->state = GAMESCENE;
}

static void EventOnPlayButton_ctor(EventOnPlayButtonClass *this, va_list *args)
{
    (void)this;
    (void)args;

    printf("~EventOnPlayButton()\n");
}

static void EventOnPlayButton_dtor(EventOnPlayButtonClass *this)
{
    (void)this;

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