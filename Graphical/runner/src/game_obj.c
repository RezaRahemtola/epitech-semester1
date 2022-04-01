/*
** EPITECH PROJECT, 2021
** MyRunner
** File description:
** Game object functions
*/

#include "my_runner.h"

void my_put(game_obj_t *obj, game_obj_t **dest)
{
    obj->next = *dest;
    *dest = obj;
}

game_obj_t *create_perso(void)
{
    game_obj_t *list = create_game_obj("assets/runner.png",
    (sfVector2f){100, 710}, (sfVector2f){0, 0}, (sfIntRect){0, 0, 88, 136});

    list->next = NULL;
    return (list);
}

game_obj_t *create_bg_list(void)
{
    game_obj_t *list = NULL;
    char *path = my_strdup("assets/bg/layer_01.png");
    sfVector2f speed = {-12, 0};
    sfIntRect rect = {0, 0, WIDTH, HEIGHT};
    sfVector2f pos1 = {0, 0};
    sfVector2f pos2 = {WIDTH, 0};

    for (int i = 1; i <= 8; i++) {
        path[17] = i + '0';
        my_put(create_game_obj(path, pos1, speed, rect), &list);
        my_put(create_game_obj(path, pos2, speed, rect), &list);
        speed.x += (speed.x < 0) ? (2) : (0);
    }
    free(path);
    return (list);
}

game_obj_t *create_obstacles_list(const char *map)
{
    game_obj_t *list = NULL;
    FILE *file = fopen(map, "r");
    size_t bufsize = 2;
    char *buffer = malloc(sizeof(char) * bufsize);
    int posx = WIDTH;

    while (getline(&buffer, &bufsize, file) > 0) {
        if (buffer[0] == '1') {
            my_put(create_game_obj("assets/spike.png", (sfVector2f){posx, 820},
            (sfVector2f){-5, 0}, (sfIntRect){0, 0, 60, 136}), &list);
        }
        if (buffer[0] == '2') {
            my_put(create_game_obj("assets/saw.png", (sfVector2f){posx, 800},
            (sfVector2f){-5, 0}, (sfIntRect){0, 0, 103, 54}), &list);
        }
        posx += DIST_OBSTACLES;
    }
    free(buffer);
    fclose(file);
    return (list);
}

game_obj_t *create_enemies_list(const char *map)
{
    game_obj_t *list = NULL;
    FILE *file = fopen(map, "r");
    size_t bufsize = 2;
    char *buffer = malloc(sizeof(char) * bufsize);
    int posx = WIDTH;

    while (getline(&buffer, &bufsize, file) > 0) {
        if (rand() % 9 == 0) {
            my_put(create_game_obj("assets/bird.png", (sfVector2f){posx, 500},
            (sfVector2f){-5, 0}, (sfIntRect){0, 0, 125, 86}), &list);
        }
        posx += DIST_OBSTACLES;
    }
    free(buffer);
    fclose(file);
    return (list);
}
