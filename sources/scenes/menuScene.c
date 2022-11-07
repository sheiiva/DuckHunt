/*
** Description:
** Menu Scene
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#include "sources.h"
#include "menuScene.h"

t_image **initMenuSceneImages(size_t imageNumber)
{
    t_image **images = createImageArray(imageNumber);

    if (!images)
        return (NULL);
    images[MENU_BACKGROUND] = createImage(MENU_BACKGROUND_PATH, (sfVector2f){0, 0});
    return (images);
}

t_text **initMenuSceneTexts(size_t textNumber)
{
    t_text **texts = createTextArray(textNumber);

    if (!texts)
        return (NULL);
    texts[MENU_TITLE] = createText(MENU_TITLE_LABEL, (sfVector2f){200, 50}, 150, sfWhite, MENU_FONT_PATH);
    texts[MENU_PLAY] = createText(MENU_PLAY_LABEL, (sfVector2f){500, 400}, 100, sfWhite, MENU_FONT_PATH);
    return (texts);
}

t_sound **initMenuSceneSounds(size_t soundNumber)
{
    t_sound **sounds = createSoundArray(soundNumber);

    if (!sounds)
        return (NULL);
    return (sounds);
}

t_scene *initMenuScene(__UNUSED__ const sfRenderWindow *window)
{
    t_scene *scene = createScene();

    if ((!scene)
        || !(scene->images = initMenuSceneImages(MENU_IMAGENUMBER))
        || !(scene->texts = initMenuSceneTexts(MENU_TEXTNUMBER))
        || !(scene->sounds =  initMenuSceneSounds(MENU_SOUNDNUMER))) {
        destroyScene(scene);
        return (NULL);
    }
    scene->ducks = NULL;
    return (scene);
}