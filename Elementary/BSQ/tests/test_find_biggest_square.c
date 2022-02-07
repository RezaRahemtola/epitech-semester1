/*
** EPITECH PROJECT, 2021
** Tests find_biggest_square
** File description:
** Tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "bsq.h"

Test(find_biggest_square, smaller_than_max)
{
    struct map sm;
    char **map = mem_alloc_2d_array(3, 4);
    for (int i = 0; i < 3; i++)
        map[i] = "...\n";
    sm.map = map;
    sm.rows = 3;
    sm.cols = 4;
    cr_assert(find_biggest_square(sm, 0, 0, 42) == 42);
}
