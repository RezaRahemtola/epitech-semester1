/*
** EPITECH PROJECT, 2021
** MyScreensaver
** File description:
** Pixel night animation
*/

#include <stdlib.h>
#include "my_screensaver.h"

static sfVector2i get_empty_pos(framebuff *fb)
{
    sfColor pxl = get_pixel(fb, 0, 0);
    sfVector2i pos;
    int x = 0;
    int y = 0;

    while (pxl.r != 0 || pxl.g != 0 || pxl.b != 0) {
        x = rand() % WIDTH;
        y = rand() % HEIGHT;
        pxl = get_pixel(fb, x, y);
    }
    pos.x = x;
    pos.y = y;
    return (pos);
}

static sfVector2i get_filled_pos(framebuff *fb)
{
    sfColor pxl = get_pixel(fb, 0, 0);
    sfVector2i pos;
    int x = 0;
    int y = 0;

    while (pxl.r == 0 && pxl.g == 0 && pxl.b == 0) {
        x = rand() % WIDTH;
        y = rand() % HEIGHT;
        pxl = get_pixel(fb, x, y);
    }
    pos.x = x;
    pos.y = y;
    return (pos);
}

void pixel_night(framebuff *fb, anim_info *info)
{
    sfColor color = get_rand_color();
    sfVector2i pos;

    for (int i = 0; i < 250; i++) {
        if (info->pxl_nb >= 0) {
            pos = get_empty_pos(fb);
            put_pixel(fb, pos.x, pos.y, color);
        } else {
            pos = get_filled_pos(fb);
            put_pixel(fb, pos.x, pos.y, sfBlack);
        }
    }
    info->pxl_nb++;
    info->pxl_nb = (info->pxl_nb == 250) ? (-250) : (info->pxl_nb);
}
