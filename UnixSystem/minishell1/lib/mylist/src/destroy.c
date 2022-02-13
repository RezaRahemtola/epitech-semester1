/*
** EPITECH PROJECT, 2022
** LIBLIST
** File description:
** Functions to destroy list elements
*/

#include <stdlib.h>
#include "mylist.h"

void obj_destroy(list_t *obj, bool free_data)
{
    if (free_data)
        free(obj->data);
    free(obj);
}

void mylist_destroy(list_t *list, bool free_data)
{
    list_t *tmp = NULL;

    while (list != NULL) {
        tmp = list;
        list = list->next;
        obj_destroy(tmp, free_data);
    }
}
