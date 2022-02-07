/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** Functions to display env
*/

#include "minishell.h"

int my_env(char **argv, str_t **env)
{
    str_t *list = *env;

    argv = argv;
    for (; list != NULL; list = list->next)
        my_printf("%s\n", list->str);
    return (0);
}
