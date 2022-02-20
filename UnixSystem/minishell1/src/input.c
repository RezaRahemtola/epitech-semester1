/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** Functions to handle input
*/

#include "minishell.h"

static char *get_home_buffer(char *buffer, list_t *env)
{
    char *new_buffer = NULL;
    char *home = get_env_value(env, "HOME=");

    if (home == NULL) {
        new_buffer = my_strdup(buffer);
    } else {
        new_buffer = my_streplace(buffer, "~", home);
    }
    free(home);
    return (new_buffer);
}

static void fill_command_struct(command_t **command, char *buffer, list_t *env)
{
    (*command)->argv = str_to_word_array(buffer);
    if ((*command)->argv != NULL) {
        (*command)->path = get_command_path((*command)->argv[0], env);
    } else {
        (*command)->path = NULL;
    }
}

int get_user_input(command_t **command, list_t *env)
{
    size_t size = 0;
    int read = 0;
    char *buffer = NULL;
    char *home_buffer = NULL;

    if (isatty(0))
        my_putstr("$> ");
    read = getline(&buffer, &size, stdin);
    if (read != -1) {
        buffer[read - 1] = '\0';
        home_buffer = get_home_buffer(buffer, env);
        fill_command_struct(command, home_buffer, env);
        free(home_buffer);
    }
    free(buffer);
    return (read);
}
