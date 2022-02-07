/*
** EPITECH PROJECT, 2022
** antman
** File description:
** Error handling
*/

#include "my.h"

int check_errors(int argc, char **argv, int fd, int size)
{
    if (argc != 3) return (84);
    if (fd == -1) return (84);
    if (size == -1) return (84);
    if (my_strcmp(argv[2], "1") != 0 && my_strcmp(argv[2], "2") != 0 &&
    my_strcmp(argv[2], "3") != 0) {
        return (84);
    }
    return (0);
}
