/*
** Description:
** Event OnPlayButton structure
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#ifndef EVENTONPLAYBUTTON_H_
    #define EVENTONPLAYBUTTON_H_

    #include "iEvent.h"

    typedef struct s_EventOnPlayButtonClass {

        /* Inheritance */
        IEventClass iEvent;

        /* Special Definition*/
    } EventOnPlayButtonClass;

    extern const Class *EventOnPlayButton;

#endif /* !EVENTONPLAYBUTTON_H_ */