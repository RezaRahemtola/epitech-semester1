/*
** EPITECH PROJECT, 2021
** MY_STR_ISALPHA
** File description:
** Task12
*/

static int is_alpha(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (1);
    return (0);
}

int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (is_alpha(str[i]) == 0)
            return (0);
    }
    return (1);
}
