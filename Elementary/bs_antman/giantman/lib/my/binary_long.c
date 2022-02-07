/*
** EPITECH PROJECT, 2021
** binary_long
** File description:
** printf
*/

#include "my.h"

void binary_long(long nb)
{
    long keep;
    char str[3] = "01";

    if (nb < 0) {
        nb = nb * -1;
    }
    keep = nb;
    while (keep >= 2) {
        keep = keep % 2;
    }
    if (nb < 1) {
        return;
    }
    binary_long(nb / 2);
    my_putchar(str[keep]);
}
