/*
** EPITECH PROJECT, 2021
** myprintf
** File description:
** Functions flags
*/

#include <stdarg.h>
#include "include/my.h"

void s_flag(va_list args)
{
    my_putstr(va_arg(args, char *));
}

void int_flag(va_list args)
{
    my_put_nbr(va_arg(args, int));
}

void percent(va_list args)
{
    my_putchar('%');
    args = args;
}

void char_flag(va_list args)
{
    my_putchar(va_arg(args, int));
}

void oct_flag(va_list args)
{
    my_putstr(int_to_base(va_arg(args, int), "01234567"));
}
