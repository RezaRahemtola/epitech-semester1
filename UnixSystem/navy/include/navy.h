/*
** EPITECH PROJECT, 2021
** navy
** File description:
** navy.h
*/

#ifndef NAVY_H_
    #define NAVY_H_
    #define _XOPEN_SOURCE 700
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <stddef.h>
    #include <stdlib.h>
    #include <signal.h>
    #include <time.h>
    #include "my.h"

typedef struct navy_info_s {
    char sig_str[9];
    pid_t enemy_pid;
    int enemy_hit;
} navy_info_t;

extern navy_info_t *navy_info;

int check_errors(int argc, char **argv);

int connect_player1(char *pos_path);
int connect_player2(pid_t pid, char *pos_path);

void disp_board(char **board);
int are_all_ships_hit(char **my_board, int enemy_hit);
char **create_empty_board(void);
char **load_board_from_file(char const *path);
int is_wrong_pos(char const *pos);

int play_game(char *pos_path, int playing);
char *binary_to_pos(void);

void send_signal(char const *sig_str, pid_t pid);
void send_pos_signal(char const *pos, pid_t pid);
void empty_sig_str(char *str);
int sig_is_pos(char const *str);

void send_missed_hit_signal(int attack);
int sig_is_missed_hit(char const *str);
void missed_or_hit(char **my_board, char const *pos);

void attack_enemy(char *pos, char **enemy_board);
void defend(char *pos, char **my_board);

#endif /* !NAVY_H_ */
