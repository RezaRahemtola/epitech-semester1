/*
** EPITECH PROJECT, 2021
** Bootstrap BSQ
** File description:
** is_square_of_size
*/

#include "bsq.h"

static int is_obstacle_in_line(struct map sm, int row, int col, int max_col)
{
    for (int j = col; j < max_col; j++) {
        if (j == sm.cols || sm.map[row][j] != '.')
            return (1);
    }
    return (0);
}

int is_square_of_size(struct map sm, int row, int col, int square_size)
{
    int max_row = row + square_size;
    int max_col = col + square_size;

    for (int i = row; i < max_row; i++) {
        if (i == sm.rows || is_obstacle_in_line(sm, i, col, max_col))
            return (0);
    }
    return (1);
}
