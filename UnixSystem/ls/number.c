/*
** EPITECH PROJECT, 2021
** EVAL_EXPR
** File description:
** NUMBER
*/

#include "my.h"
#include <stdlib.h>

char *number(char **str_ptr)
{
    char *result = malloc(sizeof(char) * my_strlen(*str_ptr));
    int i = 0;
    int j = 0;

    while ((*str_ptr)[i] != '\0') {
        if ((*str_ptr)[i] - '0' >= 0 && (*str_ptr)[i] - '0' <= 9) {
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
