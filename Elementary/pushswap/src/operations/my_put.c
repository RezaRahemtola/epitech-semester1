/*
** EPITECH PROJECT, 2021
** Pushswap
** File description:
** my_put
*/

#include "pushswap.h"

void my_put(linked_list_t **src, linked_list_t **dest)
{
    linked_list_t *elem = *src;

    *src = elem->next;
    elem->next = *dest;
    *dest = elem;
}
