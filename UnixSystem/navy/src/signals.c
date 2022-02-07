/*
** EPITECH PROJECT, 2021
** navy
** File description:
** Functions to send, receive and convert signals
*/

#include "navy.h"

void empty_sig_str(char *str)
{
    int len = my_strlen(str);

    for (int i = 0; i < len; i++)
        str[i] = '\0';
}

int sig_is_pos(char const *str)
{
    if (my_strlen(str) != 8) return (0);
    if (str[0] != '0' || str[4] != '0') return (0);
    return (1);
}

void send_signal(char const *sig_str, pid_t pid)
{
    for (int i = 0; i < my_strlen(sig_str); i++) {
        nanosleep((const struct timespec[]){{0, 10000000}}, NULL);
        if (sig_str[i] == '0')
            kill(pid, SIGUSR1);
        else if (sig_str[i] == '1')
            kill(pid, SIGUSR2);
    }
}

void send_pos_signal(char const *pos, pid_t pid)
{
    char *first_pos = int_to_base(pos[0] - 'A', "01");
    char *second_pos = int_to_base(pos[1] - '1', "01");
    char *pos_str = malloc(sizeof(char) * 9);

    pos_str[0] = '0';
    for (int i = 3; my_strlen(first_pos) < i; i--)
        my_strcat(pos_str, "0");
    my_strcat(pos_str, first_pos);
    pos_str[4] = '0';
    for (int i = 3; my_strlen(second_pos) < i; i--)
        my_strcat(pos_str, "0");
    my_strcat(pos_str, second_pos);
    send_signal(pos_str, pid);
    free(first_pos);
    free(second_pos);
    free(pos_str);
}
