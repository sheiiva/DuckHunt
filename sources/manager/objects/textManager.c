/*
** Description:
** Text Manager
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#include "text.h"
#include "my.h"

void destroyText(t_text *text)
{
    free(text->content);
    if (text->text)
        sfText_destroy(text->text);
    if (text->font)
        sfFont_destroy(text->font);
}

void destroyTexts(t_text **texts)
{
    int i = 0;

    while (texts[i]) {
        destroyText(texts[i]);
        i += 1;
    }
}

t_text *createText(char const *content, unsigned int size, char *fontPath)
{
    t_text *text = malloc(sizeof(t_text));

    if (!text)
        return (NULL);
    text->content = my_strdup(content);
    if (!text->content) {
        destroyText(text);
        return (NULL);
    }
    text->font = sfFont_createFromFile(fontPath);
    if (!text->font) {
        destroyText(text);
        return (NULL);
    }
    text->text = sfText_create();
    if (!text->text) {
        destroyText(text);
        return (NULL);
    }
    text->size = size;
    sfText_setString(text->text, text->content);
    sfText_setFont(text->text, text->font);
    sfText_setCharacterSize(text->text, text->size);
    return (text); 
}