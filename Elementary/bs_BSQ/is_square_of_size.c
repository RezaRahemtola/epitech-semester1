/*
** EPITECH PROJECT, 2021
** Bootstrap BSQ
** File description:
** is_square_of_size
*/

int is_square_of_size(char **map, int row, int col, int square_size)
{
    int max_row = row + square_size;
    int max_col = col + square_size;
    int nb_obstacles = 0;

    for (int i = row; i < max_row; i++) {
        for (int j = col; j < max_col; j++) {
            nb_obstacles += (map[i][j] == 'o') ? (1) : (0);
        }
    }
    return (nb_obstacles > 0) ? (0) : (1);
}