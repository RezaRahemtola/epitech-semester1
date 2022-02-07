/*
** EPITECH PROJECT, 2021
** navy
** File description:
** turn
*/

#include "navy.h"

static int attack_board(char *pos, char **my_board)
{
    char content = my_board[pos[1] - '0'][pos[0] - '0'];

    if (content == 'x') {
        return (0);
    } else if (content == '.' || content == 'o') {
        my_board[pos[1] - '0'][pos[0] - '0'] = 'o';
        return (0);
    } else {
        my_board[pos[1] - '0'][pos[0] - '0'] = 'x';
        return (1);
    }
}

static char *get_input_pos(void)
{
    size_t bufsize = 3;
    char *buffer = malloc(sizeof(char) * bufsize);
    int size = 0;
    int invalid_output = 1;

    while (invalid_output) {
        size = getline(&buffer, &bufsize, stdin);
        if (size != 3 || is_wrong_pos(buffer) == 84)
            my_printf("wrong position\nattack: ");
        else {
            buffer[2] = '\0';
            my_printf("%s: ", buffer);
            invalid_output = 0;
        }
    }
    return (buffer);
}

void defend(char *pos, char **my_board)
{
    int attack = 0;

    my_printf("waiting for enemy's attack...\n");
    while (sig_is_pos(navy_info->sig_str) == 0)
        pause();
    pos = binary_to_pos();
    attack = attack_board(pos, my_board);
    if (attack)
        my_printf("%c%c: hit\n\n", pos[0] + 17, pos[1] + 1);
    else
        my_printf("%c%c: missed\n\n", pos[0] + 17, pos[1] + 1);
    send_missed_hit_signal(attack);
    empty_sig_str(navy_info->sig_str);
}

void attack_enemy(char *pos, char **enemy_board)
{
    my_printf("attack: ");
    pos = get_input_pos();
    send_pos_signal(pos, navy_info->enemy_pid);
    while (sig_is_missed_hit(navy_info->sig_str) == 0)
        pause();
    missed_or_hit(enemy_board, pos);
    empty_sig_str(navy_info->sig_str);
}
