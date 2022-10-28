/*
** Description:
** Main Function
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#include "sources.h"
#include "system.h"

int gameloop(t_system *system)
{
    /* Start the game loop */
    while (sfRenderWindow_isOpen(system->window->window))
    {
        /* Clear the screen */
        sfRenderWindow_clear(system->window->window, sfBlack);

        /* Process events */
        while (sfRenderWindow_pollEvent(system->window->window, &(system->event)))
        {
            /* Close window : exit */
            if (system->event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
                sfRenderWindow_close(system->window->window);
        }

        // /* Draw the sprite */
        // sfRenderWindow_drawSprite(system->window->window, sprite, NULL);

        // /* Draw the text */
        // sfRenderWindow_drawText(system->window->window, text, NULL);

        /* Update the window */
        sfRenderWindow_display(system->window->window);
    }
    return (0);
}


int main()
{
    t_system *system = initSystem();

    if (!system)
        return (84);
    gameloop(system);
    destroySystem(system);


    // sfTexture* texture;
    // sfSprite* sprite;
    // sfFont* font;
    // sfText* text;
    // sfMusic* music;

    // /* Create the main window */
    // window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);
    // if (!window)
    //     return 84;

    // /* Load a sprite to display */
    // texture = sfTexture_createFromFile("assets/images/cute_image.jpg", NULL);
    // if (!texture)
    //     return 84;
    // sprite = sfSprite_create();
    // sfSprite_setTexture(sprite, texture, sfTrue);

    // /* Create a graphical text to display */
    // font = sfFont_createFromFile("assets/fonts/JosefinSans-Italic-VariableFont_wght.ttf");
    // if (!font)
    //     return 84;
    // text = sfText_create();
    // sfText_setString(text, "Hello SFML");
    // sfText_setFont(text, font);
    // sfText_setCharacterSize(text, 50);

    // /* Load a music to play */
    // music = sfMusic_createFromFile("assets/sounds/music.wav");
    // if (!music)
    //     return 84;

    // /* Play the music */
    // sfMusic_play(music);



    // /* Cleanup resources */
    // sfMusic_destroy(music);
    // sfText_destroy(text);
    // sfFont_destroy(font);
    // sfTexture_destroy(texture);
    // sfSprite_destroy(sprite);
    // sfRenderWindow_destroy(window);

    return (0);
}