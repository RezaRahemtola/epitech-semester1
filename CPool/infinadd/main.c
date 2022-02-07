/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** InfinAdd
*/

#include <stdlib.h>
#include "include/my.h"

int main(int argc, char **argv)
{
    if (argc < 3)
        return (84);
    char *result = infin_add(argv[1], argv[2], 0, 0);
    my_putstr(result);
    free(result);
    my_putchar('\n');
    return (0);
}
