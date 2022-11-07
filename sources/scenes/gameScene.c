/*
** Description:
** Game Scene
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#include "my.h"
#include "gameScene.h"
#include "scene.h"
#include "sources.h"

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
    texts[SCORE_LABEL] = createText("Score:", (sfVector2f){10, 10}, 50, sfWhite, FONT_PATH);
    texts[SCORE] = createText("0", (sfVector2f){200, 10}, 50, sfWhite, FONT_PATH);
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

void updateScore(t_scene *scene, int score)
{
    char newContent[12];
    int newScore = atoi((char*)scene->texts[SCORE]->content) + score;

    my_memset(newContent, 0, 12);
    sprintf(newContent, "%d", newScore);

    free(scene->texts[SCORE]->content);
    scene->texts[SCORE]->content = my_strdup(newContent);

    sfText_setString(scene->texts[SCORE]->text, scene->texts[SCORE]->content);
}