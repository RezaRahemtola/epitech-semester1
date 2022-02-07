/*
** EPITECH PROJECT, 2021
** CHARINSTR
** File description:
** count the number of one char in a str
*/

#include "include/my.h"

int my_charinstr(char *str, char c)
{
    int i = 0;
    int occurences = 0;

    if (c >= 'a' && c <= 'z') {
        str = my_strlowcase(str);
    } else if (c >= 'A' && c <= 'Z') {
        str = my_strupcase(str);
    } else {
        return (-1);
    }
    while (str[i]) {
        if (str[i] == c)
            occurences++;
        i++;
    }
    return (occurences);
}
