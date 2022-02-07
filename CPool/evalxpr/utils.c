/*
** EPITECH PROJECT, 2021
** utils
** File description:
** desc
*/

#include <stdlib.h>
#include "include/my.h"

char *int_to_str(int nb, int len)
{
    char *new_str = malloc(sizeof(char) * len);
    int i = 0;
    int negative = 0;

    if (nb < 0) {
        negative = 1;
        nb *= -1;
    }
    while (nb / 10 != 0) {
        new_str[i] = nb % 10 + '0';
        nb /= 10;
        i++;
    }
    new_str[i] = nb % 10 + '0';
    if (negative == 1) {
        new_str[i + 1] = '-';
        i++;
    }
    new_str[i + 1] = '\0';
    return (my_revstr(new_str));
}

char *char_to_str(char c)
{
    char str[2] = "\0";

    str[0] = c;
    return (my_strdup(str));
}
