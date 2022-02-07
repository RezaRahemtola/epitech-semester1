# libmy
C Pool Day07 - Lib of 30 functions

## Functional & Marvin compliant:  
1 void my_putchar(char c);  
2 int my_isneg(int nb);  
4 void my_swap(int *a, int *b);  
5 int my_putstr(char const *str);  
6 int my_strlen(char const *str);  
8 void my_sort_int_array(int *tab, int size);  
9 int my_compute_power_rec(int nb, int power);  
10 int my_compute_square_root(int nb);  
11 int my_is_prime(int nb);  
12 int my_find_prime_sup(int nb);  
13 char *my_strcpy(char *dest, char const *src);  
14 char *my_strncpy(char *dest, char const *src, int n);  
15 char *my_revstr(char *str);  
16 char *my_strstr(char *str, char const *to_find);  
17 int my_strcmp(char const *s1, char const *s2);  
18 int my_strncmp(char const *s1, char const *s2, int n);  
19 char *my_strupcase(char *str);  
20 char *my_strlowcase(char *str);  
22 int my_str_isalpha(char const *str);  
23 int my_str_isnum(char const *str);  
24 int my_str_islower(char const *str);  
25 int my_str_isupper(char const *str);  
26 int my_str_isprintable(char const *str);  
29 char *my_strcat(char *dest, char const *src);  
30 char *my_strncat(char *dest, char const *src, int nb);  

## Functional but non-Marvin tested:  
3 int my_put_nbr(int nb);  
21 char *my_strcapitalize(char *str);  

## Non-functional:  
7 int my_getnbr(char const *str);  
27 int my_showstr(char const *str);  
28 int my_showmem(char const *str, int size);  
