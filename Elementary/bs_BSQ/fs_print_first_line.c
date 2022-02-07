/*
** EPITECH PROJECT, 2021
** fs_print_first_line
** File description:
** Part 1 Step 5
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
void my_putchar(char c);

void fs_print_first_line(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char buff[500];
    int bytes_read = 1;
    int i = 0;

    if (fd == -1)
        return;
    while (bytes_read > 0) {
        bytes_read = read(fd, buff, 500);
        for (i = 0; i < bytes_read && buff[i] != '\n'; i++)
            my_putchar(buff[i]);
        if (buff[i] == '\n')
            break;
    }
    close(fd);
}
