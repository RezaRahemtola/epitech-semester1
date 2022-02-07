/*
** EPITECH PROJECT, 2021
** rush_1_1.c
** File description:
** display square
*/

#include "rush3.h"

char *rush2(int x, int y)
{
    char *square_model = "/*\\* *\\*/";
    char *line_model_x = "***";
    char *line_model_y = "***";

    if (x == 1 || y == 1) {
        return (get_special_case(x, y, line_model_x, line_model_y));
    } else
        return (get_square(x, y, square_model));
}
