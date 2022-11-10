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

    typedef struct s_ISceneClass {

        /* Inheritance */
        Class base;

        /* Special Definition*/
        Object*     images;
        Object*     texts;
        Object*     sounds;
    } ISceneClass;

    extern const Class *IScene;

#endif /* !ISCENE_H_ */