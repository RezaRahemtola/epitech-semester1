/*
** EPITECH PROJECT, 2021
** MY_GET_NBR
** File description:
** Task05
*/

int check_negative(int i, char last_char, int negative)
{
    if (negative == 1)
        return (1);
    if (i > 0 && last_char == 45)
        return (1);
    return (0);
}

int check_max(unsigned int nb, int negative)
{
    unsigned int max = 2147483647;

    if (nb > max) {
        if (nb == 2147483648 && negative == 1)
            return (0);
        return (1);
    }
    return (0);
}

int check_min(unsigned int nb)
{
    unsigned int min = -2147483648;

    if (nb < min)
        return (1);
    return (0);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int negative = 0;
    unsigned int result = 0;

    while (str[i] != '\0') {
        if (str[i] - 48 >= 0 && str[i] - 48 <= 9) {
            if (check_max(result * 10 + str[i] - 48, negative) == 1)
                return (0);
            result = result * 10 + str[i] - 48;
            negative = check_negative(i, str[i - 1], negative);
        } else if (result > 0) {
            break;
        }
        i++;
    }
    if (negative == 1) {
        if (check_min(result * - 1) == 1)
            return (0);
        return (result * - 1);
    }
    return (result);
}
