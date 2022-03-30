/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** Main file
*/

#include <stdarg.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/my_printf.h"
#include "include/func_flags.h"

static int get_char_index(char const *arr, char flag)
{
    for (int i = 0; arr[i] != 0; i++) {
        if (flag == arr[i])
            return (i);
    }
    return (-1);
}

static char get_flag(char **str_ptr)
{
    char found = '\0';

    if ((*str_ptr)[0] == '%' && my_strlen(*str_ptr) > 1) {
        found = (*str_ptr)[1];
        (*str_ptr) += 2;
    }
    return (found);
}

static void handle_flag(char flag, va_list args, char **str_ptr)
{
    char arr_flag[11] = {'s', 'd', 'i', 'u', '%', 'c', 'o',
    'x', 'X', 'b', 'S'};
    void (*f_ptr[11])(va_list args) = {s_flag, int_flag,
    int_flag, int_flag, percent, char_flag, oct_flag, lowx_flag,
    upx_flag, b_flag, ups_flag};

    if (get_char_index(arr_flag, flag) != -1)
        (*f_ptr[get_char_index(arr_flag, flag)])(args);
    if (flag == '#')
        hash_formatting(args, str_ptr);
    if (flag == 'l')
        l_ll_formatting(args, str_ptr);
}

int my_printf(const char *format, ...)
{
    va_list args;
    char flag = '\0';
    char *str = my_strdup(format);
    char **str_ptr = &str;

    va_start(args, format);
    while (my_strlen(str) > 0) {
        flag = get_flag(str_ptr);
        if (flag != 0) {
            handle_flag(flag, args, str_ptr);
        } else {
            my_putchar((*str_ptr)[0]);
            (*str_ptr)++;
        }
    }
    va_end(args);
    return (0);
}
