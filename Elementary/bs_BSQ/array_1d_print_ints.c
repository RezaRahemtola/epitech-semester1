/*
** EPITECH PROJECT, 2021
** array_1d_print_ints
** File description:
** Part 2 Step 2
*/

void my_putchar(char c);
int my_put_nbr(int nb);

void array_1d_print_ints(int const *arr, int size)
{
    for (int i = 0; i < size; i++) {
        my_put_nbr(arr[i]);
        my_putchar('\n');
    }
}
