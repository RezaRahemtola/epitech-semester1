/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** compte la chaine de caractère
*/

#include "my.h"

void my_putchar(char c);

int my_putstr(char const *str)
{
    int chaine;

    chaine = 0;
    while (str[chaine] != '\0') {
        my_putchar(str[chaine]);
        chaine++;
    }
    return (0);
}
