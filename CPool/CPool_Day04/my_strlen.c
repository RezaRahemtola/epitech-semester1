/*
** EPITECH PROJECT, 2021
** MY_STRLEN
** File description:
** Task03
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}
