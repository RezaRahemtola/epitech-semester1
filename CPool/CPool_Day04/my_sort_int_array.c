/*
** EPITECH PROJECT, 2021
** MY_SORT_INT_ARRAY
** File description:
** Task06
*/

int check_array(int arr_i, int i, int arr_min_pos, int min_pos)
{
    if (arr_i < arr_min_pos)
        return (i);
    return (min_pos);
}

void my_sort_int_array(int *array, int size)
{
    int current = 0;
    int min_pos = 0;
    int temp = 0;

    while (current < size) {
        for (int i = current; i < size; i++) {
            min_pos = check_array(array[i], i, array[min_pos], min_pos);
        }
        temp = array[min_pos];
        array[min_pos] = array[current];
        array[current] = temp;
        current++;
        min_pos = current;
    }
}
