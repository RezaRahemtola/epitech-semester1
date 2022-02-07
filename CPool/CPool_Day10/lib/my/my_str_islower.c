/*
** EPITECH PROJECT, 2021
** MY_STR_ISLOWER
** File description:
** Task14
*/

int my_str_islower(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 'a' || str[i] > 'z')
            return (0);
        i++;
    }
    return (1);
}
