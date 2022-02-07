/*
** EPITECH PROJECT, 2021
** Final Stumper
** File description:
** main.c
*/

#include <unistd.h>
#include "rush3.h"
#include "my.h"

int main(int argc, char **argv)
{
    char buff[BUFF_SIZE + 1];
    int offset = 0;
    int len;

    if (argc == 1 && my_strlen(argv[0]) > 1)
        offset = 0;
    while ((len = read(0, buff + offset, BUFF_SIZE - offset)) > 0) {
        offset += len;
    }
    buff[offset] = '\0';
    if (len < 0)
        return (84);
    my_putstr(stumper(buff));
    return (0);
}
