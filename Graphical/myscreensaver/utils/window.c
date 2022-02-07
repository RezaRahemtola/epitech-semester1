/*
** EPITECH PROJECT, 2021
** CSFML utils
** File description:
** Window functions
*/

#include <SFML/Graphics.h>
#include "utils.h"

void check_closing_event(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed || event.key.code == sfKeyEscape)
        sfRenderWindow_close(window);
}

sfRenderWindow *create_window(unsigned int width, unsigned int height, \
char const *title, unsigned int framerate)
{
    sfRenderWindow *window;
    sfVideoMode mode;

    mode.width = width;
    mode.height = height;
    mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(mode, title, sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, framerate);
    return (window);
}

void destroy_elements(sfRenderWindow *window, sfTexture *texture, \
sfSprite *sprite, framebuff *fb)
{
    sfRenderWindow_destroy(window);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
    framebuffer_destroy(fb);
}

void pixels_to_sprite(sfTexture *t, framebuff *fb, sfSprite *sprite, \
sfRenderWindow *window)
{
    sfTexture_updateFromPixels(t, fb->pixels, fb->width, fb->height, 0, 0);
    sfSprite_setTexture(sprite, t, sfFalse);
    sfRenderWindow_drawSprite(window, sprite, NULL);
}
