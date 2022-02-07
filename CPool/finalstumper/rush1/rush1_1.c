/*
** EPITECH PROJECT, 2021
** rush_1_1.c
** File description:
** display square
*/

#include "rush3.h"

char *rush1(int x, int y)
{
    char *square_model = "o|o- -o|o";
    char *line_model_x = "o-o";
    char *line_model_y = "o|o";

    if (x == 1 || y == 1) {
        return (get_special_case(x, y, line_model_x, line_model_y));
    } else
        return (get_square(x, y, square_model));
}
