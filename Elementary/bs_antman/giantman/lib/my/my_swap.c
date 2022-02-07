/*
** EPITECH PROJECT, 2021
** my_swap
** File description:
** swap des int
*/

#include "my.h"

void my_swap(int *a, int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}
