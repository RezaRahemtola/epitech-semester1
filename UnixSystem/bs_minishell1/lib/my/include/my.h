/*
** EPITECH PROJECT, 2021
** MY.H
** File description:
** Task02
*/

#ifndef MY_H_
    #define MY_H_
    #include <stdarg.h>
    #include <stddef.h>

int my_put_nbr(int nb);

void my_putchar(char c);
int my_putstr(char const *str);
char *my_revstr(char *str);

char *my_strcat(char *dest, char *src, int free_src);

int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strdup(char const *src);
char *int_to_base(unsigned long long int nb, char *base);

int my_printf(const char *format, ...);
void upper_s_flag(char *str);
void hash_formatting(va_list args, char **str_ptr);
void l_ll_formatting(va_list args, char **str_ptr);
#endif
