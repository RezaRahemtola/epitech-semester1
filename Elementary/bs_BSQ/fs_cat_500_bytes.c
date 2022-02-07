/*
** EPITECH PROJECT, 2021
** fs_cat_500_bytes
** File description:
** Part 1 Step 3
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
void my_putchar(char c);

void fs_cat_500_bytes(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char buff[500];
    int bytes_read;

    if (fd == -1)
        return;
    bytes_read = read(fd, buff, 500);
    for (int i = 0; i < bytes_read; i++)
        my_putchar(buff[i]);
    close(fd);
}
