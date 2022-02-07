/*
** EPITECH PROJECT, 2021
** my
** File description:
** list
*/

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

#ifndef _MY_H_
    #define _MY_H_

void octal(int nb);
void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest,  char const *src,int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
void my_printf(char *s, ...);
void binary(int nb);
void hexadecimal(int nb);
void hexadecimal_maj(int nb);
void pointer_void(unsigned long long nb);
int my_put_long(long nb);
void hexadecimal_long(long nb);
void hexadecimal_maj_long(long nb);
void binary_long(long nb);
void octal_long(long nb);
void put_octal(char *str);
int format_space(int i, char *s, va_list string);
int format(int i, char *s, va_list string);
void hexadecimal_maj_long_long(long long nb);
void hexadecimal_long_long(long long nb);
void octal_long_long(long long nb);
void binary_long_long(long long nb);
void my_put_long_long(long long nb);
int pourcentage(int i, char *s, va_list string);
void base(int i, char *s, va_list string);
void case_int(int i, char *s, va_list string);
void case_long(int i, char *s, va_list string);
void long_long(int i, char *s, va_list string);
int is_that_long(int i, char *s, va_list string);
void *my_memset(void *s, int c, size_t n);

#endif /* _MY_H_ */
