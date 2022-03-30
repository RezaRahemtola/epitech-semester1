/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** Functions to handle specific flags
*/

#include <stdarg.h>
#include "include/my.h"

static void disp_hash_prefix(char *str, char *flag)
{
    if (my_strcmp(flag, "x") == 0 && str[0] != '0')
        my_putstr("0x");
    if (my_strcmp(flag, "X") == 0 && str[0] != '0')
        my_putstr("0X");
    if (my_strcmp(flag, "o") == 0 && str[0] != '0')
        my_putstr("0");
}

void hash_formatting(va_list args, char **str_ptr)
{
    char flag[2] = {(*str_ptr)[0], '\0'};
    char *str;

    if (my_strcmp(flag, "x") == 0 || my_strcmp(flag, "X") == 0) {
        if (my_strcmp(flag, "x") == 0)
            str = int_to_base(va_arg(args, int), "0123456789abcdef");
        else
            str = int_to_base(va_arg(args, int), "0123456789ABCDEF");
        disp_hash_prefix(str, flag);
        my_putstr(str);
        (*str_ptr)++;
    } else if (my_strcmp(flag, "o") == 0) {
        str = int_to_base(va_arg(args, int), "01234567");
        disp_hash_prefix(str, flag);
        my_putstr(str);
        (*str_ptr)++;
    } else {
        my_putstr("%#");
    }
}
