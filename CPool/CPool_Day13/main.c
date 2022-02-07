/*
** EPITECH PROJECT, 2021
** CSFML
** File description:
** Task01
*/

#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include <SFML/Audio.h>
#include <SFML/System.h>

sfRenderWindow *create_window(unsigned int width, unsigned int height, \
char const *title)
{
    sfRenderWindow *Window;
    sfVideoMode mode;

    mode.width = width;
    mode.height = height;
    mode.bitsPerPixel = 32;
    Window = sfRenderWindow_create(mode, title, sfClose, NULL);
    return (Window);
}

int main()
{
    sfRenderWindow *window = create_window(800, 600, "Reza");
    sfEvent event;
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlue);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
}
