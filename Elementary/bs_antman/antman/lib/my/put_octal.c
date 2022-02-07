/*
** EPITECH PROJECT, 2021
** put_octal
** File description:
** printf
*/

#include "my.h"

void put_octal(char *str)
{
    for (int x = 0; str[x] != '\0'; x++) {
        if (str[x] > 32 && str[x] <= 127)
            my_putchar(str[x]);
        else {
            my_putchar('\\');
            my_putchar('0');
            my_putchar('0');
            octal(str[x]);
        }
    }
}
