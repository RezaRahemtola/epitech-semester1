/*
** EPITECH PROJECT, 2021
** MyScreensaver
** File description:
** anim_info functions
*/

#include <stdlib.h>
#include "my_screensaver.h"

anim_info *init_info(framebuff *fb)
{
    anim_info *info = malloc(sizeof(anim_info));
    sfColor tunnel_color = {0, 255, 0, 255};
    coords *tunnel_pos = coords_create(fb->width, fb-> height);
    sfVector2i circle_pos = {WIDTH / 2, HEIGHT / 2};
    int speed_y = (rand() % (15 + 1 - 5)) + 5;
    int speed_x = (rand() % (15 + 1 -5)) + 5;
    sfVector2i circle_speed = {speed_x, speed_y};
    sfColor circle_color = {rand() % 255, rand() % 255, rand() % 255, 255};

    info->tunnel_color = tunnel_color;
    info->tunnel_pos = tunnel_pos;
    info->circle_color = circle_color;
    info->circle_pos = circle_pos;
    info->circle_speed = circle_speed;
    info->circle_radius = 50;
    info->lines_nb = 0;
    info->pxl_nb = 0;
    return (info);
}

void reinit_info(anim_info *info, framebuff *fb)
{
    sfColor tunnel_color = {0, 255, 0, 255};
    coords *tunnel_pos = coords_create(fb->width, fb-> height);
    sfVector2i circle_pos = {WIDTH / 2, HEIGHT / 2};
    int speed_y = (rand() % (15 + 1 - 5)) + 5;
    int speed_x = (rand() % (15 + 1 -5)) + 5;
    sfVector2i circle_speed = {speed_x, speed_y};
    sfColor circle_color = {rand() % 255, rand() % 255, rand() % 255, 255};

    free(info->tunnel_pos);
    info->tunnel_color = tunnel_color;
    info->tunnel_pos = tunnel_pos;
    info->circle_color = circle_color;
    info->circle_pos = circle_pos;
    info->circle_speed = circle_speed;
    info->circle_radius = 50;
    info->lines_nb = 0;
    info->pxl_nb = 0;
}

void free_info(anim_info *info)
{
    free(info->tunnel_pos);
    free(info);
}
