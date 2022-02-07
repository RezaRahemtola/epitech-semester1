/*
** EPITECH PROJECT, 2021
** MyRunner
** File description:
** Pause menu functions
*/

#include "my_runner.h"

void pause_menu(sfRenderWindow *window)
{
    framebuffer_t *fb = framebuffer_create(WIDTH, HEIGHT, 32);
    sfTexture *texture = sfTexture_create(WIDTH, HEIGHT);
    sfSprite *sprite = sfSprite_create();

    framebuffer_fill(fb, (sfColor){0, 0, 0, 100});
    disp_framebuffer(texture, fb, sprite, window);
    sfRenderWindow_display(window);
    while (sfRenderWindow_isOpen(window))
        if (handle_pause_events(window) == 1) break;
    csfml_destroyer("fts", fb, texture, sprite);
}
