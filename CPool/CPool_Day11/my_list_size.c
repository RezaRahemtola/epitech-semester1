/*
** EPITECH PROJECT, 2021
** MY_LIST_SIZE
** File description:
** Task02
*/

#include <stddef.h>
#include "include/mylist.h"

int my_list_size(linked_list_t const *begin)
{
    int nb = 0;
    linked_list_t *tmp;

    if (begin == NULL) {
        return (nb);
    }
    tmp = begin->next;
    nb++;
    while (tmp != NULL) {
        nb++;
        tmp = tmp->next;
    }
    return (nb);
}
