/*
** EPITECH PROJECT, 2021
** Rush1-1
** File description:
** display_special_case
*/

#include <stdlib.h>
#include <unistd.h>
#include "rush3.h"
#include "my.h"

char *get_single(char *line_model_x)
{
    char single[3] = "\0";

    single[0] = line_model_x[0];
    single[1] = '\n';
    single[2] = '\0';
    return (my_strdup(single));
}

char *get_line(int x, char *line_model_x)
{
    char *column = malloc(sizeof(char) * (x + 1));
    int i = 0;

    for (int col = 1; col <= x; col++) {
        if (col == 1)
            column[i] = line_model_x[0];
        if (col != 1 && col != x)
            column[i] = line_model_x[1];
        if (col == x)
            column[i] = line_model_x[2];
        i += 1;
    }
    column[i] = '\n';
    column[i + 1] = '\0';
    return (my_strdup(column));
}

char *get_col(int y, char *line_model_y)
{
    char *line = malloc(sizeof(char) * ((2 * y) + 1));
    int i = 0;

    for (int l = 1; l <= y; l++) {
        if (l == 1)
            line[i] = line_model_y[0];
        if (l != 1 && l != y)
            line[i] = line_model_y[1];
        if (l == y)
            line[i] = line_model_y[2];
        i += 1;
        line[i] = '\n';
        i += 1;
    }
    return (my_strdup(line));
}

char *get_special_case(int x, int y, char *line_model_x, char *line_model_y)
{
    if (x == 1 && y == 1) {
        return get_single(line_model_x);
    }
    if (y == 1) {
        return get_line(x, line_model_x);
    } else {
        return get_col(y, line_model_y);
    }
}
