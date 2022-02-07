/*
** EPITECH PROJECT, 2021
** my_strcpy
** File description:
** copie une string dans une autre
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int chaine = 0;

    for (; src[chaine] != dest[chaine]; chaine++) {
        dest[chaine] = src[chaine];
    }
    if (src[chaine] == '\0') {
        dest[chaine] = '\0';
    }
    return (dest);
}
