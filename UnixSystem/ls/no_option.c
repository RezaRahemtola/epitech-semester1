/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** Functions for ls without options
*/

#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include "my_ls.h"
#include "my.h"

static void disp_file(char *name, flags *my_flags)
{
    if (my_flags->a) {
        my_printf("%s\n", name);
    } else if (name[0] != '.') {
        my_printf("%s\n", name);
    }
}

static int disp_files_in_dir(char *path, flags *my_flags)
{
    DIR *dir;
    struct dirent *pdirent;

    dir = opendir(path);
    if (dir == NULL) return (84);
    while ((pdirent = readdir(dir)) != NULL) {
        disp_file(pdirent->d_name, my_flags);
    }
    closedir(dir);
    return (0);
}

static int disp_no_option_path(char **paths, char *path, flags *my_flags)
{
    int error = 0;
    struct stat sb;

    if (lstat(path, &sb) == -1) {
        perror("ls");
        return (84);
    }
    if (my_strcmp(get_type(sb), "d") == 0 && my_flags->d == 0) {
        if (count_paths(paths) > 1) my_printf("%s:\n", path);
        error += disp_files_in_dir(path, my_flags);
    } else {
        my_printf("%s\n", path);
    }
    return (error);
}

int no_option(char **paths, flags *my_flags)
{
    int error = 0;

    for (int i = 0; my_strcmp(paths[i], "\0") != 0; i++)
        error += disp_no_option_path(paths, paths[i], my_flags);
    return (error >= 84) ? (84) : (0);
}
