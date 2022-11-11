/*
** Description:
** Scene's Interface class definition
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#include "iScene.h"

static const ISceneClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(ISceneClass),
        .__name__ = "IScene",
        .__ctor__ = NULL,
        .__dtor__ = NULL,
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
    /* Methods definitions */
    .__display__ = NULL,
};

const Class *IScene = (const Class *)&_description;