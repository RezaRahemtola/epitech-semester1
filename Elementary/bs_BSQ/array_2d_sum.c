/*
** EPITECH PROJECT, 2021
** array_2d_sum
** File description:
** Part 2 Step 4
*/

int array_2d_sum(int **arr, int nb_rows, int nb_cols)
{
    int result = 0;

    for (int i = 0; i < nb_rows; i++) {
        for (int j = 0; j < nb_cols; j++) {
            result += arr[i][j];
        }
    }
    return (result);
}
