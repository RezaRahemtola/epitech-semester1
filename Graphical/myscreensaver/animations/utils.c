/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** MyScreensaver
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my_screensaver.h"

static int get_anim_nb(int nb, anim_info *info, framebuff *fb, sfEvent e)
{
    if (e.type == sfEvtKeyReleased &&
    e.key.code == sfKeyLeft && nb - 1 >= 0) {
        reinit_info(info, fb);
        framebuffer_fill(fb, sfBlack);
        nb--;
    } else if (e.type == sfEvtKeyReleased &&
    e.key.code == sfKeyRight && nb + 1 <= MAX_ID - 1) {
        reinit_info(info, fb);
        framebuffer_fill(fb, sfBlack);
        nb++;
    }
    return (nb);
}

void display_window(int nb_anim)
{
    sfRenderWindow *window = create_window(WIDTH, HEIGHT, "MyScreensaver", 60);
    sfEvent event;
    framebuff *fb = framebuffer_create(WIDTH, HEIGHT, 32);
    sfTexture *texture = sfTexture_create(WIDTH, HEIGHT);
    sfSprite *sprite = sfSprite_create();
    anim_info *info = init_info(fb);
    void (*f_ptr[4])(framebuff *fb, anim_info *info) = {tunnel,
    circle, lines, pixel_night};

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            check_closing_event(window, event);
            nb_anim = get_anim_nb(nb_anim, info, fb, event);
        }
        (*f_ptr[nb_anim])(fb, info);
        pixels_to_sprite(texture, fb, sprite, window);
        sfRenderWindow_display(window);
    }
    destroy_elements(window, texture, sprite, fb);
    free_info(info);
}
