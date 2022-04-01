/*
** EPITECH PROJECT, 2021
** MyScreensaver
** File description:
** main.c
*/

#include "my_runner.h"

static int check_file(char *bin, char *path)
{
    FILE *file = fopen(path, "r");
    size_t bufsize = 2;
    char *buffer = malloc(sizeof(char) * bufsize);
    int nb_obstacles = 0;

    if (file == NULL) {
        my_printf("%s: %s: No such file.\n", bin, path);
        return (1);
    }
    while (getline(&buffer, &bufsize, file) > 0 && nb_obstacles == 0)
        if (buffer[0] == '1' || buffer[0] == '2')
            nb_obstacles++;
    if (nb_obstacles == 0) {
        my_printf("%s: File must contains at least one obstacle.\n", bin);
        return (1);
    }
    fclose(file);
    free(buffer);
    return (0);
}

static int check_menu(void)
{
    if (check_file("./my_runner", "tests/samples/easy.txt") == 1) return (1);
    if (check_file("./my_runner", "tests/samples/medium.txt") == 1) return (1);
    if (check_file("./my_runner", "tests/samples/hard.txt") == 1) return (1);
    return (0);
}

static int check_errors(int argc, char **argv)
{
    if (argc != 2) {
        my_printf("%s: bad arguments: %d", argv[0], argc - 1);
        my_putstr(" given but 1 is required\nretry with -h\n");
        return (1);
    }
    if (my_strcmp(argv[1], "-m") != 0)
        return (check_file(argv[0], argv[1]));
    else
        return (check_menu());
}

static void disp_help(void)
{
    my_printf("Finite runner created with CSFML.\nUSAGE\n");
    my_printf("./my_runner map.txt\n\n");
    my_printf("OPTIONS\n-h\tprint the usage and quit.\n");
    my_printf("-m\tdisplay a menu to let you choose between 3 levels.\n\n");
    my_printf("USER INTERACTIONS\nSPACE_KEY/UP ARROW\tjump.\n");
    my_printf("ESCAPE                  pause/play the game.\n");
    my_printf("RIGHT/LEFT ARROW\tincrease/reduce player speed.\n");
}

int main(int argc, char **argv)
{
    srand(time(NULL));
    if (argc == 2 && my_strcmp(argv[1], "-h") == 0) {
        disp_help();
        return (0);
    }
    if (check_errors(argc, argv) == 1) return (84);
    display_window(argv[1]);
    return (0);
}
