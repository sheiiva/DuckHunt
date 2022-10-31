/*
** Description:
** Game Scene
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#include "scene.h"

t_image **initGameSceneImages(size_t imageNumber)
{
    t_image **images = createImageArray(imageNumber);

    if (!images)
        return (NULL);
    images[0] = createImage("assets/images/gameScene/background.png", (sfVector2f){0, 0});
    images[1] = createImage("assets/images/gameScene/crossair.png", (sfVector2f){0, 0});
    return (images);
}

t_text **initGameSceneTexts(size_t textNumber)
{
    t_text **texts = createTextArray(textNumber);

    if (!texts)
        return (NULL);
    return (texts);
}

t_sound **initGameSceneSounds(size_t soundNumber)
{
    t_sound **sounds = createSoundArray(soundNumber);

    if (!sounds)
        return (NULL);
    return (sounds);
}

t_scene *initGameScene()
{
    size_t imageNumber = 2;
    size_t textNumber = 0;
    size_t soundNumber = 0;
    t_scene *scene = createScene();

    if (!scene
        || !(scene->images = initGameSceneImages(imageNumber))
        || !(scene->texts = initGameSceneTexts(textNumber))
        || !(scene->sounds =  initGameSceneSounds(soundNumber))) {
        destroyScene(scene);
        return (NULL);
    }
    return (scene);
}