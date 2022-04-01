/*
** EPITECH PROJECT, 2021
** MyRunner
** File description:
** End screens for won/lost games
*/

#include "my_runner.h"

void disp_youwin(sfRenderWindow *window)
{
    sfTexture *texture = sfTexture_createFromFile("assets/youwin.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sound_t *sound = sound_create("assets/victory.ogg", sfFalse, sfTrue);
    text_t *text = text_create("Press SPACE to play again",
    "assets/playagain.ttf", sfWhite, 50);

    sfText_setPosition(text->text, (sfVector2f){700, 700});
    disp_texture(texture, sprite, window);
    sfRenderWindow_drawText(window, text->text, NULL);
    sfRenderWindow_display(window);
    while (sfRenderWindow_isOpen(window))
        if (handle_end_events(window) == 1) break;
    csfml_destroyer("StsT", sound, texture, sprite, text);
}

void disp_gameover(sfRenderWindow *window)
{
    sfTexture *txtr = sfTexture_createFromFile("assets/gameover.jpg", NULL);
    sfSprite *sprite = sfSprite_create();
    sound_t *sound = sound_create("assets/gameover.ogg", sfFalse, sfTrue);
    text_t *text = text_create("Press SPACE to play again",
    "assets/playagain.ttf", sfWhite, 50);

    sfText_setPosition(text->text, (sfVector2f){700, 700});
    disp_texture(txtr, sprite, window);
    sfRenderWindow_drawText(window, text->text, NULL);
    sfRenderWindow_display(window);
    while (sfRenderWindow_isOpen(window))
        if (handle_end_events(window) == 1) break;
    csfml_destroyer("StsT", sound, txtr, sprite, text);
}
