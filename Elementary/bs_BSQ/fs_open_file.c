/*
** EPITECH PROJECT, 2021
** fs_open_file
** File description:
** Part 1 Step 1
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
void my_putstr(char *str);

int fs_open_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);

    if (fd != -1)
        my_putstr("SUCCESS\n");
    else
        my_putstr("FAILURE\n");
    close(fd);
    return (fd);
}
