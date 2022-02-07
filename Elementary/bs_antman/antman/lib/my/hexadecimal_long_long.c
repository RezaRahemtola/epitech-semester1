/*
** EPITECH PROJECT, 2021
** hexadecimal_long_long
** File description:
** printf
*/

#include "my.h"

void hexadecimal_long_long(long long nb)
{
    long long keep;
    char str[17] = "0123456789abcdef";

    if (nb < 0) {
        nb = nb * -1;
    }
    keep = nb;
    while (keep >= 16) {
        keep = keep % 16;
    }
    if (nb < 1) {
        return;
    }
    hexadecimal_long_long(nb / 16);
    my_putchar(str[keep]);
}
