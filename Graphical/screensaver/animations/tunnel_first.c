/*
** EPITECH PROJECT, 2021
** MyScreensaver
** File description:
** First animation - tunnel
*/

#include <stdlib.h>
#include "animations.h"

static sfColor tunnel_animation(framebuff *fb, coords *pos, sfColor color)
{
    for (; pos->y == pos->min_y && pos->x + 1 < pos->max_x; pos->x++)
        put_pixel(fb, pos->x, pos->y, color);
    pos->max_x--;
    color.r += 5;
    for (; pos->x == pos->max_x && pos->y + 1 < pos->max_y; pos->y++)
        put_pixel(fb, pos->x, pos->y, color);
    pos->max_y--;
    for (; pos->y == pos->max_y && pos->x > pos->min_x; pos->x--)
        put_pixel(fb, pos->x, pos->y, color);
    pos->min_x++;
    for (; pos->x == pos->min_x - 1 && pos->y > pos->min_y + 1; pos->y--)
        put_pixel(fb, pos->x, pos->y, color);
    pos->min_y++;
    if (pos->x == 499 && pos->y == 300) {
        framebuffer_fill(fb, sfBlack);
        coords_init(pos, fb->width, fb->height);
    }
    return (color);
}

void tunnel(framebuff *fb, anim_info *info)
{
    sfColor color = info->tunnel_color;

    info->tunnel_color = tunnel_animation(fb, info->tunnel_pos, color);
}
