/*
** EPITECH PROJECT, 2021
** summands
** File description:
** desc
*/

#include "eval_expr.h"
#include "bistromatic.h"
#include "my.h"

static char *get_sign_pattern(char nb1, char sign, char nb2)
{
    char *first = (nb1 == '-') ? (char_to_str(nb1)) : (char_to_str('+'));
    char *second = char_to_str(sign);
    char *third = (nb2 == '-') ? (char_to_str(nb2)) : (char_to_str('+'));

    return (my_strcat(first, my_strcat(second, third)));
}

static char *get_next_result(char *result, char sign, char **str_ptr)
{
    char *tmp = number(str_ptr);
    char *pattern = get_sign_pattern(result[0], sign, tmp[0]);

    if (my_strcmp(pattern, "+--") == 0 || my_strcmp(pattern, "-+-") == 0 ||
        my_strcmp(pattern, "---") == 0)
        tmp++;
    if (my_strcmp(pattern, "+++") == 0 || my_strcmp(pattern, "+--") == 0)
        return (infin_add(result, tmp));
    if (my_strcmp(pattern, "--+") == 0 || my_strcmp(pattern, "-+-") == 0) {
        result++;
        return (my_revstr(my_strcat(my_revstr(infin_add(result, tmp)), "-")));
    }
    if (my_strcmp(pattern, "-++") == 0 || my_strcmp(pattern, "++-") == 0 ||
        my_strcmp(pattern, "---") == 0)
        return (infin_sub(result, tmp));
    if (my_strcmp(pattern, "+-+") == 0) {
        my_strcat(my_revstr(tmp), "-");
        return (infin_sub(result, my_revstr(tmp)));
    }
    return (result);
}

char *summands(char **str_ptr)
{
    char *result = number(str_ptr);
    char sign = '0';

    while ((*str_ptr)[0] != '\0') {
        sign = (*str_ptr)[0];
        (*str_ptr)++;
        result = get_next_result(result, sign, str_ptr);
    }
    return (result);
}
