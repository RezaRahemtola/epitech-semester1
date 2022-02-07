/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** utils for my_ls
*/

#ifndef UTILS_LS_H_
    #define UTILS_LS_H_
    #include "my_ls.h"
    #include <sys/stat.h>
    #include <pwd.h>
    #include <grp.h>
    char *get_type(struct stat sb);
    char *get_name_path(char const *filepath);
    char *get_usr_grp(struct passwd *usr, struct group *grp, flags *my_flags);
    char *get_full_path(char *dir, char *file);
    int count_paths(char **paths);
    char *get_time_str(struct stat sb);
    char *get_perms_str(struct stat sb);
    void disp_total(char *path, flags *my_flags);
    my_time *parse_time(char *str);
    void my_time_free(my_time *t);
#endif /* !UTILS_LS_H_ */
