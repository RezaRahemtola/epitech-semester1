/*
** EPITECH PROJECT, 2021
** EVAL_EXPR
** File description:
** Functions to handle parenthesis
*/

#include <stdlib.h>
#include "my.h"
#include "eval_expr.h"

static char *get_expr_in_parenthesis(char *str, int start, int end)
{
    char *new_str = malloc(sizeof(char) * (end - start));

    for (int i = start + 1; i < end; i++)
        new_str[i - start - 1] = str[i];
    return (new_str);
}

static char *get_end_str_from_index(char *str, int index)
{
    char *new_str = malloc(my_strlen(str));
    int i = 0;

    while (str[index] != '\0') {
        new_str[i] = str[index];
        i++;
        index++;
    }
    new_str[i] = '\0';
    return (new_str);
}

static char *create_new_string(char *str, int start, int end, char *result)
{
    char *new_str = malloc(sizeof(char) * my_strlen(str));

    for (int i = 0; i < start; i++)
        new_str[i] = str[i];
    my_strcat(new_str, result);
    my_strcat(new_str, get_end_str_from_index(str, end + 1));
    return (new_str);
}

char *parenthesis(char **str_ptr)
{
    char *str_copy = my_strdup(*str_ptr);
    int start = 0;
    int end = 0;
    char *expr = "";

    for (end = 0; str_copy[end] != '\0'; end++) {
        if (str_copy[end] == ')')
            break;
    }
    for (start = end; start >= 0; start--) {
        if (str_copy[start] == '(')
            break;
    }
    expr = get_expr_in_parenthesis(str_copy, start, end);
    if (my_strstr(expr, "*") != 0 || my_strstr(expr, "/") != 0 ||
        my_strstr(expr, "%") != 0) {
        expr = factors(&expr);
    }
    return (create_new_string(str_copy, start, end, summands(&expr)));
}
