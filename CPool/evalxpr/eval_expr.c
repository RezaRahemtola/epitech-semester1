/*
** EPITECH PROJECT, 2021
** eval_expr
** File description:
** Main file
*/

#include <stddef.h>
#include "include/my.h"
#include "include/eval_expr.h"

int eval_expr(char const *str)
{
    char *str_copy = my_strdup(str);

    while (my_strstr(str_copy, ")") != NULL)
        str_copy = parenthesis(&str_copy);
    str_copy = factors(&str_copy);
    return (summands(&str_copy));
}
