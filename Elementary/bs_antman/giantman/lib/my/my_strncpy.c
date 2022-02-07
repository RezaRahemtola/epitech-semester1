/*
** EPITECH PROJECT, 2021
** my_strncpy
** File description:
** copie une string dans une autre jusqu'à tel caractère
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int chaine = 0;
    int chaine2 = 0;

    while (src[chaine2] != '\0') {
        chaine2++;
    } if (n > chaine2) {
        return (0);
    } if (n < chaine2) {
        for (; chaine < n && src[chaine] != '\0'; chaine++) {
            dest[chaine] = src[chaine];
        }
    }
    return (dest);
}
