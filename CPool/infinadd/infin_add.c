/*
** EPITECH PROJECT, 2021
** INFIN_ADD
** File description:
** Functions file
*/

#include "include/my.h"
#include <stdlib.h>
int get_digit(char *nb, int i);
int get_biggest_len(char *nb1, char *nb2);
char *copy_str_except_first(char *str);

static int get_biggest(char *nb1, char *nb2)
{
    char *real_nb1 = my_revstr(my_strdup(nb1));
    char *real_nb2 = my_revstr(my_strdup(nb2));
    int nb1_neg = (nb1[my_strlen(nb1) - 1] == '-') ? -1 : 1;
    int nb2_neg = (nb2[my_strlen(nb2) - 1] == '-') ? -1 : 1;

    if (nb1_neg == -1 && nb2_neg == 1) {
        char *new_nb1 = copy_str_except_first(real_nb1);
        return (my_strcmp(new_nb1, real_nb2));
    }
    if (nb2_neg == -1 && nb1_neg == 1) {
        char *new_nb2 = copy_str_except_first(real_nb2);
        return (my_strcmp(real_nb1, new_nb2));
    }
    return (-1);
}

static int mini_add(char *nb1, char *nb2, int i)
{
    int cmp = get_biggest(nb1, nb2);
    int tmp = 0;
    int nb1_neg = (nb1[my_strlen(nb1) - 1] == '-') ? -1 : 1;
    int nb2_neg = (nb2[my_strlen(nb2) - 1] == '-') ? -1 : 1;

    if (cmp > 0 && nb1_neg == -1 && nb2_neg == 1) {
        tmp = (get_digit(nb1, i)) - get_digit(nb2, i);
    } else if (cmp < 0 && nb1_neg == 1 && nb2_neg == -1) {
        tmp = (get_digit(nb2, i)) - get_digit(nb1, i);
    } else if (nb1_neg == -1 && nb2_neg == -1) {
        tmp = ABS(get_digit(nb1, i) * nb1_neg + get_digit(nb2, i) * nb2_neg);
    } else {
        tmp = (get_digit(nb1, i) * nb1_neg + get_digit(nb2, i) * nb2_neg);
    }
    if (cmp > 0 && tmp < 0 && nb1[i + 1] != '\0') {
        nb1[i + 1] -= 1;
    } else if (cmp < 0 && tmp < 0 && nb2[i + 1] != '\0') {
        nb2[i + 1] -= 1;
    }
    return (ABS(tmp));
}

static char *check_zero(char *result, int i)
{
    my_revstr(result);
    if ((result[0] == '-' && result[1] == '0') || (result[0] == '0')) {
        result[0] = '0';
        result[1] = '\0';
    }
    result[i + 1] = '\0';
    return (result);
}

char *infin_add(char const *str1, char const *str2, int i, int tmp)
{
    char *nb1 = my_revstr(my_strdup(str1));
    char *nb2 = my_revstr(my_strdup(str2));
    char *res = malloc(my_strlen(nb1) + my_strlen(nb2) + 2);
    int acc = 0;
    int size = get_biggest(nb1, nb2);

    for (int j = get_biggest_len(nb1, nb2); i < j || acc == 1; i++) {
        if (size == 0)
            return ("0");
        if ((nb1[i] == '-' && size > 0) || (nb2[i] == '-' && size < 0)) {
            res[i] = '-';
        } else if ((nb1[i] == '-' && size < 0) || (nb2[i] == '-' && size > 0)) {
            break;
        } else {
            tmp = mini_add(nb1, nb2, i);
            res[i] = DTOA((tmp + acc) % 10);
        }
        acc = (tmp + acc > 9) ? 1 : 0;
    }
    return (check_zero(res, i));
}
