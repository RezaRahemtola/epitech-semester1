/*
** EPITECH PROJECT, 2021
** MY_STRDUP
** File description:
** Task01
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *str);

char *my_strdup(char const *src)
{
    char *new_str;

    new_str = malloc(sizeof(char) * my_strlen(src) + 1);
    my_strcpy(new_str, src);
    return (new_str);
}
