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

    #include "scene.h"

    #define TIMEREFRESH 0.1

    enum _GAMESTATE {
        QUIT=       -1,
        GAMESCENE=  0,
    };

    typedef struct s_window {
        sfVideoMode mode;
        sfRenderWindow* window;
    } t_window;

    typedef struct s_system {
        t_window *window;
        sfClock *clock;
        sfEvent event;
        int state;
    } t_system;

    t_system *initSystem();
    void destroySystem(t_system *system);
    sfRenderWindow *createWindow(sfVideoMode mode);
    void destroyWindow(t_window *window);
    t_window *initWindow();
    void displayAll(sfRenderWindow* window, t_scene *scene);
    void clearWindow(sfRenderWindow* window);

#endif /* !SYSTEM_H_ */