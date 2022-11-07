/*
** Description:
** Sources' Prototypes
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#ifndef SOURCE_H_
    #define SOURCE_H_

    #include <stdlib.h>
    #include "event.h"

    void destroyAll(t_system *system, t_scene **scenes);
    void updateCrossAirPosition(t_system *system, t_scene **scenes);

    #define CROSS_WIDTH 45
    #define CROSSAIR        1
    #define CROSSAIR_PATH "assets/images/gameScene/crossair.png"

#endif /* !SOURCE_H_ */