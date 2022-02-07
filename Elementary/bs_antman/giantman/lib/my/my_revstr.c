/*
** EPITECH PROJECT, 2021
** my_revstr
** File description:
** mets à l'envers une string
*/

#include "my.h"

char *my_revstr(char *str)
{
    char x;
    int end;
    int n = 0;

    for (;str[n] != '\0'; n++) {
    }
    end = n - 1;
    for (int start = 0; start != n / 2; start++) {
        x = str[start];
        str[start] = str[end];
        str[end] = x;
        end--;
    }
    return (str);
}
