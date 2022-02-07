/*
** EPITECH PROJECT, 2021
** push_swap
** File description:
** Utils functions for pushswap
*/

#include <stddef.h>
#include "pushswap.h"
#include <unistd.h>

int list_is_sorted(linked_list_t *begin)
{
    int last_value = INT_MIN;
    linked_list_t *tmp = begin;

    while (tmp != NULL) {
        if (tmp->data < last_value) return (0);
        last_value = tmp->data;
        tmp = tmp->next;
    }
    return (1);
}
