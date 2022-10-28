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