/*
** EPITECH PROJECT, 2021
** MY_SORT_PARAMS
** File description:
** Task06
*/

int my_putstr(char *str);

int main(int argc, char **argv)
{
    int displayed = 0;
    int min_ascii = argv[0][0];
    int old_min = argv[0][0];
    int i_to_display = 0;

    while (displayed != argc) {
        for (int i = 0; i < argc; i++) {
            if (argv[i][0] < min_ascii && argv[i][0] > old_min) {
                old_min = min_ascii;
                min_ascii = argv[i][0];
                printf("TEST: %s\n", argv[i]);
                i_to_display = i;
            }
        }
        min_ascii = 127;
        my_putstr(argv[i_to_display]);
        my_putstr("\n");
        displayed++;
    }
    return (0);
}
