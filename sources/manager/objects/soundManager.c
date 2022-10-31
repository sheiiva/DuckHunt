/*
** Description:
** Sound Manager
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#include "sound.h"
#include "my.h"

void destroySound(t_sound *sound)
{
    free(sound->source);
    if (!sound->sound)
        sfMusic_destroy(sound->sound);
}

void destroySounds(t_sound **sounds)
{
    int i = 0;

    while (sounds[i]) {
        destroySound(sounds[i]);
        i += 1;
    }
}

t_sound *createSound(char const *sourcePath)
{
    t_sound *sound = malloc(sizeof(t_sound));

    if (!sound)
        return (NULL);
    sound->source = my_strdup(sourcePath);
    if (!sound->source) {
        destroySound(sound);
        return (NULL);
    }
    sound->sound = sfMusic_createFromFile(sound->source);
    if (!sound->sound) {
        destroySound(sound);
        return (NULL);
    }
    return (sound); 
}

t_sound **createSoundArray(size_t size)
{
    t_sound **array = malloc(sizeof(t_sound*) * (size + 1));
    size_t i = 0;

    if (!array)
        return (NULL);
    while (i <= size) {
        array[i] = NULL;
        i += 1;
    }
    return (array);
}