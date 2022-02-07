/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** Functions for -l option
*/

#include <stdlib.h>
#include <dirent.h>
#include <time.h>
#include "my_ls.h"

static void disp_size_str(struct stat sb, char *perms)
{
    unsigned long major;
    unsigned long minor;

    if (perms[0] == 'c' || perms[0] == 'b') {
        major = sb.st_rdev / 256;
        minor = sb.st_rdev % 256;
        my_printf(" %ld, %ld ", major, minor);
    } else {
        my_printf(" %ld ", sb.st_size);
    }
}

static int disp_file(char *filename, char *filepath, flags *my_flags)
{
    struct stat sb;
    char *perms;
    char *time_str;
    char *usr_grp;

    if (my_flags->a == 0 && filename[0] == '.') return (0);
    lstat(filepath, &sb);
    perms = get_perms_str(sb);
    time_str = get_time_str(sb);
    usr_grp = get_usr_grp(getpwuid(sb.st_uid), getgrgid(sb.st_gid), my_flags);
    if (usr_grp == NULL) return (84);
    my_printf("%s. %d %s", perms, sb.st_nlink, usr_grp);
    disp_size_str(sb, perms);
    my_printf("%s %s\n", time_str, filename);
    free(usr_grp);
    free(perms);
    free(time_str);
    return (0);
}

static int list_path(char **paths, char *path, flags *my_flgs, struct stat sb)
{
    struct dirent *pdirent;
    DIR *dir;
    char *full_path;
    int err = 0;

    if (my_strcmp(get_type(sb), "d") == 0 && my_flgs->d == 0) {
        if (count_paths(paths) > 1) my_printf("%s:\n", path);
        dir = opendir(path);
        disp_total(path, my_flgs);
        while ((pdirent = readdir(dir)) != NULL) {
            full_path = get_full_path(path, pdirent->d_name);
            err += disp_file(get_name_path(full_path), full_path, my_flgs);
        }
        closedir(dir);
        free(full_path);
    } else {
        disp_file(path, path, my_flgs);
    }
    return (err);
}

int list_option(char **paths, flags *my_flags)
{
    struct stat sb;
    int error = 0;

    for (int i = 0; my_strcmp(paths[i], "\0") != 0; i++) {
        if (lstat(paths[i], &sb) == -1) {
            error += 84;
        } else {
            error += list_path(paths, paths[i], my_flags, sb);
        }
    }
    return (error >= 84) ? (84) : (0);
}
