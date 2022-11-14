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

#include "sceneManager.h"
#include "iScene.h"
#include "menuScene.h"
#include "gameScene.h"

static void SceneManager_ctor(SceneManagerClass *this, va_list *args)
{
    // Initialize internal resources
    this->scenesArray = new(Array, SCENENUMBER, IScene);

    createscene(this->scenesArray, I_MENUSCENE, MenuScene, va_arg(*args, sfRenderWindow *));
    createscene(this->scenesArray, I_GAMESCENE, GameScene, va_arg(*args, sfRenderWindow *));

    printf("SceneManager()\n");
}

static void SceneManager_dtor(SceneManagerClass *this)
{
    // Release internal resources
    for (size_t i = 0; i < len(this->scenesArray); i++)
        delete(getitem(this->scenesArray, i));

    printf("~SceneManager()\n");
}

static const SceneManagerClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(SceneManagerClass),
        .__name__ = "SceneManager",
        .__ctor__ = (ctor_t)&SceneManager_ctor,
        .__dtor__ = (dtor_t)&SceneManager_dtor,
        .__str__ = NULL,
        .__add__ = NULL,
        .__sub__ = NULL,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .scenesArray = NULL
};

const Class *SceneManager = (const Class *)&_description;