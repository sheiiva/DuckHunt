/*
** Description:
** Event Interface structure
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#ifndef IEVENT_H_
    #define IEVENT_H_

    #include "object.h"

    #include "eventManager.h"

    typedef struct s_IEventClass {

        /* Inheritance */
        Class base;

        /* Methods definitions */
        void (*__run__)(struct s_IEventClass*, EventManagerClass*, SystemClass*);
    } IEventClass;

    #define runEvent(e, em, s) ((IEventClass*)e)->__run__(e, em, s)

    extern const Class *IEvent;

#endif /* !IEVENT_H_ */