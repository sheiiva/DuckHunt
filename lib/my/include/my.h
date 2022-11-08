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
    #include <string.h>

    #define STDIN   0
    #define STDOUT  1
    #define STDERR  2

    void*   my_memset(void *s, int c, size_t n);
    ssize_t my_putchar(char c, int fd);
    char*   my_strcpy(char *dest, const char *src);
    char*   my_strdup(const char *s);
    size_t  my_strlen(char const *str);

#endif /* !MY_H_ */