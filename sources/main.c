/*
** Description:
** Main Function
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#include "new.h"
#include "clock.h"

int main(void)
{
    Object *clock = new(Clock);

    delete(clock);
    return (0);
}