/*
** EPITECH PROJECT, 2021
** rush3
** File description:
** rush
*/

#include <stdlib.h>
#include <stddef.h>
#include "my.h"
#include "rush3.h"

char *concat(char *result, int x, int y, char *rush_str)
{
    char *str = malloc(sizeof(char) * 100);

    if (my_strlen(result) != 0) {
        my_strcat(str, " || ");
    }
    my_strcat(str, rush_str);
    my_strcat(str, " ");
    my_strcat(str, int_to_str(x));
    my_strcat(str, " ");
    my_strcat(str, int_to_str(y));
    return (str);
}

char *stumper(char *buff)
{
    int x = get_size_x(buff);
    int y = get_size_y(buff);
    char *result = malloc(sizeof(char) * 1000);

    if (my_strlen(buff) == 0)
        return ("none\n");
    if (my_strcmp(buff, rush1(x, y)) == 0)
        my_strcat(result, concat(result, x, y, "[rush1-1]"));
    if (my_strcmp(buff, rush2(x, y)) == 0)
        my_strcat(result, concat(result, x, y, "[rush1-2]"));
    if (my_strcmp(buff, rush3(x, y)) == 0)
        my_strcat(result, concat(result, x, y, "[rush1-3]"));
    if (my_strcmp(buff, rush4(x, y)) == 0)
        my_strcat(result, concat(result, x, y, "[rush1-4]"));
    if (my_strcmp(buff, rush5(x, y)) == 0)
        my_strcat(result, concat(result, x, y, "[rush1-5]"));
    my_strcat(result, "\n");
    if (my_strlen(result) == 1)
        return ("none\n");
    return result;
}
