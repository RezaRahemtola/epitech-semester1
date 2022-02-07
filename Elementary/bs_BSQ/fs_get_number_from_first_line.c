/*
** EPITECH PROJECT, 2021
** get_number_from_first_line
** File description:
** Part 1 Task 6
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int my_getnbr(char *str);

int fs_get_number_from_first_line(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char buff[500];
    int bytes_read = 1;
    int line_nb;

    if (fd == -1)
        return (-1);
    bytes_read = read(fd, buff, 500);
    if (bytes_read == 0 || buff[0] <= '0' || buff[0] > '9')
        return (-1);
    line_nb = my_getnbr(buff);
    close(fd);
    return (line_nb);
}
