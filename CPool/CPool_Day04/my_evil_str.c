/*
** EPITECH PROJECT, 2021
** MY_EVIL_STR
** File description:
** Task04
*/
int my_strlen(char const *str);

char *my_evil_str(char *str)
{
    int start = 0;
    int end = my_strlen(str) - 1;
    char temp;

    while (end - start >= 0) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
    return (str);
}
