/*
** EPITECH PROJECT, 2021
** load_2d_arr_from_file
** File description:
** Part 4 Step 2
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "bsq.h"
#include "my.h"

static int get_cols_per_line(int nb_rows, struct stat sb, char const *filepath)
{
    stat(filepath, &sb);
    return (sb.st_size / nb_rows);
}

void display_map(char **map, int nb_rows, int nb_cols)
{
    for (int i = 0; i < nb_rows; i++) {
        write(1, map[i], nb_cols);
    }
}

char **load_map(char const *f_path, int nb_rows, int nb_cols, int ignore)
{
    struct stat sb;
    nb_cols = get_cols_per_line(nb_rows, sb, f_path);
    char **new_array = mem_alloc_2d_array(nb_rows, nb_cols);
    int fd = open(f_path, O_RDONLY);
    char buff[nb_cols];
    char buff_ignore[ignore];
    int bytes_read = 1;

    read(fd, buff_ignore, ignore);
    for (int i = 0; i < nb_rows; i++) {
        bytes_read = read(fd, buff, nb_cols);
        my_strncat(new_array[i], buff, bytes_read);
    }
    close(fd);
    return (new_array);
}
