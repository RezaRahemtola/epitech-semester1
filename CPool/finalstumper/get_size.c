/*
** EPITECH PROJECT, 2021
** rush3
** File description:
** gets size of x
*/

int get_size_x(char *buff)
{
    int i = 0;

    while (buff[i] != '\n')
        i += 1;
    return i;
}

int get_size_y(char *buff)
{
    int i = 0;
    int counter = 0;

    while (buff[i] != '\0') {
        if (buff[i] == '\n')
            counter += 1;
        i += 1;
    }
    return (counter);
}
