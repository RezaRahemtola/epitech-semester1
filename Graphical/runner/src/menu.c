/*
** EPITECH PROJECT, 2022
** MyRunner
** File description:
** Functions for a menu to select the level
*/

#include "my_runner.h"

static int is_button_clicked(game_obj_t *buttons, sfEvent *event)
{
    int clicked = 1;
    sfVector2f click_vect = {event->mouseButton.x, event->mouseButton.y};
    sfFloatRect bounds;

    while (buttons != NULL) {
        bounds = sfSprite_getGlobalBounds(buttons->sprite);
        if (sfFloatRect_contains(&bounds, click_vect .x, click_vect .y))
            return (clicked);
        buttons = buttons->next;
        clicked++;
    }
    return (0);
}

static int handle_menu_events(sfRenderWindow *window, game_obj_t *buttons)
{
    sfEvent event;
    int clicked = 0;

    while (sfRenderWindow_pollEvent(window, &event)) {
        check_closing_event(window, event);
        if (event.type == sfEvtMouseButtonPressed)
            clicked = is_button_clicked(buttons, &event);
    }
    return (clicked);
}

static game_obj_t *create_menu_buttons(void)
{
    game_obj_t *list = NULL;

    my_put(create_game_obj("assets/button_hard.png", (sfVector2f){830, 500},
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 205, 90}), &list);
    my_put(create_game_obj("assets/button_medium.png", (sfVector2f){800, 350},
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 289, 90}), &list);
    my_put(create_game_obj("assets/button_easy.png", (sfVector2f){830, 200},
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 198, 90}), &list);
    return (list);
}

char *display_menu(sfRenderWindow *window, const char *arg_map)
{
    game_obj_t *bg_list = create_bg_list();
    game_obj_t *buttons = create_menu_buttons();
    int clicked = 0;

    sfRenderWindow_clear(window, sfBlack);
    disp_objects(window, bg_list);
    disp_objects(window, buttons);
    if (my_strcmp(arg_map, "-m") == 0)
        sfRenderWindow_display(window);
    while (sfRenderWindow_isOpen(window) && my_strcmp(arg_map, "-m") == 0) {
        clicked = handle_menu_events(window, buttons);
        if (clicked > 0) break;
    }
    csfml_destroyer("gg", bg_list, buttons);
    if (clicked == 1) return (my_strdup("tests/samples/easy.txt"));
    if (clicked == 2) return (my_strdup("tests/samples/medium.txt"));
    if (clicked == 3) return (my_strdup("tests/samples/hard.txt"));
    return (my_strdup(arg_map));
}
