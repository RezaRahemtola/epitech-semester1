/*
** EPITECH PROJECT, 2021
** array_2d_how_many
** File description:
** Part 2 Step 4
*/

static int browse_cols(int **arr, int nb_cols, int number, int i)
{
    int result = 0;

    for (int j = 0; j < nb_cols; j++) {
        if (arr[i][j] == number)
            result++;
    }
    return (result);
}

int array_2d_how_many(int **arr, int nb_rows, int nb_cols, int number)
{
    int result = 0;

    for (int i = 0; i < nb_rows; i++)
        result += browse_cols(arr, nb_cols, number, i);
    return (result);
}
