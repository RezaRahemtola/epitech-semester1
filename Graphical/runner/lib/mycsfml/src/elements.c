/*
** EPITECH PROJECT, 2021
** MY CSFML
** File description:
** Elements
*/

#include <stdarg.h>
#include "mycsfml_all.h"

void disp_texture(sfTexture *texture, sfSprite *sprite, sfRenderWindow *window)
{
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfRenderWindow_drawSprite(window, sprite, NULL);
}

void disp_framebuffer(sfTexture *t, framebuffer_t *fb, sfSprite *sprite,
sfRenderWindow *window)
{
    sfTexture_updateFromPixels(t, fb->pixels, fb->width, fb->height, 0, 0);
    disp_texture(t, sprite, window);
}

void csfml_destroyer(const char *format, ...)
{
    va_list args;

    va_start(args, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == 'c') clock_destroy(va_arg(args, time_clock_t *));
        if (format[i] == 't') sfTexture_destroy(va_arg(args, sfTexture *));
        if (format[i] == 'T') text_destroy(va_arg(args, text_t *));
        if (format[i] == 's') sfSprite_destroy(va_arg(args, sfSprite *));
        if (format[i] == 'S') sound_destroy(va_arg(args, sound_t *));
        if (format[i] == 'g') destroy_object_list(va_arg(args, game_obj_t *));
        if (format[i] == 'f')
            framebuffer_destroy(va_arg(args, framebuffer_t *));
        if (format[i] == 'w')
            sfRenderWindow_destroy(va_arg(args, sfRenderWindow *));
    }
    va_end(args);
}
