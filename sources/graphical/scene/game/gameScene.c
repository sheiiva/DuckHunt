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

#include "gameScene.h"
#include "image.h"
#include "text.h"
#include "eventManager.h"
#include "eventOnClose.h"

static void GameScene_display(ISceneClass *this, sfRenderWindow* window)
{
    for (size_t i = 0; i < len(this->images); i++)
        displayImage(getitem(this->images, i), window);
    // for (size_t i = 0; i < len(this->texts); i++)
    //     displayText(getitem(this->texts, i), window);
}

static void GameScene_ctor(GameSceneClass *this, __UNUSED__ va_list *args)
{
    /* Create event Array */
    this->iScene.eventManager = new(EventManager, GAME_EVENTNUMBER);
    createEvent(this->iScene.eventManager->eventArray, 0, EventOnClose);

    /* Create images Array */
    this->iScene.images = new(Array, GAME_IMAGENUMBER, Image,
        GAME_BACKGROUND_PATH, (sfVector2f){0, 0},
        GAME_ATH_PATH, (sfVector2f){0, 50}
    );
    /* Create texts Array */
    this->iScene.texts = new(Array, GAME_TEXTNUMBER, Text
    );
    /* Create sounds Array */

    printf("GameScene()\n");
}

static void GameScene_dtor(GameSceneClass *this)
{
    // Release internal resources
    delete(this->iScene.images);
    delete(this->iScene.eventManager);
    // delete(this->iScene.texts);
    // delete(this->iScene.sounds);
    printf("~GameScene()\n");
}

static const GameSceneClass _description = {
    { /* IScene struct */
        {   /* Class struct */
            .__size__ = sizeof(GameSceneClass),
            .__name__ = "GameScene",
            .__ctor__ = (ctor_t)&GameScene_ctor,
            .__dtor__ = (dtor_t)&GameScene_dtor,
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
        .__display__ = &GameScene_display,
    }
};

const Class *GameScene = (const Class *)&_description;