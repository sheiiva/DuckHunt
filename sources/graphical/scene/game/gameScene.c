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
    for (size_t i = 0; i < len(this->texts); i++)
        displayText(getitem(this->texts, i), window);
}

static void GameScene_process(ISceneClass *this, SystemClass *system)
{
    sfTime time = sfClock_getElapsedTime(system->clock->clock);

    if ((time.microseconds / 1000000.0) > TIMEREFRESH) {
        moveDuck(((GameSceneClass*)this)->duck);
        sfClock_restart(system->clock->clock);
    }
}

static void GameScene_ctor(GameSceneClass *this, __UNUSED__ va_list *args)
{

    /* Create event Array */
    this->iScene.eventManager = new(EventManager, GAME_EVENTNUMBER);
    createEvent(this->iScene.eventManager->eventArray, 0, EventOnClose);

    /* Create images Array */
    this->iScene.images = new(Array, GAME_IMAGENUMBER, Image,
        GAME_BACKGROUND_PATH, (sfVector2f){0, 0}, 0, NULL,
        GAME_DUCK_PATH, (sfVector2f){640, 600}, 0, &(sfIntRect){0, 0, DUCK_IMSIZE, DUCK_IMSIZE},
        GAME_TILES_PATH, (sfVector2f){0, 0}, 0, NULL,
        GAME_ATH_PATH, (sfVector2f){0, 50}, 0, NULL,
        GAME_AMMO_PATH, (sfVector2f){225, 705}, 0, NULL,
        GAME_WDUCK_PATH, (sfVector2f){570, 715}, 0, NULL
    );
    /* Duck */
    this->duck = new(Duck, ((Container *)this->iScene.images)->__getitem__(this->iScene.images, GAME_DUCK));

    /* Create texts Array */
    this->iScene.texts = new(Array, GAME_TEXTNUMBER, Text,
        "HIT",          30,    (sfVector2f){440, 715}, GREEN, GAME_FONT_PATH,
        "SCORE",        25,    (sfVector2f){1025, 735}, WHITE, GAME_FONT_PATH,
        "000000",       25,    (sfVector2f){1000, 705}, WHITE, GAME_FONT_PATH,
        "R.",           30,    (sfVector2f){225, 647}, GREEN, GAME_FONT_PATH,
        "1",            30,    (sfVector2f){275, 647}, GREEN, GAME_FONT_PATH,
        "SHOT",         20,    (sfVector2f){225, 740}, BLUE, GAME_FONT_PATH
    );
    /* Create sounds Array */

    printf("GameScene()\n");
}

static void GameScene_dtor(GameSceneClass *this)
{
    // Release internal resources
    delete(this->iScene.images);
    delete(this->iScene.eventManager);
    delete(this->iScene.texts);
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
        .__process__ = &GameScene_process,
    },
    .duck = NULL
};

const Class *GameScene = (const Class *)&_description;