/*
** EPITECH PROJECT, 2021
** Bootstrap my_printf
** File description:
** sum_numbers.c
*/

#include <stdarg.h>

int sum_numbers(int n, ...)
{
    int sum = 0;
    va_list args;

    va_start(args, n);
    for (int i = 0; i < n; i++)
        sum += va_arg(args, int);
    va_end(args);
    return (sum);
}
