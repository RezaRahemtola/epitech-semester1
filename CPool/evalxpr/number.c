/*
** EPITECH PROJECT, 2021
** EVAL_EXPR
** File description:
** NUMBER
*/

#include "include/my.h"

static int check_consecutive_negative(int i, char *str)
{
    int nb = 0;

    while (i >= 0 && ((str)[i] == '-' || (str)[i] == '+')) {
        if ((str)[i] == '-')
            nb++;
        i--;
    }
    return (nb);
}

static int check_negative(int i, char *str, int negative)
{
    if (negative == 1) {
        return (1);
    } else if (check_consecutive_negative(i - 1, str) % 2 == 1) {
        return (1);
    } else {
        return (0);
    }
}

static int check_min_and_max(unsigned int nb, int negative)
{
    unsigned int max = 2147483647;

    if (negative == 0 && nb > max) {
        return (1);
    } else if (negative == 1 && nb > (max + 1)) {
        return (1);
    }
    return (0);
}

int number(char **str_ptr)
{
    unsigned int result = 0;
    int negative = 0;
    int i = 0;

    while ((*str_ptr)[i] != '\0') {
        if ((*str_ptr)[i] - '0' >= 0 && (*str_ptr)[i] - '0' <= 9) {
            negative = check_negative(i, *str_ptr, negative);
            result = (result * 10) + (*str_ptr)[i] - '0';
        }
        if (check_min_and_max(result, negative) == 1) {
            result = 0;
            break;
        }
        if (((*str_ptr)[i] - '0' < 0 || (*str_ptr)[i] - '0' > 9) && result > 0)
            break;
        i++;
    }
    *str_ptr += i;
    return (negative == 1) ? (result * -1) : (result);
}
