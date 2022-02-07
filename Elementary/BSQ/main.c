/*
** EPITECH PROJECT, 2021
** BSQ
** File description:
** main.c
*/

#include <sys/stat.h>
#include <stdlib.h>
#include "bsq.h"
#include "my.h"

static void free_map(struct map sm)
{
    for (int row = 0; row < sm.rows; row++)
        free(sm.map[row]);
    free(sm.map);
}

int main(int argc, char **argv)
{
    struct map sm;
    struct stat sb;
    int biggest_size = 0;

    if (check_errors(argc, argv) == 1)
        return (84);
    sm.rows = get_first_line_nbr(argv[1]);
    stat(argv[1], &sb);
    sm.cols = (sb.st_size - first_line_bytes(argv[1])) / sm.rows;
    if (check_map_errors(argv[1], sm.cols, first_line_bytes(argv[1])) == 1)
        return (84);
    sm.map = load_map(argv[1], sm.rows, sm.cols, first_line_bytes(argv[1]));
    for (int i = 0; i < sm.rows; i++) {
        for (int j = 0; j < sm.cols; j++)
            biggest_size = find_biggest_square(sm, i, j, biggest_size);
    }
    display_map(sm.map, sm.rows, sm.cols);
    free_map(sm);
    return (0);
}
