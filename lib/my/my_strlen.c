/*
** Description:
** Count string characters
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#include <unistd.h>

size_t my_strlen(char const *str)
{
    int i = 0;

    while (str[i])
        i += 1;
    return (i);
}