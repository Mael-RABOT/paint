/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** create_layer.c
*/

#include "../../include/prototype.h"

layer_t *append_layer(layer_t *layer)
{
    while (layer->next_layer != NULL) {
        layer = layer->next_layer;
    }
    layer->next_layer = malloc(sizeof(layer_t));
    layer = layer->next_layer;
    layer->layer = malloc(DRAWING_WIDTH * DRAWING_HEIGHT * 4);
    set_background_color(layer->layer, sfTransparent);
    sfVector2f size = {DRAWING_WIDTH, DRAWING_HEIGHT};
    sfVector2f position = {DRAWING_POS_X, DRAWING_POS_Y};
    layer->rectangle = create_rectangle(size, position);
    sfTexture_updateFromPixels(layer->rectangle->texture, layer->layer,
        DRAWING_WIDTH, DRAWING_HEIGHT, 0, 0);
    layer->next_layer = NULL;
    return layer;
}

layer_t *create_layer(sfColor color)
{
    layer_t *layer = malloc(sizeof(layer_t));
    layer->layer = malloc(DRAWING_WIDTH * DRAWING_HEIGHT * 4);
    set_background_color(layer->layer, sfTransparent);
    sfVector2f size = {DRAWING_WIDTH, DRAWING_HEIGHT};
    sfVector2f position = {DRAWING_POS_X, DRAWING_POS_Y};
    layer->rectangle = create_rectangle(size, position);
    sfTexture_updateFromPixels(layer->rectangle->texture, layer->layer,
        DRAWING_WIDTH, DRAWING_HEIGHT, 0, 0);
    layer->next_layer = NULL;
    return layer;
}
