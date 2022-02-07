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
char **mem_alloc_2d_array(int nb_rows, int nb_cols);
char *my_strncat(char *dest, char const *src, int nb);

static int get_cols_per_line(int nb_rows, struct stat sb, char const *filepath)
{
    stat(filepath, &sb);
    return (sb.st_size / nb_rows);
}

char **load_2d_arr_from_file(char const *filepath, int nb_rows, int nb_cols)
{
    struct stat sb;
    nb_cols = get_cols_per_line(nb_rows, sb, filepath);
    char **new_array = mem_alloc_2d_array(nb_rows, nb_cols);
    int fd = open(filepath, O_RDONLY);
    char buff[nb_cols];
    int bytes_read = 1;

    for (int i = 0; i < nb_rows; i++) {
        bytes_read = read(fd, buff, nb_cols);
        my_strncat(new_array[i], buff, bytes_read);
    }
    close(fd);
    return (new_array);
}
