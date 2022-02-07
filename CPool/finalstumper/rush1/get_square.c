/*
** EPITECH PROJECT, 2021
** Rush1-1
** File description:
** display square
*/

#include <stdlib.h>
#include <unistd.h>
#include "rush3.h"
#include "my.h"

char *get_left_side(int line, int y, char *square_model)
{
    char left_side[2] = "\0";

    if (line == 1)
        left_side[0] = square_model[0];
    if (line != 1 && line != y)
        left_side[0] = square_model[1];
    if (line == y)
        left_side[0] = square_model[2];
    left_side[1] = '\0';
    return (my_strdup(left_side));
}

char *get_middle_side(int line, int x, int y, char *square_model)
{
    char *middle_side = malloc(sizeof(char) * (x - 1));
    int i = 0;

    for (int col = 1; col < x - 1; col++) {
        if (line == 1)
            middle_side[i] = square_model[3];
        if (line != 1 && line != y)
            middle_side[i] = square_model[4];
        if (line == y)
            middle_side[i] = square_model[5];
        i += 1;
    }
    middle_side[i] = '\0';
    return (my_strdup(middle_side));
}

char *get_right_side(int line, int y, char *square_model)
{
    char right_side[2] = "\0";

    if (line == 1)
        right_side[0] = square_model[6];
    if (line != 1 && line != y)
        right_side[0] = square_model[7];
    if (line == y)
        right_side[0] = square_model[8];
    right_side[1] = '\0';
    return (my_strdup(right_side));
}

char *get_square(int x, int y,  char *square_model)
{
    char *str = malloc(sizeof(char) * BUFF_SIZE);

    for (int line = 1; line <= y; line++) {
        my_strcat(str, get_left_side(line, y, square_model));
        my_strcat(str, get_middle_side(line, x, y, square_model));
        my_strcat(str, get_right_side(line, y, square_model));
        my_strcat(str, "\n");
    }
    return (my_strdup(str));
}
