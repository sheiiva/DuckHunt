/*
** Description:
** EventManagerClass's structure
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#ifndef EVENTMANAGER_H_
    #define EVENTMANAGER_H_

    #include <SFML/Audio.h>
    #include <SFML/Window.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>

    #include "object.h"
    #include "system.h"

    typedef struct s_SystemClass SystemClass;

    typedef struct s_EventManagerClass {

        /* Inheritance */
        Class base;

        /* Special Definition*/
        sfEvent         event;

        /* Methods definitions */
        void (*__getEvent__)(struct s_EventManagerClass*,  SystemClass*);
    } EventManagerClass;

    #define handleEvents(e, s) ((EventManagerClass*)e)->__getEvent__(e, s)

    extern const Class *EventManager;

#endif /* !EVENTMANAGER_H_ */