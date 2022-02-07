/*
** EPITECH PROJECT, 2021
** navy
** File description:
** Functions to connect the 2 players
*/

#include "navy.h"

static void handler(int sig, siginfo_t *si, void *ucontext)
{
    if (sig == SIGUSR2)
        my_strcat(navy_info->sig_str, "1");
    else if (sig == SIGUSR1)
        my_strcat(navy_info->sig_str, "0");
    if (my_strcmp(navy_info->sig_str, "1000") == 0)
        navy_info->enemy_pid = si->si_pid;
    ucontext = ucontext;
}

int connect_player1(char *pos_path)
{
    struct sigaction sa;

    sa.sa_sigaction = handler;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR2, &sa, NULL);
    sigaction(SIGUSR1, &sa, NULL);
    my_printf("waiting for enemy connection...\n\n");
    while (my_strcmp(navy_info->sig_str, "1000") != 0)
        pause();
    my_printf("enemy connected\n\n");
    empty_sig_str(navy_info->sig_str);
    return (play_game(pos_path, 1));
}

int connect_player2(pid_t pid, char *pos_path)
{
    struct sigaction sa;
    int connection = kill(pid, SIGUSR2);
    int won = -1;
    navy_info->enemy_pid = pid;

    sa.sa_sigaction = handler;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR2, &sa, NULL);
    sigaction(SIGUSR1, &sa, NULL);
    if (connection == 0) {
        my_printf("successfully connected\n\n");
        send_signal("000", pid);
        won = play_game(pos_path, 0);
    }
    return (won);
}
