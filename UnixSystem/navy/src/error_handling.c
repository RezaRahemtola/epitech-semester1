/*
** EPITECH PROJECT, 2021
** navy
** File description:
** Functions for error handling
*/

#include "navy.h"

static int check_boat_pos(char *buff)
{
    int diff_pos = (buff[5] + buff[6]) - (buff[2] + buff[3]);
    int is_error = 0;

    if (buff[2] < 'A' || buff[2] > 'H') is_error = 1;
    if (buff[3] < '1' || buff[3] > '8') is_error = 1;
    if (buff[5] < 'A' || buff[5] > 'H') is_error = 1;
    if (buff[6] < '1' || buff[6] > '8') is_error = 1;
    if (is_error == 1)
        write(2, "./navy: Invalid file: incorrect boat position.\n", 47);
    if (diff_pos != buff[0] - '0' - 1) {
        write(2, "./navy: Invalid file: position doesn't match size\n", 50);
        return (1);
    }
    return (is_error);
}

static int check_file(int fd)
{
    char buff[8];
    char boat_sizes[4] = {'2', '3', '4', '5'};

    for (int i = 0; i < 4; i++) {
        if (read(fd, buff, 8) < 8) {
            write(2, "./navy: Invalid file: not enought content.\n", 43);
            return (1);
        }
        if (buff[0] != boat_sizes[i]) {
            write(2, "./navy: Invalid file: incorrect boat sizes.\n", 44);
            return (1);
        }
        if (check_boat_pos(buff) == 1) return (1);
    }
    return (0);
}

static int check_one_arg(char **argv)
{
    int fd;

    if (my_strcmp(argv[1], "-h") == 0) return (0);
    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        write(2, "./navy: File not found\nretry with -h\n", 37);
        return (1);
    }
    if (check_file(fd) == 1) {
        close(fd);
        return (1);
    }
    return (0);
}

static int check_two_args(char **argv)
{
    int fd = open(argv[2], O_RDONLY);
    pid_t pid = my_getnbr(argv[1]);

    if (fd == -1) {
        write(2, "./navy: File not found\nretry with -h\n", 37);
        return (1);
    }
    if (kill(pid, 0) == -1) {
        write(2, "./navy: Process not found\nretry with -h\n", 40);
        return (1);
    }
    if (check_file(fd) == 1) {
        close(fd);
        return (1);
    }
    return (0);
}

int check_errors(int argc, char **argv)
{
    if (argc < 2 || argc > 3) {
        write(2, "./navy: Invalid number of arguments\nretry with -h\n", 50);
        return (1);
    }
    if (argc == 2 && check_one_arg(argv) == 1) return (1);
    if (argc == 3 && check_two_args(argv) == 1) return (1);
    return (0);
}
