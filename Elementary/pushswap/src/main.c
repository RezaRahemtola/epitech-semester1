/*
** EPITECH PROJECT, 2021
** Pushswap
** File description:
** main
*/

#include <stdlib.h>
#include "pushswap.h"

static void my_put_in_list(linked_list_t **list, int data)
{
    linked_list_t *element;

    element = malloc(sizeof(linked_list_t));
    element->data = data;
    element->next = *list;
    *list = element;
}

static void my_rev_list(linked_list_t **begin)
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

static linked_list_t *my_params_to_list(int ac, char * const *av)
{
    linked_list_t *list = NULL;

    for (int i = 1; i < ac; i++)
        if (my_strcmp(av[i], "-v") != 0)
            my_put_in_list(&list, my_getnbr(av[i]));
    my_rev_list(&list);
    return (list);
}

static int check_if_verbose(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
        if (my_strcmp(argv[i], "-v") == 0)
            return (1);
    return (0);
}

int main(int argc, char **argv)
{
    linked_list_t *list_a = my_params_to_list(argc, argv);
    linked_list_t *list_b = NULL;
    int is_v = check_if_verbose(argc, argv);

    while (list_is_sorted(list_a) == 0 || list_b != NULL) {
        lowest_algo(&list_a, &list_b, is_v);
    }
    my_putchar('\n');
    return (0);
}
