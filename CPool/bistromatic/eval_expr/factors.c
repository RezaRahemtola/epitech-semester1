/*
** EPITECH PROJECT, 2021
** factors
** File description:
** desc
*/

#include <stdlib.h>
#include "bistromatic.h"
#include "eval_expr.h"
#include "my.h"

static char *get_next_result(char *result, char **str_ptr, int len)
{
    char sign = (*str_ptr)[0];
    char *next_number = malloc(sizeof(char) * my_strlen(*str_ptr));

    (*str_ptr)++;
    next_number = number(str_ptr);
    if ((sign == '/' || sign == '%') && my_strcmp(next_number, "0") == 0) {
        my_putstr(ERROR_MSG);
        exit(EXIT_USAGE);
    }
    if (sign == '*') {
        return (infin_mult(result, next_number, 0, 0));
    } else if (sign == '/') {
        return (int_to_str((my_getnbr(result) / my_getnbr(next_number)), len));
    } else {
        return (int_to_str((my_getnbr(result) % my_getnbr(next_number)), len));
    }
}

static void if_reduct1(char *result, char *new_str)
{
    if (result[0] != '\0' && result[0] != '-')
        my_strcat(new_str, "+");
    my_strcat(new_str, result);
}

static void while_reduct(char *result, char *new_str, int len, char **ptr)
{
    while ((*ptr)[0] == '*' || (*ptr)[0] == '/' || (*ptr)[0] == '%')
        result = get_next_result(result, ptr, len);
    my_strcat(new_str, result);
}

static void if_ultimate(char *result, char **ptr, int len, char *new_str)
{
    char *sign = "";

    if ((*ptr)[0] == '+' || (*ptr)[0] == '-') {
        sign = char_to_str((*ptr)[0]);
        my_strcat(new_str, my_strcat(result, sign));
        (*ptr)++;
    } else if ((*ptr)[0] == '*' || (*ptr)[0] == '/' || (*ptr)[0] == '%') {
        while_reduct(result, new_str, len, ptr);
    } else {
        if_reduct1(result, new_str);
    }
}

char *factors(char **ptr)
{
    int len = my_strlen(*ptr);
    char *new_str = malloc(sizeof(char) * len);
    char *result = malloc(sizeof(char) * len);

    while ((*ptr)[0] != '\0') {
        if ((*ptr)[0] >= '0' && (*ptr)[0] <= '9')
            result = number(ptr);
        else {
            my_strcat(new_str, char_to_str((*ptr)[0]));
            (*ptr)++;
            continue;
        }
        if_ultimate(result, ptr, len, new_str);
    }
    free(result);
    return (new_str);
}
