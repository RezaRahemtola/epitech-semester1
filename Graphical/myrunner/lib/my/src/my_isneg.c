/*
** EPITECH PROJECT, 2021
** MY_ISNEG
** File description:
** Task04
*/

#include "my.h"

int my_isneg(int n)
{
    if (n < 0) {
        my_putchar('N');
    } else {
        my_putchar('P');
    }
    return (0);
}
