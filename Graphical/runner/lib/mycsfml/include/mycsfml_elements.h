/*
** EPITECH PROJECT, 2021
** MY CSFML
** File description:
** Elements.h
*/

#ifndef MYCSFML_ELEMENTS_H_
    #define MYCSFML_ELEMENTS_H_
    #include <SFML/Graphics.h>
    #include "mycsfml_framebuffer.h"

void disp_framebuffer(sfTexture *t, framebuffer_t *fb, sfSprite *sprite,
sfRenderWindow *window);
void disp_texture(sfTexture *texture, sfSprite *sprite,
sfRenderWindow *window);
void csfml_destroyer(const char *format, ...);

#endif /* !MYCSFML_ELEMENTS_H_ */
