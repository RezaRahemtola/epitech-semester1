/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** main
*/
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "my.h"

void long_long(int i, char *s, va_list string)
{
    switch (s[i]) {
        case 'x':
            hexadecimal_long_long(va_arg(string, long long int));
            break;
        case 'X':
            hexadecimal_maj_long_long(va_arg(string, long long int));
            break;
        case 'b':
            binary_long_long(va_arg(string, long long int));
            break;
        case 'o':
            octal_long_long(va_arg(string, long long int));
            break;
        case 'i':
            my_put_long_long(va_arg(string, long long int));
            break;
        case 'd':
            my_put_long_long(va_arg(string, long long int));
            break;
    }
}

void case_long(int i, char *s, va_list string)
{
    switch (s[i]) {
        case 'x':
            hexadecimal_long(va_arg(string, long));
            break;
        case 'X':
            hexadecimal_maj_long(va_arg(string, long));
            break;
        case 'o':
            octal_long(va_arg(string, long));
            break;
        case 'b':
            binary_long(va_arg(string, long));
            break;
        case 'd':
            my_put_long(va_arg(string, long));
            break;
        case 'i':
            my_put_long(va_arg(string, long));
            break;
    }
}

void case_int(int i, char *s, va_list string)
{
    switch (s[i]) {
        case 'x':
            hexadecimal(va_arg(string, int));
            break;
        case 'X':
            hexadecimal_maj(va_arg(string, int));
            break;
        case 'o':
            octal(va_arg(string, int));
            break;
        case 'b':
            binary(va_arg(string, int));
            break;
        case 'p':
            pointer_void(va_arg(string, unsigned long long));
            break;
    }
}

void base(int i, char *s, va_list string)
{
    switch (s[i]) {
        case 's':
            my_putstr(va_arg(string, char*));
            break;
        case 'c':
            my_putchar(va_arg(string, int));
            break;
        case 'i':
            my_put_nbr(va_arg(string, int));
            break;
        case 'd':
            my_put_nbr(va_arg(string, int));
            break;
        case 'S':
            put_octal(va_arg(string, char *));
            break;
        case '%':
            my_putchar('%');
            break;
    }
}

void my_printf(char *s, ...)
{
    va_list string;

    va_start(string, *s);
    for (int i = 0; s[i] != '\0'; i++) {
        i = pourcentage(i, s, string);
    }
    va_end(string);
}
