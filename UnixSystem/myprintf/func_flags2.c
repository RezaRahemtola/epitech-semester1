/*
** EPITECH PROJECT, 2021
** myprintf
** File description:
** Function flags 2
*/

#include <stdarg.h>
#include "include/my.h"

void lowx_flag(va_list args)
{
    my_putstr(int_to_base(va_arg(args, int), "0123456789abcdef"));
}

void upx_flag(va_list args)
{
    my_putstr(int_to_base(va_arg(args, int), "0123456789ABCDEF"));
}

void b_flag(va_list args)
{
    my_putstr(int_to_base(va_arg(args, int), "01"));
}

void ups_flag(va_list args)
{
    char *str = va_arg(args, char *);
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] >= 32 && str[i] <= 126) {
            my_putchar(str[i]);
        } else {
            my_putstr("\\00");
            my_putstr(int_to_base(str[i], "01234567"));
        }
    }
}
