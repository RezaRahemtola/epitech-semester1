/*
** EPITECH PROJECT, 2021
** load_file_in_mem
** File description:
** Part 4 Step 1
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
char *my_strncat(char *dest, char const *src, int nb);

char *load_file_in_mem(char const *filepath)
{
    struct stat sb;
    char *new_str;
    int fd = open(filepath, O_RDONLY);
    int bytes_read = 1;
    char buff[500];

    stat(filepath, &sb);
    new_str = malloc(sizeof(char) * sb.st_size);
    while (bytes_read > 0) {
        bytes_read = read(fd, buff, 500);
        my_strncat(new_str, buff, bytes_read);
    }
    close(fd);
    return (new_str);
}
