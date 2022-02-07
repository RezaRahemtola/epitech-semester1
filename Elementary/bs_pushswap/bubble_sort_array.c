/*
** EPITECH PROJECT, 2021
** bs Pushswap
** File description:
** Bubble sort array
*/

void swap_elem(int *array, int index1, int index2);

static int get_sort_status(int *array, int size)
{
    for (int i = 0; i < size - 1; i++)
        if (array[i] > array[i + 1]) return (0);
    return (1);
}

static void check_for_swap(int *array, int i)
{
    if (array[i] > array[i + 1])
        swap_elem(array, i, i + 1);
}

void bubble_sort_array(int *array, int size)
{
    int is_sorted = 0;

    while ((is_sorted = get_sort_status(array, size)) != 1) {
        for (int i = 0; i < size - 1; i++) {
            check_for_swap(array, i);
        }
    }
}
