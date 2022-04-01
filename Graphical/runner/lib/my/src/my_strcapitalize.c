/*
** EPITECH PROJECT, 2021
** MY_STRCAPITALIZE
** File description:
** Task10
*/

static int is_letter(char c)
{
    if (c >= 'a' && c <= 'z') {
        return (1);
    } else if (c >= 'A' && c <= 'Z') {
        return (2);
    }
    return (0);
}

static int to_capitalize(char *str, int i)
{
    if (i == 0)
        return (1);
    if (is_letter(str[i - 1]) == 0 && (str[i - 1] < '0' || str[i - 1] > '9'))
        return (1);
    return (0);
}

char *my_strcapitalize(char *str)
{
    int i = 0;
    int letter;

    while (str[i] != '\0') {
        letter = is_letter(str[i]);
        if (letter == 1 && to_capitalize(str, i) == 1)
            str[i] -= 32;
        if (letter == 2 && to_capitalize(str, i) == 0)
            str[i] += 32;
        i++;
    }
    return (str);
}
