/*
** EPITECH PROJECT, 2021
** EVAL_EXPR
** File description:
** NUMBER
*/

#include "my.h"
#include <stdlib.h>

static int check_consecutive_negative(int i, char *str)
{
    int nb = 0;

    while (i >= 0 && (str[i] == '-' || str[i] == '+')) {
        if (str[i] == '-')
            nb++;
        i--;
    }
    return (nb);
}

static int check_negative(int i, char *str, char *result, int j)
{
    if (j == 0 && check_consecutive_negative(i - 1, str) % 2 == 1) {
        result[j] = '-';
        return (1);
    }
    return (0);
}

char *number(char **str_ptr)
{
    char *result = malloc(sizeof(char) * my_strlen(*str_ptr));
    int i = 0;
    int j = 0;

    while ((*str_ptr)[i] != '\0') {
        if ((*str_ptr)[i] - '0' >= 0 && (*str_ptr)[i] - '0' <= 9) {
            j += check_negative(i, *str_ptr, result, j);
            result[j] = (*str_ptr)[i];
            j++;
        }
        if (((*str_ptr)[i] - '0' < 0 || (*str_ptr)[i] - '0' > 9) && j > 0)
            break;
        i++;
    }
    *str_ptr += i;
    result[j] = '\0';
    return (result);
}
