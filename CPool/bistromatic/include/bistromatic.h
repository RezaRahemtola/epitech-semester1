/*
** EPITECH PROJECT, 2021
** Bistro-matic
** File description:
** .h
*/

#ifndef BISTROMATIC_H_
    #define BISTROMATIC_H_
    #define OP_OPEN_PARENT_IDX 0
    #define OP_CLOSE_PARENT_IDX 1
    #define OP_PLUS_IDX 2
    #define OP_SUB_IDX 3
    #define OP_NEG_IDX 3
    #define OP_MULT_IDX 4
    #define OP_DIV_IDX 5
    #define OP_MOD_IDX 6
    #define EXIT_USAGE 84
    #define EXIT_BASE 84
    #define EXIT_SIZE_NEG 84
    #define EXIT_MALLOC 84
    #define EXIT_READ 84
    #define EXIT_OPS 84
    #define SYNTAX_ERROR_MSG "syntax error"
    #define ERROR_MSG "error"
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include "eval_expr.h"
    #include "my.h"
    #include "infin_add.h"
int is_greater(char const *n1, char const *n2);
char *eval_expr(char const *ops, char const *expr);
void clean_ops(char **expr_ptr, char const *ops);
void check_unknown_digit(char *expr, char const *base, char const *ops);
void check_ops(char const *ops, char const *base);
void check_base(char const *base);
void check_par(char *str, char *ops);
char *remove_zero(char const *str);
char *remove_sub(char const *str);
#endif
