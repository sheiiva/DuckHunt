/*
** Description:
** Print a character
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/Radar
**
*/

#include "my.h"

void *my_memset(void *s, int c, size_t n)
{
    size_t i = 0;

    while (i < n) {
        ((char*)s)[i] = c;
        i += 1;
    }
    return (s);
}