/*
** EPITECH PROJECT, 2021
** Pushswap
** File description:
** Display operation with space if needed
*/

#include <stddef.h>
#include "pushswap.h"

static void my_show_list(linked_list_t *list)
{
    linked_list_t *tmp;

    tmp = list;
    while (tmp != NULL) {
        my_put_nbr(tmp->data);
        if (tmp->next != NULL)
            my_putchar(' ');
        tmp = tmp->next;
    }
    my_putchar('\n');
}

void disp_op(char *op, linked_list_t *list_a, linked_list_t *list_b, int is_v)
{
    if (list_is_sorted(list_a) && list_b == NULL) {
        my_putstr(op);
    } else {
        my_putstr(op);
        my_putchar(' ');
    }
    if (is_v) {
        my_putstr("\nl_a: ");
        my_show_list(list_a);
        my_putstr("l_b: ");
        my_show_list(list_b);
    }
}
