/*
** EPITECH PROJECT, 2022
** minishell
** File description:
** Parsing functions
*/

#include "minishell.h"

static bool is_valid_command(const char *command)
{
    struct stat sb;

    if (get_builtin(command) != -1)
        return (true);
    if (lstat(command, &sb) == -1)
        return (false);
    if (access(command, X_OK) == -1)
        return (false);
    if (S_ISDIR(sb.st_mode))
        return (false);
    if (my_strstr(command, "/") == NULL)
        return (false);
    return (true);
}

static void disp_command_error(const char *command)
{
    struct stat sb;

    if (access(command, F_OK) == -1 || my_strstr(command, "/") == NULL) {
        my_puterror(command);
        my_puterror(": Command not found.\n");
        return;
    }
    if (lstat(command, &sb) == -1)
        return;
    if (S_ISDIR(sb.st_mode) || access(command, X_OK) == -1) {
        my_puterror(command);
        my_puterror(": Permission denied.\n");
        return;
    }
}

static char **get_paths(str_t *env)
{
    char *str = get_env_value(env, "PATH=");
    char **paths = NULL;

    if (str == NULL)
        return (NULL);
    paths = str_to_word_array(str, ':');
    free(str);
    return (paths);
}

static char *search_paths(char **paths, char *command)
{
    int len = 0;
    char *curr = NULL;

    if (paths == NULL)
        return (NULL);
    for (int i = 0; paths[i] != NULL; i++) {
        len = my_strlen(paths[i]) + my_strlen(command) + 2;
        curr = my_str_allocfill(sizeof(char) * len, '\0');
        my_strcat(my_strcat(my_strcat(curr, paths[i], 0), "/", 0), command, 0);
        if (is_valid_command(curr)) {
            my_free_2d_array(paths);
            return (curr);
        }
        free(curr);
    }
    my_free_2d_array(paths);
    return (NULL);
}

char *get_command_path(char *command, str_t *env)
{
    char **paths = get_paths(env);
    char *path_command = NULL;

    if (is_valid_command(command)) {
        my_free_2d_array(paths);
        return (my_strdup(command));
    }
    path_command = search_paths(paths, command);
    if (path_command != NULL)
        return (path_command);
    disp_command_error(command);
    return (NULL);
}
