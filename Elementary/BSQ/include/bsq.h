/*
** EPITECH PROJECT, 2021
** BSQ
** File description:
** .h
*/

#ifndef BSQ_H_
    #define BSQ_H_
    struct map {
        char **map;
        int rows;
        int cols;
    };
    char **mem_alloc_2d_array(int nb_rows, int nb_cols);
    char **load_map(char const *f_path, int nb_rows, int nb_cols, int ignore);
    void display_map(char **map, int nb_rows, int nb_cols);
    int get_first_line_nbr(char const *filepath);
    int first_line_bytes(char const *filepath);
    int is_square_of_size(struct map sm, int row, int col, int square_size);
    int find_biggest_square(struct map sm, int row, int col, int biggest);
    int check_map_errors(char *path, int cols, int ignore);
    int check_errors(int argc, char **argv);
#endif /* !BSQ_H_ */
