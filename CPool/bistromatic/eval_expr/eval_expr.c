/*
** EPITECH PROJECT, 2021
** eval_expr
** File description:
** Main file
*/

#include <stddef.h>
#include "my.h"
#include "eval_expr.h"
#include "bistromatic.h"

char *eval_expr(char const *ops, char const *expr)
{
    char *expr_cpy = my_strdup(expr);

    clean_ops(&expr_cpy, ops);
    while (my_strstr(expr_cpy, ")") != NULL)
        expr_cpy = parenthesis(&expr_cpy);
    if (my_strstr(expr_cpy, "*") != 0 || my_strstr(expr_cpy, "/") != 0 ||
        my_strstr(expr_cpy, "%") != 0) {
        expr_cpy = factors(&expr_cpy);
    }
    return (summands(&expr_cpy));
}
