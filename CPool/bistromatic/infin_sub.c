/*
** EPITECH PROJECT, 2021
** INFIN_SUB_C
** File description:
** do infinite subdivision
*/

#include "bistromatic.h"

char *remove_sub(char const *str)
{
    int i = 0;
    int j = 0;
    char *fin = my_strdup(str);

    if (str[0] == '-')
        j = 1;
    while (str[i + j]) {
        fin[i] = str[i + j];
        i++;
    }
    fin[i] = '\0';
    return (fin);
}

int is_greater(char const *n1, char const *n2)
{
    int i = 0;
    int j = 0;

    remove_sub(n1);
    remove_sub(n2);
    if (my_strlen(n1) > my_strlen(n2))
        return 1;
    if (my_strlen(n2) > my_strlen(n1))
        return 0;
    while (n1[i] == n2[j]) {
        i++;
        j++;
    }
    if (n1[i] > n2[j])
        return 1;
    return 0;
}

static int is_neg(char const *nb1, char const *nb2)
{
    if ((nb1[0] == '-' && is_greater(remove_sub(nb1), remove_sub(nb2))) ||
        (nb2[0] == '-' && is_greater(remove_sub(nb2), remove_sub(nb1)))) {
        return 1;
    }
    return 0;
}

static char *sub(char *nb1, char *nb2, char *res)
{
    int i = 0;
    int ret = 0;
    int tmp = 0;

    for (; nb2[i] && nb2[i] != '-'; i++) {
        tmp = ASTD(nb1[i]) - ASTD(nb2[i]) - ret;
        if (tmp < 0)
            res[i] = DTAS(10 - ABS(tmp));
        else
            res[i] = DTAS(tmp);
        ret = (tmp < 0) ? (1) : (0);
    }
    for (; nb1[i] && nb1[i] != '-'; i++) {
        tmp = ASTD(nb1[i]) - ret;
        res[i] = (tmp < 0) ? (DTAS(10 - ABS(tmp))) : (DTAS(tmp));
        ret = (tmp < 0) ? (1) : (0);
    }
    res[i] = '\0';
    return (res);
}

char *infin_sub(char const *str1, char const *str2)
{
    int neg = is_neg(str1, str2);
    char *nb1 = my_revstr(my_strdup(str1));
    char *nb2 = my_revstr(my_strdup(str2));
    char *res = malloc((my_strlen(nb1) + my_strlen(nb2) + 2) * sizeof(char));

    if (is_greater(remove_sub(str1), remove_sub(str2)))
        res = sub(nb1, nb2, res);
    else if (is_greater(remove_sub(str2), remove_sub(str1)))
        res = sub(nb2, nb1, res);
    if (neg)
        my_strcat(res, "-");
    my_revstr(res);
    res = remove_zero(res);
    return (res);
}
