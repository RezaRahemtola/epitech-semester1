/*
** EPITECH PROJECT, 2021
** infin_mult
** File description:
** desc
*/

#include "bistromatic.h"

char *init_str(char *str, int len1, int len2)
{
    int i = 0;
    int len = len1 + len2;

    while (i < len) {
        str[i] = '0';
        i++;
    }
    return (str);
}

int is_neg_mult(char const *nb1, char const *nb2)
{
    if (nb1[0] == '-' && nb2[0] == '-') {
        return 0;
    }
    if (nb1[0] == '-' || nb2[0] == '-') {
        return 1;
    }
    return 0;
}

static void end_res(char *res, int i, int j, int ret)
{
    if (ret) {
        j++;
        res[i + j - 1] = DTAS(ret);
    }
    res[i + j - 1] = '\0';
}

static char *clean_res(int is_neg, char *res)
{
    if (is_neg)
        my_strcat(res, "-");
    return (remove_zero(my_revstr(res)));
}

char *infin_mult(char const *str1, char const *str2, int i, int j)
{
    char *res = malloc((my_strlen(str1) + my_strlen(str2) + 2) * sizeof(char));
    char *nb1 = my_revstr(remove_sub(my_strdup(str1)));
    char *nb2 = my_revstr(remove_sub(my_strdup(str2)));
    int tmp = 0;
    int ret = 0;

    res = init_str(res, my_strlen(str1), my_strlen(str2));
    for (; nb1[i]; i++) {
        j = 0;
        ret = 0;
        for (; nb2[j]; j++) {
            tmp = (ASTD(nb1[i]) * ASTD(nb2[j])) + ret + ASTD(res[i + j]);
            res[i + j] = DTAS(tmp % 10);
            ret = tmp / 10;
        }
        res[i + j] = (ret) ? (DTAS(ret)) : ('0');
    }
    end_res(res, i, j, ret);
    return (clean_res(is_neg_mult(str1, str2), res));
}
