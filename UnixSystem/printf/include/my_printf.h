/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** my_printf.h
*/

#ifndef MY_PRINTF_H_
    #define MY_PRINTF_H_
    #include "my.h"
int my_printf(const char *format, ...);
void hash_formatting(va_list args, char **str_ptr);
void l_ll_formatting(va_list args, char **str_ptr);
#endif /* !MY_PRINTF_H_ */
