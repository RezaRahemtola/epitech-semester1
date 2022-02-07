/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** compte la string
*/

#include "my.h"

int my_strlen(char const *str)
{
    int chaine2 = 0;

    while (str[chaine2] != '\0') {
        chaine2++;
    }
    return (chaine2);
}
