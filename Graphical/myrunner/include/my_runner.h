/*
** EPITECH PROJECT, 2021
** MyRunner
** File description:
** Header
*/

#ifndef MY_RUNNER_H_
    #define MY_RUNNER_H_
    #include "my.h"
    #include "mycsfml_all.h"
    #include <stdio.h>
    #include <stddef.h>
    #include <stdlib.h>
    #include <time.h>
    #define WIDTH 1920
    #define HEIGHT 1080
    #define DIST_OBSTACLES 300

// Game objects functions
game_obj_t *create_perso(void);
game_obj_t *create_bg_list(void);
game_obj_t *create_obstacles_list(const char *map);
game_obj_t *create_enemies_list(const char *map);
void my_put(game_obj_t *obj, game_obj_t **dest);

// Game functions
int play_game(sfRenderWindow *window, const char *map);

// Game elements movement
void move_perso(game_obj_t *obj);
void move_background(game_obj_t *background);

// Events handling
sfBool handle_game_events(sfRenderWindow *, game_obj_t *, game_obj_t **);
int handle_pause_events(sfRenderWindow *window);
int handle_end_events(sfRenderWindow *window);

// Menus
void display_window(const char *arg_map);
char *display_menu(sfRenderWindow *window, const char *arg_map);
void display_studio(sfRenderWindow *window);
void pause_menu(sfRenderWindow *window);
void disp_youwin(sfRenderWindow *window);
void disp_gameover(sfRenderWindow *window);

#endif /* !MY_RUNNER_H_ */
