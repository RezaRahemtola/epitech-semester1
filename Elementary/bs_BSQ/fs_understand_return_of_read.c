/*
** EPITECH PROJECT, 2021
** fs_understand_return_of_read
** File description:
** Part 1 Step 2
*/

#include <unistd.h>
void my_putstr(char *str);

void fs_understand_return_of_read(int fd, char *buffer, int size)
{
    int bytes_read = read(fd, buffer, size);

    if (bytes_read == -1)
        my_putstr("read failed\n");
    else if (bytes_read == 0)
        my_putstr("read has nothing more to read\n");
    if (bytes_read < size && bytes_read > 0)
        my_putstr("read didn't complete the entire buffer\n");
    else if (bytes_read == size)
        my_putstr("read completed the entire buffer\n");
}
