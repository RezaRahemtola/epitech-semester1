/*
** EPITECH PROJECT, 2021
** MY_PUTNBR_BASE
** File description:
** Task18
*/

#include <unistd.h>

char *reverse_str(char *str)
{
    int start = 0;
    int end = 0;
    int strlen = 0;
    char temp;

    while (str[strlen] != '\0') {
        strlen++;
    }
    end = strlen - 1;
    while (end - start >= 0) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
    return (str);
}

void print_str(char *str, int negative)
{
    int i = 0;
    char neg = '-';

    if (negative == 1)
        write(1, &neg, 1);
    while (str[i] != '\0') {
        write(1, &str[i], 1);
        i++;
    }
}

int my_putnbr_base(int nbr, char const *base)
{
    int base_len = 0;
    char result[1000];
    int i = 0;
    int negative = 0;

    if (nbr < 0) {
        negative = 1;
        nbr *= -1;
    }
    while (base[base_len] != '\0')
        base_len++;
    while (nbr / base_len > 0) {
        result[i] = base[nbr % base_len];
        nbr /= base_len;
        i++;
    }
    result[i] = base[nbr % base_len];
    reverse_str(result);
    print_str(result, negative);
    return (0);
}
