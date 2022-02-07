/*
** EPITECH PROJECT, 2021
** eval_expr
** File description:
** Prototypes of functions of the project
*/

#ifndef EVAL_EXPR_H
    #define EVAL_EXPR_H
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
char *number(char **str_ptr);
char *summands(char **str_ptr);
char *factors(char **str_ptr);
char *parenthesis(char **str_ptr);
char *int_to_str(int nb, int len);
char *char_to_str(char c);
#endif
