/*
** EPITECH PROJECT, 2021
** MyRunner
** File description:
** Functions to move game elements
*/

#include "my_runner.h"

void move_perso(game_obj_t *obj)
{
    obj->rect.left += obj->rect.width;
    if (obj->rect.left >= (int)sfTexture_getSize(obj->texture).x)
        obj->rect.left = 0;
    if (obj->pos.y <= 550) obj->speed.y = 25;
    if (obj->pos.y >= 710 && obj->speed.y == 25) obj->speed.y = 0;
}

void move_background(game_obj_t *background)
{
    if (background->pos.x == -WIDTH)
        background->pos.x = WIDTH;
}
