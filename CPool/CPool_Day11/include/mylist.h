/*
** EPITECH PROJECT, 2021
** mylist.h
** File description:
** Day11
*/

#ifndef MY_LIST_
    #define MY_LIST_
typedef struct linked_list {
    void *data;
    struct linked_list *next;
} linked_list_t;
#endif
