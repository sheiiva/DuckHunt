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

static void System_display(SystemClass *this, ISceneClass *currentScene)
{
    displayScene(currentScene, this->window->window);
    displayWindow(this->window);
}

static void System_gloop(SystemClass *this)
{
    ISceneClass *currentScene = (ISceneClass *)getitem(this->sceneManager->scenesArray, this->state);

    while (isWindowOpen(this->window) && (this->state != QUIT)) {
        currentScene = (ISceneClass *)getitem(this->sceneManager->scenesArray, this->state);
        clearWindow(this->window);
        displaySystem(this, currentScene);
        handleEvents(currentScene->eventManager, this);
        //process
    }
}

static void System_ctor(SystemClass *this, __UNUSED__ va_list *args)
{
    // Initialize internal resources
    this->state = MENUSCENE;
    this->window = new(Window);
    this->clock = new(Clock);
    this->sceneManager = new(SceneManager, this->window->window);

    printf("System()\n");

    gameLoop(this);
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
    /* Methods definitions */
    .__display__ = &System_display,
    .__gameLoop__ = &System_gloop,
};

const Class *System = (const Class *)&_description;