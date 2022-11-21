/*
** Description:
** Scene Interface structure
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#ifndef ISCENE_H_
    #define ISCENE_H_

    #include "object.h"

    #include <SFML/Graphics.h>

    #include "eventManager.h"

    typedef struct s_EventManagerClass EventManagerClass;
    typedef struct s_SystemClass SystemClass;

    typedef struct s_ISceneClass {

        /* Inheritance */
        Class base;

        /* Special Definition*/
        Object*     images;
        Object*     texts;
        Object*     sounds;

        EventManagerClass* eventManager;

        /* Methods definitions */
        void    (*__display__)(struct s_ISceneClass*, sfRenderWindow*);
        void    (*__process__)(struct s_ISceneClass*, SystemClass*);
    } ISceneClass;

    #define displayScene(s, w)      ((ISceneClass*)s)->__display__(s, w)
    #define processScene(s, sys)    ((ISceneClass*)s)->__process__(s, sys)

    extern const Class *IScene;

#endif /* !ISCENE_H_ */