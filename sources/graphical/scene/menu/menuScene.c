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

#include "iScene.h"
#include "menuScene.h"

typedef struct s_class {

    /* Inheritance */
    ISceneClass iScene;

    /* Special Definition*/
} MenuSceneClass;

static void MenuScene_ctor(MenuSceneClass *this, va_list *args)
{
    (void)this;
    (void)args;
    // Initialize internal resources

    printf("MenuScene()\n");
}

static void MenuScene_dtor(MenuSceneClass *this)
{
    (void)this;
    // Release internal resources

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
    }
};

const Class *MenuScene = (const Class *)&_description;