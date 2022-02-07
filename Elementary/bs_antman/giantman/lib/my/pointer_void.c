/*
** EPITECH PROJECT, 2021
** pointer_void
** File description:
** printf
*/

#include "my.h"

void pointer_void(unsigned long long nb)
{
    if (nb == 0)
        my_printf("(nil)");
    else {
        my_putchar('0');
        my_putchar('x');
        hexadecimal_long(nb);
    }
}
