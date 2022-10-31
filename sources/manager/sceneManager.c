/*
** Description:
** Event Manager
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#include "scene.h"

void destroyScene(t_scene *scene)
{
    if (!scene)
        return;
    destroyImages(scene->images);
    destroyTexts(scene->texts);
    destroySounds(scene->sounds);
    free(scene);
}

void destroyScenes(t_scene **scenes)
{
    size_t i = 0;

    while (scenes[i]) {
        destroyScene(scenes[i]);
        i += 1;
    }
    free(scenes);
}

t_scene *createScene()
{
    t_scene *newScene = malloc(sizeof(t_scene));

    if (!newScene)
        return (NULL);
    newScene->images = NULL;
    newScene->texts = NULL;
    newScene->sounds = NULL;
    return (newScene);
}

void drawScene(sfRenderWindow* window, t_scene *scene)
{
    drawImages(window, scene->images);
    drawTexts(window, scene->texts);
}

t_scene **initScenes()
{
    t_scene **scenes = malloc(sizeof(t_scene*) * (SCENENUMBER + 1));

    if (!scenes)
        return (NULL);
    scenes[SCENENUMBER] = NULL;
    if (!(scenes[0] = initGameScene())) {
        destroyScenes(scenes);
        return (NULL);
    }
    return (scenes);
}