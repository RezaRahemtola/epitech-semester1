/*
** EPITECH PROJECT, 2021
** MyScreensaver
** File description:
** .h
*/

#ifndef CSFML_UTILS_
    #define CSFML_UTILS_
    #include <SFML/Graphics.h>
    typedef struct framebuffer {
        unsigned int width;
        unsigned int height;
        sfUint8 *pixels;
        int bpp;
    } framebuff;
    typedef struct coordinates {
        int x;
        int y;
        int min_x;
        int min_y;
        int max_x;
        int max_y;
    } coords;
    typedef struct circle_data {
        int x;
        int y;
        sfVector2i center;
        int radius;
    } circle_info;
    void check_closing_event(sfRenderWindow *window, sfEvent event);
    sfRenderWindow *create_window(unsigned int width, unsigned int height, \
    char const *title, unsigned int framerate);
    framebuff *framebuffer_create(int width, int height, int bpp);
    void framebuffer_destroy(framebuff *fb);
    void framebuffer_fill(framebuff *fb, sfColor color);
    void put_pixel(framebuff *fb, unsigned int x, unsigned int y, \
    sfColor color);
    sfColor get_pixel(framebuff *fb, unsigned int x, unsigned int y);
    void destroy_elements(sfRenderWindow *window, sfTexture *texture, \
    sfSprite *sprite, framebuff *fb);
    coords *coords_create(unsigned int width, unsigned int height);
    void coords_init(coords *c, unsigned int width, unsigned int height);
    void draw_circle(framebuff * fb, sfVector2i center, int radius, \
    sfColor c);
    int draw_line(framebuff *fb, sfVector2i point_a, sfVector2i point_b, \
    sfColor color);
    void pixels_to_sprite(sfTexture *t, framebuff *fb, sfSprite *sprite, \
    sfRenderWindow *window);
    sfColor get_rand_color(void);
#endif /* !CSFML_UTILS_ */
