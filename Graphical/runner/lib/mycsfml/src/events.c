/*
** EPITECH PROJECT, 2021
** MY CSFML
** File description:
** Events
*/

#include "mycsfml_events.h"

void check_closing_event(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
}
