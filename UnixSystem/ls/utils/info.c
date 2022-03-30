/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** Some functions to get info on files/folders
*/

#include <sys/stat.h>
#include <stdlib.h>
#include "my.h"

char *get_type(struct stat sb)
{
    if (S_ISREG(sb.st_mode))
        return ("-");
    if (S_ISCHR(sb.st_mode))
        return ("c");
    if (S_ISDIR(sb.st_mode))
        return ("d");
    if (S_ISBLK(sb.st_mode))
        return ("b");
    if (S_ISLNK(sb.st_mode))
        return ("l");
    return ("-");
}

char *get_name_path(char const *filepath)
{
    char *str = malloc(sizeof(char) * (my_strlen(filepath) + 1));
    int i = 0;
    char *path_cpy = my_strdup(filepath);

    my_revstr(path_cpy);
    for (i = 0; path_cpy[i] != '/' && i < my_strlen(path_cpy); i++)
        str[i] = path_cpy[i];
    str[i] = '\0';
    free(path_cpy);
    return (my_revstr(str));
}

char *get_full_path(char *dir, char *file)
{
    int dir_len = my_strlen(dir);
    char *full = malloc(sizeof(char) * (dir_len + my_strlen(file) + 2));

    my_strcpy(full, dir);
    if (dir[dir_len - 1] != '/') my_strcat(full, "/");
    my_strcat(full, file);
    return (full);
}

char *get_perms_str(struct stat sb)
{
    char perms[11] = "\0";

    my_strcat(perms, get_type(sb));
    (sb.st_mode & S_IRUSR) ? my_strcat(perms, "r") : my_strcat(perms, "-");
    (sb.st_mode & S_IWUSR) ? my_strcat(perms, "w") : my_strcat(perms, "-");
    (sb.st_mode & S_IXUSR) ? my_strcat(perms, "x") : my_strcat(perms, "-");
    (sb.st_mode & S_IRGRP) ? my_strcat(perms, "r") : my_strcat(perms, "-");
    (sb.st_mode & S_IWGRP) ? my_strcat(perms, "w") : my_strcat(perms, "-");
    (sb.st_mode & S_IXGRP) ? my_strcat(perms, "x") : my_strcat(perms, "-");
    (sb.st_mode & S_IROTH) ? my_strcat(perms, "r") : my_strcat(perms, "-");
    (sb.st_mode & S_IWOTH) ? my_strcat(perms, "w") : my_strcat(perms, "-");
    (sb.st_mode & S_IXOTH) ? my_strcat(perms, "x") : my_strcat(perms, "-");
    if ((sb.st_mode & __S_ISVTX) && perms[9] == 'x')
        perms[9] = 't';
    else if ((sb.st_mode & __S_ISVTX) && perms[9] == '-')
        perms[9] = 'T';
    return (my_strdup(perms));
}

int count_paths(char **paths)
{
    int count = 0;

    for (int i = 0; my_strcmp(paths[i], "\0") != 0; i++)
        count++;
    return (count);
}
