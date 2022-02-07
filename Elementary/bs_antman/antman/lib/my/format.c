/*
** EPITECH PROJECT, 2021
** format
** File description:
** printf
*/
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "my.h"

int is_that_long(int i, char *s, va_list string)
{
    int keep;

    keep = i;
    if (s[i] == 'l') {
        i++;
        if (s[i] == '\0')
            return (i);
    } if (s[i] == 'l') {
        i++;
        long_long(i, s, string);
    }
    if (keep + 1 == i)
        case_long(i, s, string);
    return (i);
}

int format(int i, char *s, va_list string)
{
    if (s[i] == '#') {
        i++;
        if (s[i] == '\0')
            return (i);
        if (s[i] == 'o')
            my_putchar('0');
        if (s[i] == 'x') {
            my_putchar('0');
            my_putchar('x');
        }
        if (s[i] == 'X') {
            my_putchar('0');
            my_putchar('X');
        }
    }
    return (i);
}

int pourcentage(int i, char *s, va_list string)
{
    int keep = i;

    if (s[i] == '%') {
        i++;
        i = format(i, s, string);
        keep = i;
        i = is_that_long(i, s, string);
        if (keep == i) {
            case_int(i, s, string);
            base(i, s, string);
        }
    } else
        my_putchar(s[i]);
    return (i);
}
