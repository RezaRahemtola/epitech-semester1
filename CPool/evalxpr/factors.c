/*
** EPITECH PROJECT, 2021
** factors
** File description:
** desc
*/

#include <stdlib.h>
#include "include/eval_expr.h"
#include "include/my.h"

static int get_next_result(int result, char **str_ptr)
{
    char sign = (*str_ptr)[0];

    (*str_ptr)++;
    if (sign == '*')
        return (result * number(str_ptr));
    else if (sign == '/')
        return (result / number(str_ptr));
    else
        return (result % number(str_ptr));
}

static char *if_reduct1(int result, char *new_str, int len)
{
    if (result >= 0)
        my_strcat(new_str, "+");
    my_strcat(new_str, int_to_str(result, len));
    return (new_str);
}

static char *while_reduct(int result, char *new_str, char **ptr)
{
    int len = my_strlen(*ptr);

    while ((*ptr)[0] == '*' || (*ptr)[0] == '/' || (*ptr)[0] == '%')
        result = get_next_result(result, ptr);
    my_strcat(new_str, int_to_str(result, len));
    return (new_str);
}

static char *if_ultimate(int result, char **ptr, char *new_str)
{
    char *sign = "";
    int len = my_strlen(*ptr);

    if ((*ptr)[0] == '+' || (*ptr)[0] == '-') {
        sign = char_to_str((*ptr)[0]);
        my_strcat(new_str, my_strcat(int_to_str(result, len), sign));
        (*ptr)++;
    } else if ((*ptr)[0] == '*' || (*ptr)[0] == '/' || (*ptr)[0] == '%') {
        while_reduct(result, new_str,  ptr);
    } else {
        if_reduct1(result, new_str, len);
    }
    return (new_str);
}

char *factors(char **ptr)
{
    int len = my_strlen(*ptr);
    char *new_str = malloc(sizeof(char) * len);
    int result = 0;

    while ((*ptr)[0] != '\0') {
        if ((*ptr)[0] >= '0' && (*ptr)[0] <= '9')
            result = number(ptr);
        else {
            my_strcat(new_str, char_to_str((*ptr)[0]));
            (*ptr)++;
            continue;
        }
        if_ultimate(result, ptr, new_str);
    }
    return (new_str);
}
