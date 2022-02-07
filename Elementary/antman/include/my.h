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

int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
int my_is_prime(int nb);
int my_isneg(int n);

int my_put_nbr(int nb);
char *my_nbr_to_string(unsigned int nb);

void my_putchar(char c);
int my_putstr(char const *str);
char *my_revstr(char *str);
void my_sort_int_array(int *array, int size);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
char *my_strcapitalize(char *str);

char *my_strcat(char *dest, char *src, int free_src);
char *my_newstrcat(char *str1, char *str2, int free1, int free2);

int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char const *str, char const *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
char *my_strdup(char const *src);
char *int_to_base(unsigned long long int nb, char *base);
int base_to_int(char *nb, char *base);

int my_printf(const char *format, ...);
void upper_s_flag(char *str);
void hash_formatting(va_list args, char **str_ptr);
void l_ll_formatting(va_list args, char **str_ptr);

char **my_malloc_2d_array(int nb_rows, int nb_cols);
void my_free_2d_array(char **array);

char *my_malloc_str(size_t nb_char, char c);

char **str_to_word_array(char *str, char delim);
#endif
