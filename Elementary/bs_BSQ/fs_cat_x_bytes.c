/*
** EPITECH PROJECT, 2021
** fs_cat_x_bytes
** File description:
** Part 1 Step 4
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
void my_putchar(char c);

void fs_cat_x_bytes(char const *filepath, int x)
{
    int fd = open(filepath, O_RDONLY);
    char buff[x];
    int bytes_read = 1;

    if (fd == -1)
        return;
    bytes_read = read(fd, buff, x);
    for (int i = 0; i < bytes_read; i++)
        my_putchar(buff[i]);
    close(fd);
}
