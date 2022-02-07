/*
** EPITECH PROJECT, 2022
** antman
** File description:
** Main file for antman
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "giantman.h"

int main(int argc, char **argv)
{
    char *buffer = NULL;
    struct stat sb;
    int fd = open(argv[1], O_RDONLY);
    int size = 0;

    if (stat(argv[1], &sb) == -1) return (84);
    buffer = my_malloc_str(sizeof(char) * (sb.st_size + 1), '\0');
    if (buffer == NULL) return (84);
    size = read(fd, buffer, sb.st_size);
    if (check_errors(argc, argv, fd, size) == 84) return (84);
    if (my_strcmp(argv[2], "1") == 0)
        decomp_lyr(&buffer);
    else if (my_strcmp(argv[2], "3") == 0)
        decomp_ppm(buffer, sb.st_size);
    else
        decomp_html(buffer, sb.st_size);
    close(fd);
    free(buffer);
    return (0);
}
