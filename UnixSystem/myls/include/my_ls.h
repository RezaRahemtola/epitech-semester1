/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** .h
*/

#ifndef MY_LS_H_
    #define MY_LS_H_
    #include "my.h"
    typedef struct my_time_struct {
        char *sec;
        char *min;
        char *hour;
        char *day;
        char *month;
        char *year;
    } my_time;
    typedef struct ls_flags {
        int l;
        int up_r;
        int d;
        int low_r;
        int t;
        int g;
        int a;
    } flags;
    #include "utils.h"
    void parse_flags(int argc, char **argv, flags *my_flags);
    char **parse_paths(int argc, char **argv);
    int no_option(char **paths, flags *my_flags);
    int list_option(char **paths, flags *my_flags);
    char *number(char **str_ptr);
#endif /* !MY_LS_H_ */
