/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** Time functions
*/

#include <time.h>
#include <stdlib.h>
#include "my_ls.h"

my_time *parse_time(char *str)
{
    my_time *t = malloc(sizeof(my_time));
    char *str_cpy = my_strdup(str);
    int len = my_strlen(str_cpy);
    char **str_ptr = &str_cpy;

    (*str_ptr) += 4;
    t->month = malloc(4);
    my_strncpy(t->month, str_cpy, 3);
    t->month[3] = '\0';
    t->day = number(str_ptr);
    t->hour = number(str_ptr);
    t->min = number(str_ptr);
    t->sec = number(str_ptr);
    t->year = number(str_ptr);
    (*str_ptr) -= len - 1;
    free(str_cpy);
    return (t);
}

char *get_time_str(struct stat sb)
{
    my_time *t = parse_time(ctime(&sb.st_mtime));
    char time_str[13] = "\0";

    my_strcat(time_str, t->month);
    my_strcat(time_str, " ");
    my_strcat(time_str, t->day);
    my_strcat(time_str, " ");
    my_strcat(time_str, t->hour);
    my_strcat(time_str, ":");
    my_strcat(time_str, t->min);
    my_time_free(t);
    return (my_strdup(time_str));
}

void my_time_free(my_time *t)
{
    free(t->month);
    free(t->day);
    free(t->hour);
    free(t->min);
    free(t->sec);
    free(t->year);
    free(t);
}
