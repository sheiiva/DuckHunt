/*
** Description:
** Main Function
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#include "new.h"
#include "system.h"

int main(void)
{
    Object *system = new(System);

    delete(system);
    return (0);
}