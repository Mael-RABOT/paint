/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** size_slide_bar
*/

#include "../../include/prototype.h"

void free_slide_bar_array(slide_bar_t **array)
{
    int i = 0;
    while (array[i] != NULL)
        free(array[i++]);
    free(array);
}

slide_bar_t **size_slider(brush_shape_t shape)
{
    if (shape == SQUARE) {
        slide_bar_t **array = malloc(sizeof(slide_bar_t *) * 2);
        array[0] = init_slide_bar((sfVector2f) SQUARE_POS);
        array[1] = NULL;
        return (array);
    }
    if (shape == RECTANGLE) {
        slide_bar_t **array = malloc(sizeof(slide_bar_t*) * 3);
        array[0] = init_slide_bar((sfVector2f)RECT_POS1);
        array[1] = init_slide_bar((sfVector2f)RECT_POS2);
        array[2] = NULL;
        return (array);
    }
    return (NULL);
}
