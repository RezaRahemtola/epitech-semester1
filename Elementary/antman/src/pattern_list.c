/*
** EPITECH PROJECT, 2022
** antman
** File description:
** Functions for the pattern list
*/

#include <stddef.h>
#include <stdlib.h>
#include "generic.h"

void my_putend(char *str, pattern_t **dest)
{
    pattern_t *list = *dest;
    pattern_t *obj = malloc(sizeof(pattern_t));

    obj->str = my_strdup(str);
    obj->next = NULL;

    if (list == NULL) {
        *dest = obj;
        return;
    }
    while (list->next != NULL)
        list = list->next;
    list->next = obj;
}

void list_destroy(pattern_t *obj)
{
    pattern_t *tmp = NULL;

    while (obj != NULL) {
        tmp = obj;
        obj = obj->next;
        free(tmp->str);
        free(tmp);
    }
}

int is_in_list(char *str, pattern_t *list)
{
    for (int i = 1; list != NULL; i++) {
        if (my_strcmp(list->str, str) == 0)
            return (i);
        list = list->next;
    }
    return (-1);
}

int get_list_len(pattern_t *list)
{
    int len = 0;

    while (list != NULL) {
        len += my_strlen(list->str);
        list = list->next;
    }
    return (len);
}

pattern_t *get_html_patterns_list(void)
{
    pattern_t *list = NULL;

    my_putend("div", &list);
    my_putend("span", &list);
    my_putend(" class=\"", &list);
    my_putend("function(", &list);
    my_putend("background", &list);
    my_putend("<a href=\"", &list);
    my_putend(" id=\"", &list);
    my_putend("</", &list);
    my_putend("=\"", &list);
    my_putend("\">", &list);
    my_putend("var ", &list);
    my_putend("https://", &list);
    my_putend("return", &list);
    my_putend("    ", &list);
    my_putend("title=\"", &list);
    return (list);
}
