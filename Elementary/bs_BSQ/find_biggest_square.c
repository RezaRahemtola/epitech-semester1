/*
** EPITECH PROJECT, 2021
** find_biggest_square
** File description:
** Part 4 Step 4
*/

int is_square_of_size(char **map, int row, int col, int square_size);

int find_biggest_square(char **map, int nb_rows, int nb_cols, int row, int col)
{
    int i = 1;
    
    if (is_square_of_size(map, row, col, 1) == 0)
        return (0);
    while (is_square_of_size(map, row, col, i))
        i++;
    return (i - 1);
}