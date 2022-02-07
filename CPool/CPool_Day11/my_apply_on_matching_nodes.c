/*
** EPITECH PROJECT, 2021
** MY_APPLY_ON_MATCHING_NODES
** File description:
** Task05
*/

#include <stddef.h>
#include "include/mylist.h"

int my_apply_on_matching_nodes(linked_list_t *begin, int (*f)(), \
void const *data_ref, int (*cmp)())
{
    linked_list_t *tmp;

    tmp = begin;
    while (tmp != NULL) {
        if ((*cmp)(tmp->data, data_ref) == 0) {
            (*f)(tmp->data);
        }
        tmp = tmp->next;
    }
    return (0);
}
