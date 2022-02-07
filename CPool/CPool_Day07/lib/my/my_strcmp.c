/*
** EPITECH PROJECT, 2021
** MY_STRCMP
** File description:
** Task06
*/

int my_strcmp(char const *s1, char const *s2)
{
    int result_s1 = 0;
    int result_s2 = 0;
    int i = 0;

    while (s1[i] != '\0') {
        result_s1 += s1[i];
        i++;
    }
    i = 0;
    while (s2[i] != '\0') {
        result_s2 += s2[i];
        i++;
    }
    return (result_s1 - result_s2);
}
