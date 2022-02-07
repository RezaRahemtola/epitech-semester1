/*
** EPITECH PROJECT, 2022
** antman
** File description:
** Generic header file
*/

#ifndef ANTMAN_GENERAL_H_
    #define ANTMAN_GENERAL_H_
    #include "my.h"
    #define HTML_UNSIGNED 241
    #define BASE "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
    #define BASE2 "0123456789!\"#$&'()*,./:;<=>?[\\]^{|}~"

typedef struct pattern_s {
    char *str;
    struct pattern_s *next;
} pattern_t;

// Error handling
int check_errors(int argc, char **argv, int fd, int size);

// Patterns list
void my_putend(char *str, pattern_t **dest);
void list_destroy(pattern_t *obj);
int is_in_list(char *str, pattern_t *list);
int get_list_len(pattern_t *list);
pattern_t *get_html_patterns_list(void);
int is_in_next_list(char *str, pattern_t *list);
void destroy_node(pattern_t **head);
pattern_t *get_words(char **content);
int get_base_nbr(char *str);

#endif /* !ANTMAN_GENERAL_H_ */
