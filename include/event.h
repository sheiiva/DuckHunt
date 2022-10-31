/*
** Description:
** Event's structure
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#ifndef EVENT_H_
    #define EVENT_H_

    #include "system.h"

    #define NUMEVENT    1

    void evenManager(t_system *system);

    void onClose(t_system *system);

#endif /* !EVENT_H_ */