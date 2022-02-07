/*
** EPITECH PROJECT, 2021
** summands
** File description:
** desc
*/

#include "include/eval_expr.h"

int summands(char **str_ptr)
{
    int result = number(str_ptr);

    if ((*str_ptr)[0] != '\0' && (*str_ptr)[0] == '+') {
        (*str_ptr)++;
        return (result + summands(str_ptr));
    } else if ((*str_ptr)[0] != '\0' && (*str_ptr)[0] == '-') {
        return (result + summands(str_ptr));
    }
    return (result);
}
