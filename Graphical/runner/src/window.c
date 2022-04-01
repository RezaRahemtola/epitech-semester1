/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** MyScreensaver
*/

#include "my_runner.h"

void display_window(const char *arg_map)
{
    sfRenderWindow *window = create_window(WIDTH, HEIGHT, "MyRunner", 60);
    char *map = NULL;
    int game_return = 0;

    display_studio(window);
    while (sfRenderWindow_isOpen(window)) {
        map = display_menu(window, arg_map);
        if (sfRenderWindow_isOpen(window) == sfFalse) {
            free(map);
            break;
        }
        game_return = play_game(window, map);
        if (game_return == 2)
            disp_youwin(window);
        if (game_return == 1)
            disp_gameover(window);
        free(map);
    }
    csfml_destroyer("w", window);
}
