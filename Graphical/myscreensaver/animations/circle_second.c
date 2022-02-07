/*
** EPITECH PROJECT, 2021
** MyScreensaver
** File description:
** Second animation - Circle
*/

#include "my_screensaver.h"

static sfVector2i get_dir(anim_info *info, int width, int height)
{
    sfVector2i new_speed = {info->circle_speed.x, info->circle_speed.y};
    sfVector2i pos = info->circle_pos;
    int radius = info->circle_radius;

    if (pos.x + radius >= width || pos.x - radius <= 0) {
        info->circle_color = get_rand_color();
        new_speed.x *= -1;
    } else if (pos.y + radius >= height || pos.y - radius <= 0) {
        info->circle_color = get_rand_color();
        new_speed.y *= -1;
    }
    return (new_speed);
}

void circle(framebuff *fb, anim_info *info)
{
    sfColor color = info->circle_color;
    int radius = info->circle_radius;

    framebuffer_fill(fb, sfBlack);
    draw_circle(fb, info->circle_pos, radius, color);
    info->circle_speed = get_dir(info, WIDTH, HEIGHT);
    info->circle_pos.x += info->circle_speed.x;
    info->circle_pos.y += info->circle_speed.y;
}
