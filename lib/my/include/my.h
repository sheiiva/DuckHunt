/*
** Description:
** Library's Prototypes
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#ifndef MY_H_
    #define MY_H_

    #include <unistd.h>
    #include <stdlib.h>

    #define STDIN   0
    #define STDOUT  1
    #define STDERR  2

    ssize_t my_putchar(char c, int fd);
    size_t my_strlen(char const *str);
    char *my_strcpy(char *dest, const char *src);
    char *my_strdup(const char *s);

#endif /* !MY_H_ */