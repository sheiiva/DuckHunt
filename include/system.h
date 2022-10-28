/*
** Description:
** Game system's structure
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#ifndef SYSTEM_H_
    #define SYSTEM_H_

    #include <SFML/Audio.h>
    #include <SFML/Window.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>

    #define QUIT    0
    #define RUN     1

    typedef struct s_window {
        sfVideoMode mode;
        sfRenderWindow* window;
    } t_window;

    typedef struct s_system {
        t_window *window;
        sfEvent event;
        int state;
    } t_system;

    t_system *initSystem();
    void destroySystem(t_system *system);
    sfRenderWindow *createWindow(sfVideoMode mode);
    void destroyWindow(t_window *window);
    t_window *initWindow();

#endif /* !SYSTEM_H_ */