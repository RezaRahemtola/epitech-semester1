/*
** EPITECH PROJECT, 2021
** my_getnbr
** File description:
** transformer un char en int
*/

#include <stdio.h>
#include <string.h>
#include "my.h"

int my_getnbr(char const *str)
{
    int signe = 1;
    int count = 0;
    int nb = 0;
    int result = 0;

    for (; str[count] == '+' || str[count] == '-'; count++) {
        if (str[count] == '-')
            signe = -signe;
    }
    for (; str[count] >= '0' && str[count] <= '9'; count++) {
        nb = str[count] - '0';
        result = (result * 10) + nb;
    }
    result = result * signe;
    return (result);
}
