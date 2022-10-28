/*
** Description:
** Duplicate a string (malloc)
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#include "my.h"

char *my_strdup(const char *s)
{
    size_t len = my_strlen(s);
    char *new = malloc(sizeof(char) * (len + 1));

    if (!new)
        return (NULL);
    return (my_strcpy(new, s));
}