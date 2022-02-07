/*
** EPITECH PROJECT, 2021
** MY_PARAMS_TO_LIST
** File description:
** Task01
*/

#include <stdlib.h>
#include <stddef.h>
#include "include/my.h"
#include "include/mylist.h"

void my_show_list(linked_list_t *list)
{
    linked_list_t *tmp;

    tmp = list;
    while (tmp != NULL) {
        my_putstr(tmp->data);
        my_putchar('\n');
        tmp = tmp->next;
    }
}

static void my_put_in_list(linked_list_t **list, void *data)
{
    linked_list_t *element;

    element = malloc(sizeof(*element));
    element->data = data;
    element->next = *list;
    *list = element;
}

linked_list_t *my_params_to_list(int ac, char * const *av)
{
    linked_list_t *list;

    list = NULL;
    for (int i = 0; i < ac; i++)
        my_put_in_list(&list, av[i]);
    return (list);
}
