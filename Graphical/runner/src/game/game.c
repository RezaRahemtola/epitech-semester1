/*
** EPITECH PROJECT, 2021
** MyRunner
** File description:
** Game functions
*/

#include "my_runner.h"

static void disp_score_and_window(int score, sfRenderWindow *window)
{
    text_t *text = text_create("", "assets/score.otf", sfRed, 50);
    char *new_string = my_nbr_to_string(score + 1);

    sfText_setStyle(text->text, sfTextBold);
    sfText_setPosition(text->text, (sfVector2f){WIDTH / 2.15, 150});
    sfText_setString(text->text, new_string);
    sfRenderWindow_drawText(window, text->text, NULL);
    sfRenderWindow_display(window);
    text_destroy(text);
    free(new_string);
}

static int is_collision(game_obj_t *perso, game_obj_t *obstacles)
{
    sfFloatRect rect1;
    sfFloatRect rect2 = sfSprite_getGlobalBounds(perso->sprite);
    game_obj_t *tmp = obstacles;

    while (tmp != NULL) {
        rect1 = sfSprite_getGlobalBounds(tmp->sprite);
        if (sfFloatRect_intersects(&rect1, &rect2, NULL) &&
        tmp->hidden == sfFalse) {
            return (1);
        }
        tmp = tmp->next;
    }
    return (0);
}

static int check_collisions(game_obj_t *perso, game_obj_t *obstacles,
game_obj_t *enemies)
{
    int return_value = 0;
    sfBool all_obstacles_passed = sfTrue;
    game_obj_t *tmp = obstacles;

    if (is_collision(perso, obstacles) == 1) return_value = 1;
    if (is_collision(perso, enemies) == 1) return_value = 1;
    while (tmp != NULL && all_obstacles_passed) {
        if (tmp->pos.x > 0)
            all_obstacles_passed = sfFalse;
        tmp = tmp->next;
    }
    if (all_obstacles_passed) return_value = 2;
    return (return_value);
}

static void move_game_content(game_obj_t *perso, game_obj_t *obstacles,
game_obj_t *enemies, sfRenderWindow *window)
{
    move_and_disp_objects(obstacles, NULL, 5, window);
    move_and_disp_objects(enemies, NULL, 5, window);
    move_and_disp_obj(perso, &move_perso, 50, window);
}

int play_game(sfRenderWindow *window, const char *map)
{
    game_obj_t *bg_list = create_bg_list();
    game_obj_t *perso = create_perso();
    game_obj_t *obstacles = create_obstacles_list(map);
    game_obj_t *enemies = create_enemies_list(map);
    sound_t *music = sound_create("assets/aliez.ogg", sfTrue, sfTrue);
    int score = 0;
    int return_value = 0;

    while (sfRenderWindow_isOpen(window) && return_value == 0) {
        if (handle_game_events(window, perso, &enemies) == 1)
            pause_menu(window);
        sfRenderWindow_clear(window, sfBlack);
        move_and_disp_objects(bg_list, &move_background, 20, window);
        move_game_content(perso, obstacles, enemies, window);
        disp_score_and_window(score++, window);
        return_value = check_collisions(perso, obstacles, enemies);
    }
    csfml_destroyer("Sgggg", music, bg_list, perso, obstacles, enemies);
    return (return_value);
}
