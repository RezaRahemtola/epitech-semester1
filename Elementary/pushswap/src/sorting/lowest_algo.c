/*
** EPITECH PROJECT, 2021
** Pushswap
** File description:
** First algo, find the lowest and push it in l_b
*/

#include <stddef.h>
#include "pushswap.h"

static int get_min_in_list(linked_list_t *begin)
{
    int min = INT_MAX;
    linked_list_t *tmp = begin;

    while (tmp != NULL) {
        min = (tmp->data < min) ? (tmp->data) : (min);
        tmp = tmp->next;
    }
    return (min);
}

static int get_nb_elem_in_list(linked_list_t *list)
{
    linked_list_t *tmp = list;
    int count = 0;

    while (tmp != NULL) {
        count++;
        tmp = tmp->next;
    }
    return (count);
}

static int get_elem_index(linked_list_t *list, int elem)
{
    linked_list_t *tmp = list;
    int pos = 0;

    while (tmp != NULL) {
        pos++;
        if (tmp->data == elem)
            return (pos);
        tmp = tmp->next;
    }
    return (pos);
}

static void optimize_rotate(linked_list_t **list_a, linked_list_t **list_b,
int min, int is_v)
{
    int nb_elem = get_nb_elem_in_list(*list_a);
    int min_pos = get_elem_index(*list_a, min);

    if (nb_elem / 2 > min_pos) {
        my_rotate(list_a);
        disp_op("ra", *list_a, *list_b, is_v);
    } else {
        my_reverse_rotate(list_a);
        disp_op("rra", *list_a, *list_b, is_v);
    }
}

void lowest_algo(linked_list_t **list_a, linked_list_t **list_b, int is_v)
{
    int min = 0;

    if ((*list_a)->next != NULL && list_is_sorted(*list_a) == 0) {
        min = get_min_in_list(*list_a);
        if ((*list_a)->data > min) {
            optimize_rotate(list_a, list_b, min, is_v);
        } else {
            my_put(list_a, list_b);
            disp_op("pb", *list_a, *list_b, is_v);
        }
    } else {
        while ((*list_b) != NULL) {
            my_put(list_b, list_a);
            disp_op("pa", *list_a, *list_b, is_v);
        }
    }
}
