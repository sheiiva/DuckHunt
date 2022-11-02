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
    memset(new, '\0', len+1);
    return (my_strcpy(new, s));
}