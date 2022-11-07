/*
** Description:
** Game Scenes' structure
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#ifndef SCENE_H_
    #define SCENE_H_

    #include <SFML/Audio.h>
    #include <SFML/Window.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>

    #include <stdlib.h>

    #include "image.h"
    #include "sound.h"
    #include "text.h"
    #include "duck.h"

    #define SCENENUMBER 2

    typedef struct s_scene {
        t_duck **ducks;
        t_image **images;
        t_text **texts;
        t_sound **sounds;
    } t_scene;

    t_scene **initScenes(const sfRenderWindow *window);
    void drawScene(sfRenderWindow* window, t_scene *scene);
    void destroyScene(t_scene *scene);
    void destroyScenes(t_scene **scenes);
    t_scene *createScene();

#endif /* !SCENE_H_ */