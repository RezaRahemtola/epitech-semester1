/*
** EPITECH PROJECT, 2021
** mem_alloc_2d_array
** File description:
** Part 3 Step 2
*/

#include <stdlib.h>

char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    char **new_array = malloc(sizeof(char *) * nb_rows);

    for (int i = 0; i < nb_rows; i++)
        new_array[i] = malloc(sizeof(char) * nb_cols);
    return (new_array);
}
