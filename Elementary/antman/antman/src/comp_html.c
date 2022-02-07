/*
** EPITECH PROJECT, 2022
** antman
** File description:
** Functions to compress HTML files
*/

#include "antman.h"

static int disp_patterns(char **content, pattern_t *list)
{
    for (int i = 0; list != NULL; i++) {
        if (my_strncmp(*content, list->str, my_strlen(list->str)) == 0) {
            my_putchar(HTML_UNSIGNED + i);
            (*content) += my_strlen(list->str);
            return (1);
        }
        list = list->next;
    }
    return (0);
}

void comp_html(char **content)
{
    int len = my_strlen(*content);
    pattern_t *list = get_html_patterns_list();

    while ((*content)[0] != '\0') {
        if (disp_patterns(content, list) == 0) {
            my_putchar((*content)[0]);
            (*content)++;
        }
    }
    list_destroy(list);
    (*content) -= len;
}
