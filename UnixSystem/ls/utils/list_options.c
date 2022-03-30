/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** Functions for -l and -g
*/

#include <pwd.h>
#include <grp.h>
#include <stdlib.h>
#include <dirent.h>
#include "my_ls.h"

char *get_usr_grp(struct passwd *usr, struct group *grp, flags *my_flags)
{
    char *str;

    if (usr == NULL || grp == NULL) return NULL;
    str = malloc(my_strlen(usr->pw_name) + my_strlen(grp->gr_name) + 2);
    str[0] = '\0';
    if (my_flags->g) {
        my_strcat(str, grp->gr_name);
    } else {
        my_strcat(str, usr->pw_name);
        my_strcat(str, " ");
        my_strcat(str, grp->gr_name);
    }
    return (str);
}

static int get_file_total(char *name, struct stat sb, flags *my_flags)
{
    lstat(name, &sb);
    if (my_flags->a) {
        return (sb.st_blocks / 2);
    } else if (name[0] != '.') {
        return (sb.st_blocks / 2);
    }
    return (0);
}

void disp_total(char *path, flags *my_flags)
{
    struct dirent *pdirent;
    struct stat sb;
    DIR *dir = opendir(path);
    int total = 0;

    while ((pdirent = readdir(dir)) != NULL) {
        total += get_file_total(pdirent->d_name, sb, my_flags);
    }
    my_printf("total %d\n", total);
    closedir(dir);
}
