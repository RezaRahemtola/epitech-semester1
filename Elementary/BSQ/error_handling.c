/*
** EPITECH PROJECT, 2021
** BSQ
** File description:
** Error handling fucntions
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "bsq.h"

static int check_unknown_char(int bytes_read, char *buff)
{
    for (int i = 0; i < bytes_read; i++) {
        if (buff[i] != 'o' && buff[i] != '.' && buff[i] != '\n')
            return (1);
    }
    return (0);
}

int check_map_errors(char *path, int cols, int ignore)
{
    int fd = open(path, O_RDONLY);
    char buff[cols];
    char buff_ignore[ignore];
    int bytes_read = 0;

    read(fd, buff_ignore, ignore);
    while ((bytes_read = read(fd, buff, cols)) >= 1) {
        if (bytes_read == cols && buff[cols - 1] != '\n')
            return (1);
        if (check_unknown_char(bytes_read, buff) == 1)
            return (1);
    }
    close(fd);
    return (0);
}

int check_errors(int argc, char **argv)
{
    int fd;
    struct stat sb;

    if (argc != 2)
        return (1);
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        return (1);
    stat(argv[1], &sb);
    if (sb.st_size == 0)
        return (1);
    if (get_first_line_nbr(argv[1]) < 1)
        return (1);
    close(fd);
    return (0);
}
