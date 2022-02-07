/*
** EPITECH PROJECT, 2021
** array_1d_sum
** File description:
** Part 2 Step 3
*/

int array_1d_sum(int const *arr, int size)
{
    int result = 0;

    for (int i = 0; i < size; i++)
        result += arr[i];
    return (result);
}
