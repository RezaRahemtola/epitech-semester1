/*
** EPITECH PROJECT, 2021
** MY_GET_NBR
** File description:
** Task05
*/

static int check_negative(int i, char const *str, int negative)
{
    if (negative == 1 || (i > 0 && str[i - 1] == '-')) {
        return (1);
    } else {
        return (0);
    }
}

static int check_min_and_max(unsigned int nb, int negative)
{
    unsigned int max = 2147483647;

    if (negative == 0 && nb > max) {
        return (1);
    } else if (negative == 1 && nb > (max + 1)) {
        return (1);
    }
    return (0);
}

int my_getnbr(char const *str)
{
    unsigned int result = 0;
    int nb_value = 0;
    int negative = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        nb_value = str[i] - 48;
        if (nb_value >= 0 && nb_value <= 9) {
            negative = check_negative(i, str, negative);
            result = (result * 10) + nb_value;
        }
        if ((nb_value < 0 || nb_value > 9) && result > 0)
            break;
        if (check_min_and_max(result, negative) == 1)
            return (0);
    }
    if (negative == 1) {
        return (result * -1);
    } else {
        return (result);
    }
}
