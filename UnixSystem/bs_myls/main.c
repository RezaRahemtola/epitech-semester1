/*
** EPITECH PROJECT, 2021
** bs my_ls
** File description:
** main file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysmacros.h>
#include "my.h"

static char *get_name_from_filepath(char *filename)
{
    char *str = malloc(sizeof(char) * my_strlen(filename));
    int i = 0;

    my_revstr(filename);
    for (i = 0; filename[i] != '/' && i < my_strlen(filename); i++)
        str[i] = filename[i];
    str[i + 1] = '\0';
    return (my_revstr(str));
}

static void disp_type(struct stat sb)
{
    if (S_ISREG(sb.st_mode))
        my_printf("Type: f\n");
    if (S_ISCHR(sb.st_mode))
        my_printf("Type: c\n");
    if (S_ISDIR(sb.st_mode))
        my_printf("Type: d\n");
    if (S_ISBLK(sb.st_mode))
        my_printf("Type: b\n");
    if (S_ISLNK(sb.st_mode))
        my_printf("Type: l\n");
}

static void disp_major_minor(struct stat sb)
{
    if (S_ISCHR(sb.st_mode) || S_ISBLK(sb.st_mode)) {
        my_printf("Minor: %d\n", sb.st_rdev % 256);
        my_printf("Major: %d\n", sb.st_rdev / 256);
    } else {
        my_printf("Minor: N/A\n");
        my_printf("Major: N/A\n");
    }
}

int main(int argc, char **argv)
{
    struct stat sb;

    if (lstat(argv[1], &sb) == -1) {
        perror("lstat");
        return (84);
    }
    my_printf("Name: %s\n", get_name_from_filepath(argv[1]));
    disp_type(sb);
    my_printf("Inode: %d\n", sb.st_ino);
    my_printf("Hard Link: %d\n", sb.st_nlink);
    my_printf("Size: %ld\n", sb.st_size);
    my_printf("Allocated space: %ld\n", sb.st_blocks * 512);
    disp_major_minor(sb);
    my_printf("UID: %d\n", sb.st_uid);
    my_printf("GID: %d\n", sb.st_gid);
    argc = argc;
    return (0);
}
