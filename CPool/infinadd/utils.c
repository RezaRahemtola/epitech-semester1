/*
** EPITECH PROJECT, 2021
** INFIN_ADD
** File description:
** utils
*/

#include <stdlib.h>
#include "include/my.h"

int get_digit(char *nb, int i)
{
    if (nb[i] == '\0' || nb[i] == '-') {
        nb[i + 1] = '\0';
        return (0);
    } else {
        return (ATOD(nb[i]));
    }
}

int get_biggest_len(char *nb1, char *nb2)
{
    int len1 = my_strlen(nb1);
    int len2 = my_strlen(nb2);

    if (len1 >= len2)
        return (len1);
    else
        return (len2);
}

char *copy_str_except_first(char *str)
{
    char *new_str = malloc(sizeof(char) * my_strlen(str));
    int i = 1;

    while (str[i] != '\0') {
        new_str[i - 1] = str[i];
        i++;
    }
    new_str[i] = '\0';
    return (new_str);
}
