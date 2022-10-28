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

    #define STDIN   0
    #define STDOUT  1
    #define STDERR  2

    ssize_t my_putchar(char c, int fd);

#endif /* !MY_H_ */