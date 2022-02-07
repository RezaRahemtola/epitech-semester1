/*
** EPITECH PROJECT, 2021
** bs Pushswap
** File description:
** Swap elem
*/

void swap_elem(int *array, int index1, int index2)
{
    int tmp;

    tmp = array[index1];
    array[index1] = array[index2];
    array[index2] = tmp;
}
