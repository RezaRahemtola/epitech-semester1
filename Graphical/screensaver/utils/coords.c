/*
** EPITECH PROJECT, 2021
** CSFML utils
** File description:
** Coords structure
*/

#include <stdlib.h>
#include "utils.h"

void coords_init(coords *c, unsigned int width, unsigned int height)
{
    c->x = 0;
    c->y = 0;
    c->min_x = 0;
    c->min_y = 0;
    c->max_x = width;
    c->max_y = height;
}

coords *coords_create(unsigned int width, unsigned int height)
{
    coords *c = malloc(sizeof(coords));

    coords_init(c, width, height);
    return (c);
}
