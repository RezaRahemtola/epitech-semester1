/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** colle deux strings ensembles
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int x = 0;
    int y = 0;

    for (; dest[x] != '\0'; x++);
    for (; src[y] != '\0'; y++)
        dest[x + y] = src[y];
    dest[x + y] = '\0';
    return (dest);
}
