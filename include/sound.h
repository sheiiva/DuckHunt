/*
** Description:
** Game Sounds' structure
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#ifndef SOUND_H_
    #define SOUND_H_

    #include <SFML/Audio.h>

    #include <stdlib.h>

    typedef struct s_sound {
        char *source;
        sfMusic *sound;
    } t_sound;

    void destroySound(t_sound *sound);
    void destroySounds(t_sound **sounds);
    t_sound *createSound(char const *sourcePath);

#endif /* !SOUND_H_ */