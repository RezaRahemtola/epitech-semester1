/*
** EPITECH PROJECT, 2021
** MY_REV_LIST
** File description:
** Task03
*/

#include <stddef.h>
#include "include/mylist.h"

void my_rev_list(linked_list_t **begin)
{
    linked_list_t *previous = NULL;
    linked_list_t *current = *begin;
    linked_list_t *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    *begin = previous;
}
