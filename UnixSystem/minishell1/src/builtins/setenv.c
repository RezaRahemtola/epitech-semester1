/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** Functions for the setenv builtin
*/

#include "minishell.h"

static bool check_setenv_errors(int argc, char **argv)
{
    if (argc > 3) {
        my_puterror("setenv: Too many arguments.\n");
        return (true);
    }
    if (argc >= 2 && my_char_isalpha(argv[1][0]) == false) {
        my_puterror("setenv: Variable name must begin with a letter.\n");
        return (true);
    }
    if (argc >= 2 && my_str_isalphanum(argv[1]) == false) {
        my_puterror("setenv: Variable name must contain ");
        my_puterror("alphanumeric characters.\n");
        return (true);
    }
    return (false);
}

static void update_current_var(str_t *list, char *var, char *new)
{
    while (list != NULL) {
        if (my_strncmp(var, list->str, my_strlen(var)) == 0) {
            free(list->str);
            list->str = new;
            break;
        }
        list = list->next;
    }
}

static void set_var(str_t **list, char *var, char *value)
{
    char *full_var = my_newstrcat(var, "=", 0, 0);
    char *current_value = get_env_value(*list, full_var);
    int len = my_strlen(var) + my_strlen(value) + 2;
    char *new = my_str_allocfill(len, '\0');

    my_strcpy(new, var);
    my_strcat(new, "=", 0);
    my_strcat(new, value, 0);
    if (current_value == NULL) {
        my_putend(new, list);
        free(new);
    } else {
        update_current_var(*list, full_var, new);
    }
    free(current_value);
    free(full_var);
}

int my_setenv(char **argv, str_t **env)
{
    int exit = 0;
    int argc = my_arraylen(argv);

    if (check_setenv_errors(argc, argv))
        return (1);
    if (argc == 1) {
        my_env(argv, env);
    } else {
        set_var(env, argv[1], argv[2]);
    }
    return (exit);
}
