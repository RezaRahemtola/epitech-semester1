/*
** EPITECH PROJECT, 2021
** pushswap
** File description:
** .h
*/

#ifndef PUSHSWAP_H_
    #define PUSHSWAP_H_
    #define INT_MIN -2147483648
    #define INT_MAX 2147483647
    #include "my.h"
    typedef struct linked_list {
        int data;
        struct linked_list *next;
    } linked_list_t;
    #include "operations.h"
    int list_is_sorted(linked_list_t *begin);
    void disp_op(char *op, linked_list_t *, linked_list_t *, int is_v);
    void lowest_algo(linked_list_t **, linked_list_t **, int is_v);
#endif /* !PUSHSWAP_H_ */
