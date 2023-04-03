/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** free_layer.c
*/

#include "../../include/prototype.h"

int free_layer(layer_t *layer)
{
    if (layer == NULL)
        return 0;
    free(layer->layer);
    sfTexture_destroy(layer->rectangle->texture);
    sfRectangleShape_destroy(layer->rectangle->rectangle);
    free(layer->rectangle);
    free_layer(layer->next_layer);
    free(layer);
    return 0;
}
