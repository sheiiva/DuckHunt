/*
** Description:
** Game Scene
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#include "gameScene.h"
#include "scene.h"

t_duck **initGameSceneDucks(size_t duckNumber, const sfRenderWindow *window)
{
    int i = 0;
    t_duck **ducks = createDuckArray(duckNumber);

    if (!ducks)
        return (NULL);
    while (i < MAX_DUCKS) {
        if (!(ducks[i] = createDuck(window))) {
            destroyDucks(ducks);
            return (NULL);
        }
        i += 1;
    }
    return (ducks);
}

t_image **initGameSceneImages(size_t imageNumber)
{
    t_image **images = createImageArray(imageNumber);

    if (!images)
        return (NULL);
    images[BACKGROUND] = createImage(BACKGROUND_PATH, (sfVector2f){0, 0});
    images[CROSSAIR] = createImage(CROSSAIR_PATH, (sfVector2f){0, 0});
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

t_scene *initGameScene(const sfRenderWindow *window)
{
    t_scene *scene = createScene();

    if (!scene
        || !(scene->ducks = initGameSceneDucks(MAX_DUCKS, window))
        || !(scene->images = initGameSceneImages(IMAGENUMBER))
        || !(scene->texts = initGameSceneTexts(TEXTNUMBER))
        || !(scene->sounds =  initGameSceneSounds(SOUNDNUMER))) {
        destroyScene(scene);
        return (NULL);
    }
    return (scene);
}