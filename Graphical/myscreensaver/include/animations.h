/*
** EPITECH PROJECT, 2021
** MyScreensaver
** File description:
** Animations
*/

#ifndef ANIMATIONS_H_
    #define ANIMATIONS_H_
    #include "utils.h"
    typedef struct animations {
        sfColor tunnel_color;
        coords *tunnel_pos;
        sfColor circle_color;
        sfVector2i circle_pos;
        sfVector2i circle_speed;
        int circle_radius;
        int lines_nb;
        int pxl_nb;
    } anim_info;
    anim_info *init_info(framebuff *fb);
    void reinit_info(anim_info *info, framebuff *fb);
    void free_info(anim_info *info);
    void tunnel(framebuff *fb, anim_info *info);
    void circle(framebuff *fb, anim_info *info);
    void lines(framebuff *fb, anim_info *info);
    void pixel_night(framebuff *fb, anim_info *info);
    void display_window(int nb_anim);
#endif /* !ANIMATIONS_H_ */
