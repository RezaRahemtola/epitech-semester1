/*
** EPITECH PROJECT, 2022
** antman
** File description:
** Functions for algo_lyr
*/

#include <stddef.h>
#include <stdlib.h>
#include "antman.h"

static void disp_comp(pattern_t *list, char *order, char *content)
{
    if (get_list_len(list) + my_strlen(order) > my_strlen(content)) {
        my_printf(content);
    } else {
        for (; list != NULL; list = list->next)
            my_printf("%s@", list->str);
        my_printf(order);
    }
    free(order);
}

static void add_existing_pattern(char *order, char *pattern, pattern_t *list)
{
    if (order[my_strlen(order) - 1] != '+')
        my_strcat(order, "-", 0);
    my_strcat(order, int_to_base(is_in_list(pattern, list), BASE BASE2), 1);
}

static void concat_unique_words(char *content, pattern_t **words,
pattern_t **patterns, char **order)
{
    char *tmp = my_malloc_str(my_strlen(content) + 1, '\0');

    while (*words != NULL && is_in_list((*words)->str, *patterns) == -1 &&
    is_in_next_list((*words)->str, *words) == -1) {
        my_strcat(tmp, (*words)->str, 0);
        destroy_node(words);
        my_strcat(tmp, " ", 0);
    }
    if (tmp[my_strlen(tmp) - 1] == ' ') tmp[my_strlen(tmp) - 1] = '\0';
    my_putend(tmp, patterns);
    my_strcat(*order, "+", 0);
    free(tmp);
}

static void inexistant_pattern(char *content, pattern_t **words,
pattern_t **patterns, char **order)
{
    if (is_in_next_list((*words)->str, *words) != -1) {
        my_putend((*words)->str, patterns);
        my_strcat(*order, "+", 0);
        destroy_node(words);
    } else {
        concat_unique_words(content, words, patterns, order);
    }
}

void comp_lyr(char **content)
{
    pattern_t *patterns = NULL;
    pattern_t *words = get_words(content);
    char *order = my_malloc_str(my_strlen(*content), '\0');

    while (words != NULL) {
        if (is_in_list(words->str, patterns) != -1) {
            add_existing_pattern(order, words->str, patterns);
            destroy_node(&words);
        } else {
            inexistant_pattern(*content, &words, &patterns, &order);
        }
    }
    disp_comp(patterns, order, *content);
    list_destroy(patterns);
}
