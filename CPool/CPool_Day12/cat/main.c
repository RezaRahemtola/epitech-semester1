/*
** EPITECH PROJECT, 2021
** CAT
** File description:
** Task01 main.c
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include "../include/my.h"

void error_handling(char *file_name, int err_code)
{
    my_putstr("cat: ");
    my_putstr(file_name);
    if (err_code == 2)
        my_putstr(": No such file or directory\n");
    if (err_code == 13)
        my_putstr(": Permission denied");
    if (err_code == 21)
        my_putstr(": Is a directory");
}

void read_and_display(int fd)
{
    int size = 1;
    char buffer[30000];

    while (size != 0) {
        size = read(fd, buffer, 29999);
        write(1, buffer, size);
    }
    close(fd);
}

int main(int argc, char **argv)
{
    int fd;

    for (int i = 1; i < argc; i++) {
        fd = open(argv[i], O_RDONLY);
        if (fd == -1) {
            error_handling(argv[i], errno);
            return (84);
        }
        read_and_display(fd);
    }
    if (argc == 1)
        read_and_display(0);
    return (0);
}
