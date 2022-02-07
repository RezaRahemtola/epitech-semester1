/*
** EPITECH PROJECT, 2021
** rush3
** File description:
** header
*/

#ifndef RUSH_3_
    #define RUSH_3_
    #define BUFF_SIZE 30000
char *stumper(char *buff);
int get_size_x(char *buff);
int get_size_y(char *buff);
char *rush1(int x, int y);
char *rush2(int x, int y);
char *rush3(int x, int y);
char *rush4(int x, int y);
char *rush5(int x, int y);
char *get_special_case(int x, int y, char *line_model_x, char *line_model_y);
char *get_square(int x, int y,  char *square_model);
char *int_to_str(int nb);
#endif
