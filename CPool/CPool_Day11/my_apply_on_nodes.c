/*
** EPITECH PROJECT, 2021
** MY_APPLY_ON_NODES
** File description:
** Task04
*/

#include <stddef.h>
#include "include/mylist.h"

int my_apply_on_nodes(linked_list_t *begin, int (*f)(void *))
{
    linked_list_t *tmp;

    tmp = begin;
    while (tmp != NULL) {
        (*f)(tmp->data);
        tmp = tmp->next;
    }
    return (0);
}
