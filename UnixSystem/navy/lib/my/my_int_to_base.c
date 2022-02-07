/*
** EPITECH PROJECT, 2021
** my_int_to_base
** File description:
** Converts an int to a string number in a given base
*/

#include <stdlib.h>
#include "my.h"

char *int_to_base(unsigned long long int nb, char *base)
{
    char *result = malloc(sizeof(char) * 10);

    if (nb == 0) {
        result[0] = base[0];
        result[1] = '\0';
        return (result);
    }
    for (int i = 0; nb != 0; nb /= my_strlen(base)) {
        result[i] = base[nb % my_strlen(base)];
        result[i + 1] = '\0';
        i++;
    }
    return (my_revstr(result));
}
