/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** size_event
*/

#include "../../include/prototype.h"

static void size_slide_event(sfEvent event, slide_bar_t **array)
{
    if (event.type == sfEvtMouseButtonPressed)
        for (int i = 0; array[i] != NULL; i++)
            array[i]->pressed(array[i], event.mouseButton);
    if (event.type == sfEvtMouseButtonReleased)
        for (int i = 0; array[i] != NULL; i++)
            array[i]->released(array[i], event.mouseButton);
    if (event.type == sfEvtMouseMoved)
        for (int i = 0; array[i] != NULL; i++)
            array[i]->move(array[i], event.mouseMove);
}

void size_event(sfRenderWindow *window, slide_bar_t **array)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        size_slide_event(event, array);
    }
}
