/*
** EPITECH PROJECT, 2022
** antman
** File description:
** Functions to compress ppm files
*/

#include <stdlib.h>
#include <unistd.h>
#include "antman.h"

static int check_is_header(char *str, int i)
{
    for (; str[i] != '\0'; i++) {
        if ((str[i] < '0' || str[i] > '9') && str[i] != '\n')
            return (1);
    }
    return (0);
}

void comp_ppm(char **content)
{
    int len = my_strlen(*content);
    unsigned char c = 0;
    int h_len = 0;

    for (; check_is_header(*content, h_len) == 1; h_len++);
    for (; (*content)[h_len] != '\n' && (*content)[h_len] != '\0'; h_len++);
    write(1, *content, h_len);
    (*content) += h_len;
    if (len > 0) my_printf("@");
    for (int i = 0; (*content)[0] != '\0'; i = 0) {
        while ((*content)[i] != '\n' && (*content)[i] != '\0') i++;
        if ((*content)[i] == '\n') i++;
        c = my_getnbr(*content);
        my_putchar(c);
        (*content) += i;
    }
    (*content) -= len;
}
