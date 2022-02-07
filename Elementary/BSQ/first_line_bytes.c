/*
** EPITECH PROJECT, 2021
** get_bytes_first_line
** File description:
** Part 1 Task 6
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int first_line_bytes(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char buff[500];
    int bytes = 0;

    read(fd, buff, 500);
    for (int i = 0; buff[i] != '\n'; i++) {
        bytes++;
    }
    close(fd);
    return (bytes + 1);
}
