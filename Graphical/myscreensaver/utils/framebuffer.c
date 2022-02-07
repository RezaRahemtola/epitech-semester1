/*
** EPITECH PROJECT, 2021
** CSFML utils
** File description:
** Framebuffer functions
*/

#include <stdlib.h>
#include "utils.h"

framebuff *framebuffer_create(int width, int height, int bpp)
{
    framebuff *framebuffer = malloc(sizeof(framebuff));

    framebuffer->width = width;
    framebuffer->height = height;
    framebuffer->bpp = bpp;
    framebuffer->pixels = malloc(width * height * bpp / 8);
    return (framebuffer);
}

void framebuffer_destroy(framebuff *fb)
{
    free(fb->pixels);
    free(fb);
}

void framebuffer_fill(framebuff *fb, sfColor color)
{
    for (unsigned int i = 0; i < fb->width; i++) {
        for (unsigned int j = 0; j < fb->height; j++)
            put_pixel(fb, i, j, color);
    }
}

void put_pixel(framebuff *fb, unsigned int x, unsigned int y, sfColor col)
{
    fb->pixels[(y * fb->width + x) * (fb->bpp / 8)] = col.r;
    fb->pixels[(y * fb->width + x) * (fb->bpp / 8) + 1] = col.g;
    fb->pixels[(y * fb->width + x) * (fb->bpp / 8) + 2] = col.b;
    fb->pixels[(y * fb->width + x) * (fb->bpp / 8) + 3] = col.a;
}

sfColor get_pixel(framebuff *fb, unsigned int x, unsigned int y)
{
    sfColor color;

    color.r = fb->pixels[(y * fb->width + x) * (fb->bpp / 8)];
    color.g = fb->pixels[(y * fb->width + x) * (fb->bpp / 8) + 1];
    color.b = fb->pixels[(y * fb->width + x) * (fb->bpp / 8) + 2];
    color.a = fb->pixels[(y * fb->width + x) * (fb->bpp / 8) + 3];
    return (color);
}
