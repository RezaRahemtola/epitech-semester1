/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** print un int
*/

#include "my.h"

int my_put_nbr(int nb)
{
    int keep;

    if (nb < 0) {
        nb = nb * -1;
        my_putchar('-');
    }
    keep = nb;
    while (keep >= 10) {
        keep = keep % 10;
    }
    if (nb < 1)
        return (0);
    my_put_nbr(nb / 10);
    my_putchar(keep + '0');
}
