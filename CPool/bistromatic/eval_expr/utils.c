/*
** EPITECH PROJECT, 2021
** utils
** File description:
** desc
*/

#include <stdlib.h>
#include "my.h"

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

char *remove_zero(char const *str)
{
    int i = 0;
    int j = 0;
    char *res = my_strdup(str);

    if (str[0] == '-') {
        res[0] = '-';
        i = 1;
        j = 1;
    }
    while (str[i] == '0' && str[i + 1])
        i++;
    while (str[i]) {
        res[j] = str[i];
        i++;
        j++;
    }
    res[j] = '\0';
    return (res);
}
