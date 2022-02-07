/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** Functions for str linked list manipulation
*/

#include "minishell.h"

void obj_destroy(str_t *obj)
{
    free(obj->str);
    free(obj);
}

void list_destroy(str_t *list)
{
    str_t *tmp = NULL;

    while (list != NULL) {
        tmp = list;
        list = list->next;
        free(tmp->str);
        free(tmp);
    }
}

void my_putend(char *str, str_t **dest)
{
    str_t *list = *dest;
    str_t *obj = malloc(sizeof(str_t));

    obj->str = my_strdup(str);
    obj->next = NULL;

    if (list == NULL) {
        *dest = obj;
        return;
    }
    while (list->next != NULL)
        list = list->next;
    list->next = obj;
}

int my_list_len(str_t *list)
{
    int i = 0;

    while (list != NULL) {
        i++;
        list = list->next;
    }
    return (i);
}
