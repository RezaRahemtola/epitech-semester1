/*
** EPITECH PROJECT, 2021
** eval_expr
** File description:
** main file
*/

#include "include/my.h"
#include "include/eval_expr.h"

int main (int ac, char **av)
{
    if (ac == 2) {
        my_put_nbr(eval_expr(av[1]));
        my_putchar('\n');
        return (0);
    }
    return (84);
}
