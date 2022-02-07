/*
** EPITECH PROJECT, 2021
** octal
** File description:
** printf
*/

#include "my.h"

void octal(int nb)
{
    int keep;
    char str[8] = "01234567";

    if (nb < 0) {
        nb = nb * -1;
    }
    keep = nb;
    while (keep >= 8) {
        keep = keep % 8;
    }
    if (nb < 1) {
        return;
    }
    octal(nb / 8);
    my_putchar(str[keep]);
}
