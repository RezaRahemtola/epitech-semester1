/*
** EPITECH PROJECT, 2021
** infini_add
** File description:
** desc
*/

#ifndef INFINI_ADD_H_
    #define INFINI_ADD_H_
    #define DTAS(x) (x + '0')
    #define ASTD(x) (x - '0')
    #define ABS(value) ((value < 0) ? ((value) * -1) : (value))
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
char *infin_div(char const *str1, char const *str2);
char *infin_sub(char const *str1, char const *str2);
char *infin_add(char const *str1, char const *str2);
char *infin_mult(char const *str1, char const *str2, int i, int j);
#endif
