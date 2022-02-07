/*
** EPITECH PROJECT, 2021
** my_memset
** File description:
** my_memset
*/

#include "my.h"

void *my_memset(void *s, int c, size_t n)
{
    char *temp = s;

    for (int i = 0; i < n; i++) {
        temp[i] = c;
    }

    return s;
}
