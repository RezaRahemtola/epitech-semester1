/*
** EPITECH PROJECT, 2021
** Rush1
** File description:
** utils
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

char *int_to_str(int nb, int len)
{
    char *new_str = malloc(sizeof(char) * len);
    int i = 0;

    while (nb / 10 != 0) {
        new_str[i] = nb % 10 + '0';
        nb /= 10;
        i++;
    }
    new_str[i] = nb % 10 + '0';
    new_str[i + 1] = '\0';
    return (my_revstr(new_str));
}
