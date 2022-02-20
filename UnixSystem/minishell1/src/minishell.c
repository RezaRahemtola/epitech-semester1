/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** Main functions
*/

#include "minishell.h"

static void empty_command(command_t *command)
{
    if (command->path != NULL)
        free(command->path);
    my_free_2d_array(command->argv);
}

int minishell(char **original_env)
{
    list_t *env = array_to_mylist(original_env, &my_strdup);
    command_t *command = malloc(sizeof(command_t));
    int exit = 0;
    bool is_exit = false;

    while (!is_exit && get_user_input(&command, env) != -1) {
        if (my_arraylen(command->argv) == 0)
            continue;
        exit = exec_command(command, &env, &is_exit);
        empty_command(command);
    }
    mylist_destroy(env, true);
    free(command);
    return (exit);
}
