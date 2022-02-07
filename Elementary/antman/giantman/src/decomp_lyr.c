/*
** EPITECH PROJECT, 2022
** giantman
** File description:
** Functions to uncompress algo_lyr
*/

#include <stdlib.h>
#include "giantman.h"

static void disp_str_from_list(pattern_t *list, char *content, int *current)
{
    pattern_t *tmp = list;
    int index = 0;

    if (content[0] == '+') {
        (*current)++;
        index = *current;
    } else {
        index = get_base_nbr(content);
    }
    for (int i = 1; tmp != NULL; i++) {
        if (i == index) {
            my_printf("%s", tmp->str);
            return;
        }
        tmp = tmp->next;
    }
}

static char *get_pattern(char **content)
{
    char *tmp = NULL;
    int i = 0;

    while ((*content)[i] != '@' && (*content)[i] != '\0')
        i++;
    tmp = my_malloc_str(sizeof(char) * (i + 1), '\0');
    my_strncpy(tmp, *content, i);
    (*content) += i;
    if ((*content)[0] == '@') (*content)++;
    return (tmp);
}

static void move_content(char **str)
{
    if ((*str)[0] == '+')
        (*str)++;
    else
        while ((*str)[0] != '+' && (*str)[0] != '-' && (*str)[0] != '\0')
            (*str)++;
    if ((*str)[0] == '-') (*str)++;
}

static void disp_decomp(char **content, pattern_t *list, int len, int *current)
{
    while ((*content)[0] != '\0') {
        disp_str_from_list(list, *content, current);
        move_content(content);
        if ((*content)[0] != '\0')
            my_putchar(' ');
    }
    (*content) -= len;
    list_destroy(list);
}

void decomp_lyr(char **content)
{
    int len = my_strlen(*content);
    int *current = malloc(sizeof(int));
    pattern_t *list = NULL;
    char *pattern = NULL;

    *current = 0;
    while ((*content)[0] != '\0' && my_strstr(*content, "@") != NULL) {
        pattern = get_pattern(content);
        my_putend(pattern, &list);
        free(pattern);
    }
    if (list == NULL)
        my_putstr(*content);
    else
        disp_decomp(content, list, len, current);
    free(current);
}
