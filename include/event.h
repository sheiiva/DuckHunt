/*
** Description:
** Event event's structure
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#ifndef EVENT_H_
    #define EVENT_H_

    #include "system.h"

    #define QUIT    0
    #define RUN     1

    #define NUMEVENT    1

    void evenManager(t_system *system);

    void onClose(t_system *system);

#endif /* !EVENT_H_ */