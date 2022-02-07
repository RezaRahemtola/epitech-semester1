/*
** EPITECH PROJECT, 2021
** mem_dup_2d_array
** File description:
** Part 3 Step 3
*/

char **mem_alloc_2d_array(int nb_rows, int nb_cols);

char **mem_dup_2d_array(char **arr, int nb_rows, int nb_cols)
{
    char **new_arr = mem_alloc_2d_array(nb_rows, nb_cols);

    for (int i = 0; i < nb_rows; i++) {
        for (int j = 0; j < nb_cols; j++) {
            new_arr[i][j] = arr[i][j];
        }
    }
    return (new_arr);
}
