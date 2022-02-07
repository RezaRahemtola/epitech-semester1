/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** Functions for unsetenv builtin
*/

#include "minishell.h"

static bool check_unsetenv_errors(int argc)
{
    if (argc == 1) {
        my_puterror("unsetenv: Too few arguments.\n");
        return (true);
    }
    return (false);
}

static void remove_all(str_t **list)
{
    str_t *tmp = NULL;

    while (*list != NULL) {
        tmp = *list;
        *list = (*list)->next;
        obj_destroy(tmp);
    }
}

static void remove_var(char *var, str_t **list)
{
    int len = my_strlen(var) + 1;
    char *pattern = my_newstrcat(var, "=", 0, 0);
    str_t *tmp = *list;
    str_t *previous = *list;

    if (tmp != NULL && my_strncmp(pattern, tmp->str, len) == 0) {
        *list = tmp->next;
        obj_destroy(tmp);
        free(pattern);
        return;
    }
    while (tmp != NULL && my_strncmp(pattern, tmp->str, len) != 0) {
        previous = tmp;
        tmp = tmp->next;
    }
    free(pattern);
    if (tmp == NULL)
        return;
    previous->next = tmp->next;
    obj_destroy(tmp);
}

int my_unsetenv(char **argv, str_t **env)
{
    int exit = 0;
    int argc = my_arraylen(argv);

    if (check_unsetenv_errors(argc))
        return (1);
    for (int i = 1; argv[i] != NULL; i++) {
        if (my_strcmp(argv[i], "*") == 0) {
            remove_all(env);
        } else {
            remove_var(argv[i], env);
        }
    }
    return (exit);
}
