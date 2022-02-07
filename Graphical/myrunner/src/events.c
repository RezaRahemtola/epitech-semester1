/*
** EPITECH PROJECT, 2021
** Myrunner
** File description:
** Events handling
*/

#include "my_runner.h"

static void check_perso_pos(game_obj_t *perso)
{
    int sprite_width = sfSprite_getTextureRect(perso->sprite).width;

    if (perso->pos.x < 0) {
        perso->pos.x = 0;
        perso->speed.x = 0;
    } else if (perso->pos.x + sprite_width > WIDTH) {
        perso->pos.x = WIDTH - sprite_width;
        perso->speed.x = 0;
    }
}

static void check_enemies_killed(sfEvent *event, game_obj_t **enemies)
{
    sfVector2f myvect = {event->mouseButton.x, event->mouseButton.y};
    sfFloatRect bounds;
    game_obj_t *tmp = *enemies;

    while (tmp != NULL) {
        bounds = sfSprite_getGlobalBounds(tmp->sprite);
        if (sfFloatRect_contains(&bounds, myvect.x, myvect.y))
            tmp->hidden = sfTrue;
        tmp = tmp->next;
    }
}

int handle_game_events(sfRenderWindow *window, game_obj_t *perso,
game_obj_t **enemies)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        check_closing_event(window, event);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            return (1);
        if (event.type == sfEvtKeyPressed &&
        (event.key.code == sfKeySpace || event.key.code == sfKeyUp))
            perso->speed.y -= (perso->speed.y == 0) ? (25) : (0);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyRight)
            perso->speed.x += 2;
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyLeft)
            perso->speed.x -= 2;
        if (event.type == sfEvtMouseButtonPressed)
            check_enemies_killed(&event, enemies);
    }
    check_perso_pos(perso);
    return (0);
}

int handle_pause_events(sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        check_closing_event(window, event);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            return (1);
    }
    return (0);
}

int handle_end_events(sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        check_closing_event(window, event);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace)
            return (1);
    }
    return (0);
}