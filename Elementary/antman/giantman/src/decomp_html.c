/*
** EPITECH PROJECT, 2022
** giantman
** File description:
** Functions to decompress HTML
*/

#include <unistd.h>
#include "giantman.h"

static void disp_pattern(unsigned char c, pattern_t *list)
{
    int diff = c - HTML_UNSIGNED;
    for (int i = 0; list != NULL; i++) {
        if (i == diff)
            my_putstr(list->str);
        list = list->next;
    }
}

void decomp_html(char *buffer, int len)
{
    pattern_t *list = get_html_patterns_list();

    for (int i = 0; i < len; i++) {
        if ((unsigned char)buffer[i] >= HTML_UNSIGNED)
            disp_pattern(buffer[i], list);
        else
            write(1, &buffer[i], 1);
    }
    list_destroy(list);
}
