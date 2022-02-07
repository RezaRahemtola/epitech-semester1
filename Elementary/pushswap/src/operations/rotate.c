/*
** EPITECH PROJECT, 2021
** Pushswap
** File description:
** my_rr
*/

#include <stddef.h>
#include "pushswap.h"

void my_reverse_rotate(linked_list_t **list)
{
    linked_list_t *tmp = *list;

    while (tmp->next->next != NULL)
        tmp = tmp->next;
    tmp->next->next = *list;
    *list = tmp->next;
    tmp->next = NULL;
}

void my_rotate(linked_list_t **list)
{
    linked_list_t *tmp = *list;

    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = *list;
    *list = (*list)->next;
    tmp->next->next = NULL;
}
