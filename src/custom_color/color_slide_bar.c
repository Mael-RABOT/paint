/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** color_slide_bar
*/

#include "../../include/prototype.h"

slide_bar_t **init_slide_bar_array(void)
{
    slide_bar_t **array = malloc(sizeof(slide_bar_t*) * 4);
    array[0] = init_slide_bar((sfVector2f){40, 51});
    array[1] = init_slide_bar((sfVector2f){40, 101});
    array[2] = init_slide_bar((sfVector2f){40, 151});
    array[3] = NULL;
    return (array);
}

void slide_bar_event(sfEvent event, slide_bar_t **array)
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
