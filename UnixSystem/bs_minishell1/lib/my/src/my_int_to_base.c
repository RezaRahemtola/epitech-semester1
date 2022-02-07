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
    char *result = malloc(sizeof(char) * 1);
    int malloc_len = my_strlen(base);
    char test[2] = {'\0', '\0'};
    char *tmp;

    if (nb == 0) {
        test[0] = base[0];
        return (my_strdup(test));
    }
    for (int i = 1; nb != 0; nb /= my_strlen(base)) {
        test[0] = base[nb % my_strlen(base)];
        my_strcat(result, test, 0);
        tmp = my_strdup(result);
        malloc_len++;
        result = malloc(sizeof(char) * malloc_len);
        my_strcpy(result, tmp);
        free(tmp);
        i++;
    }
    return (my_revstr(result));
}
