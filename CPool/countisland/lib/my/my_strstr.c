/*
** EPITECH PROJECT, 2021
** MY_STRSTR
** File description:
** Task05
*/

#include <stddef.h>

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int found = 0;
    int i_to_find = 0;
    int strlen = 0;

    while (to_find[strlen] != '\0')
        strlen++;
    if (strlen == 0)
        return (str);
    while (str[i] != '\0' && found == 0) {
        if ((str[i] != to_find[i_to_find]) && (str[i] != str[i - 1]))
            i_to_find = 0;
        if (str[i] == to_find[i_to_find])
            i_to_find++;
        if (to_find[i_to_find] == '\0')
            return (&str[i - i_to_find + 1]);
        i++;
    }
    return (NULL);
}
