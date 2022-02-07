/*
** EPITECH PROJECT, 2021
** find_biggest_square
** File description:
** Part 4 Step 4
*/

#include "bsq.h"

static void clear_x_from_map(char **map, int nb_rows, int nb_cols)
{
    for (int i = 0; i < nb_rows; i++) {
        for (int j = 0; j < nb_cols; j++) {
            map[i][j] = (map[i][j] == 'x') ? ('.') : (map[i][j]);
        }
    }
}

static void write_x_on_map(char **map, int row, int col, int square_size)
{
    for (int i = row; i < row + square_size; i++) {
        for (int j = col; j < col + square_size; j++) {
            map[i][j] = 'x';
        }
    }
}

int find_biggest_square(struct map sm, int row, int col, int biggest)
{
    int i = biggest + 1;
    int square_size;

    while (is_square_of_size(sm, row, col, i))
        i++;
    square_size = i - 1;
    if (square_size > biggest) {
        clear_x_from_map(sm.map, sm.rows, sm.cols);
        write_x_on_map(sm.map, row, col, square_size);
    }
    return (square_size > biggest) ? (square_size) : (biggest);
}
