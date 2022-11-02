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
        sfVector2f position;
        sfFont *font;
        sfText *text;
    } t_text;

    void destroyText(t_text *text);
    void destroyTexts(t_text **texts);
    void drawText(sfRenderWindow* window, t_text *text);
    void drawTexts(sfRenderWindow* window, t_text **texts);
    t_text *createText(char const *content, sfVector2f position, unsigned int size, sfColor color, char *fontPath);
    t_text **createTextArray(size_t size);

#endif /* !TEXT_H_ */