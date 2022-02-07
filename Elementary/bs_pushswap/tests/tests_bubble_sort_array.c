/*
** EPITECH PROJECT, 2021
** Tests bubble sort array
** File description:
** Tests
*/

#include <criterion/criterion.h>

void bubble_sort_array(int *array, int size);

Test(bubble_sort, simple_test)
{
    int array[6] = {1, 4, 3, 2, 6, 5};
    int sorted[6] = {1, 2, 3, 4, 5, 6};
    int size = 6;
    bubble_sort_array(array, size);
    cr_assert_arr_eq(array, sorted, size);
}
