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

#include "menuScene.h"
#include "image.h"
#include "text.h"
#include "eventManager.h"
#include "eventOnClose.h"
#include "eventOnPlayButton.h"

static void MenuScene_display(ISceneClass *this, sfRenderWindow* window)
{
    for (size_t i = 0; i < len(this->images); i++)
        displayImage(getitem(this->images, i), window);
    for (size_t i = 0; i < len(this->texts); i++)
        displayText(getitem(this->texts, i), window);
}

static void MenuScene_ctor(MenuSceneClass *this, __UNUSED__ va_list *args)
{
    /* Create event Array */
    this->iScene.eventManager = new(EventManager, MENU_EVENTNUMBER);
    createEvent(this->iScene.eventManager->eventArray, 0, EventOnClose);
    createEvent(this->iScene.eventManager->eventArray, 1, EventOnPlayButton);

    /* Create images Array */
    this->iScene.images = new(Array, MENU_IMAGENUMBER, Image
    );
    /* Create texts Array */
    this->iScene.texts = new(Array, MENU_TEXTNUMBER, Text,
        "Duck\n  Hunt",     150,    (sfVector2f){290, 100}, BLUE, MENU_FONT_PATH,
        "PLAY",             50,     (sfVector2f){540, 500}, ORANGE, MENU_FONT_PATH,
        "CC 2022 SHEIIVA",  20,     (sfVector2f){510, 350}, WHITE, MENU_FONT_PATH
    );
    /* Create sounds Array */

    printf("MenuScene()\n");
}

static void MenuScene_dtor(MenuSceneClass *this)
{
    // Release internal resources
    delete(this->iScene.images);
    delete(this->iScene.eventManager);
    delete(this->iScene.texts);
    // delete(this->iScene.sounds);
    printf("~MenuScene()\n");
}

static const MenuSceneClass _description = {
    { /* IScene struct */
        {   /* Class struct */
            .__size__ = sizeof(MenuSceneClass),
            .__name__ = "MenuScene",
            .__ctor__ = (ctor_t)&MenuScene_ctor,
            .__dtor__ = (dtor_t)&MenuScene_dtor,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = NULL,
            .__gt__ = NULL,
            .__lt__ = NULL
        },
        .images = NULL,
        .texts = NULL,
        .sounds = NULL,
        .eventManager = NULL,
        /* Methods definitions */
        .__display__ = &MenuScene_display,
    }
};

const Class *MenuScene = (const Class *)&_description;