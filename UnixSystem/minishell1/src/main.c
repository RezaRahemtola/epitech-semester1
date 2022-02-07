/*
** EPITECH PROJECT, 2022
** bs minishell
** File description:
** step 1
*/

#include <signal.h>
#include "minishell.h"

static void sigint_handler(int param)
{
    if (isatty(0))
        my_printf("\n$> ");
    param = param;
}

int main(int argc, char **argv, char **env)
{
    int exit = 0;

    if (check_errors(argc, argv) == 84)
        return (84);
    signal(SIGINT, sigint_handler);
    exit = minishell(env);
    if (isatty(0))
        my_putstr("exit\n");
    return (exit);
}
