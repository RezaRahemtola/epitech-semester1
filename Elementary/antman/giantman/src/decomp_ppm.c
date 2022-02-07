/*
** EPITECH PROJECT, 2022
** antman
** File description:
** Functions to decompress ppm files
*/

#include <unistd.h>
#include "giantman.h"

void decomp_ppm(char *buffer, int len)
{
    int i = 0;

    while (buffer[i] != '@' && buffer[i] != '\0')
        i++;
    write(1, buffer, i);
    i += 2;
    if (len > 0) my_putchar('\n');
    while (i < len) {
        if (buffer[i] < 0)
            my_put_nbr(255 - (-buffer[i] - 1));
        else
            my_put_nbr(buffer[i]);
        my_putchar('\n');
        i++;
    }
}
