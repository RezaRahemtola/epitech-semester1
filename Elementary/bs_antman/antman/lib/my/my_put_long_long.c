/*
** EPITECH PROJECT, 2021
** my_put_long_long
** File description:
** printf
*/

#include "my.h"

void my_put_long_long(long long nb)
{
    long long keep;

    if (nb < 0) {
        nb = nb * -1;
        my_putchar('-');
    }
    keep = nb;
    while (keep >= 10) {
        keep = keep % 10;
    }
    if (nb < 1)
        return;
    my_put_long_long(nb / 10);
    my_putchar(keep + '0');
}
