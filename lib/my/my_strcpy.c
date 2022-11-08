/*
** Description:
** Copy a string content
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#include "my.h"

char *my_strcpy(char *dest, const char *src)
{
    size_t i = 0;

    while (src[i]) {
        dest[i] = src[i];
        i += 1;
    }
    return (dest);
}