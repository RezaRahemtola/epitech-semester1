/*
** EPITECH PROJECT, 2021
** MyRunner
** File description:
** Display studio screen
*/

#include "my_runner.h"

void display_studio(sfRenderWindow *window)
{
    sfTexture *texture = sfTexture_createFromFile("assets/studio.jpg", NULL);
    sfSprite *sprite = sfSprite_create();
    time_clock_t *clock = clock_create();
    sfEvent event;
    sound_t *sound = sound_create("assets/segfault.ogg", sfFalse, sfTrue);

    disp_texture(texture, sprite, window);
    sfRenderWindow_display(window);
    while (clock->time_seconds < 5 && sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            check_closing_event(window, event);
        clock_update_time(clock);
    }
    csfml_destroyer("Stsc", sound, texture, sprite, clock);
}
