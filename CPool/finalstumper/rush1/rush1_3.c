/*
** EPITECH PROJECT, 2021
** rush_1_1.c
** File description:
** display square
*/

#include "rush3.h"

char *rush3(int x, int y)
{
    char *square_model = "ABCB BABC";
    char *line_model_x = "BBB";
    char *line_model_y = "BBB";

    if (x == 1 || y == 1) {
        return (get_special_case(x, y, line_model_x, line_model_y));
    } else
        return (get_square(x, y, square_model));
}
