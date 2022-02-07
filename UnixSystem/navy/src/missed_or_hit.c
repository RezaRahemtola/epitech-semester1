/*
** EPITECH PROJECT, 2021
** navy
** File description:
** signal_info
*/

#include "navy.h"

void send_missed_hit_signal(int attack)
{
    if (attack)
        send_signal("1011", navy_info->enemy_pid);
    else
        send_signal("1010", navy_info->enemy_pid);
}

int sig_is_missed_hit(char const *str)
{
    if (my_strcmp(str, "1011") == 0) return (1);
    if (my_strcmp(str, "1010") == 0) return (1);
    return (0);
}

void missed_or_hit(char **enemy_board, char const *pos)
{
    if (my_strcmp(navy_info->sig_str, "1011") == 0) {
        my_printf("hit\n\n");
        enemy_board[pos[1] - '1'][pos[0] - 'A'] = 'x';
        navy_info->enemy_hit++;
    }
    if (my_strcmp(navy_info->sig_str, "1010") == 0) {
        my_printf("missed\n\n");
        enemy_board[pos[1] - '1'][pos[0] - 'A'] = 'o';
    }
}
