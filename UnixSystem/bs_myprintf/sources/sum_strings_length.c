/*
** EPITECH PROJECT, 2021
** Bootstrap my_printf
** File description:
** sum_strings_length
*/

#include <stdarg.h>

static int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

int sum_strings_length(int n, ...)
{
    int sum = 0;
    va_list args;

    va_start(args, n);
    for (int i = 0; i < n; i++)
        sum += my_strlen(va_arg(args, char *));
    return (sum);
}
