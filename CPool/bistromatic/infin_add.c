/*
** EPITECH PROJECT, 2021
** infini_add
** File description:
** desc
*/

#include "infin_add.h"
#include "my.h"
#include <stdlib.h>

static char *final(int ret, char *result, int i)
{
    if (ret != 0) {
        result[i] = ret + '0';
        i++;
    }
    result[i] = '\0';
    result = my_revstr(result);
    return (result);
}

static char *add(char const *nb1, char const *nb2, int smax, int smin)
{
    char *result = malloc(sizeof(char) * (smax + 1));
    int i = 0;
    int ret = 0;

    while (nb1[i]) {
        if (smin > 0)
            ret = (nb1[smax - 1] - '0') + (nb2[smin - 1] - '0') + ret;
        else
            ret = (nb1[smax - 1] - '0') + ret;
        result[i] = ret % 10 + '0';
        ret /= 10;
        i++;
        smax--;
        smin--;
    }
    return (final(ret, result, i));
}

char *infin_add(char const *str1, char const *str2)
{
    int size1 = my_strlen(str1);
    int size2 = my_strlen(str2);
    char *result = malloc(sizeof(char) * (size1 + size2));

    if (size1 >= size2)
        result = add(str1, str2, size1, size2);
    else
        result = add(str2, str1, size2, size1);
    return (result);
}
