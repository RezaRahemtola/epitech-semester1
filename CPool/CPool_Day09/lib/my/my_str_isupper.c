/*
** EPITECH PROJECT, 2021
** MY_STR_ISUPPER
** File description:
** Task15
*/

int my_str_isupper(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 'A' || str[i] > 'Z')
            return (0);
        i++;
    }
    return (1);
}
