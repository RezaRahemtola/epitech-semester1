/*
** EPITECH PROJECT, 2021
** MY CSFML
** File description:
** Game_OBJ.h
*/

#ifndef MYCSFML_GAME_OBJ_H_
    #define MYCSFML_GAME_OBJ_H_
    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include "mycsfml_clock.h"

typedef struct game_object {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f pos;
    sfVector2f speed;
    time_clock_t *clock;
    sfBool hidden;
    struct game_object *next;
} game_obj_t;

void move_obj(game_obj_t *obj, void (*check_pos)(game_obj_t *),
int elapsed_millisec);
void move_objects(game_obj_t *list, void (*check_pos)(game_obj_t *),
int elapsed_millisec);

void move_and_disp_obj(game_obj_t *obj, void (*check_pos)(game_obj_t *),
int elapsed_millisec, sfRenderWindow *window);
void move_and_disp_objects(game_obj_t *list, void (*check_pos)(game_obj_t *),
int elapsed_millisec, sfRenderWindow *window);

void disp_obj(sfRenderWindow *window, game_obj_t *obj);
void disp_objects(sfRenderWindow *window, game_obj_t *list);

game_obj_t *create_game_obj(const char *path, sfVector2f pos,
sfVector2f speed, sfIntRect rect);
void destroy_object_list(game_obj_t *head);

#endif /* !MYCSFML_GAME_OBJ_H_ */
