/*
** Description:
** Game Texts' structure
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#ifndef TEXT_H_
    #define TEXT_H_

    #include <SFML/Graphics.h>

    typedef struct s_text {
        char *content;
        unsigned int size;
        sfFont *font;
        sfText *text;
    } t_text;

    void destroyText(t_text *text);
    void destroyTexts(t_text **texts);
    t_text *createText(char const *content, unsigned int size, char *fontPath);

#endif /* !TEXT_H_ */