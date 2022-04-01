/*
** EPITECH PROJECT, 2021
** MY_PUT_NBR
** File description:
** Task07
*/

#include <stdlib.h>
#include "my.h"

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        if (nb == -2147483648) {
            my_putchar('2');
            nb = -147483648;
        }
        nb *= -1;
    }
    if (nb <= 9) {
        my_putchar(nb + 48);
    } else {
        my_put_nbr(nb / 10);
        my_putchar((nb % 10) + 48);
    }
    return (0);
}

char *my_nbr_to_string(unsigned int nb)
{
    char *str = malloc(sizeof(char) * 20);
    int i = 0;

    if (nb == 0) return ("0");
    for (; nb > 0; i++) {
        str[i] = (nb % 10) + '0';
        nb /= 10;
    }
    str[i] = '\0';
    return (my_revstr(str));
}
