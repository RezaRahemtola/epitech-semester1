/*
** EPITECH PROJECT, 2021
** Bistro-matic
** File description:
** main.c
*/

#include <stdlib.h>
#include <unistd.h>
#include "bistromatic.h"
#include "my.h"

static char *get_expr(unsigned int size)
{
    char *expr;

    if (size <= 0) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_SIZE_NEG);
    }
    expr = malloc(size + 1);
    if (expr == 0) {
        my_putstr(ERROR_MSG);
        exit(EXIT_MALLOC);
    }
    if (read(0, expr, size) != size) {
        my_putstr(ERROR_MSG);
        exit(EXIT_READ);
    }
    expr[size] = 0;
    return (expr);
}

int main(int ac, char **av)
{
    char *expr;
    char *result;

    if (ac != 4) {
        my_putstr("Usage: ");
        my_putstr(av[0]);
        my_putstr(" base ops\"()+_*/%\" exp_len\n");
        return (EXIT_USAGE);
    }
    check_base(av[1]);
    check_ops(av[2], av[1]);
    expr = get_expr(my_getnbr(av[3]));
    check_par(expr, av[2]);
    check_unknown_digit(expr, av[1], av[2]);
    result = eval_expr(av[2], expr);
    my_putstr(result);
    free(result);
    free(expr);
    return (EXIT_SUCCESS);
}
