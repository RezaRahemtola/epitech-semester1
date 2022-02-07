/*
** EPITECH PROJECT, 2021
** MyScreensaver
** File description:
** Lines animation
*/

#include <stdlib.h>
#include "my_screensaver.h"

void lines(framebuff *fb, anim_info *info)
{
    sfVector2i point_a = {rand() % WIDTH, rand() % HEIGHT};
    sfVector2i point_b = {rand() % WIDTH, rand() % HEIGHT};

    if (info->lines_nb < 100) {
        draw_line(fb, point_a, point_b, get_rand_color());
        info->lines_nb++;
    } else {
        framebuffer_fill(fb, sfBlack);
        info->lines_nb = 0;
    }
}
