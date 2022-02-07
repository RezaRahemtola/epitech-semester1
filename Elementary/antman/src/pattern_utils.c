/*
** EPITECH PROJECT, 2022
** antman
** File description:
** Utils function for pattern lists
*/

#include <stdlib.h>
#include "generic.h"

int is_in_next_list(char *str, pattern_t *list)
{
    list = list->next;
    for (int i = 1; list != NULL; i++) {
        if (my_strcmp(list->str, str) == 0)
            return (i);
        list = list->next;
    }
    return (-1);
}

void destroy_node(pattern_t **head)
{
    pattern_t *obj = *head;

    *head = obj->next;
    obj->next = NULL;
    list_destroy(obj);
}

int get_base_nbr(char *str)
{
    int len = 0;
    char *nb_str = NULL;
    int nb = 0;

    while (str[len] != '\0' && str[len] != '+' && str[len] != '-')
        len++;
    nb_str = my_malloc_str(len + 1, '\0');
    my_strncpy(nb_str, str, len);
    nb = base_to_int(nb_str, BASE BASE2);
    free(nb_str);
    return (nb);
}

pattern_t *get_words(char **content)
{
    int len = my_strlen(*content);
    pattern_t *words = NULL;
    char *pattern = NULL;

    for (int i = 0; (*content)[0] != '\0'; i = 0) {
        while ((*content)[i] != ' ' && (*content)[i] != '\0')
            i++;
        pattern = my_malloc_str(i + 1, '\0');
        my_strncpy(pattern, *content, i);
        (*content) += i;
        if ((*content)[0] == ' ') (*content)++;
        my_putend(pattern, &words);
        free(pattern);
    }
    (*content) -= len;
    return (words);
}
