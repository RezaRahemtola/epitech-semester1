/*
** EPITECH PROJECT, 2021
** MyScreensaver
** File description:
** main.c
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <time.h>
#include "my_screensaver.h"
#include "my.h"

static int check_errors(int argc, char **argv)
{
    if (argc != 2) {
        my_putstr(argv[0]);
        my_putstr(": bad arguments: ");
        my_put_nbr(argc - 1);
        my_putstr(" given but 1 is required\nretry with -h\n");
        return (1);
    }
    return (0);
}

static void disp_help(void)
{
    my_printf("animation rendering in a CSFML window.\n\nUSAGE\n  ");
    my_printf("./my_screensaver [OPTIONS] animation_id\n   animation_id    ");
    my_printf("ID of the animation to process (between 1 and %d).", MAX_ID);
    my_printf("\n\nOPTIONS\n  -d               ");
    my_printf("print the description of all the animations and quit.\n  -h ");
    my_printf("              print the usage and quit.\n\nUSER INTERACTIONS");
    my_printf("\n  LEFT_ARROW       switch to the previous animation.\n");
    my_printf("  RIGHT_ARROW      switch to the next animation.\n");
}

static void disp_description(void)
{
    my_printf("1: spiral filling the window to form a tunnel ");
    my_printf("with a changing tone of green/yellow.\n");
    my_printf("2: ball moving at a random speed, bouncing when touching ");
    my_printf("a border with it's color randomly changing at each bounce.\n");
    my_printf("3: 100 segments with random colors and positions ");
    my_printf("displayed one by one.\n");
    my_printf("4: a pixel night with random colors displayed at empty spots");
    my_printf(" and a fading effect when the screen is almost full\n");
}

int main(int argc, char **argv)
{
    srand(time(NULL));
    if (check_errors(argc, argv) == 1)
        return (84);
    if (my_strcmp(argv[1], "-h") == 0) {
        disp_help();
        return (0);
    } else if (my_strcmp(argv[1], "-d") == 0) {
        disp_description();
        return (0);
    }
    if (my_strlen(argv[1]) != 1 || argv[1][0] < '1' ||
    argv[1][0] > MAX_ID + '0')
        return (84);
    display_window(argv[1][0] - '1');
    return (0);
}
