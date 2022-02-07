/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** Functions to use the env
*/

#include "minishell.h"

char *get_env_value(str_t *env, char *name)
{
    int i = 0;
    int len = my_strlen(name);
    char *path = NULL;
    char *tmp = NULL;

    while (env != NULL && my_strncmp(env->str, name, len) != 0) {
        i++;
        env = env->next;
    }
    if (env == NULL)
        return (NULL);
    tmp = my_strdup(env->str);
    tmp += len;
    path = my_strdup(tmp);
    tmp -= len;
    free(tmp);
    return (path);
}

str_t *array_to_list(char **array)
{
    str_t *list = NULL;

    for (int i = 0; array[i] != NULL; i++) {
        my_putend(array[i], &list);
    }
    return (list);
}

char **list_to_array(str_t *list)
{
    int len = my_list_len(list);
    char **array = malloc(sizeof(char *) * (len + 1));

    if (array == NULL)
        return (NULL);
    for (int i = 0; list != NULL; i++) {
        array[i] = my_strdup(list->str);
        list = list->next;
    }
    array[len] = NULL;
    return (array);
}
